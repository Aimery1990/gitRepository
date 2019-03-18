
#include<iostream>
#include<functional>

using namespace std;

struct Pair
{
    int data;
    double source;
};

class MyPair
{
public:
    void func(int x, int y)
    {
        cout << "class MyPair" << endl;
        cout << "x is " << x << " y is " << y << endl;
    }
};





int main()
{
    Pair p = {10,2000};
    cout << p.data << endl;

    auto obj = bind(&Pair::data, p);
    cout << obj() << endl;

    MyPair mp;
    auto objfunc = bind(&MyPair::func, mp, std::placeholders::_1, std::placeholders::_2); 
                    // &(MyPair::func) : error: call to non-static member function without an object argument
    objfunc(10, 20);

    return 0;
}


#if 0
https://stackoverflow.com/questions/6610046/stdfunction-and-stdbind-what-are-they-when-they-should-be-used

class MyClass {
private:
    //just shorthand to avoid long typing
    typedef std::function<void (float result)> TCallback;

    //this function takes long time
    void longRunningFunction(TCallback callback)
    {
        //do some long running task
        //...
        //callback to return result
        callback(result);
    }

    //this function gets called by longRunningFunction after its done
    void afterCompleteCallback(float result)
    {
        std::cout << result;
    }

public:
    int longRunningFunctionAsync()
    {
        //create callback - this equivalent of safe function pointer
        auto callback = std::bind(&MyClass::afterCompleteCallback, 
            this, std::placeholders::_1);

        //normally you want to start below function on seprate thread, 
        //but for illustration we will just do simple call
        longRunningFunction(callback);
    }
};

#endif