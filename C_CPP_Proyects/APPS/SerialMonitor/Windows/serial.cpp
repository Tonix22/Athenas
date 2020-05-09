#include <thread> 
#include "serial.hpp"
#include <unordered_map>
#include <cstdlib>
#include <windows.h>
#include <tchar.h>

using namespace std;
unordered_map<int,string> commands;
bool can_read = false;
void init_commands(void)
{
    //commands.insert(make_pair(KEY_UP,"KB_SIM UP\r\n"));
    commands[KEY_UP]    = "KB_SIM UP\r\n";
    commands[KEY_DOWN]  = "KB_SIM DOWN\r\n";
    commands[KEY_LEFT]  = "KB_SIM CANCEL\r\n";
    commands[KEY_RIGHT] = "KB_SIM ENTER\r\n";
    commands[QUIT]      = "Quit";
}

static DWORD WINAPI keyboardController( LPVOID lpParam ) 
{
    string cmd_check;
    SerialPort* ser = ( SerialPort*)lpParam;
    while(cmd_check !="Quit")
    {
        cmd_check = commands[getch()];
        ser->write_string(cmd_check);
        can_read = true;
    }
    delete(ser);
    return 0;
}
static DWORD WINAPI Recieve_Thread(LPVOID lpParam)
{
    SerialPort* ser = ( SerialPort*)lpParam;
    while(1)
    {
        if(can_read == true)
        {
            ser->read_string();
            can_read = false;
        }
    }
}

void create_serial_threads(SerialPort* serial_handler)
{
    HANDLE  tx_handle;
    DWORD   tx_ID;

    HANDLE  rx_handle;
    DWORD   rx_ID;

    THREAD_CREATE(tx_handle,tx_ID,keyboardController);
    THREAD_CREATE(rx_handle,rx_ID,Recieve_Thread);
    // Wait until all threads have terminated.
    WaitForSingleObject(tx_handle,INFINITE);
    
    CloseHandle(tx_handle);
    CloseHandle(rx_handle);

}


int main(int argc, char const *argv[])
{
    SerialPort* ser= (argv[1]) ? (new SerialPort(argv[1], atoi(argv[2]))) : new SerialPort("COM27", 115200);
    init_commands();
    //thread first  (keyboardController,ser); 
    //thread second (bar,ser);
    create_serial_threads(ser);
    return 0;
}
