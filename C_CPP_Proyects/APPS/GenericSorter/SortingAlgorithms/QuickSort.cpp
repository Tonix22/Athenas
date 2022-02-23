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

void fastest_sort(vector <int>& A)
{
    std::vector<int> B;
    vector<int>::iterator half;
    int item = 0;

    //Base case
    B.push_back(A.back());
    A.pop_back();

    // Other cases
    while(!A.empty())
    {
        item  = A.back();

        half = find_insert_pos(B,item);//interfaz

        if (*half < item) 
            B.insert (half+1,item);
        else 
            B.insert (half,item);

        A.pop_back();
    }
    A=B;
}
