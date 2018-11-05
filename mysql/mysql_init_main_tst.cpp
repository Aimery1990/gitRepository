
#include <iostream>
#include <string>
#include "mysql_init.h"

using namespace std;

class DB_Interfaces{
    
protected:
    //const char * dbserver, const char * dbuser, const char * dbpassword, const char * db
    string dbserver;
    string dbuser;
    string dbpassword;
    string dbname;
    
public:
    DB_Interfaces();
    DB_Interfaces(string dbsrv,string dbusr, string dbpasswd, string dbname);
    DB_Interfaces(DB_Interfaces & ano);
    
    virtual DB_Init() = 0;
    virtual DB_Uninit() = 0;
    virtual DB_Update() = 0;
    virtual DB_Query() = 0;
    
    virtual ~DB_Interfaces();
};
