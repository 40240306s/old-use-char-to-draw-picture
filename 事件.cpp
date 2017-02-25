#include<windows.h>
#include<stdio.h>
#include"space.h"
#include"tool.h"
#include"comm.h"
char colarr[8]= {14,13,12,11,10,9,6,5};
unsigned char useeve=0,noweve=0,evecol=0,evenum=0;
bool evetyp=0,hideve=0;

void puteve(char (*a)[80],unsigned char (*b)[80])
{
    put(a);
    for(int i=0; i<bouy; i++)
    {
        for(int j=0; j<boux; j++)
        {
            useeve=b[i][j];
            if(useeve)
            {
                to(0+j,3+i);
                if(midd(128*evetyp,127+128*evetyp,useeve))
                {
                    cc(colarr[(useeve/16)%8]);
                    printf("%x",useeve%16);
                    cc(15);
                }
                else if(hideve)
                {
                    cc(12);
                    printf("X");
                    cc(15);
                }
            }
        }
    }
}

void chevenum(int  x,int y,int a)
{
    to(x,y);
    cc(colarr[evecol]);
    for(int i=0; i<16; i++)
        printf("%x",i);
    clsblock(x,x+15,y+1,y+1);
    cc(15);
    to(x+a,y+1);
    printf("+");
}

void chevecol(int  x,int y,int a)
{
    to(x,y);
    for(int i=0; i<8; i++)
    {
        cc(colarr[i]);
        printf("#");
    }
    cc(15);
    clsblock(x,x+15,y+1,y+1);
    to(x+a,y+1);
    printf("+");
}


void m4()
{
    if(!(neve[c.Y-3][c.X]||noweve==0))
    {
        neve[c.Y-3][c.X]=noweve;
        to(c);
        cc(colarr[evecol]);
        printf("%x",evenum);
    }
    else
    {
        to(53,29);
        cc(colarr[(useeve/16)%8]);
        printf("%3d",neve[c.Y-3][c.X]);
    }
    cc(15);
}
void u4()
{
    if(c.Y==27)
    {
        if(midd(25,33,c.X))
        {
            to(30,27);
            printf((evetyp=(evetyp?0:1))?"自動":"被動");
            to(10,27);
            printf("{%3d}",noweve=evecol*16+evenum+(evetyp?128:0));
            puteve(nmap,neve);
        }
        if(midd(40,45,c.X))
        {
            renew(neve,leve);
            puteve(nmap,neve);
        }
        else if(midd(55,58,c.X))
        {
            for(int i=0; i<bouy; i++)
                for(int j=0; j<boux; j++)
                    if(neve[i][j])neve[i][j]>127?0:neve[i][j]=0;
            puteve(nmap,neve);
        }
        else if(midd(61,64,c.X))
        {
            for(int i=0; i<bouy; i++)
                for(int j=0; j<boux; j++)
                    if(neve[i][j])neve[i][j]>127?neve[i][j]=0:0;
            puteve(nmap,neve);
        }
        else if(midd(67,70,c.X))
        {
            charemp(neve,0);
            puteve(nmap,neve);
        }
    }
    else if(midd(28,31,c.Y)&&midd(6,21,c.X))
    {
        if(c.Y==28)chevenum(6,28,evenum=c.X-6);
        else if(c.Y==30&&midd(6,13,c.X))chevecol(6,30,evecol=c.X-6);
        to(0,27);
        printf("目前:");
        cc(colarr[evecol]);
        printf("%x",evenum);
        cc(15);
        to(10,27);
        printf("{%3d}",noweve=evecol*16+evenum+(evetyp?128:0));
    }
    else if(c.Y==29)
    {
        if(midd(25,32,c.X))
        {
            to(31,29);
            printf((hideve=hideve?0:1)?"是":"否");
            puteve(nmap,neve);
        }
        else if(midd(40,55,c.X))
        {
            chevenum(6,28,evenum=0);
            chevecol(6,30,evecol=0);
            to(0,27);
            printf("目前:");
            cc(colarr[evecol]);
            printf("%x",evenum);
            cc(15);
            to(10,27);
            printf("{%3d}",noweve=0);
            to(30,27);
            printf("被動");
            evetyp=0;
        }
    }
}
void c4()
{
    puteve(nmap,neve);
    clstool();
    to(0,27);
    printf("目前:");
    cc(colarr[evecol]);
    printf("%x",evenum);
    cc(15);
    to(10,27);
    printf("{%3d}",noweve);
    to(25,27);
    printf("事件:");
    printf(evetyp?"自動":"被動");
    to(40,27);
    printf("恢復鈕");
    to(50,27);
    printf("歸零:被動  自動  全部");
    to(40,29);
    printf("此處事件編號:");
    to(0,28);
    printf("字碼:");
    chevenum(6,28,evenum);
    to(25,29);
    printf("顯示X:");
    printf(hideve?"是":"否");
    to(0,30);
    printf("顏色:");
    chevecol(6,30,evecol);

}
void d4()
{
    if(neve[c.Y-3][c.X])
    {
        neve[c.Y-3][c.X]=0;
        to(c);
        printf("%c",nmap[c.Y-3][c.X]);
    }
}
