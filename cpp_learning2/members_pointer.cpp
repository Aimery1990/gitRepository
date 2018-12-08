#include<iostream>
#include<string>

using namespace std;

class Stu{
public:
    Stu( string na = "", int ag = 0, int sha = 0):name(na), age(ag), share(sha)
    {}
    
    void printStu()
    {
        cout << name << " " << age << endl;
    }
    
    int share;
    
private:
    string name;
    int age;
};

void printSth()
{
    cout << "hello world" << endl;
}

int main()
{
    Stu s1("xixi", 3, 0);
    Stu * stup = new Stu("zhaozhao", 5, 1);
    
    Stu * sp = &s1;
    sp->printStu();
    
    //this pointer is for a certain OBJECT's member, here is s1 and not big deal.
    int * objp = &(s1.share);
    cout << *objp << endl;
    
//    void (*fp)() = &printSth;
//    fp();
    
    
    //void (*objfp)() = &(s1.printStu);  //error: cannot create a non-constant pointer to member function
    
    //CLASS's pointers to class's members
    
    int x = 0;
    int       * xp      = &       x;     //by contrast
    int Stu:: * class_p = & Stu:: share; //share's offset in class is given by Stu::
    
    //when using the class pointer, a CERTAIN OBJECT or its pointer must be given!!!!!
    cout << s1.*class_p << endl;  //attention: !!!!! .* !!!!!
    
    void (      * fp)      ()   = &      printSth;  //by contrast
    void (Stu:: * class_fp)()   = & Stu::printStu;  //printStu's offset in class is given by Stu::
    
    //when using the class pointer, a CERTAIN OBJECT must be given!!!!!
    (s1.*class_fp)();  //attention: !!!!! .* !!!!!
    

    cout << stup->*class_p << endl;
    (stup->*class_fp)();
    

    delete stup;
    
    return 0;
}
