#include"iostream"


using namespace std;

class Test{
public:
    Test()
    {
        
        cout << "This is Test()" << endl;
    }
    
    Test(int a, int b)
    {
        a = a;
        b = b;
        cout << "this is Test(int a, int b)" << endl;
    }
    
    ~Test()
    {
        cout << "this is ~Test()" << endl;
    }
    
private:
    int a;
    int b;
    
};


int main()
{
    int * p = new int;
    *p = 101;
    delete p;
    
    int *p1 = new int(100);
    delete p1;
    
    int * pa = new int[1000];
    pa[0] = 0;
    pa[1] = 1;
    delete [] pa;
    
    Test(1,2);
    Test * np = new Test(1,2);
    
    delete np;
    
    
    np = new Test[10];
    
    delete [] np;
    
    return 0;
}
