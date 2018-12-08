
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Complex{
public:
    Complex( double re = 0, double img = 0):real(re), image(img){}
    
    
    friend class Multiplier;
    friend ostream & operator<<(ostream & os, const Complex & cplx );
    friend istream & operator>>(istream & is, Complex & cplx);
private:
    double real;
    double image;
};

ostream & operator<<(ostream & os, const Complex & cplx )
{
    os << "r = " << cplx.real << " " << "i = " << cplx.image << " ";
    return os;
}

istream & operator>>(istream & is, Complex & cplx)
{
    is >> cplx.real >> cplx.image;
    return is;
}


class Multiplier{
public:
    double operator() (double i, double j)
    {
        return i*j;
    }
    //(a+bi)(c+di)=(ac－bd)+(bc+ad)i
    Complex operator() (const Complex & c1, const Complex & c2)
    {
        return Complex(c1.real * c2.real - c1.image * c2.image, c1.image * c2.real + c1.real * c2.image);
    }
    
    
    
};

class CMP{
public:
    bool operator()(int i, int j)
    {
        return i<j;
    }
};


int main()
{
    Multiplier mult;
    Complex c1(3, 4);
    Complex c2(5, 6);
    
    
    cout << mult(3, 5) << endl;
    cout << mult(c1, c2) << endl;
    
    int array[8] = {2, 4, 2, 1, 5, 7, 6, 0};
    vector<int> vint(array, array+8);
    
    sort(vint.begin(), vint.end(), CMP());
    
    int i = 0;
    for(;i < vint.size(); i++)
        cout << vint[i] << endl;


    return 0;
}
