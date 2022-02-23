
void sort_vector_Ruth(vector<int>& A)
{
    vector<int> B;
    vector<int>::iterator result;
    while(!A.empty())
    {
        result = std::min_element(A.begin(), A.end());
        B.push_back(*result);
        A.erase(result);
    }
    A = B;
}