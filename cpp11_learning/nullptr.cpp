
#include "iostream"



using namespace std;

void * Test_Func(void * ptr)
{
    if(ptr == nullptr)
    {
        return nullptr;
    }
    void * ptr_new = new int(0);

    return ptr_new;
}


int main()
{

    auto res =  Test_Func(nullptr);
    if(res == nullptr)
    {
        cout << "this is a nullptr" << endl;
    }


    return 0;
}





