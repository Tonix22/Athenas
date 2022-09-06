#include <iostream>

using namespace std;

class Board
{
    Board()
    {
    }

};

class Cell
{
private:
    int value;
    
public:
friend std::ostream& operator<<(std::ostream& os,Cell& v);
    Cell(int value)
    {   
        this->value = value;
    }

};

class maze_matrix
{
public:
    int size;
    int** matrix;
    maze_matrix(int size) : size(size) {
        matrix = new int*[size];
        for(int i = 0; i < size; ++i) {
            matrix[i] = new int[size];
        }

        for(int i = 0; i < size; ++i)
            for(int j = 0; j < size; ++j)
                matrix[i][j] = 0xF;

        matrix[1][1]=0xA;
        matrix[1][2]=0x3;
    }
    
};

std::ostream& operator<<(std::ostream& os,Cell& v)
{
    switch(v.value)
    {
        case 0xF:
            os << "+---+\nhpw t"
               << "|   |\n"
               << "+---+";
        break;
        default:
        break;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os,maze_matrix& v)
{
    for(int i = 0; i < (v.size << 1); ++i)
    {
        for(int j = 0; j < v.size; ++j)
        {
            if(i & 1)
            {
                if(v.matrix[i >> 1][j] & 0x4)
                {
                    cout << "|   ";
                }else
                {
                    cout << "    ";
                }
            }
            else
            {
                if(v.matrix[i >> 1][j] & 0x2)
                    cout << "+---";
                else
                {
                    cout << "    ";
                }
            }
        }
        if(i & 1)
        {
            cout << "|";
        }
        else
        {
            cout << "+";
        }
        cout<<endl;
    }

    return os;
}

int main(int argc, char **argv)
{
    maze_matrix mm(4);
    cout<<mm<<endl;
}

/*
         N   0010 
         |
0100 O-------E 0001
         |
         S   1000
         
+---+---+---+ 0
  A   3 | F |
+---+   +---+ 2
| F | 5 | F |
+---+   +---+ 4
| F | C   A    
+---+---+---+ 6
*/