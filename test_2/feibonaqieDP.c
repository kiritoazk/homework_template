#include <stdio.h>
#include<stdlib.h>
int num=0;//记录比较次数
//动态规划求解
int DP(int n)
{
    int f[n],i;
    for(i=1; i<=n; i++)
    {
        if(i==1||i==2)
        {
            num++;
            f[i]=1;
        }
        else
        {
            num++;
            f[i]=f[i-1]+f[i-2];
        }
    }
    return f[n];
}
int main()
{
    int n; //接受用户输入的n的值
    printf("请输入N的值：");
    scanf("%d", &n);
    int a;
    a=DP(n);
    printf("\n第N项为%d,比较次数为%d", a, num); //调用动态规划求解斐波那第n项
    return 1;
}
