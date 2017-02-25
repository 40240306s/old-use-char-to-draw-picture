#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include"tool.h"
#include"space.h"
#include"showmap.h"
#include<ctype.h>
#include"comm.h"
bool midd(int low,int up, int n)
{
    return (low<=n&&n<=up);
}
int wordbox(int x,int y,int low,int up)
{
    hide(1);
    to(x,y);
    char a[5]= {0};
    fflush(stdin);
    scanf("%2s",a);
    while((!midd(low,up,atoi(a))))
    {
        to(x,y);
        printf("   必須介在%d~%d",low,up);
        to(x,y);
        fflush(stdin);
        scanf("%2s",a);
    }
    hide(0);
    return atoi(a);
}

extern void(*cha[6])();
void word(int colar);
void newopen()
{
    cls(bouy+4);
    to(0,3);
    printf("輸入規格:左右寬(1~80):");
    boux=wordbox(0,4,1,80);
    to(0,5);
    printf("輸入規格:上下寬(1~23):");
    bouy=wordbox(0,6,1,23);
    to(15,0);
    printf("規格:%2dx%2d",bouy,boux);
    cls(8);
    to(0,bouy+3);
    bar(boux);
    cha[nowmode]();

}
int savex=18,savey=7;
bool susech[3][5]= {{1,1,1,1,1},{1,1,1,0,0},{1,1,1,1,1}};
void putsamesavename(int x,int y)
{
    for(int i=0; i<5; i++)
    {
        to(x,y+i);
        for(int j=0; j<20; j++)
            printf("%c",samesavename[i][j]);
    }
}
void writefile(FILE *f,char (*a)[80])
{
    for(int i=0; i<bouy; i++)
    {
        for(int j=0; j<boux; j++)
            fprintf(f,"%c",a[i][j]);
        fprintf(f,"\n");
    }
}
void writefile(FILE *f,unsigned char (*a)[80])
{
    for(int i=0; i<bouy; i++)
    {
        for(int j=0; j<boux; j++)
            fprintf(f,"%3d,",a[i][j]);
        fprintf(f,"\n");
    }
}
void writefile(FILE *f,USHORT (*a)[80])
{
    for(int i=0; i<bouy; i++)
    {
        for(int j=0; j<boux; j++)
            fprintf(f,"%3d,",a[i][j]);
        fprintf(f,"\n");
    }
}
void readfile(FILE *f,char (*a)[80])
{
    for(int i=0; i<bouy; i++)
    {
        for(int j=0; j<boux; j++)
            fscanf(f,"%c",&a[i][j]);
        fscanf(f,"\n");
    }
}
void readfile(FILE *f,unsigned char (*a)[80])
{
    for(int i=0; i<bouy; i++)
    {
        for(int j=0; j<boux; j++)
            fscanf(f,"%3d,",&a[i][j]);
        fscanf(f,"\n");
    }
}
void readfile(FILE *f,USHORT(*a)[80])
{
    for(int i=0; i<bouy; i++)
    {
        for(int j=0; j<boux; j++)
            fscanf(f,"%3d,",&a[i][j]);
        fscanf(f,"\n");
    }
}
char notfilename[ ]= {92,47,':', '*', '?', '<',62,124};
int si=sizeof(notfilename);
bool checkfilename(char c)
{
    for(int i=0; i<si; i++)if(c==notfilename[i])return 1;
    return 0;
}
void filenamebox(int x,int y,char s[])
{
    to(x,y);
    char a[80]= {};
    hide(1);
    fflush(stdin);
    gets(a);
    fflush(stdin);
    hide(0);
    int l=strlen(a);
    if(a[0]=='\0'||l>=20)return;

    for(int i=0; i<l; i++)if(checkfilename(a[i]))
        {
            to(x,y);
            cc(12);
            printf("不得特殊字元");
            cc(15);
            to(x,y);
            Sleep(1000);
            printf("            ");
            return ;
        }
    int j=0;
    while(a[j]==' ')j++;
    for(int i=0; j<=l; i++)
        s[i]=a[j++];

}
class LoadFile
{
public:
    int x=25;
    int y=5;
    char loadfilename[80]="按此輸入";
    char loadmenu[5][15]=
    {
        {95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,},
        {124,-64,-55,-90,87,58,0,0,0,0,0,0,0,0,124,},
        {124,0,0,0,0,0,0,0,0,0,0,0,0,0,124,},
        {124,0,0,-67,84,-87,119,0,-88,-6,-82,-8,0,0,124,},
        {45,45,45,45,45,45,45,45,45,45,45,45,45,45,45,},
    };

