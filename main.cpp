#include<stdio.h>
#include<windows.h>
#include"tool.h"
#include"space.h"
#include"work.h"
#include"file.h"
#include <io.h>//mkdir�Ϊ�=>�Ыظ�Ƨ�

int main()
{
    mkdir("mpheader");
    mkdir("mydata");
    charemp(ncol,15);
    charemp(lcol,15);
    hide(0);
    ws(2);
    cc(14,1);
    to(0,1);
    printf("���j�p__�}������__�s��__����    �©��s2015");
    cc(15);
    to(15,0);
    printf("�W��:%2dx%2d",bouy,boux);
    putfilename(30,0);
    to(0,bouy+3);
    bar(boux);
    cha[1]();
    word(1);
    while(!ex)
    {
        mxy(c,click);
        to(0,0);
        printf("�y��:(%2d,%2d) ",c.X,c.Y-3);
        if(click==1)
        {
            if(c.Y<3&&c.X<50)
            {
                mo(menu[c.Y][c.X]);
            }
            else if(midd(3,bouy+2,c.Y)&&c.X<boux)
            {
                mode[nowmode]();
            }
            else if(c.Y>=27)
            {
                use[nowmode]();
            }
        }
        else if(click==2)
        {
            if(midd(3,bouy+2,c.Y)&&c.X<boux)
            {
                del[nowmode]();
            }
        }
    }
}


