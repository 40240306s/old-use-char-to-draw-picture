#include<windows.h>
#include<stdio.h>
#include"space.h"
#include"tool.h"
#include"comm.h"

bool space[4]= {0,1,1,0};
unsigned char usespa;
void putspa(char (*a)[80],unsigned char(*b)[80])
{
    put(a);
    for(int i=0; i<bouy; i++)
    {
        for(int j=0; j<boux; j++)
        {
            usespa=b[i][j];
            if(usespa&&space[usespa])
            {
                to(0+j,3+i);
                cc(usespa==1?12:14);
                usespa=a[i][j];
                usespa>32?printf("%c",usespa):printf("X");
                cc(15);
            }
        }
    }
}


void m3()
{
    if(space[3]&&nspa[c.Y-3][c.X])return;
    nspa[c.Y-3][c.X]=(space[0]?2:1);
    to(c);
    cc(space[0]?14:12);
    nmap[c.Y-3][c.X]>32?printf("%c",nmap[c.Y-3][c.X]):printf("X");
    cc(15);
}
void u3()
{
    if(c.Y==27)
    {
        if(midd(0,5,c.X))
        {
            to(4,27);
            printf((space[3]=space[3]?0:1)?"¶}":"Ãö");
        }
        else if(midd(10,16,c.X))
        {
            to(15,27);
            space[0]=(space[0]?0:1);
            cc(space[0]?14:12);
            printf(space[0]?"¶À":"¬õ");
            cc(15);
        }
        else if(midd(20,27,c.X))
        {
            space[1]=(space[1]?0:1);
            to(27,27);
            putchar(space[1]?'O':'X');
            putspa(nmap,nspa);
        }
        else if(midd(30,37,c.X))
        {
            space[2]=space[2]?0:1;
            to(37,27);
            putchar(space[2]?'O':'X');
            putspa(nmap,nspa);
        }
        else if(midd(40,45,c.X))
        {
            renew(nspa,lspa);
            putspa(nmap,nspa);
        }
        else if(midd(50,55,c.X))
        {
            charemp(nspa,0);
            putspa(nmap,nspa);
        }
    }
}
void c3()
{
    putspa(nmap,nspa);
    clstool();
    to(0,27);
    printf("¤¬¥¸");
    printf((space[3]=space[3]?0:1)?"¶}":"Ãö");
    to(10,27);
    printf("ÃC¦â:");
    cc(space[0]?14:12);
     printf(space[0]?"¶À":"¬õ");
    cc(15);
    to(20,27);
    printf("¬õ¦â¼h:");
    putchar(space[1]?'O':'X');
    to(30,27);
    printf("¶À¦â¼h:");
    putchar(space[2]?'O':'X');
    to(40,27);
    printf("«ì´_¶s");
    to(50,27);
    printf("Âk¹s¶s");
}
void d3()
{
    if(nspa[c.Y-3][c.X])
    {
        nspa[c.Y-3][c.X]=0;
        to(c);
        printf("%c",nmap[c.Y-3][c.X]);
    }
}
