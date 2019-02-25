

#include "iostream"

using namespace std;

class A
{
public:
    A() = default;
    ~A() = default;
    A(const A & ano) = default;
    A & operator=(const A & ano) = default;


};






int main()
{
    A a;
    A b(); //declartion
    return 0;
}