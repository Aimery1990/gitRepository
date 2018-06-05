#include "iostream"
#include <stdio.h>

using namespace std;

struct Teacher{
    char name[32];
    int age;
    int gender;
    
    Teacher( const char * na, int a, int gen)
    {
        memcpy(name, na, sizeof(name));
        age = a;
        gender = gen;
        cout << "This is constructor with 3 parameters" << endl;
    }
    
    Teacher( const char * na, int a)
    {
        memcpy(name, na, sizeof(name));
        age = a;
        gender = 0;
        cout << "This is constructor with 2 parameters" << endl;
    }
    
    Teacher( const Teacher & ano)
    {
        memcpy(name, ano.name, sizeof(name));
        age = ano.age;
        cout << "This is copy constructor" << endl;
    }
};

Teacher transferATeacher( Teacher tea)
{
    cout << __FUNCTION__ << endl;
    return tea;
}

Teacher & transferATeacherRef( Teacher & tea )
{
    cout << __FUNCTION__ << endl;
    return tea;
}

Teacher & transferATeacherRef2( Teacher & tea)
{
    cout << __FUNCTION__ << endl;
    return tea;
}

Teacher transferATeacherRef3( Teacher & tea)
{
    cout << __FUNCTION__ << endl;
    return tea;
}

class Student{
    char name[30];
    int  age;
public:
//    Student()
//    {
//        cout << "this is my constructor" << endl;
//    }
//    Student( char * na, int a)// if you only write constructor with parameters, system won't provide default the non-parameter constructor
//    {
//        cout << "this is my constructor with parameters" << endl;
//    }
//    Student( Student & ano)// if you only write copy constructor, system won't provide default the non-parameter constructor
//    {
//        cout << "this is my copy constructor" << endl;
//    }
    // total: if you define any of constructor, system won't provide non-parameter constructor
};

void checkStuConstructor()
{
    //Student s1("good", 30);
    Student s2;
    Student s3 = s2;
    
}


int main()
{
    //Two ways to call constructor with parameter:
    Teacher t1("tom", 33, 0);
    //Teacher t2 = ("Tom", 34); //error: no viable conversion from 'int' to 'Teacher'
    Teacher t3 = Teacher("tommy", 35);
    
    //4 ways to call copy constructor:
    Teacher t4 = t3;  //way1
    Teacher t5(t3);   //way2
    
    t5 = transferATeacher(t5);  // way3 and way4: when giving parameter to function, copy constructor were called; when return an object, copy constructor were called
    cout << "Before t6 constructed\n"<< endl;
    Teacher t6 = transferATeacherRef(t5); //Copy function were called due to t6's construction
    
    
    transferATeacherRef(t5);    //no constructor were called
    cout << endl;
    t6 = transferATeacherRef(t6); //no constructor were called
    cout << "Before Teacher & tr\n"<< endl;
    Teacher & tr = transferATeacherRef2(t6);  //no constructor were called
    //Teacher & tr2 =transferATeacherRef3(t6);  //error: non-const lvalue reference to type 'Teacher' cannot bind to a temporary of type 'Teacher'
    
    checkStuConstructor();
    
    return 0;
}
