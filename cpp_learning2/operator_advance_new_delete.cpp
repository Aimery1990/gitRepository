
#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

//void * operator new ( size_t size )
//void operator delete ( void * ptr )
//void * operator new[] (size_t size )
//void operator delete[] ( void ptr )


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
    
    void * operator new ( size_t size ) //run before constructor!!!
    {
        cout << "operator new  size is "  << size << endl;
        void * ptr = malloc(size);
        memset(ptr , 0, size);
        ((A *)ptr)->a = 100;
        cout << "((A *)ptr)->a is: " << ((A *)ptr)->a << endl;
        return ptr;
    }
    
    void operator delete ( void * ptr ) //run after destructor!!!
    {
        cout << "operator delete" << endl;
        free(ptr);
    }
    
    void * operator new[] (size_t size )
    {
        cout << "operator new[] size is " << size << endl;
        void * ptr = malloc(size);
        return ptr;
    }
        
    void operator delete[] ( void * ptr )
    {
        cout << "operator delete[]" << endl;
        free(ptr);
    }
    
private:
    int a;
};

//make new new[] delete delete[] into global. NOT SUGGESTED!!!
//void * operator new ( size_t size ) //run before constructor!!!
//{
//    cout << "operator new  size is "  << size << endl;
//    void * ptr = malloc(size);
//    memset(ptr , 0, size);
//    return ptr;
//}
//
//void operator delete ( void * ptr ) //run after destructor!!!
//{
//    cout << "operator delete" << endl;
//    free(ptr);
//}
//
//void * operator new[] (size_t size )
//{
//    cout << "operator new[] size is " << size << endl;
//    void * ptr = malloc(size);
//    return ptr;
//}
//
//void operator delete[] ( void * ptr )
//{
//    cout << "operator delete[]" << endl;
//    free(ptr);
//}


int main()
{
    
    int * pi = new int;
    delete pi;
    
    int * pis = new int[5];
    delete [] pis;
    
    cout << "----------------------" << endl;
    
    
    A * pa = new A;
    delete(pa);
    
    A * pas = new A[5];
    
    delete[] pas;
    
    return 0;
}
