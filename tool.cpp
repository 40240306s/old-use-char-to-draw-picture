#include <windows.h>
#include <stdio.h>
HANDLE ohandle=GetStdHandle(STD_OUTPUT_HANDLE);
void to(int x, int y)
{
    COORD xy;
    xy.X=x;
    xy.Y=y;
    SetConsoleCursorPosition(ohandle,xy);
}
void to(COORD c)
{
    SetConsoleCursorPosition(ohandle,c);
}
//顏色表:0黑.1深藍.2深綠.3藍綠.4暗紅.5暗紫.6黃綠
//7正常.8灰色.9正藍.10正綠.11青藍.12亮紅.13亮紫.14黃
//15.白
void cc(int i)//改顏色
{
    SetConsoleTextAttribute(ohandle,i);
}
void cc(int i,int j)//改顏色(字,背景)
{
    cc(i+j*16);
}
//是否顯示游標
void hide(bool i)//0關掉1打開
{
    CONSOLE_CURSOR_INFO c= {25,i};//{指標大小,是否值}
    SetConsoleCursorInfo(ohandle, &c);
}
//用鍵盤指令全螢幕: 1小 2大
void ws(short a)
{
    if(a==2)
    {
        keybd_event(0x12,MapVirtualKey(0x12, 0),0,0);
        keybd_event(0x20,MapVirtualKey(0x20, 0),0,0);
        keybd_event(0x58,MapVirtualKey(0x58, 0),0,0);
        keybd_event(0x12,MapVirtualKey(0x12, 0),KEYEVENTF_KEYUP,0);
        keybd_event(0x20,MapVirtualKey(0x20, 0),KEYEVENTF_KEYUP,0);
        keybd_event(0x58,MapVirtualKey(0x58, 0),KEYEVENTF_KEYUP,0);
    }
    else if(a==1)
    {
        keybd_event(0x12,MapVirtualKey(0x12, 0),0,0);
        keybd_event(0x20,MapVirtualKey(0x20, 0),0,0);
        keybd_event('R',MapVirtualKey('R', 0),0,0);
        keybd_event(0x12,MapVirtualKey(0x12, 0),KEYEVENTF_KEYUP,0);
        keybd_event(0x20,MapVirtualKey(0x20, 0),KEYEVENTF_KEYUP,0);
        keybd_event('R',MapVirtualKey('R', 0),KEYEVENTF_KEYUP,0);

    }
}
void mxy(COORD&xy,int& i)
{
    INPUT_RECORD Buffer;
    DWORD        NumberOfEventsRead;
    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &Buffer, 1, &NumberOfEventsRead);
    xy.X =Buffer.Event.MouseEvent.dwMousePosition.X;
    xy.Y =Buffer.Event.MouseEvent.dwMousePosition.Y;
    i = Buffer.Event.MouseEvent.dwButtonState;
}
void cls(int a)
{
    for(int i=3; i<a; i++)
    {
        to(0,i);
        for(int j=0; j<80; j++)
            putchar(' ');
    }
}
void clsblock(int xl,int xu,int yl,int yu)
{
    for(int i=yl; i<=yu; i++)
    {
        to(xl,i);
        for(int j=xl; j<=xu; j++)
            putchar(' ');
    }
}
void clsbar(int yl,int yu)
{
    for(int i=yl; i<=yu; i++)
    {
        to(0,i);
        for(int j=0; j<80; j++)
            putchar(' ');
    }
}

void bar(int k)
{
    for(int i=0; i<k; i++)printf("=");
}
