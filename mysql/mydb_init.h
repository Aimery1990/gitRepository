

#ifndef __MYDB_INIT_H_
#define __MYDB_INIT_H_

#define MAX_DB_NUM  (32)
#define MAX_DB_INFO (64)

#ifdef __cplusplus__
extern  "C" {
#endif

typedef enum{
  SUCCESS = 0,
  IP_LACK,
  USR_LACK,
  PASSWD_LACK,
  DBNAME_LACK,
  DB_API_ERRNO,
  DB_QRY_ERROR,
  DB_CALL_ERROR,
  DB_AVLB_ERROR,
}DB_ERROR_T;

typedef void (*QRY_CBK_T)(char **, unsigned long);

//extern DB_ERROR_T get_database_info( int dbfd, const char * dbserver, const char * dbuser, const char * dbpassword, const char * db);
extern int init_connect_db(const char * dbserver, const char * dbuser, const char * dbpassword, const char * db);
extern DB_ERROR_T run_update_db(int dbfd, char * sql_stm, unsigned long sql_len);
extern DB_ERROR_T run_query_db(int dbfd, char * sql_stm, unsigned long sql_len, QRY_CBK_T fp);
extern void free_db(int dbfd);

#ifdef __cplusplus__
}
#endif





#endif /* __MYDB_INIT_H_ */