    void putloadmenu()
    {
        for(int i=0; i<5; i++)
        {
            to(x,y+i);
            for(int j=0; j<15; j++)
                printf("%c",loadmenu[i][j]);
        }
    }
    void putloadfilename()
    {
        to(x+6,y+1);
        printf("%s",loadfilename);
    }
    void putmenu()
    {
        putloadmenu();
        putloadfilename();
    }
    void loading()
    {
        char nam[80]= {};
        sprintf(nam,".\\mydata\\%s%s",loadfilename,fileaname);
        FILE *f=fopen(nam,"r");
        if(f==0)
        {
            to(6+x,1+y);
            printf("無此存檔");
            return;
        }
        clsbar(bouy+3,bouy+3);
        charemp(nmap,0);
        charemp(nspa,0);
        charemp(neve,0);
        charemp(ncol,15);
        charemp(lmap,0);
        charemp(lspa,0);
        charemp(leve,0);
        charemp(lcol,15);
        fscanf(f,"%2d%2d\n",&boux,&bouy);
        readfile(f,lmap);
        readfile(f,lcol);
        readfile(f,lspa);
        readfile(f,leve);
        renew(neve,leve);
        renew(nmap,lmap);
        renew(ncol,lcol);
        renew(nspa,lspa);
        to(15,0);
        printf("規格:%2dx%2d",bouy,boux);
        strcpy(filename,loadfilename);
        putfilename(30,0);
        ex=1;
        fclose(f);
    }
    void event()
    {
        if(click==1)
        {
            if(c.Y==y+1&&midd(6+x,13+x,c.X))
            {
                to(6+x,1+y);
                printf("        ");
                filenamebox(6+x,y+1,loadfilename);
                putmenu();
            }
            else if(c.Y==y+3)
            {
                if(midd(3+x,6+x,c.X))
                {
                    loading();
                }
                else if(midd(8+x,11+x,c.X))
                {
                    ex=1;
                }
            }
        }
    }
} loadfile;

void load()
{
    loadfile.putmenu();

    while(!ex)
    {
        mxy(c,click);
        to(0,0);
        printf("座標:(%2d,%2d) ",c.X,c.Y);
        loadfile.event();
    }
    ex=0;
    clsblock(loadfile.x,loadfile.x+14,loadfile.y,loadfile.y+4);
    to(0,bouy+3);
    bar(boux);
    cha[nowmode]();
}

template<class T>
void writecpp(FILE *f,T (*a)[80])
{
    fprintf(f,"{\n");
    for(int i=0; i<bouy; i++)
    {
        fprintf(f,"{");
        for(int j=0; j<boux; j++)
            fprintf(f,"%3d,",a[i][j]);
        fprintf(f,"},\n");
    }
    fprintf(f,"};\n");
}

