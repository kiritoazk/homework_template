//冒泡排序C实现
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//rand()函数生成随机数
void RandomLGC(int *list,int n,int l,int r)   //生成范围在l~r的随机数
{
	srand(time(0));                     //设置时间种子
	for(int i=0;i<n;i++){
		list[i]=rand()%(r-l+1)+l;          //生成区间r~l的随机数
	}
}

void BubbleSort(int list[], int n) {
        int i, j, temp,sum=0;
        for (i = 0; i < n - 1; i++){//一趟排序
                for (j = 0; j < n - 1 - i; j++){//每趟比较次数
                        if (list[j] > list[j + 1]) {//交换两个数的位置
                                temp = list[j];
                                list[j] = list[j + 1];
                                list[j + 1] = temp;
                        }
                }
                sum=sum+n-1-i;//比较次数
        }
        printf("\n冒泡排序后的数组为：");
        for (int i = 0; i < n; i++){
            printf("%d ",list[i]);
        }
        printf("\n冒泡排序比较次数为：%d\n",sum);
}


int main(){
        int n;  //数组元素的个数，即生成随机数的个数
        printf("请输入生成随机数的个数：");
        scanf("%d",&n);
	int list[n];
	RandomLGC(list,n,1,100000);//生成随机数的通常范围为0~32767，这里通过取模控制取值为0~100000
        int len = (int) sizeof(list) / sizeof(*list);
        printf("随机生成的数组为：");
        for (int i = 0; i < len; i++){
                 printf("%d ",list[i]);
        }
        BubbleSort(list, len);
        return 0;
}
