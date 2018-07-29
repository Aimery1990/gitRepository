#include"iostream"
#include"string"
#include"vector"
//#include"queue"
#include"list"



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




int main()
{
    list<int> l;
    
    cout << l.size() << endl;
    int i = 0;
    for(i = 0; i<5; i++)
    {
        l.push_back(i);
    }
    
    cout << l.size() << endl;
    
    list<int>::iterator current = l.begin();
    
    while( current!=l.end() )
    {
        cout << *current << endl;
        current++;
    }
    
    current = l.begin();
    current++;
    current++;
    current++;
    l.insert(current, 100);
    
    list<int>::iterator p = l.begin();
    for(;p!=l.end();p++) //end() points out of the list
    {
        cout << *p << endl;
    }
    
    vector<Teacher> vt(5);
    list<Teacher> tealist;
    
    i = 0;
    for(;i<5; i++)
    {
        tealist.push_back(vt[i]);
    }
    
    list<Teacher>::iterator cur = tealist.begin();
    
    for(;cur!=tealist.end();cur++)
    {
        cout << *cur ;
        cout << cur->get_name() << endl;
    }
    cout <<"*********************************" << endl;
    list<Teacher *> tpl;
    
    i = 0;
    for(;i<5; i++)
    {
        //tpl.push_back(&tealist[i]);  //error: type 'list<Teacher>' does not provide a subscript operator
        tpl.push_back(&vt[i]);
    }
    
    list<Teacher *>::iterator teaptr = tpl.begin();
    
    for(; teaptr!=tpl.end(); teaptr++)
    {
        cout << **teaptr;
        cout << (*teaptr)->get_name() << endl;
    }
    
    
    
    return 0;
}














