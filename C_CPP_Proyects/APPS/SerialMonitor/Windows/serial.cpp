#include "serial.hpp"
#include <unordered_map>
#include <cstdlib>
using namespace std;
unordered_map<int,string> commands;
void init_commands(void)
{
    //commands.insert(make_pair(KEY_UP,"KB_SIM UP\r\n"));
    commands[KEY_UP]    = "KB_SIM UP\r\n";
    commands[KEY_DOWN]  = "KB_SIM DOWN\r\n";
    commands[KEY_LEFT]  = "KB_SIM CANCEL\r\n";
    commands[KEY_RIGHT] = "KB_SIM ENTER\r\n";
    commands[QUIT]      = "Quit";
}

void keyboardController(SerialPort* ser)
{
    string cmd_check;
    while(cmd_check !="Quit")
    {
        cmd_check = commands[getch()];
        ser->write_string(cmd_check);
    }
}
int main(int argc, char const *argv[])
{
    SerialPort* ser= (argv[1]) ? (new SerialPort(argv[1], atoi(argv[2]))) : new SerialPort("COM27", 115200);
    init_commands();
    keyboardController(ser);
    delete(ser);
    return 0;
}
