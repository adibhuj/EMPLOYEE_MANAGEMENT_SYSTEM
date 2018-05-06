#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<dos.h>
#include<graphics.h>
#include<string.h>
#include<stdlib.h>
#include<bios.h>
#include<ctype.h>
int clay=24;
int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
void login();
void logohead();
void window();
void window()
{
setfillstyle(1,15);
bar(20,20,600,60);
setfillstyle(1,1);
bar(20,70,600,470);
setcolor(15);
rectangle(25,75,595,465);
setcolor(4);
outtextxy(170,35,"********* LEAVE MONITOR *********");
setcolor(15);
}

class employee
{
private:
int id;
char pno[10];
char name[40];
char post[70];
char gender[10];
public:
friend class cl;
char dept[20];
employee()
{
id=0;
}

void getdata()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:/turboc3/bgi");
window();
outtextxy(30,130,"IDENTITY NUMBER OF EMPLOYEE       :");
setfillstyle(1,0);
bar(375,125,590,145);
gotoxy(50,9);
cin>>id;
outtextxy(30,180,"DEPARTMENT OF THE EMPLOYEE        :");
setfillstyle(1,0);
bar(375,175,590,195);
gotoxy(50,12);
gets(dept);
outtextxy(30,225,"NAME OF THE EMPLOYEE              :");
setfillstyle(1,0);
bar(375,220,590,240);
gotoxy(50,15);
gets(name);
}

void get()
{
outtextxy(30,275, "GENDER OF THE EMPLOYEE (M/F)     :");
setfillstyle(1,0);
bar(375,270,590,290);
gotoxy(50,18);
gets(gender);
outtextxy(30,325,"ADDRESS OF THE EMPLOYEE         :");
setfillstyle(1,0);
bar(375,320,590,340);
gotoxy(50,21);
gets(post);
outtextxy(30,370,"PHONE NUMBER                    :");
setfillstyle(1,0);
bar(375,365,590,385);
gotoxy(50,24);
gets(pno);
}
void display()
{
cout<<"\n------------------------------------------------------------------------------";
cout<<"\nID"<<"   DEPT"<<"\t NAME "<<"\t   GENDER"<<"\tPHONE NUMBER  "<<"\t"<<"ADDRESS ";
cout<<"\n------------------------------------------------------------------------------";
}
void put()
{
cout<<"\n"<<id<<"   "<<dept<<"\t"<<name<<"\t   "<<gender<<"\t\t"<<pno<<"\t\t"<<post;
}
void modify();
void deletion();
void searching();
}emp;

class allocation
{
int dd,dd1;
int mm,mm1;
long yy,yy1;
friend class cl;
friend class ml;
friend class el;
public:
void get()
{
cout<<"\n Enter The Starting Date Of The Leave (dd mm yyyy) : ";
cin>>dd>>mm>>yy;
if(dd>31||mm>12||yy>3000&&yy<=2000)
{
cout<<"\n Invalid Date ";
getch();
exit(0);
}
cout<<"\n Entre The Joining Date  (dd mm yyyy) : ";
cin>>dd1>>mm1>>yy1;
if(dd1>31||mm1>12||yy1>3000)
{
cout<<"\n Invalid Date ";
getch();
exit(0);
}
}
void display()
{
cout<<"\t"<<dd<<"/"<<mm<<"/"<<yy<<"\t"<<dd1<<"/"<<mm1<<"/"<<yy1;
}
}dat;
class cl:public allocation
{
int no,empno,mpn;
int remain;
int k,l,kq,lq,nd;
int alm[12],aly;
public:
void cle();
void cl_display();
void cle_display();
void clst(int);
cl()
{
for(int nan=0;nan<=11;nan++)
{
alm[nan]=2;
}
aly=24;
}

int almf()
{ int mnd=0;
  mnd=nod(dd,mm,yy,dd1,mm1,yy1);
  alm[mm]=alm[mm]-mnd;
  return (alm[mm]);
}
int alyf()
{ int ynd=0;
  ynd=nod(dd,mm,yy,dd1,mm1,yy1);
  aly=aly-ynd;
  return (aly);
}
/*
int nod(int d1,int m1,int y1,int d2,int m2,int y2)
{
int days;
int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(y1 == y2)
    {
	if(m1==m2)
	    days = d2 - d1;
	else
	{
	    for(int i1 = m1; i1 < m2-1;i1++)
	     {
	     days += month_days[i1];
	     }
	    days += month_days[m1-1] - d1 + d2;
	}
    }
    else
    {
	for(int i2 = 0; i2 < m2-1; i2++)
	    days += month_days[i2];
	for(int i = m1; i < 12; i++)
	    days += month_days[i];
	if(y2 - y1 >= 0)
	days += (y2 - y1- 1)*365 +
	    month_days[m1-1] - d1 + d2;
    }
    return (days);
} */
//******************
int nod(int first_date_days,int first_date_month,int first_date_year,int second_date_days,int second_date_month,int second_date_year)
{
int days=0;



    if(first_date_year == second_date_year)
    {
	if(first_date_month == second_date_month)
	    days = second_date_days - first_date_days;
	else
	{
	    for(int i = first_date_month; i < second_date_month-1;i++)
		days += month_days[i];
	    days += month_days[first_date_month-1] - first_date_days + second_date_days;
	}
    }
    else
    {
	for(int i = 0; i < second_date_month-1; i++)
	    days += month_days[i];
	for(int ih = first_date_month; ih < 12; ih++)
	    days += month_days[ih];
	if(second_date_year - first_date_year >= 0)
	days += (second_date_year - first_date_year - 1)*365 +
	    month_days[first_date_month-1] - first_date_days + second_date_days;
    }

    return (days);
    }
//***********



}cl1;

