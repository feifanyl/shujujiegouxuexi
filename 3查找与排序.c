#include "stdio.h"
#include "stdlib.h"
//创建数组
int *CreateArr(int num){
    int *r;
    int tmp;
    if(num<0){
        return NULL;
    }
    r=(int *) malloc(sizeof(int)*num);
    for (int i = 0; i < num; i++) {
        printf("请输入%d的值:",i+1);
        scanf("%d",&tmp);
        r[i]=tmp;
    }
    return r;
}
//打印数组
void prn(int arr[],int num){
    for(int i=0;i<num;i++){
        printf("%d",arr[i]);
    }
}
//直接插入排序
int *InsertSort(int arr[],int num){
    for(int i=1;i<num;i++){
        if(arr[i]<arr[i-1]){
            int j= i-1;
            int x = arr[i];
            while(j>-1 && x < arr[j]){  //采用顺序查找方式找到插入的位置，在查找的同时，将数组中的元素进行后移操作，给插入元素腾出空间
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = x;
        }
    }
    return arr;
}
//直接选择排序
int *SelectSort(int arr[],int num){
    int i,j,k,index;    //定义变量
    for(i=0;i<num-1;i++)   //遍历
    {
        k=i;
        for(j=i+1;j<num;j++)    //j初始不为0，冒泡初始为0，所以选排比冒泡快，但不稳定
        {
            if(arr[j]<arr[k])   //顺序从这里改顺序 小到大"<",大到小">" ！！！
                k=j;      //这里是区分冒泡排序与选择排序的地方，冒泡没这句
        }
        if(k!=j)    //为了严谨，去掉也行
        {
            index=arr[i];   //交换R[i]与R[k]中的数
            arr[i]=arr[k];    //简单的交换c=a,a=b,b=c
            arr[k]=index;
        }
    }
    return arr;
}
//冒泡排序
int *BubbleSort(int arr[], int num){
    int i,j,temp;    //定义三个整型变量
    for (j=0;j<num-1;j++)    //用一个嵌套循环来遍历一遍每一对相邻元素 （所以冒泡函数慢嘛，时间复杂度高）
    {
        for (i=0;i<num-1-j;i++)
        {
            if(arr[i]>arr[i+1])  //从大到小排就把左边的">"改为"<" ！！！
            {
                temp=arr[i];      //a[i]与a[i+1](即a[i]后面那个) 交换
                arr[i]=arr[i+1];    //基本的交换原理"c=a;a=b;b=c"
                arr[i+1]=temp;
            }
        }
    }
    return arr;
}
//递归的快速排序
void quicksort(int arr[],int low,int high)
{
    int i=low;
    int j=high;
    int temp=arr[i];
    if(low<high)
    {
        while(i<j)       //当i=j时结束循环
        {
            while((arr[j]>=temp)&&(i<j))   //处理右边
            {
                j--;
            }
            arr[i]=arr[j];
            while((arr[i]<=temp)&&(i<j))      //处理左边
            {
                i++;
            }
            arr[j]=arr[i];
        }
        arr[i]=temp;
        //第一轮结束，递归调用。i-1和j+1是因为中间数已经排好，不用再次递归
        quicksort(arr,low,i-1);
        quicksort(arr,j+1,high);
    }
    else
        return ;
}
//折半查找
int BinSearch(int arr[],int len,int key)             //折半查找法（二分法）
{
    int low=0;             //定义初始最小
    int high=len-1;         //定义初始最大
    int mid;              //定义中间值
    while(low<=high)
    {
        mid=(low+high)/2;       //找中间值
        if(key==arr[mid])        //判断min与key是否2020111122411718相等
            return mid;
        else if(key>arr[mid])       //如果key>mid 则新区间为[mid+1,high]
            low=mid+1;
        else                    //如果key<mid 则新区间为[low,mid-1]
            high=mid-1;
    }
    return -1;               //如果数组中无目标值key，则返回 -1 ；
}
int main(void){
    int select=1;
    int num;
    int key;
    int *arr;
    do {
        printf("\n*************************************************************\n"
               "主菜单如下:\n"
               "select 1:输入待排序的元素值\n"
               "select 2:直接插入排序\n"
               "select 3:直接选择排序\n"
               "select 4:冒泡排序\n"
               "select 5:递归的快速排序\n"
               "select 6:折半查找\n"
               "select 7:显示元素序列\n"
               "select 0:退出\n"
               "input your select(0-6): "
        );
        scanf("%d",&select);
        getchar();
        switch (select) {
            case 1:
                printf("请输入带排序元素个数:");
                scanf("%d",&num);
                getchar();
                arr= CreateArr(num);
                break;
            case 2:
                printf("直接插入排序\n");
                InsertSort(arr,num);
                break;
            case 3:
                printf("直接选择排序:\n");
                SelectSort(arr,num);
                break;
            case 4:
                printf("冒泡排序:\n");
                BubbleSort(arr,num);
                break;
            case 5:
                printf("递归的快速排序");
                quicksort(arr,0,num-1);
                break;
            case 6:
                printf("折半查找,请输入要查找的值:\n");
                scanf("%d",&key);
                printf("要查找值所在位置为:%d",BinSearch(arr,num,key));
                break;
            case 7:
                printf("显示元素序列:\n");
                prn(arr,num);
                break;
            case 0:select=0;
                break;
            default:
                printf("输入错误");
                select=1;
                break;
        }
        if(select==0){
            break;
        }
    } while (1);
}
