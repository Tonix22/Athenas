# include <iostream>
# include <string>

using namespace std;

class Test {
    public:
    Test(){}
};

class Alumno{
    private:
    string name;
    int age; 
    int ID;  

    public:
    Alumno();
    Alumno(string nombre, int edad);
    Alumno(const Alumno& alumno2);

    void AlumnoID(int id);
    
    ~Alumno();
 
};

