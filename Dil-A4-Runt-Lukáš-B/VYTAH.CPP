#include <stdio.h>
#include <conio.h>
#include <dos.h>
int PortA= 0x300; //P1 P3
int PortB= 0x301; //P2 P4
int klavesnice;
int dvere;
int podlaha;
int tlacitko;
int TL1V;	//Tlaèítko uvnitø kabiny v patøe 1
int TL1U;   //Tlaèítko  v patøe 1
int TL2V;	//Tlaèítko uvnitø kabiny v patøe 2
int TL2U;	//Tlaèítko  v patøe 2
int TL3V;	//Tlaèítko uvnitø kabiny v patøe 3
int TL3U;	//Tlaèítko  v patøe 3
int TL4V;	//Tlaèítko uvnitø kabiny v patøe 4
int TL4U;	//Tlaèítko  v patøe 4
int a =0; //ukonŸení programu
int b;    //aktuální patro vıtahu
int c;    //tlaèítko uvnitø vıtahu (poadované patro)
int snimac;
int snimac1;
int snimac2;
int snimac3;
int snimac4;
int mask1 = 0xFE; //Maska dveri a TL1V
int mask2 = 0xFB; //Maska podlahy a TL2V
int mask3 = 0xFD; //Maska TL1U a cidla1
int mask4 = 0xF7; //Maska TL2U a cidla2
int mask5 = 0xEF; //Maska TL3V
int mask6 = 0xDF; //Maska TL3U a cidla3
int mask7 = 0xBF; //Maska TL4V
int mask8 = 0x7F; //Maska TL4U a cidla4

