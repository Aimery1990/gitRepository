
#include<iostream>
#include<memory>

using namespace std;

class A{
public:
    A(int i = 1): a(i)
    {
        cout << "hi! this is A(int i)" << endl;
    }
    
    ~A(){
        cout << "hi! this is ~A()" << endl;
    }
    
    void print()
    {
        cout << "a in void print() is: " << a << endl;
    }
    
private:
    int a;
};

template<typename A>
class MY_AUTO_PTR{
public:
    MY_AUTO_PTR(A * ptr):at_ptr(ptr)
    {
    }
    
    ~MY_AUTO_PTR()
    {
        delete at_ptr;
    }
    
    A * operator->()
    {
        return at_ptr;
    }
    
    A & operator*()
    {
        return *at_ptr;
    }
    
private:
    A * at_ptr;
};


void func()
{
    auto_ptr<A> at_ptr(new A);
    
    at_ptr->print();
    (*at_ptr).print();
}

void func1()
{
    MY_AUTO_PTR<A> my_at_ptr(new A);
    
    my_at_ptr->print();
    (*my_at_ptr).print();
}




int main()
{
    func();
    func1();
    return 0;
}
