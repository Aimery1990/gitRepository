
#include<iostream>
#include<string>


using namespace std;

class Date{
public:
    Date(unsigned y=2000, unsigned m=1, unsigned d=1):year(y), mon(m), day(d)
    {}
    
    unsigned year;
    unsigned mon;
    unsigned day;
    
    friend ostream & operator<<(ostream & os, const Date & date);
};

ostream & operator<<(ostream & os, const Date & date)
{
    os << date.year << "-" << date.mon << "-" << date.day;
    return os;
}



class SchoolMember{
public:
    SchoolMember(unsigned id = 0, string na = "null", string pw = "null", Date date = Date(2000, 1, 1), unsigned ag = 0, string gend = "null"):
                schoolId(id),name(na), password(pw), birthday(date), age(ag), gender(gend)
    {}
    
    SchoolMember(const SchoolMember & ano):schoolId(ano.schoolId), name(ano.name), password(ano.password), birthday(ano.birthday), age(ano.age), gender(ano.gender)
    {}
    
    void printSM()
    {
        cout << schoolId << endl;
        cout << name << endl;
        cout << birthday << endl;
        cout << age << endl;
        cout << gender << endl;
    }
    
    SchoolMember & operator=( SchoolMember & ano )
    {
        if(this == &ano){
            return *this;
        }
        
        this->schoolId = ano.schoolId;
        this->name = ano.name;
        this->password = ano.password;
        this->birthday = ano.birthday;
        this->age = ano.age;
        this->gender = ano.gender;
        return *this;
    }
    
protected:
    void printPW()
    {
        cout << password << endl;
    }
    
protected:
    unsigned    schoolId;
    string      name;
    string      password;
    Date        birthday;
    unsigned    age;
    string      gender;
};

class Student: public SchoolMember{
public:
    Student(unsigned id = 0, string na = "null", string pw = "null", Date date = Date(2000, 1, 1), unsigned ag = 0, string gend = "null", string majo = "null", string clas = "null"):SchoolMember(id, na, pw, date, ag, gend), major(majo), classNo(clas)
    {}
    //here SchoolMember(ano) is using assignment compatibility
    Student(const Student & ano): SchoolMember(ano), major(ano.major), classNo(ano.classNo)
    {}
    
//    Student(SchoolMember sm = SchoolMember(), string majo = "null", string clas = "null"):SchoolMember(sm),major(majo), classNo(clas)
//    {}
    
    //if base class has constructor whose parameter(s) can be default or none, derived class constructor needn't call base class's constructor by programmer
//    Student(/*SchoolMember sm = SchoolMember(),*/ string majo = "null", string clas = "null"):/*SchoolMember(sm),*/major(majo), classNo(clas)
//    {}
    
    void printStu()
    {
        printSM();
        cout << major << endl;
        cout << classNo << endl;
    }
    
    //if Student's operator= implemented here SchoolMemeber's operator= will be shadowed, and therefore unable be invoked
    //Shadow take places only by father and son classes' function whose names (merely names) are equal!!!!!
    Student & operator=( Student & ano )
    {
        if( this == &ano ){
            return *this;
        }
        
        SchoolMember::operator=(ano);//calling SchoolMember's operator= function father class's namespace and :: are must!!!
        
        this->major = ano.major;
        this->classNo = ano.classNo;
        return *this;
    }
    
    
protected:
    string      major;
    string      classNo;
};

int main()
{
    Student stu1;
    stu1.printStu();
    Student stu2 = stu1;
    stu2.printStu();
    
    
    Student stu3(22, "john", "1222", Date(1990,2,2), 22, "male", "computer sciense", "CS001");
    stu1 = stu3;
    stu1.printStu();
    
    return 0;
}




