#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

typedef struct
{
    vector<string> MAC_vector;
    vector<string> RSSI_vector;
}wifi_data_t;

void exec(string &result, const char* cmd) 
{
    char buffer[128];
    result = "";
    FILE* pipe = _popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
            //cout<<buffer<<endl;
        }
    } catch (...) {
        _pclose(pipe);
        throw;
    }
    _pclose(pipe);
    //return result;
}
void parse_exec(string &CMD,wifi_data_t* WIFI)
{
    string MAC_addres;
    string RSSI;
    std::size_t found = 0;//position of string found
    while(found != string::npos)
    {
        found = CMD.find("BSSID 1",found);
        found = CMD.find(":",found);

        MAC_addres = CMD.substr (found+2,17);

        found = CMD.find("Signal",found);
        found = CMD.find(":",found);
        RSSI  = CMD.substr (found+2,2);

        if(found != string::npos)
        {
            WIFI -> MAC_vector.push_back(MAC_addres);
            WIFI -> RSSI_vector.push_back(RSSI);
            //cout << "Mac: " << MAC_addres << endl;
            //cout << "RSSI: " << RSSI << endl;
        }
    }

}

int main(int argc, char const *argv[])
{
    /* code */
    string cmd_out="";
    exec(cmd_out,"netsh wlan show networks mode=bssid");
    wifi_data_t Signal_data;
    parse_exec(cmd_out,&Signal_data);
    string python_script;;
    for(auto N:Signal_data.MAC_vector)
    {   
        python_script="";
        python_script += "python Get_request.py ";
        python_script += N;
        exec(cmd_out,python_script.c_str());
        cout<<cmd_out<<endl;
    }
    


    return 0;
}
