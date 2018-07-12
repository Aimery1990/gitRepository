
#include "iostream"
#include "string"

using namespace std;


template <typename T1, typename T2>
T2 Swap_Func_Tmp(T1 & a, T1 & b)
{
    T2 ret = 1;
    
    T1 tmp;
    tmp = a;
    a = b;
    b = tmp;
    return ret;
}

template <typename T1>
void Swap_Func_Tmp2(T1 & a, T1 & b)
{
    T1 tmp;
    tmp = a;
    a = b;
    b = tmp;
}


int main()
{
    int a = 10;
    int b = 50;
    bool res = 0;
    res = Swap_Func_Tmp<int, bool> ( a, b );
    
    string str1 = "this is str 1";
    string str2 = "this is str 2";
    
    //res = Swap_Func_Tmp(str1, str2); // it couldn't derive type by itself: candidate template ignored: couldn't infer template argument 'T2'
    res = Swap_Func_Tmp<string, bool>(str1, str2);
    
    cout << a << " and " << b << endl;
    cout << str1 << endl;
    cout << str2 << endl;
    cout << res << endl;
    
    Swap_Func_Tmp2(a, b); //it can derive simple type by itself
    cout << a << " and " << b << endl;
    
    return 0;
}