struct funbuf
{
    UCHAR i;
    char st[5000];
};
int fbuftop=-1,fbpos;
funbuf fb[20];
char nbuf[1000];
char obuf[100000];
bool savefile()
{
    char nam[80];
    strcpy(nam,filename);
    strcat(nam,fileaname);
    sprintf(nam,".\\mydata\\%s%s",filename,fileaname);
    FILE *f=fopen(nam,"r");
    if(f!=0)
    {
        putsamesavename(17,10);
        while(!ex)
        {
            mxy(c,click);
            to(0,0);
            printf("座標:(%2d,%2d) ",c.X,c.Y);
            if(click==1)
            {
                if(c.Y==3+10)
                {
                    if(midd(17+5,17+8,c.X))
                    {
                        ex=1;
                    }
                    else if(midd(17+12,17+15,c.X))
                    {
                        return 0;
                    }
                }
            }
        }
        ex=0;
    }
    f=fopen(nam,"w");
    fprintf(f,"%2d%2d\n",boux,bouy);
    writefile(f,nmap);
    writefile(f,ncol);
    writefile(f,nspa);
    writefile(f,neve);
    if(susech[suse][0])
    {
        fclose(f);
        sprintf(nam,".\\mpheader\\%s%s.h",filehead[suse],filename);
        f=fopen(nam,"r");
        if(f!=0)
        {
            fclose(f);
            f=fopen(nam,"r");
            char*cpt;
            if(suse==0)
            {
                fbuftop=-1;
                while(fgets(nbuf,1000,f)!=NULL)
                {
                    cpt=nbuf;
                    while(*cpt==' ')cpt++;
                    if(cpt[0]=='c'&&cpt[1]=='h'&&cpt[2]=='a'&&cpt[3]=='r'&&cpt[4]==' '&&cpt[5]=='m')break;
                    if(cpt[0]=='c'&&cpt[1]=='a'&&cpt[2]=='s'&&cpt[3]=='e'&&cpt[5]!='0')
                    {
                        cpt+=5;
                        UCHAR ni=0;
                        fbuftop++;
                        while(cpt[ni]!=':')ni++;
                        cpt[ni]='\0';
                        fb[fbuftop].i=atoi(cpt);
                        fb[fbuftop].st[0]='\0';
                        while(fgets(nbuf,1000,f)!=NULL)
                        {
                            cpt=nbuf;
                            while(*cpt==' ')cpt++;
                            if(cpt[0]=='B'&&cpt[1]=='R'&&cpt[2]=='E'&&cpt[3]=='A'&&cpt[4]=='K')break;
                            strcat(fb[fbuftop].st,cpt);
                        }
                    }
                }
            }
            else if(suse==1)
            {
                /* obuf[0]= '\0';
                  while(fgets(nbuf,1000,f)!=NULL)
                  {
                      cpt=nbuf;
                      if(cpt[0]=='c'&&cpt[1]=='h'&&cpt[2]=='a'&&cpt[3]=='r'&&cpt[4]==' '&&cpt[5]=='m')break;
                      strcat(obuf,cpt);
                  }*/
            }
            fclose(f);
            f=fopen(nam,"w");
            if(suse==0)
            {
                bool findeve[256]= {};
                unsigned char k;
                for(int i=0; i<bouy; i++)
                {
                    for(int j=0; j<boux; j++)
                        if(k=neve[i][j])findeve[k]=1;
                }
                fprintf(f,"void event%s(int a)\n",filename);
                fprintf(f,"{\n");
                fprintf(f,"switch(a)\n");
                fprintf(f,"{\n");
                fprintf(f,"case 0:return;\n");
                fbpos=0;
                for(int i=1; i<128; i++)
                {
                    if(findeve[i])
                    {
                        while(fbpos<=fbuftop&&fb[fbpos].i<i)fbpos++;
                        if(fb[fbpos].i==i)
                        {
                            fprintf(f,"case %d:\n%sBREAK;\n",i,fb[fbpos].st);
                        }
                        else fprintf(f,"case %d:\n\nBREAK;\n",i);
                    }
                }
                fprintf(f,"\n\n}\n");
                fprintf(f,"}\n");
                fprintf(f,"void autoevent%s(int a)\n",filename);
                fprintf(f,"{\n");
                fprintf(f,"switch(a)\n");
                fprintf(f,"{\n");
                fprintf(f,"case 0:return;\n");
                for(int i=128; i<256; i++)
                {
                    if(findeve[i])
                    {
                        while(fbpos<=fbuftop&&fb[fbpos].i<i)fbpos++;
                        if(fb[fbpos].i==i)
                        {
                            fprintf(f,"case %d:\n%sBREAK;\n",i,fb[fbpos].st);
                        }
                        else fprintf(f,"case %d:\n\nBREAK;\n",i);
                    }
                }
                fprintf(f,"\n\n}\n");
                fprintf(f,"}\n");
            }
            else if(suse==1)
            {
                //   fprintf(f,"%s",obuf);
            }
        }
        else
        {
            f=fopen(nam,"w");
            if(suse==0)
            {
                bool findeve[256]= {};
                unsigned char k;
                for(int i=0; i<bouy; i++)
                {
                    for(int j=0; j<boux; j++)
                        if(k=neve[i][j])findeve[k]=1;
                }
                fprintf(f,"void event%s(int a)\n",filename);
                fprintf(f,"{\n");
                fprintf(f,"switch(a)\n");
                fprintf(f,"{\n");
                fprintf(f,"case 0:return;\n");
                for(int i=1; i<128; i++)
                {
                    if(findeve[i])
                    {
                        fprintf(f,"case %d:\n\n\nBREAK;\n",i);
                    }
                }
                fprintf(f,"\n\n}\n");
                fprintf(f,"}\n");
                fprintf(f,"void autoevent%s(int a)\n",filename);
                fprintf(f,"{\n");
                fprintf(f,"switch(a)\n");
                fprintf(f,"{\n");
                fprintf(f,"case 0:return;\n");
                for(int i=128; i<256; i++)
                {
                    if(findeve[i])
                    {
                        fprintf(f,"case %d:\n\n\nBREAK;\n",i);
                    }
                }
                fprintf(f,"\n\n}\n");
                fprintf(f,"}\n");
            }
            else if(suse==1)
            {
                /*
                fprintf(f,"/*\n");
                fprintf(f,"unsigned char readevent%s(MK c)\n",filename);
                fprintf(f,"{\n");
                fprintf(f,"     if(c.type==1&&c.kbdown)\n");
                fprintf(f,"     {\n");
                fprintf(f,"          switch(c.kb)\n");
                fprintf(f,"          {\n");
                fprintf(f,"          case 72://上\n");
                fprintf(f,"          return 1;\n");
                fprintf(f,"          case 80://下\n");
                fprintf(f,"          return 2;\n");
                fprintf(f,"          case 75://左\n");
                fprintf(f,"          return 3;\n");
                fprintf(f,"          case 77://右\n");
                fprintf(f,"          return 4;\n");
                fprintf(f,"          case 28://ENTER\n");
                fprintf(f,"          return 5;\n");
                fprintf(f,"          case 44://Z\n");
                fprintf(f,"          return 6;\n");
                fprintf(f,"          case 59://F1\n");
                fprintf(f,"          return 255;\n");
                fprintf(f,"          }\n");
                fprintf(f,"     }\n");
                fprintf(f,"     else\n");
                fprintf(f,"     {\n");
                fprintf(f,"          if(c.click==0)\n");
                fprintf(f,"          {\n\n");
                fprintf(f,"          \n");
                fprintf(f,"          }\n");
                fprintf(f,"          else if(c.click==1)\n");
                fprintf(f,"          {\n");
                fprintf(f,"          \n\n");
                fprintf(f,"          }\n");
                fprintf(f,"     }\n");
                fprintf(f,"\n");
                fprintf(f,"return 0;\n");
                fprintf(f,"}\n");
                fprintf(f,"void mevent%s(MK c)\n",filename);
                fprintf(f,"{\n");
                fprintf(f,"     switch(readevent%s(c))\n",filename);
                fprintf(f,"     {\n");
                fprintf(f,"     case 0:return;\n");
                fprintf(f,"     case 1://上\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 2://下\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 3://左\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 4://右\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 5://ENTER\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 6://Z\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 7:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 8:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 9:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 10:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 11:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 12:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 13:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 14:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 15:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 16:\n\n");
                fprintf(f,"     break;\n");
                fprintf(f,"     case 255: usecircle=1;//F1\n");
                fprintf(f,"     return;\n");
                fprintf(f,"     }\n\n\n");
                fprintf(f,"}\n");
                */
                //    fprintf(f,"*/\n");

            }
        }
        if(f==0)f=fopen(nam,"w");

        if(susech[suse][1])
        {
            fprintf(f,"char map%s[%d][%d]=\n",filename,bouy,boux);
            writecpp(f,nmap);
        }
        if(susech[suse][2])
        {
            fprintf(f,"USHORT col%s[%d][%d]=\n",filename,bouy,boux);
            writecpp(f,ncol);
        }
        if(susech[suse][3])
        {
            fprintf(f,"unsigned char spa%s[%d][%d]=\n",filename,bouy,boux);
            writecpp(f,nspa);
        }
        if(susech[suse][4])
        {
            fprintf(f,"unsigned char eve%s[%d][%d]=\n",filename,bouy,boux);
            writecpp(f,neve);
        }
        fprintf(f,"\n%s %s%s=\n",strnam[suse],filehead[suse],filename);
        fprintf(f,"{\n");
        fprintf(f,"{%d,%d},\n",boux,bouy);
        //   fprintf(f,"{%d,%d},\n",40-boux/2,12-bouy/2);
        if(susech[suse][1])fprintf(f,"map%s[0],\n",filename);
        if(susech[suse][2])fprintf(f,"col%s[0],\n",filename);
        if(susech[suse][3])fprintf(f,"spa%s[0],\n",filename);
        if(susech[suse][4])fprintf(f,"eve%s[0],\n",filename);
        if(suse==0)
        {
            fprintf(f,"event%s,\n",filename);
            fprintf(f,"autoevent%s,\n",filename);
        }
        else if(suse==1)
        {
            // fprintf(f,"0,//mevent%s,\n",filename);
        }
        fprintf(f,"};\n");
    }

    fclose(f);
    mxy(c,click);
    return 1;
}




