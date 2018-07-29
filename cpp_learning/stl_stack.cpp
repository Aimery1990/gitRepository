
#include"iostream"
#include"string"
#include"vector"
#include"stack"



using namespace std;

class Teacher{
private:
    string name;
    int age;
public:
    Teacher()
    {
        this->name = "?";
        this->age = 0;
        cout << "Teacher()" << endl;
    }
    Teacher( string na, int ag):name(na), age(ag)
    {
        cout << "Teacher( string name, int age)" << endl;
    }
    Teacher(const Teacher & ano):name(ano.name),age(ano.age)
    {
        cout << "Teacher(const Teacher & ano)" << endl;
    }
    
    string get_name()
    {
        return this->name;
    }
    
    void set_name(string na)
    {
        this->name = na;
    }
    
    friend ostream & operator<<(ostream & out, const Teacher & tea)
    {
        return out << tea.name << " " << tea.age << endl;
    }
};

void print_and_empty_stack(stack<int> & s)
{
    while(!s.empty())
    {
        int tmp = 0;
        tmp = s.top();
        cout << tmp << endl;
        s.pop();
    }
}

void print_and_empty_stack(stack<Teacher *> & s)
{
    while(!s.empty())
    {
        Teacher * tmp = 0;
        tmp = s.top();
        cout << tmp << " "<< *tmp;
        s.pop();
    }
}


int main()
{
  
    stack<int> s;
    
    int i = 0;
    for(;i<5 ;i++)
    {
        s.push(i);
    }
    
    print_and_empty_stack(s);
    
    
    vector<Teacher> teaV(5);
    teaV[1].set_name("Jennifer");
    
    stack<Teacher *> stp;
    
    for(i = 0;i<5 ;i++)
    {
        stp.push(&teaV[i]);
    }
    
    print_and_empty_stack(stp);
    
    
    return 0;
}









