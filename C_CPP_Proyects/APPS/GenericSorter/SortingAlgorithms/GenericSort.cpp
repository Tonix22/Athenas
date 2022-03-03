#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class GenericSort
{
private:

public:

virtual void sorter () = 0; 
virtual void search () = 0; // ??
virtual void move   () = 0;
virtual void update () = 0;
virtual bool condition() = 0;
virtual void imprimir()  = 0;
};


class QuickSort : public GenericSort
{
    private:
    vector <int> A;
    vector<int> B;
    vector<int>::iterator half;
    int item = 0;
    public:
    QuickSort(vector <int> v){
        A = v;
        //Base case
        B.push_back(A.back());
        A.pop_back();
    };
    ~QuickSort(){};
    
    bool condition(){
        return !A.empty();
    } 

    void search ()
    {
        // search BEGIN
        item  = A.back();

        half = find_insert_pos(B,item);//interfaz 
        // search END
    } 
    void move   ()
    {
        // MOVE BEGIN
        if (*half < item) 
            B.insert (half+1,item);
        else 
            B.insert (half,item);

        A.pop_back();
        // MOVE END
    }
    void update ()
    {
        A = B;
    }

    void sorter ()
    {
        while(condition())
        {
            search();
            move();
        }
        update();
    } 

    void imprimir(){
        for(auto i : A){
            cout << i <<" ,";
        }
        cout<< endl;
    }

    
    vector<int>::iterator find_insert_pos(vector <int>& B,int valor)
    {
        vector<int>::iterator inicio = B.begin(); 
        vector<int>::iterator fin    = B.end()-1; 
        vector<int>::iterator mitad;

        while (inicio <= fin) 
        {
            mitad = inicio + (fin-inicio)/2;

            if (*mitad == valor) // Si es numero repetido
                break; 

            if (*mitad < valor) // Recorrer inicio al centro
                inicio = mitad + 1; 

            else // recorrer final hacia la izquierda
                fin    = mitad - 1;
        }
        return mitad;
    }
    
};



class BubbleSort : public GenericSort
{
    private:
    vector<int> B;
    vector<int> A;
    vector<int>::iterator result;

    public:
    BubbleSort(vector <int> v)
    {
        A = v;
    };
    ~BubbleSort(){};
    //void search (vector<int>& A)
    bool condition(){
        return !A.empty();
    }
    void search ()
    {
       result = std::min_element(A.begin(), A.end()); // serach
    }
    //void move (vector<int>& A)
    void move ()
    {
        B.push_back(*result); // Move
        A.erase(result); // move
    }
    //void update (vector<int>& A)
    void update ()
    {
        A = B; // update
    }
    //void sorter (vector<int>& A)
    void sorter ()
    {
        while(condition())
        {
            search();
            move();
        }
        update();

    }

    void imprimir()
    {
        for(auto i: A)
        {
            cout<<i<<" ,";
        }
        cout<<endl;
    }

};



void radix_sort(std::vector<int>& values,int bit_size)
{
    for(int b_size = 0; b_size<bit_size; b_size++)
    {
        //// SEARCH BEGIN
        std::vector<int> zeros;
        std::vector<int> ones;
        for(int& v: values)
        {
            // v -> values[i]
            if((v & (1<<b_size) )>>b_size) // if 1      B->(1)
            {
                ones.push_back(v);
            }
            else // if 0  (0)<-(1)
            {
                zeros.push_back(v);
            }
        }
        ///// SEARCH END
        
        //// MOVE BEGIN
        values.clear(); 
        //pegar el de ceros
        values.insert(values.end(),zeros.begin(),zeros.end());
        //pegar el de unos
        values.insert(values.end(),ones.begin(), ones.end());
        /// MOVE END
    }
    
}

class RadixSort : public GenericSort{
    private:
        
        std::vector<int> values;
        int bit_size = 8;
        int b_size = 0;
        std::vector<int> zeros;
        std::vector<int> ones;
    public:
        void set_vector(std::vector<int> vec);
        bool condition()
        {
            return b_size < bit_size;
        }

        void sorter(){            
            while(condition())
            {
                //// SEARCH BEGIN
                search();
                move();   
            }
        }
        void search(){
            zeros.clear();
            ones.clear();
            for(int& v: values)
            {
                // v -> values[i]
                if((v & (1<<b_size) )>>b_size) // if 1      B->(1)
                {
                    ones.push_back(v);
                }
                else // if 0  (0)<-(1)
                {
                    zeros.push_back(v);
                }
            }
        }
        
        void move(){
            values.clear(); 
            values.insert(values.end(),zeros.begin(),zeros.end());
            values.insert(values.end(),ones.begin(), ones.end());
            b_size++;
        }
        void update(){

        } 
        void imprimir(){
            for(auto i: values){
                cout << i <<", ";
            }
            cout<<endl;
        }
};

void RadixSort::set_vector(std::vector<int> vec)
{
    values = vec;  
}

// polimorfico 
void SortAny(GenericSort* gen)
{
    while(gen->condition())
    {
        gen->search();
        gen->move();
    }
    gen->update();
    gen->imprimir();
}

int main()
{
    vector <int> data {30,4,2,0,8,9,1,10,20};
    
    QuickSort* quickRuth = new QuickSort(data);
    SortAny(quickRuth);
    //
    BubbleSort BubbleMigue = BubbleSort(data);
    SortAny(&BubbleMigue);
    //
    RadixSort FSort; 
    FSort.set_vector(data);  
    SortAny(&FSort);

    return 0;
}