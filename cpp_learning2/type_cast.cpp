
#include<iostream>


using namespace std;

//class Point3D;

class Point2D{

public:
    Point2D( double x = 0, double y = 0):_x(x), _y(y){}
    //Point2D( const Point3D & p3d ):_x(p3d._x), _y(p3d._y){} //error: member access into incomplete type 'const Point3D'
    
    friend ostream & operator<<( ostream & os, Point2D & p2d );
    friend class Point3D;
private:
    double _x;
    double _y;
};

ostream & operator<<( ostream & os, Point2D & p2d )
{
    os << "2d: _x=" << p2d._x << " \t_y=" << p2d._y;
    return os;
}


class Point3D{
public:
    Point3D( double x = 0, double y = 0, double z = 0):_x(x), _y(y), _z(z){}
    //explicit
    Point3D( const Point2D & p2d ):_x(p2d._x), _y(p2d._y), _z(0){}  //type cast constructor: feature: single parameter

    operator Point2D(void)
    {
        return Point2D(this->_x, this->_y);
    }
    
    
    friend ostream & operator<<( ostream & os, Point3D & p3d );
    //friend class Point2D;
private:
    double _x;
    double _y;
    double _z;
};

ostream & operator<<( ostream & os, Point3D & p3d )
{
    os << "3d: _x=" << p3d._x << " \t_y=" << p3d._y << " \t_z=" << p3d._z;
    return os;
}



int main()
{
    Point2D p2d(1,2);
    Point3D p3d(3,4,5);
    
    cout << p2d << endl;
    cout << p3d << endl;
    
    //p3d = static_cast<Point3D>(p2d); /* or */ p3d = (Point3D)p2d;  //if explicit
    p3d = p2d;
    cout << p2d << endl;
    cout << p3d << endl;
    
    p2d = p3d;
    cout << p2d << endl;
    cout << p3d << endl;
    
    return 0;
}
