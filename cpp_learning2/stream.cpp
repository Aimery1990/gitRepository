
#include<iostream>
#include<fstream>
#include<unistd.h>

using namespace std;


int main()
{
    fstream fs1;
    //fstream fs2(fs1);  //stream objects are not been constructed by copying
    
    //stream object has buffer, without endl or flush or ... it won't output immediately
//    for(int i = 0; i<1000; i++)
//    {
//        cout << "aaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccdddddddddd";
//        usleep(500000);
//    }
    
//    for(int i = 0; i<1000; i++)
//    {
//        cout << "aaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccdddddddddd" << endl; //it outputs Enter
//        usleep(200000);
//    }
//
//
//    for(int i = 0; i<1000; i++)
//    {
//        cout << "aaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccdddddddddd" << flush; //it won't output Enter
//        usleep(200000);
//    }
    
//    for(int i = 0; i<1000; i++)
//    {
//        cout << unitbuf<<"aaaaaaaaaaaaabbbbbbbbbbbbbbbbcccccccccccccccdddddddddd"; //it won't output Enter
//        usleep(200000);
//    }
    
    fstream fs("abc.txt", ios::in|ios::out|ios::trunc);
    
    fs << 1 << " " << 2 << " " << 3 << endl;
    fs.seekp(0, ios::beg);
    
    int x, y, z;
    
    fs >> x >> y >> z;
    
    cout << x << y << z << endl;
    
    return 0;
}
