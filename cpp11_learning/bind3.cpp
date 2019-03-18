
#include<iostream>
#include<functional>

using namespace std;

int add(int x, int y)
{
    cout << "int"<< endl;
    return x + y;
}

double add(double x, double y)
{
    cout << "double" << endl;
    return x + y;
}

class Pck{
public:
    int add(int x, int y)
    {
        cout << "Pck::int"<< endl;
        return x + y;
    }

    double add(double x, double y)
    {
        cout << "Pck::double" << endl;
        return x + y;
    }
};

int main()
{
    
    auto ba = bind((int (*)(int, int))add, placeholders::_1, placeholders::_2);
    ba(10, 20);

    auto bb = bind((double (*)(double, double))add, placeholders::_1, placeholders::_2);
    bb(3.14, 2.2);

    Pck p;
    auto bpa = bind((int (Pck::*)(int, int))&Pck::add, p, placeholders::_1, placeholders::_2);
    bpa(10, 20);

    auto bpb = bind((double (Pck::*)(double, double))&Pck::add, p, placeholders::_1, placeholders::_2);
    bpb(3.14, 2.2);


}