
#include <iostream>
#include <string>

using namespace std;

class Stu{
public:
    Stu(int id = 0, string na = "x", int ag = 0, bool shown = false)
            :   sid(id), name(na), age(ag), shown_flag(shown)
    //In c++99 const member variable must be initialized in initial parameters list!!!!!
    {}
    
    //Here by using const, 2 functions are overloaded.
    //const version is called when: const Stu stu1; stu1.showStu();
    void showStu() const;
    void showStu();
    void updateStuShowFlg();
    void noUpdatingStuShowFlg() const;
    
private:
    const int sid /* = 0*/; /*available in c++11*/
    string name;
    int age;
    bool shown_flag;
    static const int label = 0; /*must initialize in this way!!!!!!*/
};
void Stu::updateStuShowFlg()
{
    shown_flag = true;
    cout << shown_flag << endl;
}

void Stu::noUpdatingStuShowFlg() const
{
    cout << shown_flag << endl;
}

void Stu::showStu() const /* const here is must!! */
{
    cout << "showStu() const" << endl;
    cout << name<< endl;
    cout << sid << endl;
    cout << age << endl;
    
    //const function must requre calling const function also
    //updateStuShowFlg();//error: member function 'updateStuShowFlg' not viable: 'this' argument has type 'const Stu', but function is not marked const
    
    noUpdatingStuShowFlg();
}

void Stu::showStu()
{
    cout << "showStu()" << endl;
    cout << name << endl;
    cout << sid << endl;
    cout << age << endl;
    shown_flag = true;
    
    updateStuShowFlg();
}

int main()
{
    const Stu stu1;
    stu1.showStu();
    
    Stu stu2;
    stu2.showStu();
    
    return 0;
}



