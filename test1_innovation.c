#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <windows.h>//这个头文件能用Sleep，单位是毫秒
//直接宏定义，方便修改
//我也问了问，也可以用枚举来存变量，但我还是不太懂枚举
#define MONITOR_MS 8000
#define LED_ON 1
#define LED_OFF 0
#define T_MS 4000
#define KEY1 111
#define KEY2 222
#define KEY3 333

void led_blink(int T,int t)//用一个函数来实现会重复调用的灯闪烁，更方便。T周期，t时间
{
    int times=t/T;//次数
    for (int i=0;i<times;i++)
    {
        printf("\r%d\a",LED_ON);//\r是光标移动到行首，\a是发出警告声，1，0表示灯亮灭
        fflush(stdout);//printf 不带\n 时内容留在缓冲区，不刷屏屏幕就不会更新。这里有 \r不能加\n
        Sleep(T/2);
        
        printf("\r%d\a",LED_OFF);
        fflush(stdout);
        Sleep(T/2);
    }
    printf("\n");
}

void alarm()//保留alarm，表示是报警而不是普通闪烁
{
    led_blink(T_MS/2,MONITOR_MS);

    //下面是我没写函数时重复的

    // for (int i=0;i<MONITOR_MS/T_MS*2;i++)//8秒内闪烁4次
    //     {
    //         printf("\r1\a");
    //         fflush(stdout);
    //         Sleep(T_MS/4);///4表示频率*2

    //         printf("\r0\a");
    //         fflush(stdout);
    //         Sleep(T_MS/4);
    //     }
}

int main()
{
    //上电初始化
    printf("班级:263  姓名:帅哥（张烨超）  学号:5913126087\n");
    Sleep(1000);
    system("cls");
    printf("即将开始进行温度检测\n");

    while(1)
    {
        //进行检测
        led_blink(T_MS,MONITOR_MS);
        //下面是我没写函数时重复的

        //for (int i=0;i<MONITOR_MS/T_MS;i++)
        // {
        //     printf("\r1\a");//\r是光标移动到行首，\a是发出警告声，1，0表示灯亮灭
        //     fflush(stdout);
        //     Sleep(T_MS/2);

        //     printf("\r0\a");
        //     fflush(stdout);
        //     Sleep(T_MS/2);
        // }
        //printf ("\n");

        int a=0;
        printf("请输入111(温度处于安全范围)，222(温度超过安全范围 )，333(系统断电退出)\n");
        scanf("%d",&a);
        switch (a)
        {
        case KEY1:
            printf("safe\n");
            while(1)//进入二级菜单再选择
            {
                int cmd=0;
                printf("1-强制报警  2-维持原状态  3-退出系统\n");
                scanf("%d",&cmd);
                switch (cmd)
                {
                case 1:
                    printf("强制报警\n");
                    alarm();//报警
                    break;
                case 2:
                    printf("维持原状态\n");
                    break;
                case 3:
                    printf("退出系统\n");
                    return 0;
                default:
                    printf("无效\n");
                    return 0;//输错直接结束，如果想要能返回重新输一遍的话，我问了AI，看不懂它的方法，外层的default也是一样
                }
            }
            break;
        case KEY2://报警，并进行下一次测试
            alarm();
            Sleep(2000);
            printf("即将再次进行检测\n");
            Sleep(2000);
            break;//到while（1）中进行下一次检测
        case KEY3:
            return 0;//直接结束
        default:
            printf("传回的值有误\n");
            return 0;
        }
    }

    return 0;
}