class ml:public allocation
{
int no,empno;
int remain;
int k,l,kq,lq,nd;
int alm[12],aly;
public:
void mle();
void ml_display();
void mle_display();
void mlst(int);

ml()
{
for(int nan=0;nan<=11;nan++)
{
alm[nan]=2;
}
aly=24;
}

int almf()
{ int mnd=0;
  mnd=nod(dd,mm,yy,dd1,mm1,yy1);
  alm[mm]=alm[mm]-mnd;
 /*
  if(alm[mm-1]<0)
  {
  alm[mm-1]=0;
  }
   */
return (alm[mm]);
}
int alyf()
{ int ynd=0;
  ynd=nod(dd,mm,yy,dd1,mm1,yy1);
  aly=aly-ynd;
return (aly);
}
/*
int nod(int d1,int m1,int y1,int d2,int m2,int y2)
{
int days;
int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(y1 == y2)
    {
	if(m1==m2)
	    days = d2 - d1;
	else
	{
	    for(int i1 = m1; i1 < m2-1;i1++)

	     days += month_days[i1];

	    days += month_days[m1-1] - d1 + d2;
	}
    }
    else
    {
	for(int i2 = 0; i2 < m2-1; i2++)
	    days += month_days[i2];
	for(int i = m1; i < 12; i++)
	    days += month_days[i];
	if(y2 - y1 >= 0)
	days += (y2 - y1- 1)*365 +
	    month_days[m1-1] - d1 + d2;
    }


    return (days);
} */
int nod(int first_date_days,int first_date_month,int first_date_year,int second_date_days,int second_date_month,int second_date_year)
{
int days=0;



    if(first_date_year == second_date_year)
    {
	if(first_date_month == second_date_month)
	    days = second_date_days - first_date_days;
	else
	{
	    for(int i = first_date_month; i < second_date_month-1;i++)
		days += month_days[i];
	    days += month_days[first_date_month-1] - first_date_days + second_date_days;
	}
    }
    else
    {
	for(int i = 0; i < second_date_month-1; i++)
	    days += month_days[i];
	for(int ih = first_date_month; ih < 12; ih++)
	    days += month_days[ih];
	if(second_date_year - first_date_year >= 0)
	days += (second_date_year - first_date_year - 1)*365 +
	    month_days[first_date_month-1] - first_date_days + second_date_days;
    }

    return (days);
    }
}ml1;
class el:public allocation
{
int no,empno;
int remain;
int k,l,kq,lq,nd;
int alm[12],aly;
public:
void ele();
void el_display();
void ele_display();
void elst(int);
el()
{
for(int nan=0;nan<=11;nan++)
{
alm[nan]=2;
}
aly=24;
}

int almf()
{ int mnd=0;
  mnd=nod(dd,mm,yy,dd1,mm1,yy1);
  alm[mm]=alm[mm]-mnd;
 /*
  if(alm[mm-1]<0)
  {
  alm[mm-1]=0;
  }
   */
return (alm[mm]);
}
int alyf()
{ int ynd=0;
  ynd=nod(dd,mm,yy,dd1,mm1,yy1);
  aly=aly-ynd;
return (aly);
}
/*
int nod(int d1,int m1,int y1,int d2,int m2,int y2)
{
int days;
int month_days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(y1 == y2)
    {
	if(m1==m2)
	    days = d2 - d1;
	else
	{
	    for(int i1 = m1; i1 < m2-1;i1++)
	     {
	     days += month_days[i1];
	     }
	    days += month_days[m1-1] - d1 + d2;
	}
    }
    else
    {
	for(int i2 = 0; i2 < m2-1; i2++)
	    days += month_days[i2];
	for(int i = m1; i < 12; i++)
	    days += month_days[i];
	if(y2 - y1 >= 0)
	days += (y2 - y1- 1)*365 +
	    month_days[m1-1] - d1 + d2;
    }


    return (days);
} */
int nod(int first_date_days,int first_date_month,int first_date_year,int second_date_days,int second_date_month,int second_date_year)
{
int days=0;
 if(first_date_year == second_date_year)
    {
	if(first_date_month == second_date_month)
	    days = second_date_days - first_date_days;
	else
	{
	    for(int i = first_date_month; i < second_date_month-1;i++)
		days += month_days[i];
	    days += month_days[first_date_month-1] - first_date_days + second_date_days;
	}
    }
    else
    {
	for(int i = 0; i < second_date_month-1; i++)
	    days += month_days[i];
	for(int ih = first_date_month; ih < 12; ih++)
	    days += month_days[ih];
	if(second_date_year - first_date_year >= 0)
	days += (second_date_year - first_date_year - 1)*365 +
	    month_days[first_date_month-1] - first_date_days + second_date_days;
    }

    return (days);
    }


}el1;

void start()                        //welcome screen
{
   int i,n,gd=DETECT,gm;
   initgraph(&gd,&gm,"c:/turboc3/bgi");

      setfillstyle(11,1);
      bar(0,0,getmaxx(),getmaxy());


 int it, a=(getmaxx()-textwidth("<<<               >>>"))/2;
 setfillstyle(1,1);

 setcolor(15);
 settextstyle(4, 0, 8);
 outtextxy((getmaxx()-textwidth("Employee"))/2,80,"Employee");
 outtextxy((getmaxx()-textwidth("Leave Management")-90)/2,180," Leave Management");
 outtextxy((getmaxx()-textwidth("System"))/2,280,"System");

 do{
 int k=100;
 settextstyle(0, 0, 2);
 setcolor(14);
 outtextxy(a-k,getmaxy()-20,"<<<               >>>");
 setcolor(4);
 outtextxy(a-k,getmaxy()-20,"    PRESS ANY KEY    ");
 delay(250);
 if(kbhit())
 {
 getch();
 break;
 }
 setcolor(14);
 outtextxy(a-k,getmaxy()-20,"<<<               >>>");
 setcolor(4);
 outtextxy(a-k,getmaxy()-20,"  < PRESS ANY KEY >  ");
 delay(250);
 if(kbhit())
 {
 getch();
 break;
 }
 setcolor(14);
 outtextxy(a-k,getmaxy()-20,"<<<               >>>");
 setcolor(4);
 outtextxy(a-k,getmaxy()-20," << PRESS ANY KEY >> ");
 delay(250);
 if(kbhit())
 {
 getch();
 break;
 }
 setcolor(YELLOW);
 outtextxy(a-k,getmaxy()-20,"<<<               >>>");
 setcolor(4);
 outtextxy(a-k,getmaxy()-20,"<<< PRESS ANY KEY >>>");
 }while(1);

     //getch();
}

