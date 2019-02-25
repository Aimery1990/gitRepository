
#include <stdio.h>

void switcher( int * a, int * b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void switcherx( int * a, int * b)
{
    if(a!=b)
    {
        *a^=*b^=*a^=*b;
#if 0
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
#endif
    }
}

void bubble_sort( int * a, int len)
{
    int i = 0;
    int j = 0;

    for(i = 0; i < len - 1; i ++)
    {
        for(j = 0; j < len - 1 - i; j ++ )
        {
            if(a[j+1] < a[j])
                switcherx(&a[j], &a[j+1]);
        }
    }
}

int main()
{
    int a[] = {8,5,3,6,1,8,9,4,1,0};

    bubble_sort( a, sizeof(a)/sizeof(a[0]) );

    for(int i=0; i<sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}






#if 0
/*C语言中几种排序法*/
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
/* 创建数组 */
void makeArray( int *p, int len )
{
    int i;
    srand( (unsigned) time( NULL ) );
    for ( i = 0; i < len; i++ )
    {
        p[i] = rand() % 100 + 1;
    }
}
/* 交换两个数 */
void mySwap( int *p1, int *p2 )
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
/* 输出 */
void outPut( int *p, int len )
{
    int i;
    for ( i = 0; i < len; i++ )
    {
        printf( "%d,", p[i] );
    }
    puts( "" );
}
/* 插入排序 */
void insertSort( int *p, int len )
{
    int i = 0, j = 0;
    int temp;
    for ( i = 1; i < len; i++ )
    {
        j = i;
        temp = p[i];
        while ( j > 0 && temp < p[j - 1] )
        {
            p[j] = p[j - 1];
            j--;
        }
        p[j] = temp;
    }
}
/*选择排序 */
void selectSort( int *p, int len )
{
    int i, j, k;
    for ( i = 0; i < len - 1; i++ )
    {
        k = i;
        for ( j = i + 1; j < len; j++ )
        {
            if ( p[k] > p[j] )
                k = j;
        }
        if ( k != i )
        {
            mySwap( &p[i], &p[k] );
        }
    }
}
/* 冒泡排序 */
void bubbleSort( int *p, int len )
{
    int i, j;
    for ( i = 0; i < len - 1; i++ )
    {
        for ( j = 0; j < len - i - 1; j++ )
        {
            if ( p[j] > p[j + 1] )
            {
                mySwap( &p[j], &p[j + 1] );
            }
        }
    }
}
/*希尔排序 */
void shellSort( int *p, int len )
{
    int i, j, now, temp;
    for ( now = len / 2; now >= 1; now /= 2 )
    {
        for ( i = now; i < len; i++ )
        {
            temp = p[i];
            j = i;
            while ( j >= now && temp < p[j - now] )
            {
                p[j] = p[j - now];
                j -= now;
            }
            p[j] = temp;
        }
    }
}
/* 快速排序 */
void quickSort( int *p, int begin, int end )
{
    int i = begin;
    int j = end;
    int temp = p[i];
    while ( i < j )
    {
        while ( i < j && p[j] > temp )
            j--;
        if ( i < j )
        {
            p[i] = p[j];
            i++;
        }
        while ( i < j && p[i] < temp )
            i++;
        if ( i < j )
        {
            p[j] = p[i];
            j--;
        }
    }
    p[i] = temp;
    if ( begin < i - 1 )
    {
        quickSort( p, begin, i - 1 );
    }


    if ( j + 1 < end )
    {
        quickSort( p, j + 1, end );
    }
}
/*快速排序2: qsort(来源于C程序设计语言(第二版)*/
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);
    if(left > right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
        if(v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}
void swap(int v[], int i, int j)
{
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
/* 堆排序(从下标为1的位置开始) */
void heap_adjust( int *p, int root, int len )
{
    int i = 2 * root;
    int t = p[root];
    while ( i <= len )
    {
        if ( i < len )
        {
            if ( p[i] < p[i + 1] )
                i++;
        }
        if ( t >= p[i] )
            break;
        p[i / 2] = p[i];
        i = 2 * i;
    }
    p[i / 2] = t;
}
void heapSort( int *p, int len )
{
    int i;
    for ( i = len / 2; i > 0; i-- )
    {
        heap_adjust( p, i, len );
    }
    for ( i = len; i >= 1; i-- )
    {
        mySwap( p + i, p + 1 );
        heap_adjust( p, 1, i - 1 );
    }
}
/* 基数排序(编译正确, 当改变数组长度(不是10时),运行结果不正确或出错 */
int temp_digit( int temp, int flag )
{
    int i;
    i = temp / (int) pow( 10, flag ) % 10;


    return i;
}
void baseSort( int *p, int len )
{
    int i, j, k, index, temp;
    int count[10];
    int array[10][20] = { 0 };
    for ( i = 0; i < 3; i++ )
    {
        for ( j = 0; j < 10; j++ )
        {
            count[j] = 0;
        }
        for ( j = 0; j < len; j++ )
        {
            temp = temp_digit( p[j], i );
            array[temp][count[temp]++] = p[j];
        }
        index = 0;
        for ( j = 0; j < len; j++ )
        {
            for ( k = 0; k < count[j]; k++ )
            {
                p[index] = array[j][k];
                index++;
            }
        }
    }
}
int main( void )
{
    int num[10];
    int len = sizeof(num) / sizeof(int);
    clock_t start, finish;
    double total_time;
    makeArray( num, len );
    // outPut( num, len );
    start = clock();
    // insertSort( num, len );
    // selectSort( num, len );
    // bubbleSort( num, len );
    // shellSort( num, len );
    // quickSort( num, 0, len - 1 );
    qsort(num, 0, len - 1);
    // heapSort( num, len );
    // baseSort( num, len );
    finish = clock();
    total_time = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Total_time is %f\n", total_time);
    // outPut( num, len );
    return 0;
}
#endif