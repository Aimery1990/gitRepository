
#include <iostream>
#include <string>
#include "mydb_init.h"

using namespace std;

class DB_Interfaces{
    
protected:
    //const char * dbserver, const char * dbuser, const char * dbpassword, const char * db
    string      dbserver;
    string      dbuser;
    string      dbpassword;
    string      dbname;
    QRY_CBK_T   qryfp;
    int         dbfd;
    bool        db_init_flag;
    
public:
    //DB_Interfaces();
    DB_Interfaces(string dbsrv="",string dbusr="", string dbpasswd="", string dbna="", QRY_CBK_T qfp=NULL, int dfd = -1, bool db_init_flg=false);
    //DB_Interfaces(const DB_Interfaces & ano);
    
    virtual int DB_Init(string dbsrv,string dbusr, string dbpasswd, string dbna) = 0;
    virtual DB_ERROR_T DB_Uninit(int dbfd) = 0;
    virtual DB_ERROR_T DB_Update(int dbfd, string sql_stm, unsigned long sql_len) = 0;
    virtual DB_ERROR_T DB_Query (int dbfd, string sql_stm, unsigned long sql_len, QRY_CBK_T fp) = 0;
    
    virtual ~DB_Interfaces();
};
    
DB_Interfaces::DB_Interfaces(string dbsrv,string dbusr, string dbpasswd, string dbna, QRY_CBK_T qfp, int dfd, bool db_init_flg)
                            :dbserver(dbsrv), dbuser(dbusr), dbpassword(dbpasswd), dbname(dbna), qryfp(qfp), dbfd(dfd), db_init_flag(db_init_flg)
{
}


DB_Interfaces::~DB_Interfaces()
{
    db_init_flag = false;
    dbfd = -1;
}