void logohead()
{

 //logo
 setcolor(0);
 circle(60,45,43);
 setfillstyle(1,0);
 floodfill(60,45,0);
 setcolor(15);
 circle(60,30,18);
 ellipse(60,44,220,320,40,40);
 ellipse(60,69,360,70,30,25);
 ellipse(60,69,112,180,30,25);
 ellipse(60,31,230,310,20,20);
 setfillstyle(1,15);
 floodfill(60,45,15);
 floodfill(70,64,15);
  setcolor(0);
  outtextxy(140,60,"A Employee Leave Management System........");
 //head name
 int z=9; //9
 int h=35;
 setcolor(z);
 //L
   line(100+h,5,100+h,50);
   line(100+h,50,130+h,50);
   line(130+h,50,130+h,40);
   line(130+h,40,110+h,40);
   line(110+h,40,110+h,5);
   line(110+h,5,100+h,5);
   //E
   line(135+h,5,135+h,50);
   line(135+h,5,160+h,5);
   line(135+h,50,160+h,50);
//  //down
   line(160+h,50,160+h,40);
   line(160+h,40,145+h,40);
     //up
   line(145+h,40,145+h,31);
   line(145+h,31,155+h,31);
   line(155+h,31,155+h,24);
   line(155+h,24,145+h,24);
   line(145+h,24,145+h,13);
   line(145+h,13,160+h,13);
   line(160+h,13,160+h,5);

     //A
   line(165+h,50,175+h,5);
   line(175+h,5,190+h,5);
   line(178+h,35,186+h,35);
   line(190+h,5,200+h,50);
   line(200+h,50,190+h,50);

   line(190+h,50,186+h,35);
   line(179+h,35,175+h,50);
   line(175+h,50,165+h,50);

   line(178+h,30,186+h,30);
   line(178+h,30,182+h,15);
   line(186+h,30,182+h,15);

  //v
  line(210-10+h,5,220-10+h,50);
  line(220-10+h,50,230-10+h,50);
  line(230-10+h,50,240-10+h,5);
  line(240-10+h,5,230-10+h,5);
  line(210-10+h,5,220-10+h,5);
  line(220-10+h,5,225-10+h,35);
  line(230-10+h,5,225-10+h,35);
   //E
   int e=100;
   line(135+e+h,5,135+e+h,50);
   line(135+e+h,5,160+e+h,5);
   line(135+e+h,50,160+e+h,50);
     //down
   line(160+e+h,50,160+e+h,40);
   line(160+e+h,40,145+e+h,40);
     //up
   line(145+e+h,40,145+e+h,31);
   line(145+e+h,31,155+e+h,31);
   line(155+e+h,31,155+e+h,24);
   line(155+e+h,24,145+e+h,24);
   line(145+e+h,24,145+e+h,13);
   line(145+e+h,13,160+e+h,13);
   line(160+e+h,13,160+e+h,5);

    //m
   line(290+h,5,290+h,50);
   line(290+h,5,300+h,5);
   line(290+h,50,300+h,50);
   line(300+h,50,300+h,30);
   line(300+h,30,310+h,45);
   line(310+h,45,320+h,30);
   line(320+h,30,320+h,50);
   line(320+h,50,330+h,50);
   line(330+h,50,330+h,5);
   line(330+h,5,320+h,5);
   line(320+h,5,310+h,30);
   line(310+h,30,300+h,5);

   //o
   ellipse(350+h,27,0,360,8,15);
   ellipse(350+h,27,0,360,16,23);

   //n
   line(370+h,5,370+h,50);
   line(370+h,50,380+h,50);
   line(370+h,5,380+h,5);   //
   line(380+h,50,380+h,25);
   line(380+h,25,400+h,50);
   line(400+h,50,410+h,50);
   line(410+h,50,410+h,5);
   line(410+h,5,400+h,5);
   line(400+h,5,400+h,30);
   line(400+h,30,380+h,5);

   //i
   rectangle(415+h,5,423+h,50);
   //o
   int o=135;
   ellipse(350+o+h,27,0,360,8,15);
   ellipse(350+o+h,27,0,360,16,23);

   //t
   int t=33;
   rectangle(460-t+h,5,500-t+h,15);
   rectangle(475-t+h,15,485-t+h,50);


   //r
   line(507+h,5,507+h,50);
   line(507+h,5,517+h,5);
   line(507+h,50,517+h,50);
   line(517+h,50,517+h,35);
   ellipse(517+h,21,290,90,26,16);
   line(517+h,35,537+h,50);
   line(537+h,50,547+h,50);
   line(547+h,50,527+h,35);

   line(517+h,27,517+h,13);
   ellipse(517+h,21,270,90,15,7);
  // color
   //l
     setfillstyle(1,z);
   floodfill(105+h,20,z);
 //e
   setfillstyle(1,z);
   floodfill(138+h,15,z);
  //a
   setfillstyle(1,z);
   floodfill(178+h,6,z);
  //v
  setfillstyle(1,z);
  floodfill(215+h,40,z);
 //e
      setfillstyle(1,z);
   floodfill(138+e+h,15,z);
 //m
   setfillstyle(1,z);
   floodfill(295+h,8,z);
 //o
   setfillstyle(1,z);
   floodfill(359+h,27,z);
//n
   setfillstyle(1,z);
   floodfill(375+h,15,z);
//i
   setfillstyle(1,z);
   floodfill(420+h,15,z);
//o
   setfillstyle(1,z);
   floodfill(359+o+h,27,z);
//t
   setfillstyle(1,z);
   floodfill(460+h,8,z);
   floodfill(445+h,18,z);
//r
   setfillstyle(1,z);
   floodfill(510+h,8,z);

  }
  void login()
  {
  clrscr();
  int i,gd=DETECT,gm;
  initgraph(&gd,&gm,"c:/turboc3/bgi");

char code[5];
char un[5];
int n;
int y=40;
setfillstyle(1,15);
bar(100,100,479,379);
setfillstyle(1,1);
bar(102,130,477,377);
//setcolor(4);
//rectangle(102,102,477,128);

setcolor(0);
///rectangle(0,0,629,479);
outtextxy(260,110,"LOGIN");
setcolor(15);
outtextxy(160,150+y+15,"USER     :");
outtextxy(160,200+y+15,"PASSWORD :");
rectangle(250,152+y+10,400,177+y+10);
rectangle(250,202+y+10,400,227+y+10);
setfillstyle(1,0);
bar(250+2,152+y+12,400-2,177+y+8);
bar(250+2,202+y+12,400-2,227+y+8);
gotoxy(34,14);
cout<<"admin";
   for(i=0;code[i-1]!=13;i++)
	{       gotoxy(34+i,17);
		code[i]=getch();
		if(code[i]!=13)            //condition added only
		cout<<"* ";
	}
	code[i-1]=NULL;
	n=strcmp(code,"admin");
	if(n!=0)
	{
	  outtextxy(200,360,"Sorry ! Incorrect Code ");
	  getch();
	  exit(0);
	}
	else
	{
	 outtextxy(200,355,"Correct Code ");
	 outtextxy(200,365,"Press Enter to continue... ");


	 getch();
	}


  }
