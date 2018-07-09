
#include "iostream"


using namespace std;

class Root{
    
public:
    int pub;
protected:
    int pro;
private:
    int pri;
    
};

class Trunk1:public Root{
public:
    void testPub()
    {
        cout << "Trunk1 Root pub " << pub << endl;
    }
    void testPro()
    {
        cout << "Trunk1 Root pro " << pro << endl;
    }
    void testPri()
    {
        cout << "Trunk1 Root pri " << "Unable" << endl;
    }
    
};

class Trunk2:protected Root{
public:
    void testPub()
    {
        cout << "Trunk2 Root pub " << pub << endl;
    }
    void testPro()
    {
        cout << "Trunk2 Root pro " << pro << endl;
    }
    void testPri()
    {
        cout << "Trunk2 Root pri " << "Unable" << endl;
    }
    
};

class Trunk3:private Root{
public:
    void testPub()
    {
        cout << "Trunk3 Root pub " << pub << endl;
    }
    void testPro()
    {
        cout << "Trunk3 Root pro " << pro << endl;
    }
    void testPri()
    {
        cout << "Trunk3 Root pri " << "Unable" << endl;
    }
    
};



int main()
{
    Trunk1 test1;
    test1.testPub();
    test1.testPro();
    test1.testPri();
    cout << "--------------------------------------------------------" << endl;
    cout << "main Trunk1 Root pub " << test1.pub << endl;
    cout << "main Trunk1 Root pro " << "Unable protected" << endl;
    cout << "main Trunk1 Root pri " << "Unable private" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl << endl;
    
    Trunk2 test2;
    test2.testPub();
    test2.testPro();
    test2.testPri();
    cout << "--------------------------------------------------------" << endl;
    cout << "main Trunk2 Root pub " << "Unable protected" << endl;
    cout << "main Trunk2 Root pro " << "Unable protected" << endl;
    cout << "main Trunk2 Root pri " << "Unable private" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl << endl;
    
    Trunk3 test3;
    test3.testPub();
    test3.testPro();
    test3.testPri();
    cout << "--------------------------------------------------------" << endl;
    cout << "main Trunk3 Root pub " << "Unable private" << endl;
    cout << "main Trunk3 Root pro " << "Unable private" << endl;
    cout << "main Trunk3 Root pri " << "Unable private" << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << endl << endl;
    
    return 0;
}












