#include"iostream"
#include"string"
#include"vector"
#include"queue"


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

template <typename T>
void print_and_empty_queue(queue<T> & q) //don't forget & !!!!
{
    while(!q.empty())
    {
        T tmp = q.front();
        cout << tmp << endl;
        q.pop();
    }
}



int main()
{
    queue<int> q;
    
    int i = 0;
    for(;i<5; i++)
    {
        q.push(i);
    }
    
    print_and_empty_queue(q);
  
    

    vector<Teacher> teaV(5);
    teaV[1].set_name("Jennifer");
    queue<Teacher *> qtp;
    
    
    for(i=0; i<5; i++)
    {
        qtp.push(&teaV[i]);
    }
    
    print_and_empty_queue( qtp);
    
    
    
    return 0;
}







