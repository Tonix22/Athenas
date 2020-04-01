#include<vector>
#include<cassert>
using namespace std;

template<class T>
class Stack
{
    private:
        vector<T> elems;
    public:
        Stack() = default;
        Stack<T>& operator= (Stack<T> const&);

        void push(T const& elem);
        T pop();
        T const& top() const;
        bool empty() const
        {
            return elems.empty();
        }

};
template<typename T>
void Stack<T>::push(T const& elem)
{
    elems.push_back(elem);
}
template<typename T>
T Stack<T>::pop(void)
{
    assert(!elems.empty());
    T elem = elems.pop_back();
    return elem;
}
template<typename T>
T const& Stack<T>::top(void) const
{
    assert(!elems.empty());
    return elems.back();
}