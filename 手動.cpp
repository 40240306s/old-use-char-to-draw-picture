#include<windows.h>
#include<stdio.h>
#include"space.h"
#include"tool.h"
#include"comm.h"
bool usescanf=0;
void m2()
{
    hide(1);
    to(c);
    printf("X");
    char s[100];
    to(0,29);
    if(usescanf)
    {
        printf("輸入行數:");
        int amo=0;
        scanf("%d",&amo);
        clsbar(29,30);
        fflush(stdin);
        to(0,29);
        COORD nowc=c;
        for(int i=0; i<amo; ++i)
        {
            to(0,29+i);
            gets(s);
            to(nowc);
            int l=nowc.X+strlen(s);
            if(l>=boux)l=boux;
            for(int i=nowc.X; i<l; i++)
                printf("%c",s[i-nowc.X]);
            for(int i=nowc.X; i<l; i++)
                nmap[nowc.Y-3][i]=s[i-nowc.X];
            ++nowc.Y;
        }
        clsbar(29,29+amo);
    }
    else
    {
        gets(s);
        to(c);
        int l=c.X+strlen(s);
        if(l>=boux)l=boux;
        for(int i=c.X; i<l; i++)
            printf("%c",s[i-c.X]);
        for(int i=c.X; i<l; i++)
            nmap[c.Y-3][i]=s[i-c.X];
    clsbar(29,30);
    }
    hide(0);
}

void u2()
{
    if(c.Y==27)
    {
        if(midd(40,45,c.X))
        {
            renew(nmap,lmap);
            put(nmap);
        }
        else if(midd(50,55,c.X))
        {
            charemp(nmap,0);
            put(nmap);
        }

    }
    if(c.Y==28&&midd(0,11,c.X))
    {
        to(0,28);
        printf("緩衝輸入:");
        printf((usescanf=usescanf?0:1)?"開":"關");
    }
}

void c2()
{
    put(nmap);
    clstool();
    to(0,27);
    printf("輸入文字區");
    to(0,28);
    printf("緩衝輸入:");
    printf(usescanf?"開":"關");
    to(40,27);
    printf("重做鈕");
    to(50,27);
    printf("歸零鈕");
}
void d2()
{
    if(nmap[c.Y-3][c.X])
    {
        to(c);
        printf(" ");
        nmap[c.Y-3][c.X]=0;
    }
}
