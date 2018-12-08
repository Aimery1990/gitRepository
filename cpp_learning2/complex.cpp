

#include <iostream>
#include <string>

using namespace std;

class Complex{
public:
    Complex(double re = 0, double img = 0):real(re), image(img)
    {
    }
    
    Complex( const Complex & ano):real(ano.real), image(ano.image)
    {
    }
    
    ~Complex()
    {
    }
    
    Complex & operator=( const Complex & ano )
    {
        this->real = ano.real;
        this->image = ano.image;
        return *this;
    }
    
    Complex & operator+=(const Complex & ano )
    {
        this->real += ano.real;
        this->image += ano.image;
        return *this;
    }
    
    
    Complex & operator-=(const Complex & ano )
    {
        this->real -= ano.real;
        this->image -= ano.image;
        return *this;
    }
    
    const Complex operator+(const Complex & ano) const
    {
        return Complex( this->real+ano.real, this->image+ano.image );
    }
    
    const Complex operator-(const Complex & ano) const
    {
        return Complex( this->real-ano.real, this->image-ano.image );
    }
    
    //negative operator not minus!!!
    const Complex operator-() const //for -(-c2)
    {
        return Complex(-this->real, -this->image);
    }
    //positive operator not plus!!!
    const Complex operator+() const //for +(+c2)
    {
        return Complex(-this->real, -this->image);
    }
    
    Complex & operator++() //++c1
    {
        ++this->real;
        ++this->image;
        return *this;
    }
    
    const Complex operator++(int) //c1++
    {
        return Complex(this->real++, this->image++);
    }
    
    Complex & operator--() //--c1
    {
        --this->real;
        --this->image;
        return *this;
    }
    
    const Complex operator--(int) //c1--
    {
        return Complex(this->real--, this->image--);
    }
    
    void show()
    {
        cout << "r = " << real << " " << "i = " << image << endl;
    }
    
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

int main()
{
    int i = 0;
    int j(4);
    int k = i;
    i = 0;
    j = 4;
    k = 5;
    
    k = i = j;
    cout << i << j << k << endl;
    
    i = 0;
    j = 4;
    k = 5;
    
    (k=i) =j ;
    cout << i << j << k << endl;
    
    i = 0;
    j = 4;
    k = 5;
    
    k = -k;
    cout << i << j << k << endl;

    j = -k;
    cout << i << j << k << endl;
    
    //-k = i;  //not supported
    (i = -k) = j;
    cout << i << j << k << endl;
    cout << -(-k) << endl;
    
    //(i+j)+k;
    (--i)  = k;
    (k = ++i) = j;
    
    cout << "----------------------INT TEST ABOVE---------------------" << endl;
    
    Complex c1;
    Complex c2(3, 5);
    Complex c3(c2);
    

    
    c1.show();
    c2.show();
    c3.show();
    cout << endl;
    
    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);
    
    c1 = c2;
    c1.show();
    c2.show();
    c3.show();
    cout << endl;

    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);

    c3 = c1 = c2;
    c1.show();
    c2.show();
    c3.show();
    cout << endl;
    
    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);
    
    (c3 = c1) = c2;
    c1.show();
    c2.show();
    c3.show();
    cout << endl;
    
    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);
    
    c1 = -c2;
    c1.show();
    c2.show();
    c3.show();
    cout << endl;
    
    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);
    
    (c1 = -c2) = c3;
    c1.show();
    c2.show();
    c3.show();
    cout << endl;
    
    c1 = -(-c2);
    c1.show();
    c2.show();
    c3.show();
    cout << endl;
    
    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);
    
    c1+=c2 += c3;
    c1.show();
    c2.show();
    c3.show();
    cout << endl;
    
    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);
    
    (c1-=c2) -= c3;
    c1.show();
    c2.show();
    c3.show();
    cout << endl;
    
    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);
    
    Complex c4 = (c1 - c2) - c3;
    c1.show();
    c2.show();
    c3.show();
    c4.show();
    cout << endl;
    
    ++c1;
    c1.show();

    ++c1 = c2;
    c1.show();
    cout << endl;
    
    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);
    
    (c3 = --c1) += c2;
    c1.show();
    c2.show();
    c3.show();
    c4.show();
    cout << endl;
    
    c1 = Complex(0, 0);
    c2 = Complex(3, 5);
    c3 = Complex(4, 6);
    
    c3 = c1--;
    c1.show();
    c2.show();
    c3.show();
    c4.show();
    cout << endl;
    
    cout << c1 << endl;
    cout << c2 << c3 << endl;
    
    cin >> c1;
    cout << c1 << endl;
    
    
    return 0;
}
