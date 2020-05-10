#include<stdio.h>
int MaxSubseqSum1( int A[], int N )
{
    int ThisSum, MaxSum = 0;
    int i, j, k;
    for( i = 0; i < N; i++ )   /* i���������λ�� */
    {
        for( j = i; j < N; j++ )   /* j�������Ҷ�λ�� */
        {
            ThisSum = 0;  /* ThisSum�Ǵ�A[i]��A[j]�����к� */
            for( k = i; k <= j; k++ )
                ThisSum += A[k];
            if( ThisSum > MaxSum ) /* ����յõ���������к͸��� */
                MaxSum = ThisSum;    /* ����½�� */
        } /* jѭ������ */
    } /* iѭ������ */
    return MaxSum;
}
int MaxSubseqSum2( int A[], int N )
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for( i = 0; i < N; i++ )   /* i���������λ�� */
    {
        ThisSum = 0;  /* ThisSum�Ǵ�A[i]��A[j]�����к� */
        for( j = i; j < N; j++ )   /* j�������Ҷ�λ�� */
        {
            ThisSum += A[j];        /*������ͬ��i����ͬ��j��ֻҪ��j-1��ѭ���Ļ������ۼ�1���*/
            if( ThisSum > MaxSum ) /* ����յõ���������к͸��� */
                MaxSum = ThisSum;    /* ����½�� */
        } /* jѭ������ */
    } /* iѭ������ */
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
          ThisSum += A[i]; /* �����ۼ� */
          if( ThisSum > MaxSum )
                  MaxSum = ThisSum; /* ���ָ��������µ�ǰ��� */
          else if( ThisSum < 0 ) /* �����ǰ���к�Ϊ�� */
                  ThisSum = 0; /* �򲻿���ʹ����Ĳ��ֺ���������֮ */
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


