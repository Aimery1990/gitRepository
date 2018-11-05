
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mysql/mysql.h>
#include "mydb_init.h"



//static MYSQL * conn = NULL;
//static MYSQL_RES * res = NULL;
//static MYSQL_ROW row = {0};
//
//static char server[MAX_DB_INFO] = {0}; //"localhost";
//static char user[MAX_DB_INFO] = {0}; //"root";
//static char password[MAX_DB_INFO] = {0}; //"password";
//static char database[MAX_DB_INFO] = {0}; //"mysql";




typedef struct db_info{
    MYSQL * conn;
    MYSQL_RES * res;
    MYSQL_ROW row;
    MYSQL_FIELD * fields;
    QRY_CBK_T qry_func;
    unsigned long rows;
    unsigned long columns;
    char server[MAX_DB_INFO]; //"localhost";
    char user[MAX_DB_INFO]; //"root";
    char password[MAX_DB_INFO]; //"password";
    char database[MAX_DB_INFO]; //"mysql";
    char flag;
}DB_INFO_T;

static DB_INFO_T databases[MAX_DB_NUM];
//static unsigned  db_idx;



DB_ERROR_T get_database_info( int dbfd, const char * dbserver, const char * dbuser, const char * dbpassword, const char * db)
{
    if(dbserver){
        strncpy(databases[dbfd].server, dbserver, MAX_DB_INFO);
    }
    else{
        printf("Lack of server ip\n");
        return IP_LACK;
    }
    
    if(dbuser){
        strncpy(databases[dbfd].user, dbuser, MAX_DB_INFO);
    }
    else{
        printf("Lack of user\n");
        return USR_LACK;
    }
    
    if(dbpassword){
        strncpy(databases[dbfd].password, dbpassword, MAX_DB_INFO);
    }
    else{
        printf("Lack of password\n");
        return PASSWD_LACK;
    }
    
    if(db){
        strncpy(databases[dbfd].database, db, MAX_DB_INFO);
    }
    else{
        printf("Lack of database\n");
        return DBNAME_LACK;
    }
    
    return SUCCESS;
}

int init_connect_db(const char * dbserver, const char * dbuser, const char * dbpassword, const char * db)
{
    int dbi = 0;
    for(;dbi<MAX_DB_NUM; ++dbi){
        if(!databases[dbi].flag){
            databases[dbi].flag = 1;
            break;
        }
    }

    if(dbi==MAX_DB_NUM){
        printf("Unable to connect more database for MAX_DB_NUM %d in %s\n", MAX_DB_NUM, __FUNCTION__);
        return DB_AVLB_ERROR;
    }
    
    DB_ERROR_T dberr = get_database_info(dbi, dbserver, dbuser, dbpassword, db);
    if(dberr){
        printf("get_database_info() error: %d\n", dberr);
        databases[dbi].flag = 0;
        return dberr;
    }
    
    databases[dbi].conn = mysql_init(NULL);
    
    if(!mysql_real_connect(databases[dbi].conn, databases[dbi].server, databases[dbi].user, databases[dbi].password, databases[dbi].database, 0, NULL, 0)){
        fprintf(stderr, "mysql_real_connect() %s\n",  mysql_error(databases[dbi].conn));
        databases[dbi].flag = 0;
        return DB_API_ERRNO;
    }
    else{
        printf("MySQL Connection Info: %s \n",  mysql_get_host_info(databases[dbi].conn));
        printf("MySQL Client Info: %s \n",      mysql_get_client_info());
        printf("MySQL Server Info: %s \n",      mysql_get_server_info(databases[dbi].conn));
    }
    
    return dbi;
}

DB_ERROR_T run_update_db(int dbfd, char * sql_stm, unsigned long sql_len)
{
    if(!sql_stm||(dbfd>MAX_DB_NUM || dbfd<0)||sql_len<=0){
        printf("%s calling error\n", __FUNCTION__);
        return DB_CALL_ERROR;
    }
    
    if(sql_len>0){
        unsigned long i = 0;
        printf("SQL: ");
        for(i=0;i<sql_len;++i){
            printf("%c", sql_stm[i]);
        }
        printf("\n");
    }
    
    int qry_res = 0;
    qry_res = mysql_real_query(databases[dbfd].conn, sql_stm, sql_len);
    if(qry_res){
        fprintf(stderr, "mysql_real_query() %s\n", mysql_error(databases[dbfd].conn));
        return DB_QRY_ERROR;
    }
    
    return SUCCESS;
}


DB_ERROR_T run_query_db(int dbfd, char * sql_stm, unsigned long sql_len, QRY_CBK_T fp)
{
    DB_ERROR_T ret = run_update_db(dbfd, sql_stm, sql_len);
    if(ret!=SUCCESS){
        printf("%s run_update_db() error\n", __FUNCTION__);
        return ret;
    }
    
    if(fp){
        databases[dbfd].qry_func = fp;
    }

    databases[dbfd].res = mysql_use_result(databases[dbfd].conn);
    if(!databases[dbfd].res){
        fprintf(stderr, "mysql_use_result() %s\n", mysql_error(databases[dbfd].conn));
        return DB_API_ERRNO;
    }
    
    
    databases[dbfd].fields = mysql_fetch_fields(databases[dbfd].res);
    databases[dbfd].rows = mysql_num_rows(databases[dbfd].res);
    databases[dbfd].columns = mysql_num_fields(databases[dbfd].res);
    
    printf("\n");
    unsigned long i = 0;
    for(;i<databases[dbfd].columns; ++i)
    {
        printf("%s\t", databases[dbfd].fields[i].name);
    }
    printf("\n\n");
    
    i = 0;
    while ((databases[dbfd].row = mysql_fetch_row(databases[dbfd].res)))
    {
        if(databases[dbfd].qry_func){
            databases[dbfd].qry_func((char **)(databases[dbfd].row), databases[dbfd].columns);
        }
        ++i;
    }
    
//    databases[dbfd].res = mysql_store_result(databases[dbfd].conn);
//    if(!databases[dbfd].res){
//
//    }
    
    return SUCCESS;
}


void free_db(int dbfd)
{
    if(databases[dbfd].res){
        mysql_free_result(databases[dbfd].res);
    }
    if(databases[dbfd].conn){
        mysql_close(databases[dbfd].conn);
    }
    printf("Database DONE!\n");
}

//https://dev.mysql.com/doc/refman/8.0/en/mysql-field-count.html
//https://blog.csdn.net/ftxc_blog/article/details/12654705


