#include<windows.h>
#include<stdio.h>
#include"space.h"
#include"tool.h"
#include"comm.h"
char usechar=0;
bool usecol=0;
void put(char (*a)[80])
{
    COORD nc= {0,3};
    USHORT sx=boux,sy=bouy,colo[sx+1];
    for(int i=0;i<sx;++i)colo[i]=15;
    char *p=a[0];
    for(UCHAR i=0; i<sy; ++i)
    {
        WriteConsoleOutputCharacter(ohandle,(LPCSTR)(p+i*80),sx,nc,&dword);
        WriteConsoleOutputAttribute(ohandle,colo,sx, nc,&dword);
        ++nc.Y;
    }
}


void m1()
{
    nmap[c.Y-3][c.X]=usechar;
    to(c);
    printf("%c",usechar);
}
void u1()
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
        else if(midd(60,65,c.X))
        {
            to(65,27);
            printf((usecol=usecol?0:1)?"O":"X");
            usecol?putcol(nmap,ncol):put(nmap);
        }
    }
    else if(midd(28,31,c.Y)&&midd(0,32,c.X))
    {
        to(5,27);
        printf("%c",usechar=chara[c.Y-28][c.X]);
    }
}


void c1()
{
    clstool();
    usecol?putcol(nmap,ncol):put(nmap);
    to(0,27);
    printf("¨Ï¥Î:%c",usechar);
    to(40,27);
    printf("«ì´_¶s");
    to(50,27);
    printf("Âk¹s¶s");
    to(60,27);
    printf("ÃC¦â:");
    printf(usecol?"O":"X");
    for(int i=0; i<4; i++)
    {
        to(0,28+i);
        for(int j=0; j<33; j++)
            putchar(chara[i][j]);
    }
}

void d1()
{
    if(nmap[c.Y-3][c.X])
    {
        to(c);
        printf(" ");
        nmap[c.Y-3][c.X]=0;
    }
}
