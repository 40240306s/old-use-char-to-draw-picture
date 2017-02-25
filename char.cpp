#include<windows.h>
#include<stdio.h>
#include"space.h"
#include"tool.h"
#include"comm.h"
void put(char (*a)[80])
{
    for(int i=0; i<bouy; i++)
    {
        to(0,3+i);
        for(int j=0; j<boux; j++)
            printf("%c",a[i][j]);
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
            if(usecol)
            {
                to(65,27);
                printf("X");
                usecol=0;
                put(nmap);
            }
            else
            {
                usecol=1;
                to(65,27);
                printf("O");
                putcol(nmap,ncol);
            }
        }
    }
    else if(midd(28,31,c.Y)&&midd(0,32,c.X))
    {
        usechar=chara[c.Y-28][c.X];
        to(6,27);
        printf("%c",usechar);
    }
}


void d1()
{
    to(c);
    printf(" ");
    nmap[c.Y-3][c.X]=0;
}
