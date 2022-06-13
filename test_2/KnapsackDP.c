//0-1背包动态规划
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int max(int a,int b);  //求最大值
int F[10000][10000];  //前i个物品装入容量为j的背包中获得的最大价值

//使用两个随机生成函数，设置不同的时间种子，以便产生不同的随机数
 void RandomW(int *list,int n,int l,int r)   //生成范围在l~r的随机物品重量
{
    int seed=time(NULL);
	srand(seed);                     //设置时间种子
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //生成区间r~l的随机数
	}
    for (int i = 0; i < n; i++){
        printf("%d ",list[i]);
    }
}

void RandomV(int *list,int n,int l,int r)   //生成范围在l~r的随机随机物品价值
{
    int seed=1;
	srand(seed);                     //设置时间种子
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //生成区间r~l的随机数
	}
    for (int i = 0; i < n; i++){
        printf("%d ",list[i]);
    }
}
int max(int a,int b){
   if(a>=b)
       return a;
   else return b;
}

int KnapSackDP(int n,int weight[],int value[],int C){

	//填表,其中第一行和第一列全为0,即 F(i,0)=F(0,j)=0；
    for(int i=0;i<=n;i++){
        F[i][0]=0;
    }
    for(int j=0;j<=C;j++){
        F[0][j]=0;
    }
    //用到的矩阵部分V[n][C] ,下面输出中并不输出 第1行和第1列

	printf("\n编号 重量 价值 \n ");

    for(int i=1;i<=n;i++){
		printf("%2d   %2d   %2d    \n ",i,weight[i-1],value[i-1]);   // (weight与value都是从0开始存的，所以开始i=1时对应0的位置)
    }
    printf("\n0—1背包动态规划表:\n");
    for(int i=1;i<=C;i++){
		printf("%2d   ",i);
    }
    printf("\n\n");

    for(int i=1;i<=n;i++){

        for(int j=1;j<=C;j++){
            if(j<weight[i-1]){                                  //包的容量比该商品体积小，装不下，此时的价值与前i-1个的价值是一样的
				F[i][j]=F[i-1][j];
				printf("%2d   ",F[i][j]);
			}
            else{                                             //还有足够的容量可以装该商品，但装了也不一定达到当前最优价值，所以在装与不装之间选择最优的一个
                F[i][j]=max(F[i-1][j],F[i-1][j-weight[i-1]]+value[i-1]);
				printf("%2d   ",F[i][j]);
			}
		}
		printf("\n");
	}

        return F[n][C];

}

void Judge(int C,int n,int weight[]){	//判断哪些物品被选中
    int j=C;
    int *state=(int *)malloc(n*sizeof(int));

    for(int i=n;i>=1;i--){
	    if(F[i][j]>F[i-1][j]){  //如果装了就标记，然后减去相应容量
				state[i]=1;
				j=j-weight[i-1];
	        }
	    else
	        state[i]=0;
    }
    printf("选中的物品编号是:");
    for(int i=1;i<=n;i++)
        if(state[i]==1)
        	printf("%d ",i);
    printf("\n");
}



int main(){

    int n;         //物品数量
    int Capacity;  //背包最大容量

    printf("请输入背包的最大容量:");
    scanf("%d",&Capacity);

    printf("输入物品数:");
    scanf("%d",&n);

    int weight[n];//每个物品的重量
    int value[n];//每个物品的价值

    clock_t begin, end;//程序的起始时间
    double cost;//程序的运行时间

    printf("随机生成物品的重量为：\n");
    RandomW(weight,n,1,100);//通过调用随机函数生成随机物品

    printf("\n随机生成物品的价值:\n");
    RandomV(value,n,1,100);
    begin = clock();//记录开始时间
    int reslut=KnapSackDP(n,weight,value,Capacity);  //获得的最大价值

    Judge(Capacity,n,weight);  //判断那些物品被选择
    printf("最大价值为:%d\n",reslut);
    end = clock();//记录结束时间
    cost = (double)(end - begin)*1000/CLOCKS_PER_SEC;
    printf("\n算法运行时间: %lf ms",cost);
    return 0;
}

