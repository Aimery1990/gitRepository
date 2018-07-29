
#include "iostream"
#include "string"

using namespace std;

template <typename T>
class Complex {
private:
    T real, image;
    
public:
    Complex(T real = 0, T image = 0);
    Complex(T a);  //never called in this program
    void print();
    
//    Complex operator+(Complex c2)
//    {
//        Complex tmp(this->real+c2.real, this->image+c2.image);
//        return tmp;
//    }
//
//    Complex operator-(Complex c2)
//    {
//        Complex tmp(this->real-c2.real, this->image-c2.image);
//        return tmp;
//    }
    //friend Complex operator+(Complex c1, Complex c2);  // !!!!error: linker command failed with exit code 1 (use -v to see invocation)
    //friend Complex operator-(Complex c1, Complex c2);  // !!!!error: linker command failed with exit code 1 (use -v to see invocation)
    //Due to Compiler compiles class template twice, friend functions need to implement inner class
    

    friend Complex operator+(Complex c1, Complex c2)
    {
        Complex<T> tmp(c1.real+c2.real, c1.image+c2.image);
        return tmp;
    }
    

    friend Complex operator-(Complex c1, Complex c2)
    {
        Complex<T> tmp(c1.real-c2.real, c1.image-c2.image);
        return tmp;
    }
    
    static int count;
    
    
};

template <typename T>
int Complex<T>::count = {0};

template <typename T>
Complex<T>::Complex(T real /*= 0*/, T image /*= 0*/)  //error on macOS g++, error: redefinition of default argument
{
    this->real = real;
    this->image = image;
    count ++;
}

template <typename T>
Complex<T>::Complex(T a)
{
    this->real = a.real;
    this->image = a.image;
    count ++;
}

template <typename T>
void Complex<T>::print()
{
    cout << real << "+" << image << endl;
}

//template <typename T>
//Complex<T> operator+(Complex<T> c1, Complex<T> c2)
//{
//    Complex<T> tmp(c1.real+c2.real, c1.image+c2.image);
//    return tmp;
//}
//
//template <typename T>
//Complex<T> operator-(Complex<T> c1, Complex<T> c2)
//{
//    Complex<T> tmp(c1.real-c2.real, c1.image-c2.image);
//    return tmp;
//}


int main()
{
    Complex<float> c1(1.2, 3.6);
    Complex<float> c2(4.8, 9.9);
    c1.print();
    c2.print();
    
    Complex<float> c3;
    c3 = c1 + c2;
    c3.print();
    
    Complex<float> c4;
    c4 = c1 - c2;
    c4.print();
    
    Complex<int> c5(4, 8);
    cout << c4.count << endl; //for different typename T, static is irrelavent to each other.
    cout << c5.count << endl; //for different typename T, static is irrelavent to each other.
    
    return 0;
}
