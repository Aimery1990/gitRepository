#include"iostream"
#include"string"
#include"vector"
#include"algorithm"
#include"cmath"


using namespace std;

#if 1
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
#endif

void printInt(int & in)
{
    cout << in << " ";
}

bool compareInt(int & in1, int & in2)
{
    return in1 >= in2;
}


int main()
{
    vector<int> v(10);
    int i = 0;
    
    for(i = 0; i < 10; i++)
    {
        v[i] = rand() % 10;
    }
    
    for(i = 0; i < 10; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    
    for_each(v.begin(),  v.end(), printInt);
    cout << endl;
    
    sort(v.begin(), v.end(), compareInt);
    
    for_each(v.begin(),  v.end(), printInt);
    cout << endl;
    
    
    return 0;
}