void main()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:/turboc3/bgi");
int ch;
start();
char date[11];
struct date da;
char ch1='y';
clrscr();       //change
login();

clrscr();
while(ch1=='y'||ch1=='Y')
 {
 initgraph(&gd,&gm,"c:\turboc3\bgi");

 setcolor(15);
 rectangle(0,0,639,440);
 rectangle(1,1,638,439);
 setfillstyle(1,14);  //upper bar
 bar(2,2,637,95);
  setfillstyle(11,9);//9  //bar behind menu
  bar(2,96,635,374);
  setfillstyle(1,1);
  bar(100,97,536,373);
  setcolor(1);
  ellipse(230,100-4,90,180,130,20);
  line(230,80-5,637,80-5);
  line(637,80-5,637,97);
  line(100,97,637,97);
  setfillstyle(1,1);
  floodfill(400,90,1);
  logohead();
  setcolor(15);
		      //bar behind men
  setfillstyle(1,1); //mitaoe bar
  bar(2,407,637,438);
  outtextxy(30,410+2,"Team : Aditya Bhujbal ");
  outtextxy(87,423+2,"Nikhil Bora");
  outtextxy(400,412,"Guide : Pranali Lokhande");
  //date
  getdate(&da);
  sprintf(date,"%02d/%02d/%d",da.da_day,da.da_mon,da.da_year);
  setcolor(15);
  settextstyle(2,0,2);
  outtextxy(540,85,date);
  setcolor(15);
  int a1=30;
  setcolor(15);
  settextstyle(7,0,3);
  outtextxy(120+a1,120,"  MAIN MENU                    KEY ");
  outtextxy(110+a1,140,"--------------------------------------");
  settextstyle(7,0,2);
  outtextxy(120+a1,170,"EMPLOYEE INFORMATION            1 ");
  outtextxy(120+a1,200,"ENTER LEAVE FORM                2 ");
  outtextxy(120+a1,230,"EMPLOYEE LEAVE STATUS           3 ");
  outtextxy(120+a1,260,"GUIDELINES                      4 ");
  outtextxy(120+a1,290,"EXIT                            5 ");
  settextstyle(7,0,3);
  outtextxy(110+a1,320,"--------------------------------------");
  setcolor(14);
  setfillstyle(1,4);
  bar(2,375,637,405);
  settextstyle(9,0,6);
  outtextxy(18,386,"ENTER YOUR CHOICE ::  ");
  setfillstyle(1,0);
  bar(181,378,632,402);
  gotoxy(25,25);
  cin>>ch;
  //end lower bar
  cleardevice();
  switch(ch)
{
case 1:
	{
	fstream file;
	file.open("employee",ios::ate|ios::in|ios::out|ios::binary);
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);
	window();
	setcolor(GREEN);
	settextstyle(1,0,2);
	outtextxy(120,130,"      MAIN MENU               KEY ");
	setcolor(1001);
	outtextxy(120,140,"----------------------------");
	settextstyle(1,0,1);
	setcolor(WHITE);
	outtextxy(120,170,"  ENTER   DATA                 7  ");
	outtextxy(120,200,"  DISPLAY DATA                 8  ");
	outtextxy(120,230,"  MODIFY  DATA                 9  ");
	outtextxy(120,260,"  DELETE  EMPLOYEE DATA        10  ");
	outtextxy(120,290,"  SEARCH  EMPLOYEE RECORD      11 ");
	settextstyle(1,0,2);
	setcolor(1001);
	outtextxy(120,320,"-----------------------------");

  setcolor(14);
  setfillstyle(1,4);
  bar(20,375,600,405);
  settextstyle(7,0,1);
  outtextxy(28,390,"ENTER YOUR CHOICE ::  ");
  setfillstyle(1,0);
  bar(190,378,598,402);
  gotoxy(25,25);
  cin>>ch;
  setcolor(15);
  //end lower bar
	switch(ch)
	{
	 case 8:
	 {
	 //*******************

	     window();
      //menu bar
	//setcolor()

	settextstyle(1,0,2);
	outtextxy(120,130,"      MAIN MENU            KEY ");
	setcolor(15);
	outtextxy(120,140,"--------------------------------");
	settextstyle(1,0,1);
	setcolor(WHITE);
	outtextxy(120,170,"  COMPUTER DEPT            81  ");
	outtextxy(120,195,"  CIVIL DEPT               82  ");
	outtextxy(120,220,"  ENTC DEPT                83  ");
	outtextxy(120,245,"  ETX DEPT                 84  ");
	outtextxy(120,270,"  CHEMICAL DEPT            85  ");
	outtextxy(120,295,"  IT DEPT                  86  ");
	outtextxy(120,320,"  ALL                      87  ");
	settextstyle(1,0,2);
	setcolor(15);
	outtextxy(120,345,"--------------------------------");


 //lower input bar

  setcolor(14);
  setfillstyle(1,4);
  bar(20,375,600,405);
  settextstyle(7,0,1);
  outtextxy(28,390,"ENTER YOUR CHOICE ::  ");
  setfillstyle(1,0);
  bar(190,378,598,402);
  gotoxy(25,25);
  cin>>ch;
  setcolor(15);
  //end lower bar
	       //change starts*************
	       switch(ch)
	       {
	       case 81:  	cleardevice();
				file.seekg(0);
				emp.display();

		while(file.read((char*)&emp,sizeof(emp)))
		{
			if(strcmpi(emp.dept,"computer")==0||strcmpi(emp.dept,"Comp")==0)
			{
			emp.put();
			}

		}
		getch();

		break;
		case 82:  	cleardevice();
				file.seekg(0);
				emp.display();

		while(file.read((char*)&emp,sizeof(emp)))
		{
			if(strcmpi(emp.dept,"civil")==0)
			{
			emp.put();
			}

		}
		getch();

		break;

	       case 83:  	cleardevice();
				file.seekg(0);
				emp.display();

		while(file.read((char*)&emp,sizeof(emp)))
		{
			if(strcmpi(emp.dept,"ENTC")==0)
			{
			emp.put();
			}

		}
		getch();

		break;

		case 84:  	cleardevice();
				file.seekg(0);
				emp.display();

		while(file.read((char*)&emp,sizeof(emp)))
		{
			if(strcmpi(emp.dept,"ETX")==0)
			{
			emp.put();
			}

		}
		getch();

		break;

		case 85:  	cleardevice();
				file.seekg(0);
				emp.display();

		while(file.read((char*)&emp,sizeof(emp)))
		{
			if(strcmpi(emp.dept,"chemical")==0)
			{
			emp.put();
			}

		}
		getch();

		break;

		case 86:  	cleardevice();
				file.seekg(0);
				emp.display();

		while(file.read((char*)&emp,sizeof(emp)))
		{
			if(strcmpi(emp.dept,"it")==0)
			{
			emp.put();
			}

		}
		getch();

		break;


		case 87:   	cleardevice();
				file.seekg(0);
				emp.display();

		while(file.read((char*)&emp,sizeof(emp)))
		{
			emp.put();
		}
		getch();

		break;

	       }

	       //change eb=nds**************



	       /*
	 //*******************

		cleardevice();
		file.seekg(0);
		emp.display();

		while(file.read((char*)&emp,sizeof(emp)))
		{
			emp.put();
		}
		getch();
		 */
		break;

	 }     //
	 case 7:
	 {
	 /*	 //change starts here***************
		cleardevice();
		window();
	      as:outtextxy(30,130,"IDENTITY NUMBER OF EMPLOYEE       :");
		setfillstyle(1,0);
		bar(375,125,590,145);
		gotoxy(50,9);
		cin>>jid;

		while(file.read((char*)&emp,sizeof(emp)))
		{
		 file.seekg(0);

		 if(jid==emp.id)
		 {
		 outtextxy(375,150,"Sorry id already used ,try other");
		 goto as;
		 }
		// else
		// {goto x;}
		 }
		 cleardevice();
		 emp.getdata(jid);
		 emp.get();
		 file.write((char*)&emp,sizeof(emp));
		 getch();
		 file.close();

		     //ends here
		     */
		     cleardevice();

			emp.getdata();
			emp.get();
			file.write((char*)&emp,sizeof(emp));
			getch();
			file.close();



		break;
	 }
	 case 9:
	 {
		cleardevice();
		emp.modify();
		break;
	 }
	 case 10:
	 {
	       cleardevice();
	       emp.deletion();
	       break;
	 }
	 case 11:
	 {
	       cleardevice();
	       emp.searching();
	       break;
	 }
	} //switch end
	file.close();
	break;
	} //case 1 end
case 2:
{
      window();
      //menu bar
	settextstyle(1,0,2);
	outtextxy(120,130,"      MAIN MENU            KEY ");
	setcolor(1);
	outtextxy(120,140,"----------------------------");
	settextstyle(1,0,1);
	setcolor(WHITE);
	outtextxy(120,170,"  CASUAL LEAVE ENTRY           12  ");
	outtextxy(120,200,"  SICK   LEAVE ENTRY           13  ");
	outtextxy(120,230,"  MATERNITY LEAVE ENTRY        14  ");
	settextstyle(1,0,2);
	setcolor(1001);
	outtextxy(120,320,"-----------------------------");


 //lower input bar

  setcolor(14);
  setfillstyle(1,4);
  bar(20,375,600,405);
  settextstyle(7,0,1);
  outtextxy(28,390,"ENTER YOUR CHOICE ::  ");
  setfillstyle(1,0);
  bar(190,378,598,402);
  gotoxy(25,25);
  cin>>ch;
  setcolor(15);
  //end lower bar
switch(ch)
{
	case 12:
	{
	cleardevice();
	cl1.cle();
	}
	break;
	case 13:
	{
	cleardevice();
	ml1.mle();
	}
	break;
	case 14:
	{
	cleardevice();
	el1.ele();
	}
	break;
}
break;
}
case 3:
{
  window();
	//menu bar
	settextstyle(1,0,2);
	outtextxy(120,130,"      MAIN MENU            KEY ");
	setcolor(1);
	outtextxy(120,140,"----------------------------");
	settextstyle(1,0,1);
	setcolor(WHITE);
	outtextxy(120,170,"  CASUAL LEAVE DISPLAY           15  ");
	outtextxy(120,200,"  SICK   LEAVE DISPLAY           16  ");
	outtextxy(120,230,"  MATERNITY LEAVE DISPLAY        17  ");
	settextstyle(1,0,2);
	setcolor(1001);
	outtextxy(120,320,"-----------------------------");

	 //lower input bar

  setcolor(14);
  setfillstyle(1,4);
  bar(20,375,600,405);
  settextstyle(7,0,1);
  outtextxy(28,390,"ENTER YOUR CHOICE ::  ");
  setfillstyle(1,0);
  bar(190,378,598,402);
  gotoxy(25,25);
  cin>>ch;
  setcolor(15);
  //end lower bar

switch(ch)
{
case 15:
	cleardevice();
	cl1.cle_display();
	getch();

	break;
case 16:
	cleardevice();
	ml1.mle_display();
	getch();
	break;
case 17:
	cleardevice();
	el1.ele_display();
	getch();
	break;
}
break;
}
case 4:
	cleardevice();
	window();
	settextstyle(1,0,2);
	outtextxy(160+50,130,"      GUIDELINES           ");
	//setcolor(1);
	outtextxy(170,150,"-------------------------------");
	settextstyle(1,0,1);
	setcolor(WHITE);
	outtextxy(40,170,"1. For every employee only 24 Casual leaves are permitted per Year ");
	outtextxy(40,200,"2. For every employee only 30 Meadical Leaves are permitted per Year ");
	outtextxy(40,230,"3. If any of the following leaves remain they would be lapsed at the");
	outtextxy(40,250,"   end of the year");
	outtextxy(40,280,"4. Only six months of maternity leave is allowed ");
	outtextxy(40,310,"5. All leaves are Paid and granted if informed in prior ");

	 //lower input bar

  setcolor(14);
  setfillstyle(1,4);
  bar(20,375,600,405);
  settextstyle(7,0,1);
  outtextxy(28,390,"ENTER YOUR CHOICE ::  ");
  setfillstyle(1,0);
  bar(190,378,598,402);
  gotoxy(25,25);
  cin>>ch;
  setcolor(15);
  //end lower bar
	break;
case 5:
	{
	break;
	}
default:

	 //escape screen
	cout<<"\n PLEASE ENTER THE CHOICE BETWEEN 1 TO 6";
	}

	clrscr();
	cleardevice();
	setfillstyle(1,9);
	bar(3,28,633,58);
	setcolor(0);
	setfillstyle(1,0);
	bar(290,31,630,55);
	setcolor(15);
	outtextxy(20,38,"WANT TO RETURN TO MAIN MENU(Y/N):: ");
	gotoxy(38,3);
	cin>>ch1;
	clrscr();

}
  }//added here