void putsavemenu()
{

    for(int i=0; i<11; i++)
    {
        to(savex,savey+i);
        for(int j=0; j<19; j++)
            printf("%c",savemenu[i][j]);
    }
}


void putsaveuse(int a)
{
    for(int i=0; i<3; i++)
    {
        to(savex+3,savey+i+4);
        cc(a==i?12:15);
        printf(a==i?"v ":"口");
    }
    cc(15);
}
void putsaveusech()
{
    cc(susech[suse][0]?12:15);
    to(savex+10,savey+3);
    printf(susech[suse][0]?"v ":"口");
    if(susech[suse][0])
    {
        for(int i=1; i<5; i++)
        {
            to(savex+13,savey+i+3);
            cc(susech[suse][i]?12:15);
            printf(susech[suse][i]?"v ":"口");
        }
    }
    else for(int i=1; i<5; i++)
        {
            to(savex+13,savey+i+3);
            printf("  ");
        }

    cc(15);
}

void putsave()
{
    putsavemenu();
    putsaveuse(suse);
    putsaveusech();
    putname(savex+1,savey+2);

}
void save()
{
    putsave();
    while(!ex)
    {
        mxy(c,click);
        to(0,0);
        printf("座標:(%2d,%2d) ",c.X,c.Y);
        if(click==1)
        {
            if(c.Y==2+savey&&midd(savex+6,savex+17,c.X))
            {
                clsblock(savex+6,savex+17,2+savey,2+savey);
                filenamebox(savex+6,savey+2,filename);
                putsave();
            }
            else if(midd(savex+3,savex+9,c.X)&&midd(savey+4,savey+6,c.Y))
            {
                putsaveuse(suse=c.Y-savey-4);
                putsaveusech();
            }
            else if(midd(savex+10,savex+17,c.X)&&c.Y==savey+3)
            {
                susech[suse][0]=susech[suse][0]?0:1;
                putsaveusech();
            }
            else if(suse==2&&midd(savex+12,savex+17,c.X)&&midd(savey+4,savey+7,c.Y))
            {
                susech[suse][c.Y-savey-3]=susech[suse][c.Y-savey-3]?0:1;
                putsaveuse(suse);
                putsaveusech();
            }
            else if(c.Y==savey+9)
            {
                if(midd(savex+3,savex+6,c.X))
                {
                    if(savefile())ex=1;
                    else putsave();
                }
                else if(midd(savex+10,savex+13,c.X))
                {
                    ex=1;
                }
            }
        }
    }
    clsblock(savex,savex+18,savey,savey+10);
    ex=0;
    to(0,bouy+3);
    bar(boux);
    cha[nowmode]();
    putfilename(30,0);
}

