
#include <iostream>
#include <list>
#include <functional>

using namespace std;

class FunctorA
{
public:
    void operator()()
    {
        cout << "Functor A" << endl;
    }
};

class FunctorB
{
public:
    void operator()()
    {
        cout << "Functor B" << endl;
    }
};

class FunctorC
{
public:
    void operator()()
    {
        cout << "Functor C" << endl;
    }
};

class Object
{
public:
    Object(FunctorA a, FunctorB b, FunctorC c)
    {
        _list.push_back(a);
        _list.push_back(b);
        _list.push_back(c);
    }

    void notify()
    {
        for(auto & i:_list)
        {
            i();
        }
    }

private:
    list<function<void(void)>> _list;
};


int main()
{
    FunctorA a;
    FunctorB b;
    FunctorC c;
    Object obj(a, b, c);
    obj.notify();
}