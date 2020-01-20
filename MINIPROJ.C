#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
void drawCloud(int x,int y)
{
		int r=40;

		arc(x,y,45,135,r);
		arc(x+50,y,45,135,r);
		arc(x+100,y,45,135,r);
		arc(x,y,135,225,r);
		arc(x+50,y,135+90,225+90,r);
		arc(x,y,135+90,225+90,r);
		arc(x+100,y,135+90,225+90,r);
		arc(x+100,y,315,45,r);
}

void tagName()
{
	settextstyle(2,0,6);
	outtextxy(195,460,"Designed & Developed By : Motasim @7409856583");
}
void main()
{
	int gd=DETECT,gm;
	int rhx,rhy,j,i;
	static int count=0;
	clrscr();
	initgraph(&gd,&gm,"");

	while(!kbhit()){

		for(i=0;i<600;i+=5){

			if(!kbhit()){
				count++;
				drawCloud(50+count,70);
				setfillstyle(SOLID_FILL,BLUE);
				floodfill(60+count,60,WHITE);
				drawCloud(350+count,90);
				floodfill(360+count,80,WHITE);

				tagName();

				line(0,380,639,380); //platform
				setfillstyle(LTSLASH_FILL,BROWN);
				floodfill(0,390,WHITE);

				if(i%2==0){
					line(25+i,380,35+i,340); //leftleg
					line(45+i,380,35+i,340);//right leg
					line(35+i,310,25+i,330);//left hand
					delay(20);
				}
				else{
					line(35+i,380,35+i,340);
					line(35+i,310,40+i,330);
					delay(20);
				}
				line(35+i,340,35+i,310); //body
				circle(35+i,300,10); //head
				line(35+i,310,50+i,330); // hand
				line(50+i,330,50+i,280); //umbrella stick
				line(15+i,280,85+i,280); //umbrella right

				setfillstyle(INTERLEAVE_FILL,RED);
				floodfill(55+i,280,WHITE);
				pieslice(50+i,280,0,180,35); //umbrella body
				arc(55+i,330,180,360,5);//umbrella handle
				rhx=getmaxx();
				rhy=getmaxy();
				for(j=0;j<100;j++){

					setcolor(BLUE);
					outtextxy(random(rhx),random(rhy-50),"|");

					setcolor(WHITE);
				}
				delay(150);
				cleardevice();
			}

		}

	}


	getch();
}