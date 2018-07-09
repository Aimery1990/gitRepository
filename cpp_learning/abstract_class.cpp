
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Protocal{
public:
    Protocal(){ init_flag = true; cout << "Protocal()" << endl;}
    Protocal(bool init_flag){ init_flag = true; cout << "Protocal(bool init_flag)" << endl;}
    Protocal( const Protocal & ano ){ init_flag = ano.init_flag; cout << "Protocal( const Protocal & ano )" << endl;}
    virtual ~Protocal(){ init_flag = false; cout << "virtual ~Protocal()" << endl;}
    
    virtual int Initialize( int * number ) = 0;
    virtual int Data_Get( char * data, int * len ) = 0;
    virtual int Data_Set( char * data, int len ) = 0;
    virtual int Destory( int * number ) = 0;
    
protected:
    bool init_flag;
    
};

#define DEFAUL_SPACE_LEN    (1024)

class ThirdPartyImp01: public Protocal{
private:
    char * data_space;
    unsigned space_len;
    bool data_lock;
    static int count;
    
public:
    ThirdPartyImp01()
    {
        cout << "this is ThirdPartyImp01()" << endl;
        data_lock = true;
        space_len = DEFAUL_SPACE_LEN;
        data_space = (char *) malloc(space_len);
        if(! (data_space)){
            cout << "error malloc error!!" << endl;
            abort();
        }
        memset(data_space, 0 , space_len);
        count++;
        data_lock = false;
    }
    ThirdPartyImp01( bool init_flag, char * data_space, unsigned space_len ):Protocal(init_flag)
    {
        cout << "this is ThirdPartyImp01( bool init_flag, char * data_space, unsigned space_len )" << endl;
        data_lock = true;
        
        if( data_space==NULL){
            this->data_space = (char *) malloc(space_len);
            if(! (this->data_space)){
                cout << "error malloc error!!" << endl;
                abort();
            }
            memset(this->data_space, 0 , space_len);
        }
        else{
            this->data_space = data_space;
            this->space_len = space_len;
        }
        count++;
        data_lock = false;
    }
    ThirdPartyImp01( const ThirdPartyImp01 & ano )
    {
        cout << "this is ThirdPartyImp01( const ThirdPartyImp01 & ano )" << endl;
        data_lock = true;
        if(ano.data_space!=NULL){
            this->data_space = ano.data_space;
            this->space_len = ano.space_len;
        }
        else{
            cout << "error trying to copy and construct a NULL data space" << endl;
            abort();
        }
        count++;
        data_lock = ano.data_lock;
    }
    virtual ~ThirdPartyImp01()
    {
        cout << "this is ~ThirdPartyImp01()" << endl;
        data_lock = true;
        if(this->data_space){
            free(this->data_space);
            data_space = NULL;
        }
        else{
            cout << "error trying to destruct a NULL data data space" << endl;
        }
        space_len = 0;
        count--;
        data_lock = false;
    }
    
    virtual int Initialize( int * number )
    {
        *number = count;
        return 0;
    }
    
    virtual int Data_Get( char * data, int * len )
    {
        char tmp[1024] = {"this is the test data buffer"};
        sprintf(this->data_space, "%s", tmp);
        this->data_lock = true;
        memcpy(data, this->data_space, this->space_len);
        * len = this->space_len;
        this->data_lock = false;
        return 0;
    }
    
    virtual int Data_Set( char * data, int len )
    {
        this->data_lock = true;
        memset(this->data_space, 0, this->space_len);
        memcpy(this->data_space, data,  len );
        cout << this->data_space << endl;
        this->data_lock = false;
        return 0;
    }
    
    virtual int Destory( int * number )
    {
        * number = 0;
        return 0;
    }
    
};

int ThirdPartyImp01::count = 0;



int Start( Protocal ** p)
{
    *p = new ThirdPartyImp01;
    if(*p)
        return 0;
    else
        return -1;
}

int End( Protocal * p)
{
    delete p;
    return 0;
}


int main()
{
    Protocal * basic = NULL;
    int number = 0;
    char set_data[1024] = {"hello !!"};
    char get_data[1024] = {0};
    int get_len = 0;
    int ret = 0;
    
    //basic = new ThirdPartyImp01;
    ret = Start(&basic);

    
    basic->Initialize(&number);
    cout << number << endl;
    
    basic->Data_Get(get_data, & get_len);
    cout << get_data << endl;
    cout << get_len << endl;
    
    
    basic->Data_Set(set_data, sizeof(set_data));
    
    End(basic);
    
    
    return 0;
}

