//end of main()
//definitions of public members start

void employee::deletion()
{
int empnum;
char ch='y';

while(ch=='y'||ch=='Y')
{
 fstream fp,ft;
 fp.open("employee",ios::in|ios::out|ios::binary);

 if(fp==NULL)
  {
   printf("File creation error...");
   exit(0);
  }
 fflush(stdin);
 gotoxy(1,2);
 cout<<"\n Enter the id number of employee who's record you want to delete :";
 cin>>empnum;
 ft.open("temp",ios::out);
 if(ft==NULL)
  {
   printf("File creation error...");
   exit(0);
  }
 while(fp.read((char*)&emp,sizeof(emp)))
  {
  if(id!=empnum)
  ft.write((char*)&emp,sizeof(emp));
  }
 ft.close();
 fp.close();
 remove("employee");
 rename("temp","employee");
 fp.open("employee",ios::in);
 if(fp==NULL)
 {
  printf("File creation error...");
  exit(0);
 }
 if(id!=empnum)      //will never work wrong place cond
  {
  clrscr();
  //cleardevice();
  cout<<"Sorry! Employee Id Not found";
  }
       clrscr();
       cleardevice();
	//sound(1000);
	gotoxy(1,3);
	cout<<"Would you like to enter again(y/n) :" ;
   cin>>ch;
  }
  clrscr();
 }
