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
/*clock_t是clock()函数返回的变量类型）*/
double duration;
/*记录被测函数运行时间，以秒为单位*/
int main()
{/*不在测试范围内的准备工作写在clock()调用之前*/
    start =clock();
    for(int i=0;i<MAXK;i++)//要测的函数
        f1();
    stop=clock();
    duration=((double)(stop-start))/CLK_TCK/MAXK;
    printf("%lf,%6.2e,%d",(double)(stop-start),duration,CLK_TCK);
    /*其他不做测试 范围内的处理写在后面，例如输出duration的值*/
    return 0;
}
