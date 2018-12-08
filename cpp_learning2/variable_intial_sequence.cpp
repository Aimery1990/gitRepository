
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class Stu{
public:
    //OK
//    Stu(string na):name(na),len(strlen(na.c_str()))
//    {
//    }
    
    //if sequence of 2 variables is:
    //    string name;
    //    int len;
    //OK.
    
    //if sequence of 2 variables is:
    //    int len;
    //    string name;
    //then:
    //warning: field 'name' is uninitialized when
    //    used here [-Wuninitialized]
    //    Stu(string na):len(strlen(name.c_str())), name(na)
    
    Stu(string na):len(strlen(name.c_str())), name(na)
    {
    }
    
    void dis()
    {
        cout << len << endl;
    }
private:
    string name;
    int len;
    
    //conclusion: the sequence of initial parameter list doesn't matter,
    //            but the sequence of variables declaration does really matter.
};

int main()
{
    Stu s("something");
    s.dis();
    return 0;
}
