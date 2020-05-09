#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define QUIT 113

#define THREAD_CREATE(hand,id,func)  hand = CreateThread(NULL, 0, func, (void*)serial_handler,0,&id);\
                                if (hand == NULL)\
                                {\
                                    ExitProcess(3);\
                                }\

using namespace std;
#define RECIVE_BUFFER_SIZE 100
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
        hSerial = CreateFile(COM,GENERIC_READ | GENERIC_WRITE,0,0,OPEN_EXISTING,FILE_FLAG_OVERLAPPED,0);
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

        COMMTIMEOUTS timeouts;
        timeouts.ReadIntervalTimeout=MAXDWORD;
        timeouts.ReadTotalTimeoutMultiplier=0;
        timeouts.ReadTotalTimeoutConstant=0;
        timeouts.WriteTotalTimeoutConstant=0;
        timeouts.WriteTotalTimeoutMultiplier=0;
        if(!SetCommTimeouts(hSerial, &timeouts))
        {
            std::cout << "set timeout error" << std::endl;
        }
    }
    int read_string()
    {
        DCB dcb; 
        int retVal;
        BYTE Byte[RECIVE_BUFFER_SIZE]; 
        DWORD dwBytesTransferred;
        DWORD dwCommModemStatus;
        
        OVERLAPPED ov;
        OVERLAPPED rx;
        memset(&ov,0,sizeof(ov));
        ov.hEvent = CreateEvent( 0,true,0,0);
        
        memcpy(&rx,&ov,sizeof(rx));

        memset(Byte,0,RECIVE_BUFFER_SIZE);

        if (!GetCommState(hSerial,&dcb))
        {
            cout<<"COM state NOT OK "<<endl;
        }
        
        dcb.BaudRate = 115200; //9600 
        dcb.ByteSize = 8; //8 
        dcb.Parity   = NOPARITY; //no 
        dcb.StopBits = ONESTOPBIT; //1 stop 
        if (!SetCommState(hSerial,&dcb))
        {
            cout<<"CON SET NOT OK"<<endl;
            return 0x100; 
        }
        
        SetCommMask (hSerial, EV_RXCHAR |EV_ERR); //receive character event 
        WaitCommEvent (hSerial, &dwCommModemStatus, &ov); //wait for character
        
        if (dwCommModemStatus & EV_RXCHAR) 
        {
            ReadFile (hSerial, &Byte, RECIVE_BUFFER_SIZE, &dwBytesTransferred, &rx); //read 1 
            printf("%s\r\n",Byte);
        }
        else if (dwCommModemStatus & EV_ERR) 
        {
            retVal = 0x101; 
        }
       
        return retVal;
    }
    bool write_string(string& message)
    {
        OVERLAPPED tx;
        DWORD dwBytesRead = 0;
        DWORD read = 0;
        memset(&tx,0,sizeof(tx));
        tx.hEvent = CreateEvent( 0,true,0,0);
        bool status = WriteFile(hSerial, message.c_str(), message.size(), &dwBytesRead, &tx);
        return status;
    }
    ~SerialPort()
    {
        if(CloseHandle(hSerial))
            std::cout << "close sucefully" << std::endl;
    }
};