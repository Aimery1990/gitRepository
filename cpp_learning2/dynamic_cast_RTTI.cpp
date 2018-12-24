#include <iostream>
#include <typeinfo>

using namespace std;


class Reger{
public:
    Reger(){ cout << __FUNCTION__ << endl; }
    virtual int starter() = 0;
    virtual int ender() = 0;
    virtual int writer() = 0;
    virtual int reader() = 0;
    virtual ~Reger(){ cout << __FUNCTION__ << endl; }
    
protected:
    static int value;
};

int Reger::value = 0;


class GPIO: public Reger{
public:
    GPIO();
    virtual int starter();
    virtual int ender();
    virtual int writer();
    virtual int reader();
    virtual ~GPIO();
};

GPIO::GPIO():Reger()
{ 
    cout << __FUNCTION__ << endl; 
}

int GPIO::starter()
{
    cout << "int GPIO::starter()" << endl;
    return 0;
}

int GPIO::ender()
{
    cout << "int GPIO::ender()" << endl;
    return 0;
}

int GPIO::writer()
{
    cout << "int GPIO::writer()" << endl;
    return 0;
}

int GPIO::reader()
{
    cout << "int GPIO::reader()" << endl;
    return 0;
}

GPIO::~GPIO()
{
    cout << __FUNCTION__ << endl;
}


class IIC: public GPIO{
public:
    IIC();
    virtual int starter();
    virtual int ender();
    virtual int writer();
    virtual int reader();
    virtual ~IIC();

    int watch_dog();

};

IIC::IIC():GPIO()
{
    cout << __FUNCTION__ << endl;
}

int IIC::starter()
{
    cout << "int IIC::starter()" << endl;
    return 0;
}

int IIC::ender()
{
    cout << "int IIC::ender()" << endl;
    return 0;
}

int IIC::writer()
{
    cout << "int IIC::writer()" << endl;
    return 0;
}

int IIC::reader()
{
    cout << "int IIC::reader()" << endl;
    return 0;
}

IIC::~IIC()
{
    cout << __FUNCTION__ << endl;
}

int IIC::watch_dog()
{
    cout << "int IIC::watch_dog()" << endl;
    return 0;
}







int main()
{
    Reger * rp[] = {new GPIO, new IIC};

    for( int i = 0; i<2; i++)
    {
        rp[i]->starter();

        if(typeid(*rp[i]) == typeid(IIC))  //must use *rp[i] to compare not pointer itself!!!
        {
            IIC * iicp = dynamic_cast<IIC *>(rp[i]);
            if(iicp)
            {
                iicp->watch_dog();
            }
        }

    }
    
    for( int i = 0; i<2; i++)
    {
        delete rp[i];
    }
    
    return 0;
}

