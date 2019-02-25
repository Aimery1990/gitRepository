
#include "iostream"

using namespace std;

class A  //final   by final keyword this class is not allowed to be inherited
{
    public:
    virtual void funcx();

};

void A::funcx()
{
    cout << "this is funcx in A" << endl;
}

class B final : public A
{
    public:
    virtual void funcx() override
    {
        cout << "this is funcx in B by rewriting funcx in A by notation of override" << endl;
    }
};

int main()
{
    B b;
    b.funcx();
    return 0;
}