void main()
{
	outportb(PortB,0xFF);	//Vypínám  motory (ve vıtahu je neznámı program)
	clrscr();
	printf("Zadej ve kterem je vytah patre\n");	//Musím zjistit ve kterém je vıtah patøe, vıtah mùe bıt i v mezipatøe, proto ruèní zadání na zaèátku programu
	scanf("%d",&b);
	printf("Vytah je v %d",b);
	printf(" patre\n");
	printf("Vypnuti programu - ESC\n");
	b=c;
	do
	{
		podlaha=inportb(PortA);	//Naèítam data z portuA
		podlaha=podlaha|mask2;	//Maskuji 
		if(podlaha==0xFB)		//Zjišuji zda je nìkdo v kabinì, kdy nìkdo v kabinì je, svìtlo v kabinì vdy svítí, jdou poívat jen tlaèítka uvnitø
		{
			if(b==1)
			outportb(PortA,0x79);	//Zapnutí svìtla v kabinì, rozsvícení èíslice 1 na displeji
			if(b==2)
			outportb(PortA,0x7A);	//Zapnutí svìtla v kabinì, rozsvícení èíslice 2 na displeji
			if(b==3)
			outportb(PortA,0x7B);	//Zapnutí svìtla v kabinì, rozsvícení èíslice 3 na displeji
			if(b==4)
			outportb(PortA,0x7C);	//Zapnutí svìtla v kabinì, rozsvícení èíslice 4 na displeji
			tlacitko=inportb(PortB);	//Testuji jen tlaèítka uvnitø
			TL1U=tlacitko|mask3;
			TL2U=tlacitko|mask4;
			TL3U=tlacitko|mask6;
			TL4U=tlacitko|mask8;
			if(TL1U==0xFD)			//Testuji zda není stisknuto tlaèítko 1 uvnitø
			c=1;
			if(TL2U==0xF7)			//Testuji zda není stisknuto tlaèítko 2 uvnitø
			c=2;
			if(TL3U==0xDF)			//Testuji zda není stisknuto tlaèítko 3 uvnitø
			c=3;
			if(TL4U==0x7F)			//Testuji zda není stisknuto tlaèítko 4 uvnitø
			c=4;
			if(b<c) //Vıtah pojede nahoru
			{
				do
				{
					dvere=inportb(PortA);
					dvere=dvere|mask1;
					if(dvere==0xFE)		//testuji zda jsou otevøeny dveøe
					{
						outportb(PortB,0xFF);	//dveøe jsou otevøeny, zastavuji vıtah
						printf("Zavrete dvere\n");
					}
					else
					{
						outportb(PortB,0x6F); //vıtah se rozjídí nahoru, Led šipka nahoru svítí
						snimac=inportb(PortA);
						snimac1=snimac|mask3;	
						snimac2=snimac|mask4;
						snimac3=snimac|mask6;
						snimac4=snimac|mask8;
						if(snimac1==0xFD)		//Testuji jestli není vıtah v patøe 1
						b=1;
						if(snimac2==0xF7)		//Testuji jestli není vıtah v patøe 2 
						b=2;
						if(snimac3==0xDF)		//Testuji jestli není vıtah v patøe 3
						b=3;
						if(snimac4==0x7F)		//Testuji jestli není vıtah v patøe 4
						b=4;
					}
				}while(b==c);					//Kdy je vıtah v poadovaném patøe cyklus konèí
				outportb(PortB,0xFF);			//Zastavuji vıtah
			}
			if(b>c); //Vıtah pojede dolu
			{
				do
				{
					dvere=inportb(PortA);
					dvere=dvere|mask1;
					if(dvere==0xFE)		//testuji zda jsou otevøeny dveøe
					{
						outportb(PortB,0xFF);		//dveøe jsou otevøeny, zastavuji vıtah
						printf("Zavrete dvere\n");
					}
					else
					{
						outportb(PortB,0x37);	//vıtah se rozjídí dolù, Led šipka dolù svítí
						snimac=inportb(PortA);
						snimac1=snimac|mask3;
						snimac2=snimac|mask4;
						snimac3=snimac|mask6;
						snimac4=snimac|mask8;
						if(snimac1==0xFD)	//Testuji jestli není vıtah v patøe 1
						b=1;
						if(snimac2==0xF7)	//Testuji jestli není vıtah v patøe 2
						b=2;
						if(snimac3==0xDF)	//Testuji jestli není vıtah v patøe 3
						b=3;
						if(snimac4==0x7F)	//Testuji jestli není vıtah v patøe 4
						b=4;
					}
				}while(b==c);			//Kdy je vıtah v poadovaném patøe cyklus konèí
				outportb(PortB,0xFF);	//Zastavuji vıtah
			}
		}
		else	//V kabinì nìkdo není, testuji tlaèítka venku
		{
			if(b==1)
			outportb(PortA,0xF9);	//Svìtlo v kabinì nesvítí, rozsvícení èíslice 1 na displeji
			if(b==2)
			outportb(PortA,0xFA);	//Svìtlo v kabinì nesvítí, rozsvícení èíslice 2 na displeji
			if(b==3)
			outportb(PortA,0xFB);	//Svìtlo v kabinì nesvítí, rozsvícení èíslice 3 na displeji
			if(b==4)
			outportb(PortA,0xFC);	//Svìtlo v kabinì nesvítí, rozsvícení èíslice 4 na displeji
			tlacitko=inportb(PortB);
			TL1V=tlacitko|mask1;
			TL2V=tlacitko|mask2;
			TL3V=tlacitko|mask5;
			TL4V=tlacitko|mask7;
			if(TL1V==0xFE)		//Testuji zda je stisknuto tlaèítko 1 v patøe
			c=1;
			if(TL2V==0xFB)		//Testuji zda je stisknuto tlaèítko 2 v patøe
			c=2;
			if(TL3V==0xDF)		//Testuji zda je stisknuto tlaèítko 3 v patøe
			c=3;
			if(TL4V==0xBF)		//Testuji zda je stisknuto tlaèítko 4 v patøe
			c=4;
			if(b<c)		//Vıtah pojede nahoru
			{
				do
				{
					dvere=inportb(PortA);	
					dvere=dvere|mask1;
					if(dvere==0xFE)		//testuji zda jsou otevøeny dveøe
					{
						outportb(PortB,0xFF);	//dveøe jsou otevøeny, zastavuji vıtah
						printf("Zavrete dvere\n");
						if(b==1)
						outportb(PortA,0x79);	//Svìtlo v kabinì svítí, rozsvícení èíslice 1 na displeji
						if(b==2)
						outportb(PortA,0x7A);	//Svìtlo v kabinì svítí, rozsvícení èíslice 2 na displeji
						if(b==3)
						outportb(PortA,0x7B);	//Svìtlo v kabinì svítí, rozsvícení èíslice 3 na displeji
						if(b==4)
						outportb(PortA,0x7C);	//Svìtlo v kabinì svítí, rozsvícení èíslice 4 na displeji
					}
					else
					{	
						outportb(PortB,0x6F);		//vıtah se rozjídí nahoru, Led šipka nahoru svítí
						snimac=inportb(PortA);
						snimac1=snimac|mask3;
						snimac2=snimac|mask4;
						snimac3=snimac|mask6;
						snimac4=snimac|mask8;
						if(snimac1==0xFD)		//Testuji jestli není vıtah v patøe 1
						b=1;
						if(snimac2==0xF7)		//Testuji jestli není vıtah v patøe 2
						b=2;
						if(snimac3==0xDF)		//Testuji jestli není vıtah v patøe 3
						b=3;
						if(snimac4==0x7F)		//Testuji jestli není vıtah v patøe 4
						b=4;
					}
				}while(b==c);			//Kdy je vıtah v poadovaném patøe cyklus konèí
				outportb(PortB,0xFF);	//Zastavuji vıtah
			}
			if(b>c)	//Vıtah pojede dolu
			{
				do
				{
					dvere=inportb(PortA);
					dvere=dvere|mask1;
					if(dvere==0xFE)		//testuji zda jsou otevøeny dveøe
					{
						outportb(PortB,0xFF);		//dveøe jsou otevøeny, zastavuji vıtah
						printf("Zavrete dvere\n");
						if(b==1)
						outportb(PortA,0x79);	//Svìtlo v kabinì svítí, rozsvícení èíslice 1 na displeji
						if(b==2)
						outportb(PortA,0x7A);	//Svìtlo v kabinì svítí, rozsvícení èíslice 2 na displeji
						if(b==3)
						outportb(PortA,0x7B);	//Svìtlo v kabinì svítí, rozsvícení èíslice 3 na displeji
						if(b==4)
						outportb(PortA,0x7C);	//Svìtlo v kabinì svítí, rozsvícení èíslice 4 na displeji
					}
					else
					{
						outportb(PortB,0x37);		//vıtah se rozjídí dolù, Led šipka dolù svítí
						snimac=inportb(PortA);
						snimac1=snimac|mask3;
						snimac2=snimac|mask4;
						snimac3=snimac|mask6;
						snimac4=snimac|mask8;
						if(snimac1==0xFD)	//Testuji jestli není vıtah v patøe 1
						b=1;
						if(snimac2==0xF7)	//Testuji jestli není vıtah v patøe 2
						b=2;
						if(snimac3==0xDF)	//Testuji jestli není vıtah v patøe 3
						b=3;
						if(snimac4==0x7F)	//Testuji jestli není vıtah v patøe 4
						b=4;
					}
				}while(b==c);			//Kdy je vıtah v poadovaném patøe cyklus konèí
				outportb(PortB,0xFF);	//Zastavuji vıtah
			}
		dvere=inportb(PortA);	
		dvere=dvere|mask1;
		if(dvere==0xFE)		//testuji zda jsou otevøeny dveøe
		{
			if(b==1)
			outportb(PortA,0x79);	//Svìtlo v kabinì svítí, rozsvícení èíslice 1 na displeji
			if(b==2)
			outportb(PortA,0x7A);	//Svìtlo v kabinì svítí, rozsvícení èíslice 2 na displeji
			if(b==3)
			outportb(PortA,0x7B);	//Svìtlo v kabinì svítí, rozsvícení èíslice 3 na displeji
			if(b==4)
			outportb(PortA,0x7C);	//Svìtlo v kabinì svítí, rozsvícení èíslice 4 na displeji
		}
		if(kbhit)
		{
			klavesnice=getch();
		}
		if(klavesnice==27)  //Identifikuje ESC -> vypne program
		{
			a=a+1;
		}
	}while(a==0);
}

