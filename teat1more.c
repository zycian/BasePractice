#include<stdio.h>
int is_draw(void);//用于判断是否平局，即横竖及两对角线是否有5个相同的数
void dfs(int pos,int w);//用于枚举，不返回值，将答案存在ans中送出

int board[5][5];//棋盘，1=白，0=黑
int ans=0;//计数

int is_draw(void)//先写对结果的判断和return再进入分支；通过计数器来统计
{
    
    //检查行
    for(int i=0;i<5;i++)
    {
        int base=board[i][0];//以每行第一个为基准
        int same=1;
    
        for(int j=1;j<5;j++)
        {
            if(board[i][j]!=base)//遍历每行中剩余的数看是否相同
            {
                same=0;//通过same将循环内发生的传出，==0就是表示相同，且会立马跳出
                break;
            }
        }

        if (same==1)//如果same==1，就表示不是平局
        {
            return 0;
        }
    }

    //检查列        与上一个差不多就不写注释了
    for(int i=0;i<5;i++)
    {
        int base=board[0][i];
        int same=1;
    
        for(int j=1;j<5;j++)
        {
            if(board[j][i]!=base)
            {
                same=0;
                break;
            }
        }

        if (same==1)
        {
            return 0;
        }
    }
    //检查对角线,两条分别检查。i和j来遍历行和列
    {
        int base=board[0][0];
        int same=1;

        for (int j = 1; j < 5; j++)
        {
            if (board[j][j] != base)
            {
                same = 0;
                break;
            }
        }

        if (same == 1) 
        return 0;
    }
    //另一条对角线
    {
        int base = board[0 * 5][ 4];
        int same = 1;

        for (int j = 1; j < 5; j++)
        {
            if (board[j][4 - j] != base)
            {
                same = 0;
                break;
            }
        }

        if (same == 1) 
        return 0;
    }
    
    return 1;//平局
}

void dfs(int pos,int w)
{
    if (pos==25)
    {
        if (w==13&&is_draw())//平局条件，if中is_draw返回0就表示不是平局，不符合，返回1才会执行
        {
            ans=ans+1;//25局结束且有13个白棋且使平局则计数器加一
        }
        return;//在下完后退出分支
    }

    //因为用了二维数组所以需要把25格换为行和列
    int row=pos/5;
    int col=pos%5;
    //分出两条叉，一直分分分，直到列出所有可能，在通过前面的循环判断是否满足条件进行筛选
    board[row][col]=0;//第一个下了黑棋
    dfs(pos+1,w);//开始一个分支

    board[row][col]=1;//下了白棋
    dfs(pos+1,w+1);//再开始一个分支
}

int main(void)
{
    dfs(0,0);
    printf("下满且平局的可能有%d\n",ans);

    return 0;
}

/*
不得不说还是挺难的，第一次做枚举题，用了递归的方法，其实我都不太懂，AI帮了很多很多
通过这题我也第一次发现C语言比较切实的用处
虽然很多是AI写的，但是至少注释是我自己写的，二维数组也是我改出来的，
我也是在分析题目找到许多不知道怎么落实的想法才问了AI，怎么判断平局，怎么融入计数器，怎么实现黑一个白一个
但不得不说AI是真好用啊
*/