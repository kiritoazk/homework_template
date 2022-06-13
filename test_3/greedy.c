//背包问题，贪心算法C实现
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void package(float P[], float w[], int M,int n);//贪心算法
//void package(int n,float c,float v[],float w[],int x[]);
void RandomWeight(float *list, int n, int l, int r);//随机生成n个数，每个数的范围在[l,r]之间
void RandomValue(float *list, int n, int l, int r);//随机生成n个数，每个数的范围在[l,r]之间
void sortkp(float pw[],int index[], float w[],float v[],int M,int n);//按照价值排序


int main(){
  int n;
  int M;

  clock_t begin, end;
  double cost;

  printf("请输入物品个数：");
  scanf("%d",&n);
  printf("请输入背包最大容量：");
  scanf("%d",&M);
  float v[n];
  float w[n];
  //开始记录

  begin = clock();

  RandomWeight(w,n,1,100);
  RandomValue(v,n,1,100);

  float pw[n];
  int x[n];
  sortkp(pw,x,w,v,M,n);
  //package(v,w,c,n);
  end = clock();
  cost = (double)(end - begin)*1000/CLOCKS_PER_SEC;
  //CLOCKS_PER_SEC=1000,它用来表示一秒钟会有多少个时钟计时单元，
  //时钟计时单元的长度为1毫秒，clock()/CLOCKS_PER_SEC就是将毫秒转化为秒。

  printf("\n运行时间: %lf ms",cost);
  printf("\n");
  return 0;
}

void package(float P[], float w[], int M,int n)
{
  printf("%d\n",M);
  int i;
  float x[n];
  for (i = 0; i < n; i++)
  {
    x[i] = 0; //初始状态，所有物品都没有被放入背包
  }
  float cu=M;   //cu是背包剩余重量
  for (i = 0; i < n; i++)
  {
    if (w[i] > cu)
    {
      break;
    }
    x[i] = 1;
    cu = cu - w[i];
    //printf("放入第%d件物品，背包剩余容量%f.\n", (i + 1), cu);
  }

  if (i < n) //还可以放入一个物品的一部分
  {
    x[i] = cu / w[i];
    //printf("\n放入第%d件物品的%f部分.背包剩余容量为0.\n", (i + 1), w[i] * x[i]);
  }
  printf("\n问题的最优解为：\n");
  for (i = 0; i < n; i++)
  {
   printf("%f ", x[i]);
  }
  float sum=0;
  for (i = 0; i < n; i++)
  {
    sum=sum+x[i]*P[i];
  }
  printf("\n最优解的价值为：%f\n",sum);
}

void RandomWeight(float *list, int n, int l, int r) //生成范围在l~r的随机物品重量
{
  int seed = time(NULL);
  srand(seed); //设置时间种子
  for (int i = 0; i < n; i++)
  {
    list[i] = (float)(rand() % (r - l + 1) + l); //生成区间r~l的随机数
  }
  printf("随机生成的物品重量为：\n");
  for (int i = 0; i < n; i++)
  {
    printf("%f ", list[i]);
  }
}

void RandomValue(float *list, int n, int l, int r) //生成范围在l~r的随机随机物品价值
{
  int seed = 1;
  srand(seed); //设置时间种子
  for (int i = 0; i < n; i++)
  {
    list[i] = (float)(rand() % (r - l + 1) + l); //生成区间r~l的随机数
  }
  printf("\n随机生成的物品价值为：\n");
  for (int i = 0; i < n; i++)
  {
    printf("%f ", list[i]);
  }
}


//排序
void sortkp(float pw[],int index[], float w[],float v[],int M,int n)
{
  for(int i=0;i<n;i++)
  {
   pw[i]=v[i]/w[i];
   index[i]=i;
  }
  float temp=0;
  for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (pw[i] < pw[j])   //对价值/重量数组按递增进行排序
                {
                    temp = pw[i];
                    pw[i] = pw[j];
                    pw[j] = temp;
                    int x = index[i];       //交换相应的数组下标
                    index[i] = index[j];
                    index[j] = x;
                }
            }
        }
        float w1[n];
        float v1[n];
        for(int i=0;i<n;i++)
        {
          w1[i]=w[index[i]];
          v1[i]=v[index[i]];
        }
        printf("\n各物品价值/重量的值：\n");
        for(int i=0;i<n;i++)
        {
          printf("%f ",pw[i]);
        }
        printf("\n相应重量数组为：\n");
        for(int i=0;i<n;i++)
        {
          printf("%f ",w1[i]);
        }
        printf("\n相应价值数组为：\n");
        for(int i=0;i<n;i++)
        {
          printf("%f ",v1[i]);
        }
        printf("%d\n",M);
        package(v1,w1,M,n);
}

