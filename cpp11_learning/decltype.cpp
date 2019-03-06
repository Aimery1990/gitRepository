
#include<iostream>
#include <typeinfo>


using namespace std;

void func()
{
    cout << "hello world" << endl;
}

typedef void (*FUNC)();

int main()
{
    int i = 10;
    decltype(i) ii;
    cout << sizeof(i) << " type " << typeid(i).name() << endl;
    cout << sizeof(ii) << " type " << typeid(ii).name() << endl;

    decltype("china000") p = "aimer111";  //"china000" is const char *, therefore p needs to be initialized
    cout << sizeof(p) << " type " << typeid(p).name() << endl;

    string str = "china";
    char * pp = const_cast<char *>(str.c_str());
    decltype(pp) np;
    cout << sizeof(np) << " type " << typeid(np).name() << endl;

    FUNC f;
    decltype(f) fp = func;
    fp();
    cout << sizeof(fp) << " type " << typeid(fp).name() << endl;
 }