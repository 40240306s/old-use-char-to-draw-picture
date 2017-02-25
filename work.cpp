
#include<stdio.h>
#include<windows.h>
#include"tool.h"
#include"space.h"
#include"showmap.h"
#include"file.h"
#include"forwork.h"

char modnam[6][12]= {"","字符繪圖  ","鍵盤輸入  ","空間模式  ","事件模式  ","顏色模式  "};
void word(int colar)
{
    to(0,2);
    for(int i=1; i<6; i++)
    {
        cc(15);
        if(colar==i)cc(14);
        printf(modnam[i]);
    }
    cc(15);
}


void cmode(int a)
{
    for(int i=1; i<=5; i++)
        if(a<i*10-2)
        {
            nowmode=i;
            break;
        }
    word(nowmode);
}

void(*mode[6])()= {0,m1,m2,m3,m4,m5};

void(*use[6])()= {0,u1,u2,u3,u4,u5};

void(*cha[6])()= {0,c1,c2,c3,c4,c5};

void(*del[6])()= {0,d1,d2,d3,d4,d5};

void charemp(char(*b)[80],int n)
{
    for(int i=0; i<23; i++)
        for(int j=0; j<80; j++)
            b[i][j]=n;
}
void charemp(unsigned char(*b)[80],int n)
{
    for(int i=0; i<23; i++)
        for(int j=0; j<80; j++)
            b[i][j]=n;
}
void charemp(USHORT(*b)[80],int n)
{
    for(int i=0; i<23; i++)
        for(int j=0; j<80; j++)
            b[i][j]=n;
}

void renew(char (*a)[80],char(*b)[80])
{
    for(int i=0; i<bouy; i++)
        for(int j=0; j<boux; j++)
            a[i][j]=b[i][j];
}

void renew(unsigned char (*a)[80],unsigned char (*b)[80])
{
    for(int i=0; i<bouy; i++)
        for(int j=0; j<boux; j++)
            a[i][j]=b[i][j];
}
void renew(USHORT (*a)[80],USHORT (*b)[80])
{
    for(int i=0; i<bouy; i++)
        for(int j=0; j<boux; j++)
            a[i][j]=b[i][j];
}
void putfilename(int x,int y)
{
    clsblock(x,79,y,y);
    to(x,y);
    printf("檔名:%s%s",filename,fileaname);
}
void putname(int x,int y)
{
    to(x,y);
    printf("檔名:%s",filename);
}

void mo(char a)
{
    char d=a-'D';
    switch(a)
    {
    case'A':
        newopen();
        break;
    case'B':
        load();
        break;
    case'C':
        save();
        break;
    case'D':
        ex=1;
        break;
    case'E':
    case'F':
    case'G':
    case'H':
    case'I':
        if(nowmode!=d)
        {
            nowmode=d;
            word(nowmode);
            cha[nowmode]();
        }
        break;
    }
}

void clstool()
{
    clsbar(27,31);
}



