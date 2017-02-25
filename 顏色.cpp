#include<windows.h>
#include<stdio.h>
#include"space.h"
#include"tool.h"
#include"comm.h"
char col=15,bcol=0;
DWORD dword;
void putcol(char (*a)[80],USHORT (*b)[80])
{
    USHORT*t=&b[0][0];
    char*p=&a[0][0];
    COORD coor;
    coor.X=0;
    for(UCHAR i=0; i<bouy; i++)
    {
        coor.Y=i+3;
        WriteConsoleOutputCharacter(ohandle,(LPCSTR)(p+i*80),boux,coor,&dword);
        WriteConsoleOutputAttribute(ohandle,(t+i*80) ,boux, coor,&dword);
    }
}


void chcol(int  x,int y,int a)
{
    to(x,y);
    for(int i=0; i<16; i++)
    {
        cc(i);
        printf("#");
    }
    clsblock(x,x+15,y+1,y+1);
    to(x+a,y+1);
    printf("+");
}
int nowcol=15;
void m5()
{
    ncol[c.Y-3][c.X]=nowcol;

    WriteConsoleOutputAttribute(ohandle,&ncol[c.Y-3][c.X] ,1, c,&dword);
}

void u5()
{
    if(c.Y==27)
    {
        if(midd(20,25,c.X))
        {
            chcol(6,28,col=15);
            chcol(6,30,bcol=0);
            cc(nowcol=15);
            to(5,27);
            printf("#");
        }
        else if(midd(30,35,c.X))
        {
            putcol(nmap,ncol);
        }
        else if(midd(40,45,c.X))
        {
            renew(ncol,lcol);
            putcol(nmap,ncol);
        }
        else if(midd(50,55,c.X))
        {
            charemp(ncol,15);
            put(nmap);
        }
    }
    else if(midd(28,31,c.Y)&&midd(6,21,c.X))
    {
        if(c.Y==28)
            chcol(6,28,col=c.X-6);
        else if(c.Y==30)
            chcol(6,30,bcol=c.X-6);
        to(5,27);
        cc(nowcol=col+16*bcol);
        printf("#");
        cc(15);
    }
}
void c5()
{
    clstool();
    putcol(nmap,ncol);
    to(0,27);
    printf("現在:");
    cc(nowcol);
    printf("#");
    cc(15);
    to(20,27);
    printf("選白色");
    to(30,27);
    printf("重刷鈕");
    to(40,27);
    printf("恢復鈕");
    to(50,27);
    printf("歸零鈕");
    to(0,28);
    printf("文字:");
    chcol(6,28,col);
    to(0,30);
    printf("背景:");
    chcol(6,30,bcol);
}
void d5()
{
    if(ncol[c.Y-3][c.X]!=15)
    {
        ncol[c.Y-3][c.X]=15;
        WriteConsoleOutputAttribute(ohandle,&ncol[c.Y-3][c.X] ,1, c,&dword);
    }
}
