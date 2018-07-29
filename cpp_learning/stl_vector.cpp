
#include"iostream"
#include"string"
#include"vector"

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
    
    friend ostream & operator<<(ostream & out, const Teacher & tea)
    {
        return out << tea.name << " " << tea.age << endl;
    }
};


void printV(vector<int> & v)
{
    int sz = v.size();
    int i = 0;
    for(; i<sz; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printV(vector<Teacher> & v)
{
    int sz = v.size();
    int i = 0;
    for(; i<sz; i++)
    {
        cout << v[i] ;
    }
    cout << endl;
}

void printV(vector<Teacher *> & v)
{
    int sz = v.size();
    int i = 0;
    for(; i<sz; i++)
    {
    
        cout << v[i] << " ";
        if(v[i]){
            cout << v[i]->get_name();
        }
        
        cout << endl;
    }

}



int main()
{
    vector<int> v1(5);
    
    int i = 0;
    for(;i<5 ;i++)
    {
        v1[i] = i;
    }
    
    for(i = 0; i<5; i++)
    {
        cout << v1[i];
    }
    cout << endl;
    
    vector<int> v2 = v1;
    
    printV(v2);
    
    //vector<int> v3 = {0};  //error: non-aggregate type 'vector<int>' cannot be initialized with an initializer list
    vector<int> v3(20);
    v3.push_back(100);
    v3.push_back(101);
    printV(v3);
    
    Teacher t1;
    Teacher t2("tom", 40);
    vector<Teacher> vt1(5);
    printV(vt1);
    
    vt1[1] = t1;
    vt1[2] = t2;
    vt1.push_back(t2);
    
    printV(vt1);
    
    vector<Teacher *> vtp1(5);
    vtp1[1] = &vt1[1];
    vtp1[2] = &vt1[2];
    
    printV(vtp1);
    
    
    
    return 0;
}
