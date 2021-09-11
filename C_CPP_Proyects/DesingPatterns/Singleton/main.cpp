#include <string>
#include <iostream>

using namespace std;

class Singleton {
   static Singleton *instance;
   int data;
   // Private constructor so that no objects can be created.
   Singleton() {
      data = 0;
   }
   
   public:
   static Singleton * getInstance() {
      if (!instance) // aca solo existe una sola vez
      {
         instance = new Singleton;
      }
      return instance;
   }
   int getData() {
      return this -> data;
   }
   void setData(int data) {
      this -> data = data;
   }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton* Singleton::instance = 0; //AQUI

int main(){

   Singleton* hola = hola -> getInstance();
   hola -> setData(10);
   cout << hola -> getData() << endl;

   Singleton* adios = adios -> getInstance();
   cout << adios -> getData() << endl; // nifty

   return 0;
}