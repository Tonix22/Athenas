#include<iostream>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std; 

int debt, cambio;
string payment; //dinero que inserta la persona
int pay;


class monedas{
    public:
    int valor;
    int cantidad;
    monedas(int val, int max_cantidad)
    {
        this->valor = val;
        this->cantidad = ( rand( )% max_cantidad )+ 1;
    }

};
class billetes{
    public:
    int valor;
    int cantidad;
    billetes(int val,int max_cantidad)
    {
        this->valor = val;
        this->cantidad = ( rand( )% max_cantidad )+ 1;
    }        
};

class cajero{
    public:
    monedas m_1    = monedas (1,  100);
    monedas m_2    = monedas (2,  10);
    monedas m_5    = monedas (5,  10);
    monedas m_10   = monedas (10, 20);
    billetes b_20  = billetes(20, 4 );
    billetes b_50  = billetes(50, 10);
    billetes b_100 = billetes(100,5 );
    billetes b_200 = billetes(200,4 );
    billetes b_500 = billetes(500,10);
    cajero(){};
    int change (int pay){ //235 200+30+5

        //30 ---> 20
        //150 --> 100,50 
        int aux = 0;
        int cent;
        int dec;
        int uni;
        //con una deuda de 823
        /*aux = pay/500; //número de billetes que necesito
        aux = pay%500; //lo que me falta pagar*/
        cent = pay/100;
        pay = pay - cent;
        dec = pay/10;
        pay = pay - dec;
        uni = pay;
        cout<<"SI ENTRA ( ͡° ͜ʖ ͡°)"<<endl;
        return 0;
    }

    int change2LaVenganzaDelPincheCharroNegroMamadorEquisDeEquisDe(){ //referencias cultisimas
        
        

    }//soy una gisel moribunda, hambrienta y confundida :D x2 porque Gisel debe pasear a la Kira :D Son chidos valen mil!
};
cajero my_cajero; //zukis trukis

void payDebt_func(void)
{
    do{
    cout << "Pago insuficiente. CAITE CON LA LANA (ง ͠° ͟ل͜ ͡°)ง" << endl;
     cout<<"_______________||"<<endl;
     cout<<"\  ____________||------|"<<endl;
     cout<<" '.____________||-~~~~~|"<<endl;
     cout<<"               ||"<<endl;
        cout << "Total a pagars: $" << debt <<endl;
        cin >> payment;
        pay = stoi(payment);//conversion

        debt -= pay;
        cout<<"DEUDA"<<debt<<endl;
        cout<<"PAGO"<<pay<<endl;
    }while(debt > 0);

    pay = pay + debt; //200 -100
    cout<<"pay: "<<pay<<endl;
    my_cajero.change(pay);//zukis trukis 2.0
    
    if(pay == debt)
    {
        cout << "Deuda saldada. ( ‾ ʖ̫ ‾) " << endl;
    }
}

int main() 
{ 
    srand (time(NULL));
    /* generate secret number between 1 and 10: */
    debt =( rand( )% 1000 )+ 1;
    payDebt_func();

}


/*

                                                       ___
                                                      |_  |
                                                        | |
__                      ____                            | |
\ ````''''----....____.'\   ````''''--------------------| |--.               _____      .-.
 :.                      `-._                           | |   `''-----''''```     ``''|`: :|
  '::.                       `'--.._____________________| |                           | : :|
    '::..       ----....._______________________________| |                           | : :|
      `'-::...__________________________________________| |   .-''-..-'`-..-'`-..-''-.cjr :|
           ```'''---------------------------------------| |--'                         `'-'
                                                        | |
                                                       _| |
                                                      |___|
     _______________||
     \  ____________||------|
      '.____________||-~~~~~|
                    ||
*/ 