#include "iostream"
#include <stdio.h>

using namespace std;

class Complex{
    friend ostream & operator<< ( ostream & out, Complex & c);
    friend istream & operator>> ( istream & in, Complex & c);
public:
    Complex()
    {
        this->a = 0;
        this->b = 0;
        this->space = new char[100];
    }
    
    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
        this->space = NULL;
    }
    int get(int i)
    {
        if(i==0){
            return a;
        }
        else{
            return b;
        }
    }

//    Complex operator-(Complex & ano)
//    {
//        Complex res = Complex(this->a-ano.a, this->b-ano.b);
//        return res;
//    }
//    Complex & operator--()
//    {
//        --this->a;
//        --this->b;
//        return *this;
//    }
//    Complex operator--(int) // use int to take position for distinguishing from ++c
//    {
//        this->a--;
//        this->b--;
//        return *this;
//    }
    char & operator[](int i)
    {
        static char error = -1;
        if(!this->space){
            cout << "ERROR! this Complex doesn't involve extral space" << endl;
            error = -1;
            return error;
        }
        
        if (i >=0 && i<100){
            return this->space[i];
        }
        else{
            cout << "ERROR! given index is out of range" << endl;
            error = -2;
            return error;
        }
        
    }
    
    
    ~Complex()
    {
        this->a = 0;
        this->b = 0;
        if(this->space){
            delete []this->space;
            this->space = NULL;
        }
    }
 
    
private:
    int a;
    int b;
    char * space;
    
    
};

ostream & operator<< ( ostream & out, Complex & c)
{
    return out << c.a << " " << c.b << endl;
}

istream & operator>> ( istream & in, Complex & c)
{
    cout << "Please enter you real and image parts: ";
    return in >> c.a >> c.b;
}

int main()
{
    Complex c1(1, 2), c2(3, 4), c3(0, 0), c4(0, 0);
    int i1, i2, i3;
    //cin >> i1 >> c3 >> c4 >> i2 >> i3;
    
    cout << c1 << c2 << endl;
    
    Complex cs[5];
    cs[0][3] = 'A';
    cout << cs[0][3] << endl;
    
    cout << c1[4] << endl;
    printf("%d\n", c1[4]);
    cs[0][-1];
    
    return 0;
}














