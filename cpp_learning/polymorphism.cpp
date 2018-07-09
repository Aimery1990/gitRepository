
#include "iostream"
#include <stdio.h>

using namespace std;

class Origin{
public:
    Origin()
    {
        cout << "Origin()" << endl;
    }
    
    virtual ~Origin()
    {
        cout << "This is ~Origin()" << endl;
    }

};

class Root: public Origin{
    
public:
    int pub;
    
    Root()
    {
        pub = 1010;
        cout << "Root()" << endl;
    }
    
    Root(Root & ano)
    {
//        pub = ano.pub;
//        cout << "Root(Root & ano)" << pub << endl;
    }
    
    virtual void print()
    {
        cout << "This is Root" << endl;
        //cout << "pub is " << pub << endl;
    }
    

    
    virtual ~Root() //if destructor isn't virtual, void Free_Root_Family( Root * p ) is unable to delete or free Trunk's obj just by given Root type pointer univerally
                    //if destructor isn't virtual, Root type pointer's deleting obj is just implementing assignment compatibility merely
                    //if destructor is virtual, Root type pointer can call all families' destructor one by one, when destructing.
    {
        cout << "This is ~Root()" << endl;
    }
    
protected:
    int pro;
private:
    //int pri;
    
};

class Trunk1:public Root{
public:
    Trunk1()
    {
        pub = 2020;
        cout << "Trunk()" << endl;
    }
    
    
    virtual void print()
    {
        cout << "This is Trunk1" << endl;
//        cout << "pub is " << pub << endl;
    }
    
    virtual ~Trunk1()
    {
        cout << "This is ~Trunk1()" << endl;
    }
    int pub;
//    int pub1;
    
};

class Empty{
    virtual void test1(){}
    virtual void test2(){}
    virtual void test3(){}
    virtual void test4(){}
    virtual void test5(){}
    virtual void test6(){}
    virtual void test7(){}
    virtual void test8(){}
    virtual void test9(){}
    virtual void test0(){}
    // char t[1024];
    
};

void Free_Root_Family( Root * p )
{
    delete p;
}

void Free_Origin_Family( Origin * p)
{
    
    delete p;
}

int main()
{
//    cout << "sizeof int: " << sizeof(int) << endl;      // size of int is 4
//    cout << "sizeof Empty: "<< sizeof(Empty) << endl;   // if any virtual function emerges and no matter how many virtual functions it involves, the sizeof the class is at first 8;
//                                                        // if further structure is larger in the class, the alignment of the class should be 8 + X
    cout << "sizeof Root: " << sizeof(Root) << endl;
    cout << "sizeof Trunk1: " << sizeof(Trunk1) << endl;
//
//    Trunk1 * pTrk1 = new Trunk1();
//
//    Free_Root_Family(pTrk1);
    
    //Trunk1 * pTrk11 = new Trunk1();
    
    //Free_Origin_Family(pTrk11);
    //    This is ~Trunk1()
    //    This is ~Root()
    //    This is ~Origin()
    
    Root * rptr = NULL;
    Trunk1 * tptr = NULL;
    
    Trunk1 trks[3];
    
    rptr = trks;
    tptr = trks;
    
    rptr->print();
    tptr->print();
    cout << "pos 0" << endl;
    
    rptr++;
    cout << "pos 1" << endl;
    
    tptr++;
    cout << "pos 2" << endl;
    
    rptr->print(); //Segmentation fault: 11 // due to the size or length of 2 class is different
    cout << "pos 3" << endl;
    
    tptr->print();
    cout << "pos 4" << endl;
    
    
    return 0;
}












