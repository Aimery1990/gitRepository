#include <iostream>
#include <vector>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define BUFF_SZ (1024)

int main_c()
{
    FILE * fp = fopen("src_string.txt", "r+");
    if(!fp){
        printf("fail to fopen(), %d\n", __LINE__);
        return -1;
    }
    
    char * op = (char *)malloc(BUFF_SZ + sizeof(char *));
    if(!op){
        printf("fail to malloc() %d\n", __LINE__);
        return -2;
    }
    memset(op, 0, sizeof(char *)+BUFF_SZ);
    
    char * lp = op;
    while(fgets(lp, BUFF_SZ, fp)){
        lp+=BUFF_SZ;
        
        char * tp;
        tp = (char *)malloc(BUFF_SZ + sizeof(char *));
        if(!tp){
            printf("Fail to malloc() %d\n", __LINE__);
            return -3;
        }
        
        memset(tp, 0, sizeof(char *)+BUFF_SZ);
        memcpy(lp, &tp, sizeof(char *));
        
        lp = * (char **)lp;
        
    }
    
    char * xp = lp = op;
    while(xp)
    {
        printf("%s", lp);
        lp = *(char **)(xp + BUFF_SZ);
        free(xp);
        xp = lp;
    }
    printf("\n");
    fclose(fp);
    return 0;
}

int main_cpp()
{
    vector<string> strs;
    char buffer[BUFF_SZ] = {0};
    FILE * fp = fopen("src_string.txt", "r+");
    while(fgets(buffer, BUFF_SZ, fp))
    {
        strs.push_back(buffer);
        memset(buffer, 0, BUFF_SZ);
    }
    
    vector<string>::iterator it = strs.begin();
    for(;it!=strs.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
    fclose(fp);
    return 0;
}


int main()
{
    int ret1 = main_c();
    int ret2 = main_cpp();
    return 0;
}
