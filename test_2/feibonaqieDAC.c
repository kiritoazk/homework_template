#include <stdio.h>
#include<stdlib.h>
int num=0;//记录比较次数
//递归求解
int DAC(int n)
{
    if (n == 1 || n == 2)
    {
        num++;
        return 1;
    }
    else
    {
        num++;
        return DAC(n - 1) + DAC(n - 2);
    }
}

int main()
{
    int n; //接受用户输入的n的值
    printf("请输入N的值：");
    scanf("%d", &n);
    int a;
    a=DAC(n);
    printf("\n第N项为%d,比较次数为%d", a, num); //调用递归求解斐波那第n项
}
