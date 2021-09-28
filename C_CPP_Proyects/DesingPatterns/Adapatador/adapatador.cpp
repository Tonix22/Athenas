#include <iostream>
#include <string>

using namespace std;

/*Clase que ya existe*/
class interface {
    public:
    virtual ~interface(){}; 
    virtual string read_file(string file) const = 0;  
    virtual string Request() const {
        return "Parent: The default target's behavior.";
    }
};

class XML : public interface{
    public:
    string read_file (string file) const override 
    {
        
        return "XML file";
    }
};

/*CSV */
/*Adapatar tu clase*/
class CSV : public interface {
    public:
    //CSV(){};
    string read_file(string file) const override{
        
        return  "CSV file";
    }

    string Request() const {
        return "Child: Adapter :)";
    }
};

void client_code(const interface &app, string name) 
{
    string a = app.read_file(name);
    string b = app.Request();
    cout << a << endl;
    cout << b << endl;
}


int main(int argc, char const *argv[])
{
    //Ruti
    XML* xml = new XML();
    client_code(*xml,"Archivo.txt");
    
    //louigi
    CSV* csv = new CSV();
    client_code(*csv,"Archivo2.txt");
    
    return 0;
}