void employee::modify()
{
int empnum;
char ch='y';
while(ch=='y'||ch=='Y')
{
fstream fp,ft;
fp.open("employee",ios::in|ios::out|ios::binary);
if(fp==NULL)
{
cout<<"file creation error ";
exit(0);
}

cout<<"\n Entre The Id Number Of The Employee Which You Want To Modify : ";
cin>>empnum;
ft.open("temp",ios::out);
while(fp.read((char*)&emp,sizeof(emp)))
{
if(id!=empnum)
{
cout<<"\n Invalid Id Number ";
//getch();
ft.write((char*)&emp,sizeof(emp));
}
else
{
id=empnum;
cout<<"\n Enter The Dept Of The Employee : ";
cin>>dept;
cout<<"\n Enter The Name Of The Employee : ";
cin>>name;
cout<<"\n Enter The New Address Of The Employee : ";
cin>>post;
cout<<"\n Enter The New Phone Number Of The Employee : ";
cin>>pno;
ft.write((char*)&emp,sizeof(emp));
}
}

ft.close();
fp.close();
remove("employee");
rename("temp","employee");
fp.open("employee",ios::in);
if(fp==NULL)
{
cout<<"\n file creation error ";
exit(0);
}

cout<<"\n Want To Modify Another Record (y/n) : ";
cin>>ch;
}
clrscr();
}
void employee::searching()
{
int empno;
fstream file;
char ch='y';
file.open("employee",ios::in|ios::out|ios::binary);
if(file==NULL)
{
cout<<"file creation error!!!!!!!!!!!!!!!!!";
getch();
exit(0);
}
while(file.read((char*)&emp,sizeof(emp)))
{
while(ch=='y'||ch=='Y')
{
cout<<"\n Entre The Id Of The Employee Whose Record You Want To Find : ";
cin>>empno;
if(id==empno)
{
cout<<"\n\n\n THE EMPLOYEE DETAILS ARE : ";
cout<<"\n\n NAME IS : "<<name;
cout<<"\n\n DEPARTMENT IS : "<<dept;
cout<<"\n\n GENDER IS : "<<gender;
cout<<"\n\n THE ADDRESS IS : "<<post;
cout<<"\n\n THE PHONE NUMBER IS : "<<pno;
}
else
{
cout<<"\n EMPLOYEE NUMBER NOT FIND !!!!!!!!!!!!!!!!!!!!!!!!!!!";
getch();
exit(0);
}
cout<<"\n WANT TO SEARCH ANOTHER RECORD(Y/N)::--->";
cin>>ch;
}
}
}
void cl::cle()
{
char ch='y';
fstream file;
file.open("casual",ios::ate|ios::in|ios::out|ios::binary);

if(file==NULL)
{
cout<<"\n file creation error!!!!!!!!!!!!!";
getch();
exit(0);
}
while(ch=='y'||ch=='Y')
{

cout<<"\n Enter The Employee Id Number : ";
cin>>empno;
if(empno==0)
break;
clst(empno);
allocation::get();
nd=nod(dd,mm,yy,dd1,mm1,yy1);
cout << "\n No Of Days Of Leave : " <<nd ;
if(nd<=cl1.aly&&nd<=cl1.alm[mm-1])
{
 cout<<"\n Leave Is Possible";
}
else
{
// cout<<"\n Already Leave Full For This Month"<<endl;
 }

cout<<"\n Number Of CL Taken :"<<nd;
file.write((char*)&cl1,sizeof(cl1));
cout<<"\n\nWant To Enter The CL Data For Another Employee(Y/N) : ";
cin>>ch;
}
file.close();
}

