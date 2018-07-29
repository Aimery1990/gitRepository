
#include "iostream"
#include "string"

using namespace std;

template <typename T>
class A{
protected:
    T a;
    
public:
    A(){;}
    A(T a)
    {
        this->a = a;
    }
    A(const A & ano)
    {
        this->a = ano.a;
    }
    ~A(){;}
    
    
    void set(T a)
    {
        this->a = a;
    }
    T get()
    {
        return this->a;
    }
};

template <typename T1, typename T2>
class B: public A<T2>{
    T1 c;
public:
    B(T1 ca, T2 a):c(ca)/*, A(a)*/ //this doesn't works, due to A hasn't been a valid class.  error: member initializer 'A' does not name a non-static data member or base class !!!!
    {
        A<T2>::a = a;   //If a in A is private, this doesn't work!!!!
    }
    void set(T1 c){
        this->c = c;
    }
    T1 get()
    {
        return this->c;
    }
};


void printAi(A<int> * ptr)
{
    cout << ptr->get() << endl;
}

void printAc(A<char> * ptr)
{
    cout << ptr->get() << endl;
}


int main()
{
    A<int> insa;
    A<char> insb;
    insb.set('W');
    insa.set(4);
    cout << insa.get() << endl;
    
    printAi(&insa);
    printAc(&insb);
    
    B<int, char> inb(55, 'c');
    inb.set(5);
    cout << inb.get() << endl;
    
    
    return 0;
}


