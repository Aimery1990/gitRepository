
#include "iostream"
#include <stdio.h>

using namespace std;

class Complex{
    //friend Complex operator+(Complex & c1, Complex & c2);
    friend Complex & operator++(Complex & c);
    friend Complex   operator++(Complex & c, int); // use int to take position for distinguishing from ++c
public:
    Complex(int a, int b)
    {
        this->a = a;
        this->b = b;
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
    Complex operator-(Complex & ano)
    {
        Complex res = Complex(this->a-ano.a, this->b-ano.b);
        return res;
    }
    Complex & operator--()
    {
        --this->a;
        --this->b;
        return *this;
    }
    Complex operator--(int) // use int to take position for distinguishing from ++c
    {
        this->a--;
        this->b--;
        return *this;
    }
private:
    int a;
    int b;
    
    
};

Complex operator+(Complex & c1, Complex & c2)
{
    Complex cx(c1.get(0) + c2.get(0), c1.get(1) + c2.get(1));
    return cx;
}

Complex & operator++(Complex & c)
{
    ++c.a;
    ++c.b;
    return c;
}

Complex operator++(Complex & c, int) // use int to take position for distinguishing from ++c
{
    Complex tmp = c;
    c.a++;
    c.b++;
    return tmp;
}

int main()
{
    Complex c1 = Complex(1,2);
    cout << c1.get(0) << endl;
    cout << c1.get(1) << endl;
    Complex c2 = Complex(4,6);
    Complex c3 = c1 + c2;
    cout << c3.get(0) << endl;
    cout << c3.get(1) << endl;
    Complex c4 = c1 - c2;
    cout << c4.get(0) << endl;
    cout << c4.get(1) << endl;
    ++c4;
    cout << c4.get(0) << endl;
    cout << c4.get(1) << endl;
    --c4;
    cout << c4.get(0) << endl;
    cout << c4.get(1) << endl;
    c4++;
    cout << c4.get(0) << endl;
    cout << c4.get(1) << endl;
    c4--;
    cout << c4.get(0) << endl;
    cout << c4.get(1) << endl;
    
    return 0;
}