void cl::clst(int emnu)
{
int temp=0;
fstream f;      //filename ch
f.open("casual",ios::ate|ios::in|ios::out|ios::binary);
f.seekg(0);
while(f.read((char*)&cl1,sizeof(cl1)))
{

if(emnu==cl1.empno)
{		       //need to change empno to mpn
cout<<"\n---------------------------------------------------";
cout<<"\nID :"<<empno;
cout<<"\nLeave :"<<nd;
display();
temp=temp+cl1.nd;
cout<<"\nTotal number of leaves left :"<<(clay-temp);
cout<<"\n---------------------------------------------------";

}
cl1.empno=emnu;
}
f.close();

}

void cl::cl_display()
{
cout<<"\n\n---------------------------------- CL INQUIRY -------------------------------";
cout<<"\nID"<<"\t  "<<"LEAVE"<<"\t\t "<<"FROM"<<"\t\t  "<<"TO"<<"\t\t     "<<"STATUS";
cout<<"\n-------------------------------------------------------------------------------";
}


void cl::cle_display()
{
fstream file;      //filename ch
file.open("casual",ios::ate|ios::in|ios::out|ios::binary);
file.seekg(0);
cl_display();
while(file.read((char*)&cl1,sizeof(cl1)))
{                        //need to change empno to mpn
cout<<"\n"<<empno<<"\t   "<<nd<<"\t";
display();
if(nd<=2)
cout<<"\tGRANTED & UNPAID";
else
{
cout<<"\tREJECTED";
}
cout<<"\n";
}
file.close();

}

void ml::mle()
{
char ch='y';
fstream file;
file.open("medical",ios::ate|ios::in|ios::out|ios::binary);

if(file==NULL)
{
cout<<"\n file creation error!!!!!!!!!!!!!";
getch();
exit(0);
}
while(ch=='y'||ch=='Y')
{
cout<<"\n Enter The Employee Id Number : ";
cin>>empno;
if(empno==0)
break;
	//change*********************************
mlst(empno);

	//chnage**********************************
allocation::get();
nd=nod(dd,mm,yy,dd1,mm1,yy1);

cout << "\n No Of Days Of Leave : " <<nd ;
if(nd<=ml1.aly&&nd<=ml1.alm[mm-1])
{
 cout<<"\n Leave Is Possible ";
 }
 else
 {
// cout<<"\n Already Leave Full For This Month"<<endl;
 }

cout<<"\n Number Of ML Taken :"<<nd;
//cin>>no;

//cout<<"\n remaining cl:::---> ";
//cin>>remain;

file.write((char*)&ml1,sizeof(ml1));
cout<<"\n\nWant To Enter The ML Data For Another Employee(Y/N) : ";
cin>>ch;
}
file.close();
}

void ml::mlst(int mlemnu)
{
int temp=0;
fstream f;      //filename ch
f.open("medical",ios::ate|ios::in|ios::out|ios::binary);
f.seekg(0);
while(f.read((char*)&ml1,sizeof(ml1)))
{

if(mlemnu==ml1.empno)
{		       //need to change empno to mpn
cout<<"\n---------------------------------------------------";
cout<<"\nID :"<<empno;
cout<<"\nLeave :"<<nd;
//cout<<"\nRemain :"<<remain;
display();
temp=temp+ml1.nd;
/*
if((cl1.clay-nd)>=0)
{
cl1.clay=cl1.clay-nd;
cout<<"Total leaves remaining are :"<<cl1.clay;
}
else
{
cout<<"\n Leave not applicable ";
}
*/

cout<<"\nTotal number of leaves left :"<<(clay-temp);

cout<<"\n---------------------------------------------------";

}
ml1.empno=mlemnu;
}
f.close();
//clay=clay-temp;
//cout<<"Total number of leaves left :"<<cl1.clay;

}

void ml::ml_display()
{
cout<<"\n\n---------------------------------- MEDIICAL LEAVE INQUIRY -------------------------------";
cout<<"\nID"<<"\t  "<<"LEAVE"<<"\t\t "<<"FROM"<<"\t\t  "<<"TO"<<"\t\t     "<<"STATUS";
cout<<"\n-------------------------------------------------------------------------------";
}


