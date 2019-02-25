

#include "iostream"

using namespace std;


class Base{

public:
    virtual void funcx(void);
};

void Base::funcx(void)
{
    cout << "This is funcx(void)" << endl;
}

class Derived: public Base{
public:
    virtual void funcx(void) override;
};

void Derived::funcx(void)
{
    cout << "This is rewriting Base's funxc in Derived with override keyword to tell compiler \
        it's rewriting" << endl;
}


int main()
{
    Derived test;
    test.funcx();
    return 0;
}
