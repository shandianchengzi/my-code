#include<stdio.h>
int MaxSubseqSum1( int A[], int N )
{
    int ThisSum, MaxSum = 0;
    int i, j, k;
    for( i = 0; i < N; i++ )   /* i是子列左端位置 */
    {
        for( j = i; j < N; j++ )   /* j是子列右端位置 */
        {
            ThisSum = 0;  /* ThisSum是从A[i]到A[j]的子列和 */
            for( k = i; k <= j; k++ )
                ThisSum += A[k];
            if( ThisSum > MaxSum ) /* 如果刚得到的这个子列和更大 */
                MaxSum = ThisSum;    /* 则更新结果 */
        } /* j循环结束 */
    } /* i循环结束 */
    return MaxSum;
}
int MaxSubseqSum2( int A[], int N )
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for( i = 0; i < N; i++ )   /* i是子列左端位置 */
    {
        ThisSum = 0;  /* ThisSum是从A[i]到A[j]的子列和 */
        for( j = i; j < N; j++ )   /* j是子列右端位置 */
        {
            ThisSum += A[j];        /*对于相同的i，不同的j，只要在j-1次循环的基础上累加1项即可*/
            if( ThisSum > MaxSum ) /* 如果刚得到的这个子列和更大 */
                MaxSum = ThisSum;    /* 则更新结果 */
        } /* j循环结束 */
    } /* i循环结束 */
    return MaxSum;
}

int MAXK;
int SCAN(int A[],int middle,int t,int le_ri)
{
    int m=A[middle],n=A[middle];
    while(middle*t>t*le_ri)
    {
        if(m+A[middle-t]>n)
        {
            m+=A[middle-t];
            n=m;
            if(MAXK<n)
                MAXK=n;
        }
        else
            m+=A[middle-t];
        middle-=t;
    }
    return n;
}
void Depart(int A[],int left,int right)
{
    if(left!=right)
    {
        int middle=(left+right)/2;
        int m=SCAN(A,middle,1,left)+SCAN(A,middle+1,-1,right);
        MAXK=(m>MAXK?m:MAXK);
        Depart(A,left,middle);
        Depart(A,middle+1,right);
    }
    else return;
}
int MaxSubseqSum3( int A[], int N )
{
    Depart(A,0,N);
    return MAXK;
}
int MaxSubseqSum4( int A[], int N )
{   int ThisSum, MaxSum;
    int i;
    ThisSum = MaxSum = 0;
    for( i = 0; i < N; i++ ) {
          ThisSum += A[i]; /* 向右累加 */
          if( ThisSum > MaxSum )
                  MaxSum = ThisSum; /* 发现更大和则更新当前结果 */
          else if( ThisSum < 0 ) /* 如果当前子列和为负 */
                  ThisSum = 0; /* 则不可能使后面的部分和增大，抛弃之 */
    }
    return MaxSum;
}
int main()
{
    int A[100010],K,flag=1;
    if (scanf("%d", &K) != 1)
        printf("Failed to read integer.\n");
    for(int i=0; i<K; i++)
    {
        if (scanf("%d", &A[i]) != 1)
            printf("Failed to read integer.\n");
        if(flag&&A[i]>=0)
            flag=0;
    }
    if(flag)
        printf("0");
    else
    {
        MaxSubseqSum3(A,K);
        printf("%d",MAXK);
    }
    return 0;
}