void ml::mle_display()
{
fstream file;      //filename ch
file.open("medical",ios::ate|ios::in|ios::out|ios::binary);
file.seekg(0);
ml_display();
while(file.read((char*)&ml1,sizeof(ml1)))
{
//cout<<"\n---------------------------------------------------";
//cout<<empno<<"\t"<<nd;
cout<<"\n"<<empno<<"\t   "<<nd<<"\t";
//cout<<"\nRemain :"<<remain;
display();
if(nd<=4)
cout<<"\tGRANTED & PAID";
else
{
cout<<"\tREJECTED";
}
cout<<"\n";
}
file.close();

}

void el::ele()
{
char ch='y';
fstream file;
file.open("maternity",ios::ate|ios::in|ios::out|ios::binary);

if(file==NULL)
{
cout<<"\n file creation error!!!!!!!!!!!!!";
getch();
exit(0);
}
while(ch=='y'||ch=='Y')
{
cout<<"\n Enter The Employee Id Number : ";
cin>>empno;
if(empno==0)
break;
	//change*********************************
elst(empno);

	//chnage**********************************
allocation::get();
nd=nod(dd,mm,yy,dd1,mm1,yy1);

cout << "\n No Of Days Of Leave : " <<nd ;
if(nd<=el1.aly&&nd<=el1.alm[mm-1])
{
 cout<<"\n Leave Is Possible ";
 }
 else
 {
// cout<<"\n Already Leave Full For This Month"<<endl;
 }

cout<<"\n Number of days in Maternity Leave :"<<nd;

file.write((char*)&el1,sizeof(el1));
cout<<"\n\nWant To Apply for Maternity Leave For Another Employee(Y/N) : ";
cin>>ch;
}
file.close();
}

void el::elst(int elemnu)
{
int temp=0;
fstream f;      //filename ch
f.open("maternity",ios::ate|ios::in|ios::out|ios::binary);
f.seekg(0);
while(f.read((char*)&ml1,sizeof(ml1)))
{

if(elemnu==el1.empno)
{		       //need to change empno to mpn
cout<<"\n---------------------------------------------------";
cout<<"\nID :"<<empno;
cout<<"\nLeave :"<<nd;
//cout<<"\nRemain :"<<remain;
display();
temp=temp+el1.nd;

cout<<"\nTotal number of leaves left :"<<(clay-temp);

cout<<"\n---------------------------------------------------";

}
el1.empno=elemnu;
}
f.close();

}

void el::el_display()
{
cout<<"\n\n---------------------------------- MATERNITY LEAVE INQUIRY -------------------------------";
cout<<"\nID"<<"\t  "<<"LEAVE"<<"\t\t "<<"FROM"<<"\t\t  "<<"TO"<<"\t\t     "<<"STATUS";
cout<<"\n-------------------------------------------------------------------------------";
}


void el::ele_display()
{
fstream file;      //filename ch
file.open("maternity",ios::ate|ios::in|ios::out|ios::binary);
file.seekg(0);
el_display();
while(file.read((char*)&el1,sizeof(el1)))
{
cout<<"\n"<<empno<<"\t   "<<nd<<"\t";
display();
if(nd<=186)
cout<<"\tGRANTED & PAID";
else
{
cout<<"\tREJECTED";
}
cout<<"\n";
}
file.close();

}




/*
void el::ele()
{
char ch='y';
fstream file;
file.open("earned",ios::ate|ios::in|ios::out|ios::app|ios::binary);
if(file==NULL)
{
cout<<"\n file creation error!!!!!!!!!!!!!";
getch();
exit(0);
}
while(ch=='y'||ch=='Y')
{
cout<<"\n entre the employee id number:::---> ";
cin>>empno;
if(empno==0)
break;
cout<<"\n enter the number of the el taken:::---> ";
cin>>no;
allocation::get();

nd=nod(dd,mm,yy,dd1,mm1,yy1);

cout << "\n No of days of leave : " <<nd ;
if(nd<=el1.aly&&nd<=el1.alm[mm-1])
{
 cout<<"\n leave can be possible for this "<<mm<<" month "<<endl;
 }
 else
 {
 cout<<"\n already leave full for this month"<<endl;
 }

cout<<"\n the number of the ml taken:::---> "<<nd;
cin>>no;
cout<<"\n enter the remaining ml:::---> ";
cin>>remain;

cout<<"\n want to enter the cl data for another employee(y/n):::---> ";
cin>>ch;
file.write((char*)&el1,sizeof(el1));
}
file.close();
}

void el::ele_display()
{
fstream file;      //filename ch
file.open("earned",ios::ate|ios::in|ios::out|ios::binary);
file.seekg(0);
while(file.read((char*)&el1,sizeof(el1)))
{                        //need to change empno to mpn
cout<<"\n---------------------------------------------------";
cout<<"\nID :"<<empno;
cout<<"\nleave :"<<nd;
cout<<"\nRemain :"<<remain;
display();
if(nd<=2)
cout<<"\nSTATUS : GRANTED & PAID";
else
{
cout<<"\nSTATUS : REJECTED";
}
cout<<"\n---------------------------------------------------";

}
file.close();

}
  */

/*
void el::el_display()
{
cout<<"\n\n****************EL STATUS*****************";
cout<<"\n\n ID NUMBER "<<"\t"<<"REMAINING"<<"\t|||||"<<"\t\t"<<"FROM DATE"<<"\t"<<"TO DATE ";
cout<<"\n---------------------------------------------------------------------------";
}
void el::ele_display()
{
fstream file;
file.open("earned",ios::ate|ios::in|ios::out|ios::binary);
file.seekg(0);
el_display();
while(file.read((char*)&el1,sizeof(el1)))
{
cout<<"\n "<<empno<<"\t\t"<<remain;
display();
}
file.close();
} */

