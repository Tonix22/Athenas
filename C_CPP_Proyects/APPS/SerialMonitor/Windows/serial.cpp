#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
using namespace std;
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define QUIT 113

class SerialPort
{
    HANDLE hSerial;
    public:
    SerialPort(string port, int baudrate)
    {
        string number = port.substr(3);
        if(number.size()>1)
        {
            port="\\\\.\\"+port;//stupid windows stuff required
        }
        const TCHAR* COM = port.c_str();
        //hSerial = CreateFile(COM,GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
        hSerial = CreateFile(COM,GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,0);
        cout<<"serial ptr: "<<hSerial<<endl;
        if(hSerial==INVALID_HANDLE_VALUE)
        {
            if(GetLastError()==ERROR_FILE_NOT_FOUND)
            {
                std::cout << "serial port doesn't exist" << std::endl;
            }
        }
        //UART CONFIG 
        DCB dcbSerialParams = {0};
        if (!GetCommState(hSerial, &dcbSerialParams))
        {
            std::cout << "Get serial data error" << std::endl;
        }
        dcbSerialParams.BaudRate=baudrate;
        dcbSerialParams.ByteSize=8;
        dcbSerialParams.StopBits=ONESTOPBIT;
        dcbSerialParams.Parity=NOPARITY;
        if(!SetCommState(hSerial, &dcbSerialParams))
        {
            std::cout << "Set serial data error" << std::endl;
            //error setting serial port state
        }

        COMMTIMEOUTS timeouts={0};
        timeouts.ReadIntervalTimeout=50;
        timeouts.ReadTotalTimeoutConstant=50;
        timeouts.ReadTotalTimeoutMultiplier=10;
        timeouts.WriteTotalTimeoutConstant=50;
        timeouts.WriteTotalTimeoutMultiplier=10;
        if(!SetCommTimeouts(hSerial, &timeouts))
        {
            std::cout << "set timeout error" << std::endl;
        }
    }
    bool write_string(string message)
    {
        DWORD dwBytesRead = 0;
        bool status = WriteFile(hSerial, message.c_str(), message.size(), &dwBytesRead, NULL);
        if(status == false)
        {
            std::cout << "write error" << std::endl;
        }
        else
        {
            std::cout << "write sucefully" << std::endl;
        }
        return status;
    }
    ~SerialPort()
    {
        if(CloseHandle(hSerial))
            std::cout << "close sucefully" << std::endl;
    }


};

void keyboardController(SerialPort* ser)
{
    int c = 0;
    int end =1;
    while(end)
    {
        c = 0;

        switch((c=getch())) {
        case KEY_UP:
            cout << endl << "Up" << endl;//key up
            ser->write_string("KB_SIM UP\r\n");
            break;
        case KEY_DOWN:
            cout << endl << "Down" << endl;   // key down
            ser->write_string("KB_SIM DOWN\r\n");
            break;
        case KEY_LEFT:
            cout << endl << "Left" << endl;  // key left
            ser->write_string("KB_SIM CANCEL\r\n");
            break;
        case KEY_RIGHT:
            cout << endl << "Right" << endl;  // key right
            ser->write_string("KB_SIM ENTER\r\n");
            break;
        case QUIT:
            cout << c << "null" << endl;  // quit
            end = 0;
            break;
        }

    }
}

int main(int argc, char const *argv[])
{
    SerialPort* ser= new SerialPort("COM27",115200);
    keyboardController(ser);
    delete(ser);
    return 0;
}
