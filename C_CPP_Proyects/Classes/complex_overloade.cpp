#include <stdlib.h>
#include <complex>
#include <iostream>
namespace std
{
    
    class Dual : public std::complex<double>
    {
        public:
        Dual(double real, double imag): complex(real,imag)  
        {}
        
    };


    inline Dual operator * (const Dual &a, const Dual &b)
    {
        cout<<"multiplicando duales"<<endl;
        return Dual(a.real() * b.real(),a.real()*b.imag()+a.imag()*b.real());
    }

    inline Dual operator * (int a, const Dual &b)
    {
        cout<<"multiplicando duales"<<endl;
        return Dual(a*b.real(),a*b.imag());
    }

    inline Dual operator + (const Dual &a, const Dual &b)
    {
        return Dual(a.real()+b.real(),a.imag()+b.imag());
    }
    inline Dual operator + (const Dual &a, int b)
    {
        return Dual(a.real()+b,a.imag());
    }

}

int main(int argc, char const *argv[])
{
    std::complex<double> a(2,3);
    std::complex<double> b(5,7);
    std::Dual d(3,1); // 3*3+ 2*3*1 i +-1 
    
    //std::Dual res = d*d+2*d+3;
    //std::cout<<pow(d, 2)<<std::endl;

    return 0;
}
