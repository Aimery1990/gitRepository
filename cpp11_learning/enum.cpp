
#include <iostream>
#include <fstream>

using namespace std;

#if 0
class Season
{
public:
    enum _Season
    {
        Spring,
        Summer,
        Autumn,
        Winter
    };
};

class XX
{
public:
    enum _xx
    {
        Spring,
        Summer,
        Autumn,
        Winter
    };
};


int main()
{
    Season::_Season s = Season::Spring;
    XX::_xx x = XX::Spring;

    fstream f;
    f.open("aa.txt", ios::in|ios::out|ios::trunc);

    f.close();
}

#endif

enum class Season: char
{
    Spring,
    Summer,
    Autumn,
    Winter
};

enum struct XX: long long
{
    Spring,
    Summer,
    Autumn,
    Winter    
};

int main()
{
    Season s = Season::Spring;
    XX x = XX::Spring;

    cout << static_cast<int> (Season::Summer) << " " << static_cast<int> (XX::Autumn) << endl;
    cout << sizeof(Season::Autumn) << " " << sizeof(XX::Winter) << endl;

    return 0;
}
