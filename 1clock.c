#include<stdio.h>
#include<time.h>
#include<math.h>

#define MAXK 1e7
int m,j;
void f1(void)
{
    m=j+1;
}
clock_t start,stop;
/*clock_t��clock()�������صı������ͣ�*/
double duration;
/*��¼���⺯������ʱ�䣬����Ϊ��λ*/
int main()
{/*���ڲ��Է�Χ�ڵ�׼������д��clock()����֮ǰ*/
    start =clock();
    for(int i=0;i<MAXK;i++)//Ҫ��ĺ���
        f1();
    stop=clock();
    duration=((double)(stop-start))/CLK_TCK/MAXK;
    printf("%lf,%6.2e,%d",(double)(stop-start),duration,CLK_TCK);
    /*������������ ��Χ�ڵĴ���д�ں��棬�������duration��ֵ*/
    return 0;
}
