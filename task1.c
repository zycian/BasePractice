#include <stdio.h>

int main()
{
    printf("1、输出 char、int、short、long、float、double 的大小。\n");
    printf("char=%zu\n", sizeof(char));
    printf("int=%zu\n", sizeof(int));
    printf("short=%zu\n", sizeof(short));
    printf("long=%zu\n", sizeof(long));
    printf("float=%zu\n", sizeof(float));
    printf("double=%zu\n", sizeof(double));

    printf("----------------------------------------------------------------------------------------\n");
    
    printf("2、定义两个 char 类型的变量，一个赋值为 127，一个赋值为 128。再将其以d 输出，看看输出了什么结果，并想想这是为什么？\n");
    char char1=127;
    char char2=128;
    printf("char1=%d\n", char1);
    printf("char2=%d\n", char2);//char2=-128,因为char的范围是-128~127，128超出范围，发生溢出

    printf("----------------------------------------------------------------------------------------\n");

    printf("3、完成一个程序，用于计算阶乘（循环）\n");
    int a=0;
    int res1=1;
    printf ("请输入要进行阶乘的数:");
    scanf ("%d",&a );
    for (int i=1;i<=a;i++)
    {
        res1 =i*res1 ;
    }
    printf("%d!=%d\n",a,res1);

    printf("----------------------------------------------------------------------------------------\n");

    printf ("4、输入一个数，将这个数为数字为偶数的位去除后再输出（选择加循环）\n");
    int b=0;
    printf ("请输入一个多位数");
    scanf ("%d",&b);
    int arr1[16];//int类型16位
    int num=0;
    while (b != 0)
    {
        int b1=b%10;//从个位开始读
        b=b/10;

        if (b1 % 2 != 0)//判断奇偶
        {
            arr1[num]=b1;
            num++;
        }
    }
    for (int i=num-1 ;i>=0;i--)//索引要-1
    {
        printf ("%d",arr1[i]);//遍历只需一个个遍历出数组中的数，不需要考虑位数
    }




    return 0;
}