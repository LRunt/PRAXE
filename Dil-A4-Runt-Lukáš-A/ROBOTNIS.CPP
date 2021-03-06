#include <stdio.h>
#include <conio.h>
#include <dos.h>

int PORTA=0x301;   //Nadefinov�n� port� a prom�n�ch
int PORTB=0x300;
int stisk;
int a =0;
int mask;
int zakladna=0;
int hlrameno=0;
int rameno=0;
int chnapka=0;

void main()
{
do             //Nastaven� z�kladny do nulov�ho bodu(IR z�vora z�klady)
{
mask=0x1;
zakladna=inportb(PORTB); //Na��t�m data
zakladna=zakladna&mask;  //Maskuji ostatn� bity
outportb(PORTA,0x6E);    //Zap�n�m motor z�kladny
printf("Prob�h� nastavov�n� nulov�ho bodu z�kladny\n");
}while(zakladna!=0);     //kdy� je z�kladna na z�vo�e, p�estane se nastavovat nulov� bod
outportb(PORTA,0xFF);    //Vyp�n�m motory
do
{
mask=0x2;
hlrameno=inportb(PORTB); //Na��t�m data
hlrameno=hlrameno&mask;  //Maskuji ostatn� bity
outportb(PORTA,0x6D);    //Zap�n�m motor hlramena
printf("Prob�h� nastavov�n� nulov�ho bodu hlavn�ho ramena\n");
}while(hlrameno!=0);     //kdy� je hlrameno na z�vo�e, p�estane se nastavovat nulov� bod
outportb(PORTA,0xFF);    //Vyp�n�m motory
do
{
mask=0x4;
rameno=inportb(PORTB);  //Na��t�m data
rameno=rameno&mask;     //Maskuji ostatn� bity
outportb(PORTA,0x7B);   //Zap�n�m motor ramena
printf("Prob�h� nastavov�n� nulov� polohy ramena s ch�apkou");
}while(rameno!=0);      //Kdy� je rameno na z�vo�e, p�estane se nastavovat nulov� bod
outportb(PORTA,0xFF);   //Vyp�n�m motory
do
{
mask=0x08;
chnapka=inport(PORTB);  //Na��t�m data
chnapka=chnapka&mask;   //Maskuji ostatn� bity
outportb(PORTA,0x67);   //Zap�n�m motor ch�apky
printf("Prob�h� nastavov�n� nulov� polohy ch�apky");
}while(chnapka!=0);     //Kdy� je ch�apka na z�vo�e, p�estane se nastavovat nulov� bod
outportb(PORTA,0xFF);   //Vyp�n�m motory
clrscr();
printf("Ovl�d�n�:\n");
printf("Ot��en� z�kladny: a-doleva d-doprava\n");
printf("Pohybov�n� hlavn�m ramenem: w-nahoru s-dolu\n");
printf("Pohybov�n� ramenem s ch�apkou: r-nahoru f-dolu\n");
printf("Ovl�d�n� ch�apky: q-k sob� e-od sebe\n\n");
printf("Tla��tko ESC zav�e program\n");
do
{
if(kbhit)         //nastavuji aby stisk reagoval na zm��nut� kl�ves
{
stisk=getch();
}
if(stisk==0)     //Kdy� nen� stla�eno ��dn� tla��tko vyp�n�m motory
{
outportb(PORTA,0xFF);
}
if(stisk==97)    //a - ot��en� z�klady doleva
{
if(zakladna==0)  //Kdy� je z�kladna na z�vo�e nezap�n�m motory
{
printf("Bylo dasa�eno koncov� polohy z�kladny\n");
outportb(PORTA,0xFF);
stisk=0;
}
else             //kdy� nen� z�kladna na z�vo�e zap�n�m motory
{
printf("Z�kladna se pohybuje vlevo\n");
zakladna=zakladna-1;
outportb(PORTA,0xEE);
stisk=0;
}
}break;
if(stisk==100)   //d- ot��en� z�kladny doprava
{
if(zakladna==400)  //nastavil jsem druh� koncov� bod na 400
{
outportb(PORTA,0xFF);
printf("Bylo dosa�eno koncov� polohy z�kladny\n");
stisk=0;
}
else               //kdy� nen� z�kladna na koncov�m bodu zap�n�m motory
{
printf("Z�kladna se pohybuje vpravo\n");
outportb(PORTA,0xFE);
zakladna=zakladna+1;
stisk=0;
}
}break;
if(stisk==119)     //w- hlrameno nahoru
{
if(hlrameno==0)   //kdy� je hlrameno na z�vo�e nezap�n�m motory
{
printf("Bylo dosa�eno koncov� polohy hlavn�ho ramena\n");
outportb(PORTA,0xFF);
stisk=0;
}
else              //kdy� nen� z�kladna na z�vo�e zap�n�m motory
{
printf("Hlavn� rameno se pohybuje nahoru\n");
stisk=0;
hlrameno=hlrameno-1;
outportb(PORTA,0xED);
}
}break;
if(stisk==115)     //s - hlrameno dolu
{
if(hlrameno==400)   //druhou z�voru jem nastavil na 400
{
printf("Bylo dosa�eno koncov� polohy hlavn�ho ramena\n");
outportb(PORTA,0xFF);
stisk=0;
}
else            //kdy� nen� hlrameno na koncov�m bodu zap�n�m motory
{
hlrameno=hlrameno+1;
printf("Hlavn� rameno se pohybuje dolu\n");
outportb(PORTA,0xFD);
stisk=0;
}
}break;
if(stisk==114)    //r- rameno s ch�apkou nahoru
{
if(rameno==0)    //kdy� je rameno na z�vo�e nezap�n�m motory
{
printf("Bylo dosa�eno koncov� polohy ramena s ch�apkou\n");
outportb(PORTA,0xFF);
stisk=0;
}
else            //kdy� nen� rameno na z�kladn� zap�n�m motory
{
printf("Rameno s ch�apkou se pohybuje nahoru\n");
rameno=rameno-1;
outportb(PORTA,0xFB);
stisk=0;
}
}break;
if(stisk==102)     //f- rameno s ch�apkou dolu
{
if(rameno==400)    //nastavuji 2. z�voru na 400
{
printf("Dosa�eno koncov� polohy ramena s ch�apkou\n");
outportb(PORTA,0xFF);
stisk=0;
}
else              //kdy� nen� rameno na koncov�m bodu zap�n�m motory
{
printf("Rameno s ch�apkou se pohybuje dolu\n");
rameno=rameno+1;
outportb(PORTA,0xEB);
stisk=0;
}
}break;
if(stisk==113)         //q- ch�apka od sebe
{
if(chnapka==400)      //Nastavuji 2. z�voru na 400
{
printf("Dosa�ena konsov� poloha ch�apky\n");
outportb(PORTA,0xFF);
stisk=0;
}
else               //Kdy� ch�apka nen� na z�vo�e zap�n�m motory
{
printf("Ch�apka se pohybuje k sob�\n");
chnapka=chnapka+1;
outportb(PORTA,0xF7);
stisk=0;
}
}break;
if(stisk==101)           //e- ch�apka od sebe
{
if(chnapka==0)
{
printf("Dosa�ena koncov� poloha chnapky\n");
outportb(PORTA,0xFF);
stisk=0;
}
else                //Kdy� nen� ch�apka na koncov� poloze vyp�n�m motory
{
printf("Ch�apka se pohybuje od sebe\n");
chnapka=chnapka-1;
outportb(PORTA,0xE7);
stisk=0;
}
}break;
if(stisk==27) //Konec programu p�i stisku ESC
{
a=a+1;        //Aby byla poru�ena podm�nka a byl ukon�en program
}
}while(a==0);
}