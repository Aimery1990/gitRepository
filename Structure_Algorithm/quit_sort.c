#include <stdio.h>

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


int main()
{
    int b[] = {1,4,3,6,11,8,46,0};

    quit_sort(b, 0, sizeof(b)/sizeof(b[0])-1);
    
    for(int i = 0; i<sizeof(b)/sizeof(b[0]); i++)
    {
        printf("%d ", b[i]);
    }

    printf("\n");
    return 0;
}