
#include <iostream>
#include <functional>

using namespace std;

double divide(double x, double y)
{
    return x/y;
}

int main()
{
    auto div = bind(divide, 10, 3);
    cout << div() << endl;  //3.3333

    auto div2 = bind(divide, std::placeholders::_1, 10);
    cout << div2(30) << endl; //3

    auto div3 = bind(divide, std::placeholders::_1, std::placeholders::_2);
    cout << div3(10, 5) << endl; //2

    auto div4 = std::bind(divide, placeholders::_2, placeholders::_1);
    cout << div4(10, 5) << endl; //0.5


    return 0;
}