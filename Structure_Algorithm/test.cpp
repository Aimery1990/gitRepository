
#include <stdio.h>
#include <string.h>
#include <math.h>


void switcherx( int * a, int * b)
{
    *a^=*b^=*a^=*b;
}

void bubble_sort( int * a, int len)
{
    int i = 0;
    int j = 0;

    for(i =0; i<len-1; i++)
    {
        for(j=0; j<len-1-i; j++)
        {
            if(a[j] > a[j+1])
            {
                switcherx(&a[j], &a[j+1]);
            }
        }
    }
}

void quit_sort( int * a, int left, int right)
{
    if(left>=right)
        return;
    
    int i = left;
    int j = right;
    int key = a[left];

    while(i<j && key <= a[j])
    {
        j--;
    }

    a[i] = a[j];

    while(i<j && a[i] <= key)
    {
        i++;
    }

    a[j] = a[i];

    a[i] = key;
    quit_sort(a, left, i-1);
    quit_sort(a, i+1, right);
}


void str_transfer(const char * src, int * out)
{
    char * p = (char *)src;
    int result = 0;
    //printf("%s, %s, strlen(src)=%d\n", src, p, strlen(src));
    for(int i = 0; i < strlen(src); i++)
    {
        result += (p[i] - 48) * pow(10, strlen(src)-1-i);
        //printf("%d %d\n", result, p[i]);

    }
    *out = result;
}


int main()
{
    int a[] = {1,4,3,6,11,8,46};

    bubble_sort(a, sizeof(a)/sizeof(a[0]));

    for(int i =0; i< sizeof(a)/sizeof(a[0]); i ++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");
    int b[] = {1,4,3,6,11,8,46};

    quit_sort(b, 0, sizeof(b)/sizeof(b[0])-1);
    
    for(int i = 0; i<sizeof(b)/sizeof(b[0]); i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");

    const char str[] = {"123"};
    int result = 0;

    str_transfer(str, &result);

    printf("%d\n", result);


    return 0;
}