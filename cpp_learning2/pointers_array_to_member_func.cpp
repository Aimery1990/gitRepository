
#include<iostream>
#include<string>
#include<string.h>

using namespace std;

class Guider{
public:
    Guider()
    {
        fp[0] = &Guider::f1;
        fp[1] = &Guider::f2;
        fp[2] = &Guider::f3;
        fp[3] = &Guider::f4;
        
        strcpy(duty1, "d1");
        strcpy(duty2, "d2");
        strcpy(duty3, "d3");
        strcpy(duty4, "d4");
        dtys[0] = duty1;
        dtys[1] = duty2;
        dtys[2] = duty3;
        dtys[3] = duty4;
    }
    
    void select(int idx)
    {
        (this->*fp[idx])();  //this-> is very MUST!!!
        cout << dtys[idx] << endl;
    }
    
    
private:
    void f1(){cout << "f1()" << endl;}
    void f2(){cout << "f2()" << endl;}
    void f3(){cout << "f3()" << endl;}
    void f4(){cout << "f4()" << endl;}
    
    enum{FP_CNT=4};
    
    void (Guider::*fp[FP_CNT])();
    
    char duty1[4];
    char duty2[4];
    char duty3[4];
    char duty4[4];
    
    enum{DTY_CNT=4};
    
    char *dtys[DTY_CNT];
    
    
};


int main()
{
    Guider g1;
    g1.select(2);
    
    return 0;
}
