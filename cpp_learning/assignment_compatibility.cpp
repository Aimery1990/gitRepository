
#include "iostream"


using namespace std;

class Root{
    
public:
    int pub;
    
    Root()
    {
        pub = 1010;
        cout << "Root()" << pub << endl;
    }
    
    Root(Root & ano)
    {
        pub = ano.pub;
        cout << "Root(Root & ano)" << pub << endl;
    }
    
    void print()
    {
        cout << "This is Root" << endl;
        cout << "pub is " << pub << endl;
    }
    
    virtual void print(int i)
    {
        
    }
    
    ~Root()
    {
        cout << "This is ~Root()" << endl;
    }
    
protected:
    int pro;
private:
    int pri;
    
};

class Trunk1:public Root{
public:
    Trunk1()
    {
        pub = 2020;
        cout << "Trunk()" << pub << endl;
    }
    

    virtual void print(int i)
    {
        
    }
    
    ~Trunk1()
    {
        cout << "This is ~Trunk1()" << endl;
    }
    int pub;
    
};

int main()
{
    Trunk1 trk1;
    
    Root * ptr = &trk1;
    
    ptr->print();
    
    Root & ref = trk1;
    ref.print();
    cout << "----------------------------" << endl;
    

    Root rt = trk1;
    cout << rt.pub << endl;
    rt.print();
    
    trk1.pub = 10;
    //trk1.print(); //if overwrite functions with same name exist, child class is unable to fetch father class's function, unless designating father's namespace
    trk1.Root::print();
    
    return 0;
}
