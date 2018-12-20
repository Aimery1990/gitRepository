#include <iostream>

using namespace std;

#if 0 //version 0: without virtual inheritance, _m have 2 pieces in Total which are from Left's and Right's perspectively
class M{
public:
    M()
    {}

    //M( int m = 0 ) : _m(m)
    //{}

    void print_m()
    {
        cout << _m << endl;
    }
protected:
    int _m;

};

class Left: public M{
public:
    Left()
    {}

    void set_m( int m ){
        _m = m;
    }

    ~Left()
    {
        cout<< "Left _m:" << _m << endl;
    }
};

class Right: public M{
public:
    Right()
    {}

    int get_m()
    {
        return _m;
    }

    ~Right()
    {
        cout<< "Right _m:" << _m << endl;
    }
};

class Total: public Right, public Left{
public:
    Total()
    {}

};

#endif

#if 0 //version 1: by virtual inheritance _m becomes unique

class M{
public:
    M()
    {}

    //M( int m = 0 ) : _m(m)
    //{}

    void print_m()
    {
        cout << _m << endl;
    }

    virtual ~M()
    {}
protected:
    int _m;

};

class Left: virtual public M{
public:
    Left()
    {}

    void set_m( int m ){
        _m = m;
    }

    ~Left()
    {
        cout<< "Left _m:" << _m << endl;
    }
};

class Right: virtual public M{
public:
    Right()
    {}

    int get_m()
    {
        return _m;
    }

    ~Right()
    {
        cout<< "Right _m:" << _m << endl;
    }
};

class Total: public Right, public Left{
public:
    Total()
    {}

};

#endif

class M{
public:
//    M()
//    {}

    M( int m ) : _m(m)
    {}

    void print_m()
    {
        cout << _m << endl;
    }

    virtual ~M()
    {}
protected:
    int _m;

};

class Left: virtual public M{
public:
    Left( int m ): M(m)
    {}

    void set_m( int m ){
        _m = m;
    }

    ~Left()
    {
        cout<< "Left _m:" << _m << endl;
    }
};

class Right: virtual public M{
public:
    Right( int m ): M(m)
    {}

    int get_m()
    {
        return _m;
    }

    ~Right()
    {
        cout<< "Right _m:" << _m << endl;
    }
};

class Total: public Right, public Left{
public:
    Total( int m = 200): Left(m), Right(m), M(m)//3 class's constructor are all necessary here
    {}

};

int main()
{
    Total t;
    //t.set_m(20);
    cout << t.get_m() << endl;
    return 0;
}
