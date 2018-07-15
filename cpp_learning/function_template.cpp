
#include "iostream"
#include <string.h>

#include "string"

using namespace std;

/*
 C++ compiles template first, then it compiles specific function by given type, when calling it.
 So it compiles at least twice.
 */

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

template <typename T1, typename T2>
void Swap_Func_Tmp2(T1 & a, T2 & b)
{
    T1 tmp;
    tmp = a;
    a = b;
    b = tmp;
}

void Swap_Func_Tmp2(int & a, char & b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout <<"This is a normal function not a template" << endl;
}

template <typename T>
void Sort_Array(T * array, int len)
{
    int i = 0;
    int j = 0;
    for(; i<len; i++)
    {
        for(j=i+i; j<len; j++)
        {
            if(array[j]<array[i]){
                Swap_Func_Tmp2<T>(array[i], array[j]);
            }
        }
    }
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
    
    string strs[] = {str1, str2};
    
    //Sort_Array<string>(str1, str1.length()); //it couldn't accept string type directly, candidate function not viable: no known conversion from 'string' ...
    
    Sort_Array<char>((char *)(str1.c_str()), str1.length());
    cout << str1.length() << endl;
    cout << str1 << endl;
    
    cout << strs[0] << " and " << strs[1] << endl;
    Sort_Array<string>(strs, sizeof(strs)/sizeof(strs[0]));
    cout << strs[0] << " and " << strs[1] << endl;
    
    char array[] = "aojfosiergisergj";
    Sort_Array<char>(array, strlen(array));
    cout << array << endl;
    
    int x = 100;
    char y = 'a';
    //Swap_Func_Tmp2(x, y); //error: no matching function for call to 'Swap_Func_Tmp2'
    //Swap_Func_Tmp2<int>(x, y); //error: no matching function for call to 'Swap_Func_Tmp2'

    /*Without function overload, function template won't convert data type implicitly and defaultly !!!*/
    
    
    Swap_Func_Tmp2<int>(x, y);  //function overload takes place
    cout << x << " " << y << endl;
    
    Swap_Func_Tmp2(x, y); //normal function is perior to call, if it can
    cout << x << " " << y << endl;
    
    Swap_Func_Tmp2<>(x, y); //by <>, function template is called explictly
    cout << x << " " << y << endl;
    
    return 0;
}

