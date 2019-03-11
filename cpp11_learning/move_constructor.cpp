
#include <iostream>
#include <assert.h>
#include <string.h>

using namespace std;

class Mem
{
public:
    Mem( int size = 1 ): memb(nullptr), sz(size)
    {
        cout << "Mem( int size = 1 )" << endl;
        cout << this << endl;
        if(sz>0)
        {
            memb = new char[sz];
        }
        else
        {
            //static_assert(static_cast<int>(size>0), "Trying to apply memory with negative value size");
            cout << "Trying to apply memory with negative value size" << endl;
        }
    }

    Mem(const Mem & ano)
    {
        cout << "Mem(const Mem & ano)" << endl;
        memb = new char[ano.sz];
        memcpy(memb, ano.memb, ano.sz);
        sz = ano.sz;
    }

    Mem( Mem && ano)
    {
        cout << "Mem( Mem && ano)" << endl;
        memb = ano.memb;
        sz = ano.sz;
        ano.memb = nullptr;
        ano.sz = 0;
    }

    Mem & operator=(const Mem & ano)
    {
        cout << "Mem & operator=(const Mem & ano)" << endl;
        if(memb!=nullptr)
        {
            delete [] memb;
        }
        memb = new char[ano.sz];
        memcpy(memb, ano.memb, ano.sz);
        sz = ano.sz;
        return *this;
    }

    void mem_show() const
    {
        cout << memb << endl;
        cout << sz << endl;
    }

    virtual ~Mem()
    {
        cout << "virtual ~Mem()" << endl;
        if(memb!=nullptr)
        {
            delete [] memb;
            memb = nullptr;
        }
        sz = 0;
    }

    char * Get_Mem()
    {
        return memb;
    }

private:
    char * memb;
    int sz;

};




int main()
{
    Mem m1(100);
    strcpy(m1.Get_Mem(), "hello world");
    Mem m2(std::move(m1));
    //m1.mem_show();
    m2.mem_show();
    Mem m3;
    m3.mem_show();
    m3 = m2;
    m3.mem_show();

    return 0;
}