
g++ -Wall mysql_test.cpp -o mysql_test -lmysqlclient
gcc -Wall mysql_init.c -o mysql_init.so -fPIC -shared -lmysqlclient
