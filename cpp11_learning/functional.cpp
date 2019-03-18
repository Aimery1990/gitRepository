
#include <iostream>
#include <functional>
#include <map>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

typedef int(*OPT_T)(int, int);

class Divide
{
public:
    int operator()(int x, int y)
    {
        return x/y;
    }
};

typedef function<void(int &, int &)> SWAP_T;

int main()
{
    auto op = function<int (int, int)>(add);
    cout << op(11, 5) << endl;
    op = function<int (int, int)>(sub);
    cout << op(11, 5) << endl;

    OPT_T optr = sub;
    op = function<int (int, int)> (optr);
    cout << op(11, 5) << endl;


    op = function<int(int, int)>([](int x, int y){return x * y;});
    cout << op(11, 5) << endl;

    auto mul = [](int x, int y){ return x * y; };
    cout << mul(11, 66) << endl;
    op = function<int (int, int)>(mul);
    cout << op(11, 6) << endl;

    Divide divider;
    op = function<int (int, int)>(divider);
    cout << op(5,6) << endl;

    map<string, function<int(int, int)>> op_map = {
        {"+", add},
        {"-", optr},
        {"*", mul},
        {"/", divider}
    };

    cout << op_map["+"](1,2) << endl;
    cout << op_map["-"](2,8) << endl;
    cout << op_map["*"](2,8) << endl;
    cout << op_map["/"](8, 2) << endl;

    SWAP_T swaper = []( int  a, int  b){ return a^=b^=a^=b;};
    int a = 10;
    int b = 20;
    swaper(a, b);
    cout << a << " " << b << endl;
    SWAP_T swaper2 = []( int  & a, int  & b){ return a^=b^=a^=b;};
    swaper2(a, b);
    cout << a << " " << b << endl;
    auto swaper3 = SWAP_T([]( int  & a, int  & b){ return a^=b^=a^=b;});
    swaper3(a, b);
    cout << a << " " << b << endl;

}










#if 0
class Oper
{
public:
    virtual int op(int x, int y) = 0;
};

class Add: public Oper
{
public:
    virtual int op(int x, int y) override
    {
        return x + y;
    }
};

class Sub: public Oper
{
public:
    virtual int op(int x, int y) override
    {
        return x - y;
    }
};

int main()
{
    Oper * op;
    Add adder;
    Sub subtracter;

    op = & adder;
    cout << op->op(5, 6) << endl;
    op = & subtracter;
    cout << op->op(7, 9) << endl;

    return 0;
}

#endif