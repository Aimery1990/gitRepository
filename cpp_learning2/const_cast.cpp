
#include <iostream>

using namespace std;
class CCTest {
public:
   void setNumber( int );
   void printNumber() const;
   void getNumber();
private:
   int number;
};

void CCTest::setNumber( int num ) { number = num; }

void CCTest::printNumber() const {
   cout << "\nBefore: " << number;
   const_cast< CCTest * >( this )->number--;
   cout << "\nAfter: " << number;
   cout << endl;
}

void CCTest::getNumber(){
    cout << number << endl;
}

int main() {
   CCTest X;
   X.setNumber( 8 );
   X.printNumber();
   X.getNumber();
}