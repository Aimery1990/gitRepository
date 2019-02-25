
#include "iostream"

using namespace std;

void lock()
{
    cout << "This is lock()" << endl;
}

void unlock()
{
    cout << "This is unlock()" << endl;
}


class Singletion
{
public:
    static Singletion * getInstance()
    {
        if(_ins == nullptr){
            lock();

            if(_ins == nullptr)
                _ins = new Singletion;
            
            unlock();
        }
        return _ins;
    }

private:
    Singletion(){}
    //~Singletion(){}
    Singletion(const Singletion &){}
    Singletion & operator==(const Singletion & ano){}
    static Singletion * _ins;
};

Singletion * Singletion::_ins = nullptr;






int main()
{
    Singletion * ps = Singletion::getInstance();
    delete ps;   
    return 0;
}

//http://www.cnblogs.com/cxjchen/p/3148582.html