#include <stdio.h>
#include <conio.h>
#include <dos.h>
int PortA= 0x300; //P1 P3
int PortB= 0x301; //P2 P4
int klavesnice;
int dvere;
int podlaha;
int tlacitko;
int TL1V;	//Tla��tko uvnit� kabiny v pat�e 1
int TL1U;   //Tla��tko  v pat�e 1
int TL2V;	//Tla��tko uvnit� kabiny v pat�e 2
int TL2U;	//Tla��tko  v pat�e 2
int TL3V;	//Tla��tko uvnit� kabiny v pat�e 3
int TL3U;	//Tla��tko  v pat�e 3
int TL4V;	//Tla��tko uvnit� kabiny v pat�e 4
int TL4U;	//Tla��tko  v pat�e 4
int a =0; //ukon�en� programu
int b;    //aktu�ln� patro v�tahu
int c;    //tla��tko uvnit� v�tahu (po�adovan� patro)
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
	outportb(PortB,0xFF);	//Vyp�n�m  motory (ve v�tahu je nezn�m� program)
	clrscr();
	printf("Zadej ve kterem je vytah patre\n");	//Mus�m zjistit ve kter�m je v�tah pat�e, v�tah m��e b�t i v mezipat�e, proto ru�n� zad�n� na za��tku programu
	scanf("%d",&b);
	printf("Vytah je v %d",b);
	printf(" patre\n");
	printf("Vypnuti programu - ESC\n");
	b=c;
	do
	{
		podlaha=inportb(PortA);	//Na��tam data z portuA
		podlaha=podlaha|mask2;	//Maskuji 
		if(podlaha==0xFB)		//Zji��uji zda je n�kdo v kabin�, kdy� n�kdo v kabin� je, sv�tlo v kabin� v�dy sv�t�, jdou po��vat jen tla��tka uvnit�
		{
			if(b==1)
			outportb(PortA,0x79);	//Zapnut� sv�tla v kabin�, rozsv�cen� ��slice 1 na displeji
			if(b==2)
			outportb(PortA,0x7A);	//Zapnut� sv�tla v kabin�, rozsv�cen� ��slice 2 na displeji
			if(b==3)
			outportb(PortA,0x7B);	//Zapnut� sv�tla v kabin�, rozsv�cen� ��slice 3 na displeji
			if(b==4)
			outportb(PortA,0x7C);	//Zapnut� sv�tla v kabin�, rozsv�cen� ��slice 4 na displeji
			tlacitko=inportb(PortB);	//Testuji jen tla��tka uvnit�
			TL1U=tlacitko|mask3;
			TL2U=tlacitko|mask4;
			TL3U=tlacitko|mask6;
			TL4U=tlacitko|mask8;
			if(TL1U==0xFD)			//Testuji zda nen� stisknuto tla��tko 1 uvnit�
			c=1;
			if(TL2U==0xF7)			//Testuji zda nen� stisknuto tla��tko 2 uvnit�
			c=2;
			if(TL3U==0xDF)			//Testuji zda nen� stisknuto tla��tko 3 uvnit�
			c=3;
			if(TL4U==0x7F)			//Testuji zda nen� stisknuto tla��tko 4 uvnit�
			c=4;
			if(b<c) //V�tah pojede nahoru
			{
				do
				{
					dvere=inportb(PortA);
					dvere=dvere|mask1;
					if(dvere==0xFE)		//testuji zda jsou otev�eny dve�e
					{
						outportb(PortB,0xFF);	//dve�e jsou otev�eny, zastavuji v�tah
						printf("Zavrete dvere\n");
					}
					else
					{
						outportb(PortB,0x6F); //v�tah se rozj�d� nahoru, Led �ipka nahoru sv�t�
						snimac=inportb(PortA);
						snimac1=snimac|mask3;	
						snimac2=snimac|mask4;
						snimac3=snimac|mask6;
						snimac4=snimac|mask8;
						if(snimac1==0xFD)		//Testuji jestli nen� v�tah v pat�e 1
						b=1;
						if(snimac2==0xF7)		//Testuji jestli nen� v�tah v pat�e 2 
						b=2;
						if(snimac3==0xDF)		//Testuji jestli nen� v�tah v pat�e 3
						b=3;
						if(snimac4==0x7F)		//Testuji jestli nen� v�tah v pat�e 4
						b=4;
					}
				}while(b==c);					//Kdy� je v�tah v po�adovan�m pat�e cyklus kon��
				outportb(PortB,0xFF);			//Zastavuji v�tah
			}
			if(b>c); //V�tah pojede dolu
			{
				do
				{
					dvere=inportb(PortA);
					dvere=dvere|mask1;
					if(dvere==0xFE)		//testuji zda jsou otev�eny dve�e
					{
						outportb(PortB,0xFF);		//dve�e jsou otev�eny, zastavuji v�tah
						printf("Zavrete dvere\n");
					}
					else
					{
						outportb(PortB,0x37);	//v�tah se rozj�d� dol�, Led �ipka dol� sv�t�
						snimac=inportb(PortA);
						snimac1=snimac|mask3;
						snimac2=snimac|mask4;
						snimac3=snimac|mask6;
						snimac4=snimac|mask8;
						if(snimac1==0xFD)	//Testuji jestli nen� v�tah v pat�e 1
						b=1;
						if(snimac2==0xF7)	//Testuji jestli nen� v�tah v pat�e 2
						b=2;
						if(snimac3==0xDF)	//Testuji jestli nen� v�tah v pat�e 3
						b=3;
						if(snimac4==0x7F)	//Testuji jestli nen� v�tah v pat�e 4
						b=4;
					}
				}while(b==c);			//Kdy� je v�tah v po�adovan�m pat�e cyklus kon��
				outportb(PortB,0xFF);	//Zastavuji v�tah
			}
		}
		else	//V kabin� n�kdo nen�, testuji tla��tka venku
		{
			if(b==1)
			outportb(PortA,0xF9);	//Sv�tlo v kabin� nesv�t�, rozsv�cen� ��slice 1 na displeji
			if(b==2)
			outportb(PortA,0xFA);	//Sv�tlo v kabin� nesv�t�, rozsv�cen� ��slice 2 na displeji
			if(b==3)
			outportb(PortA,0xFB);	//Sv�tlo v kabin� nesv�t�, rozsv�cen� ��slice 3 na displeji
			if(b==4)
			outportb(PortA,0xFC);	//Sv�tlo v kabin� nesv�t�, rozsv�cen� ��slice 4 na displeji
			tlacitko=inportb(PortB);
			TL1V=tlacitko|mask1;
			TL2V=tlacitko|mask2;
			TL3V=tlacitko|mask5;
			TL4V=tlacitko|mask7;
			if(TL1V==0xFE)		//Testuji zda je stisknuto tla��tko 1 v pat�e
			c=1;
			if(TL2V==0xFB)		//Testuji zda je stisknuto tla��tko 2 v pat�e
			c=2;
			if(TL3V==0xDF)		//Testuji zda je stisknuto tla��tko 3 v pat�e
			c=3;
			if(TL4V==0xBF)		//Testuji zda je stisknuto tla��tko 4 v pat�e
			c=4;
			if(b<c)		//V�tah pojede nahoru
			{
				do
				{
					dvere=inportb(PortA);	
					dvere=dvere|mask1;
					if(dvere==0xFE)		//testuji zda jsou otev�eny dve�e
					{
						outportb(PortB,0xFF);	//dve�e jsou otev�eny, zastavuji v�tah
						printf("Zavrete dvere\n");
						if(b==1)
						outportb(PortA,0x79);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 1 na displeji
						if(b==2)
						outportb(PortA,0x7A);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 2 na displeji
						if(b==3)
						outportb(PortA,0x7B);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 3 na displeji
						if(b==4)
						outportb(PortA,0x7C);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 4 na displeji
					}
					else
					{	
						outportb(PortB,0x6F);		//v�tah se rozj�d� nahoru, Led �ipka nahoru sv�t�
						snimac=inportb(PortA);
						snimac1=snimac|mask3;
						snimac2=snimac|mask4;
						snimac3=snimac|mask6;
						snimac4=snimac|mask8;
						if(snimac1==0xFD)		//Testuji jestli nen� v�tah v pat�e 1
						b=1;
						if(snimac2==0xF7)		//Testuji jestli nen� v�tah v pat�e 2
						b=2;
						if(snimac3==0xDF)		//Testuji jestli nen� v�tah v pat�e 3
						b=3;
						if(snimac4==0x7F)		//Testuji jestli nen� v�tah v pat�e 4
						b=4;
					}
				}while(b==c);			//Kdy� je v�tah v po�adovan�m pat�e cyklus kon��
				outportb(PortB,0xFF);	//Zastavuji v�tah
			}
			if(b>c)	//V�tah pojede dolu
			{
				do
				{
					dvere=inportb(PortA);
					dvere=dvere|mask1;
					if(dvere==0xFE)		//testuji zda jsou otev�eny dve�e
					{
						outportb(PortB,0xFF);		//dve�e jsou otev�eny, zastavuji v�tah
						printf("Zavrete dvere\n");
						if(b==1)
						outportb(PortA,0x79);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 1 na displeji
						if(b==2)
						outportb(PortA,0x7A);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 2 na displeji
						if(b==3)
						outportb(PortA,0x7B);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 3 na displeji
						if(b==4)
						outportb(PortA,0x7C);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 4 na displeji
					}
					else
					{
						outportb(PortB,0x37);		//v�tah se rozj�d� dol�, Led �ipka dol� sv�t�
						snimac=inportb(PortA);
						snimac1=snimac|mask3;
						snimac2=snimac|mask4;
						snimac3=snimac|mask6;
						snimac4=snimac|mask8;
						if(snimac1==0xFD)	//Testuji jestli nen� v�tah v pat�e 1
						b=1;
						if(snimac2==0xF7)	//Testuji jestli nen� v�tah v pat�e 2
						b=2;
						if(snimac3==0xDF)	//Testuji jestli nen� v�tah v pat�e 3
						b=3;
						if(snimac4==0x7F)	//Testuji jestli nen� v�tah v pat�e 4
						b=4;
					}
				}while(b==c);			//Kdy� je v�tah v po�adovan�m pat�e cyklus kon��
				outportb(PortB,0xFF);	//Zastavuji v�tah
			}
		dvere=inportb(PortA);	
		dvere=dvere|mask1;
		if(dvere==0xFE)		//testuji zda jsou otev�eny dve�e
		{
			if(b==1)
			outportb(PortA,0x79);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 1 na displeji
			if(b==2)
			outportb(PortA,0x7A);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 2 na displeji
			if(b==3)
			outportb(PortA,0x7B);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 3 na displeji
			if(b==4)
			outportb(PortA,0x7C);	//Sv�tlo v kabin� sv�t�, rozsv�cen� ��slice 4 na displeji
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

