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
//�C���:0��.1�`��.2�`��.3�ź�.4�t��.5�t��.6����
//7���`.8�Ǧ�.9����.10����.11�C��.12�G��.13�G��.14��
//15.��
void cc(int i)//���C��
{
    SetConsoleTextAttribute(ohandle,i);
}
void cc(int i,int j)//���C��(�r,�I��)
{
    cc(i+j*16);
}
//�O�_��ܴ��
void hide(bool i)//0����1���}
{
    CONSOLE_CURSOR_INFO c= {25,i};//{���Фj�p,�O�_��}
    SetConsoleCursorInfo(ohandle, &c);
}
//����L���O���ù�: 1�p 2�j
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
