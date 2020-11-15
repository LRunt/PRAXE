#include<stdio.h>
#include<conio.h>
#include<dos.h>
int CLK=0x300;  //nadefinování výstupu pro hodinový signál
int DATA=0x301; //nadefinování výstupu pro data
int nul[7]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00};  //pole pro každý znak na numerickém displeji 
int jdn[7]={0x00,0xFF,0xFF,0x00,0x00,0x00,0x00};
int dva[7]={0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF};
int tri[7]={0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF};
int ctr[7]={0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF};
int pet[7]={0xFF,0x00,0xFF,0xFF,0x00,0xFF,0xFF};
int ses[7]={0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0xFF};
int sdm[7]={0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00};
int osm[7]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
int dvt[7]={0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0xFF};
//             a    b     c   d    e    f    g    h    j    k    l    m    n    p    D.P
int nula[15]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};  //pole pro každý znak na alfanumerickém displeji
int jedn[15]={0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int dvaa[15]={0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int tria[15]={0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int ctyr[15]={0x00,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int peta[15]={0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int sest[15]={0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int sedm[15]={0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int osma[15]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int deve[15]={0xFF,0xFF,0xFF,0xFF,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int aaaa[15]={0xFF,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int bbbb[15]={0x00,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int cccc[15]={0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int dddd[15]={0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int eeee[15]={0xFF,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int ffff[15]={0xFF,0x00,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int gggg[15]={0xFF,0x00,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00};
int hhhh[15]={0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int iiii[15]={0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00};
int jjjj[15]={0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int kkkk[15]={0x00,0x00,0x00,0x00,0xFF,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00};
int llll[15]={0x00,0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int mmmm[15]={0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0xFF,0x00};
int nnnn[15]={0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00};
int oooo[15]={0x00,0x00,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int pppp[15]={0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int qqqq[15]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00};
int rrrr[15]={0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0xFF,0x00,0x00,0xFF,0x00,0x00};
int ssss[15]={0xFF,0x00,0xFF,0xFF,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00};
int tttt[15]={0xFF,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00};
int uuuu[15]={0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
int vvvv[15]={0x00,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00};
int wwww[15]={0x00,0xFF,0xFF,0x00,0xFF,0xFF,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0x00,0x00};
int xxxx[15]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00};
int yyyy[15]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00,0x00,0xFF,0x00};
int zzzz[15]={0xFF,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0xFF,0x00,0x00,0x00};
int volban;
void main()
{
int p = 0;
char volbaa;
char start;
int stisk;
int a;
while(1)
{
printf("Alfanumerak - A\n");
printf("Numerak - N\n");
scanf("%c",&start);
switch(start) // Volba jestli chci použít numerický nebo alfanumerický displej
{
 case 'N': //numerický displej
 {
  outportb(CLK,0x00);  //start bit
  outportb(DATA,0xFF);
  outportb(CLK,0xFF);
  outportb(CLK,0x00);
  clrscr(); //vmazání textu na obrazovce
  for(int kuk=0;kuk<5;kuk++) //5 znakù => 5* cyklus na zadávání znakù, které se budou zobrazovat na displeji.
  {
   printf("Zadejte cislo, ktere chcete zobrazit na displeji: \n");
   scanf("%d",&volban);
   switch(volban) //Urèení která èíslice má být zobrazena
   {
    case 0: // èíslice 0 se má zobrazit na displeji
    {
    for(int l=0;l<7;l++) //cyklus pøi kterém se pošle 7 hodnot do numerického displeje
      {
      printf("%d",nul[l]);  //kontrola (pøi zkoušení programu bez periferie) jestli se pošlou správné hodnoty 
      outportb(DATA,nul[l]); //poslání hodnoty do na datový bit
      outportb(CLK,0xFF); //hodinový signál
      outportb(CLK,0x00);
      }
    }
    break;
    case 1:
    {
    for(int a=0;a<7;a++)
      {
       printf("%d",jdn[a]);
       outportb(DATA,jdn[a]);
       outportb(CLK,0xFF);
       outportb(CLK,0x00);
      }
    }
    break;
    case 2:
    {
    for(int b=0;b<7;b++)
      {
      printf("%d",dva[b]);
      outportb(DATA,dva[b]);
      outportb(CLK,0xFF);
      outportb(CLK,0x00);
      }
    }
    break;
    case 3:
    {
    for(int c=0;c<7;c++)
      {
      printf("%d",tri[c]);
      outportb(DATA,tri[c]);
      outportb(CLK,0xFF);
      outportb(CLK,0x00);
      }
    }
    break;
    case 4:
    {
    for(int d=0;d<7;d++)
      {
      printf("%d",ctr[d]);
      outportb(DATA,ctr[d]);
      outportb(CLK,0xFF);
      outportb(CLK,0x00);
      }
    }
    break;
    case 5:
    {
    for(int e=0;e<7;e++)
      {
      printf("%d",pet[e]);
	  outportb(DATA,pet[e]);
      outportb(CLK,0xFF);
      outportb(CLK,0x00);
      }
    }
    break;
    case 6:
    {
    for(int f=0;f<7;f++)
      {
      printf("%d",ses[f]);
	  outportb(DATA,ses[f]);
	  outportb(CLK,0xFF);
	  outportb(CLK,0x00);
      }
    }
    break;
    case 7:
    {
    for(int i=0;i<7;i++)
      {
      printf("%d",sdm[i]);
	  outportb(DATA,sdm[i]);
	  outportb(CLK,0xFF);
	  outportb(CLK,0x00);
      }
    }
    break;
    case 8:
    {
    for(int j=0;j<7;j++)
      {
      printf("%d",osm[j]);
	  outportb(DATA,osm[j]);
	  outportb(CLK,0xFF);
	  outportb(CLK,0x00);
      }
    }
    break;
    case 9:
    {
    for(int k=0;k<7;k++)
      {
      printf("%d",dvt[k]);
	  outportb(DATA,dvt[k]);
	  outportb(CLK,0xFF);
	  outportb(CLK,0x00);
      }
    }
	break;
   }
  }
  getch();
  break;
 case 'A': //alfanumerický displej
 {
  int pole[72]; //nadefinování pole (2x start bit + 2x poslání všech požadovaných bitù (36bitù))
  p = 0;    //vynulování p - poèítání pod kterým indexem se má uložit do pole bit
  outportb(CLK,0x00); //start bit
  outportb(DATA,0xFF); 
  outportb(CLK,0xFF);
  outportb(CLK,0x00);
  pole[p]=0xFF; //uložení start bitu pod index 0
  p=p+1;  //další index
  clrscr();
  for(int sup=0;sup<8;sup++)
  {
    if(sup==4) // když už jsou zadány 2 znaky musím zaplnit zbylé bity a urcit jestli se sepne tranzistor T1 nebo T2
	{
	  outportb(DATA,0xFF); //data poslány na displeje A1
	  pole[p]=0xFF;
	  p=p+1;
      outportb(CLK,0xFF);
      outportb(CLK,0x00);
	  printf("A1\n");
	  outportb(DATA,0x00);
	  pole[p]=0x00;
	  p=p+1;
	  outportb(CLK,0xFF);
	  outportb(CLK,0x00);
	  for(int rur=0;rur<3;rur++) //zaplnìní zbylých bitù
	  {
	  outportb(DATA,0x00);
	  pole[p]=0x00;
	  p=p+1;
	  outportb(CLK,0xFF);
	  outportb(CLK,0x00);
	  }
	  outportb(DATA,0xFF); //start bit
	  pole[p]=0xFF;
	  p=p+1;
	  outportb(CLK,0xFF);
	  outportb(CLK,0x00);
	}
    printf("Zadejte cislo, ktere chcete zobrazit na displeji: \n");
    scanf("%c",&volbaa);
    switch(volbaa)
	{
	  case '0':  // znak 0 se má zobrazit na displeji
    {
    for(int nn=0;nn<15;nn++) //cyklus pøi kterém se pošle 15 bitù znaku
      {
      printf("%d",nula[nn]); //kontrola (pøi zkoušení programu bez periferie) jestli se pošlou správné hodnoty
      outportb(DATA,nula[nn]); //poslání hodnoty do na datový bit
	  pole[p]=nula[nn]; //uložení hodnoty bitu do pole pod pøíslušný index
      outportb(CLK,0xFF); //hodinový signál
      outportb(CLK,0x00);
	  p=p+1;  //další index
      }
    }
	break;
	  case '1':
      {
      for(int jj=0;jj<15;jj++)
	   {
	  printf("%d",jedn[jj]);
	  outportb(DATA,jedn[jj]);
	  pole[p]=jedn[jj];
	  outportb(CLK,0xFF);
	  outportb(CLK,0x00);
	  p=p+1;
	  }
	  break;
	  case '2':
      {
      for(int dd=0;dd<15;dd++)
	  {
	  printf("%d",dvaa[dd]);
	  outportb(DATA,dvaa[dd]);
	  pole[p]=dvaa[dd];
	  outportb(CLK,0xFF);
	  outportb(CLK,0x00);
	  p=p+1;
	  }
      }
	  break;
	  case '3':
      {
      for(int tt=0;tt<15;tt++)
	    {
	    printf("%d",tria[tt]);
	    outportb(DATA,tria[tt]);
		pole[p]=tria[tt];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	  case '4':
      {
      for(int cc=0;cc<15;cc++)
	    {
	    printf("%d",ctyr[cc]);
	    outportb(DATA,ctyr[cc]);
		pole[p]=ctyr[cc];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	  case '5':
      {
      for(int pp=0;pp<15;pp++)
	    {
	    printf("%d",peta[pp]);
	    outportb(DATA,peta[pp]);
		pole[p]=peta[pp];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	  case '6':
      {
      for(int ss=0;ss<15;ss++)
	    {
	    printf("%d",sest[ss]);
	    outportb(DATA,sest[ss]);
		pole[p]=sest[ss];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	  case '7':
      {
      for(int sss=0;sss<15;sss++)
	    {
	    printf("%d",sedm[sss]);
	    outportb(DATA,sedm[sss]);
		pole[p]=sedm[sss];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	  case '8':
      {
      for(int oo=0;oo<15;oo++)
	    {
	    printf("%d",osma[oo]);
	    outportb(DATA,osma[oo]);
		pole[p]=osma[oo];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	  case '9':
      {
      for(int ddd=0;ddd<15;ddd++)
	    {
	    printf("%d",deve[ddd]);
	    outportb(DATA,deve[ddd]);
		pole[p]=deve[ddd];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	  case 'A':
      {
      for(int aa=0;aa<15;aa++)
	    {
	    printf("%d",aaaa[aa]);
	    outportb(DATA,aaaa[aa]);
		pole[p]=aaaa[aa];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'B':
      {
      for(int bb=0;bb<15;bb++)
	    {
	    printf("%d",bbbb[bb]);
	    outportb(DATA,bbbb[bb]);
		pole[p]=bbbb[bb];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'C':
      {
      for(int ccc=0;ccc<15;ccc++)
	    {
	    printf("%d",cccc[ccc]);
	    outportb(DATA,cccc[ccc]);
		pole[p]=cccc[ccc];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'D':
      {
      for(int ddddd=0;ddddd<15;ddddd++)
	    {
	    printf("%d",dddd[ddddd]);
	    outportb(DATA,dddd[ddddd]);
		pole[p]=dddd[ddddd];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'E':
      {
      for(int ee=0;ee<15;ee++)
	    {
	    printf("%d",eeee[ee]);
	    outportb(DATA,eeee[ee]);
		pole[p]=eeee[ee];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'F':
      {
      for(int ff=0;ff<15;ff++)
	    {
	    printf("%d",ffff[ff]);
	    outportb(DATA,ffff[ff]);
		pole[p]=ffff[ff];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'G':
      {
      for(int gg=0;gg<15;gg++)
	    {
	    printf("%d",gggg[gg]);
	    outportb(DATA,gggg[gg]);
		pole[p]=gggg[gg];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'H':
      {
      for(int hh=0;hh<15;hh++)
	    {
	    printf("%d",hhhh[hh]);
	    outportb(DATA,hhhh[hh]);
		pole[p]=hhhh[hh];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'I':
      {
      for(int ii=0;ii<15;ii++)
	    {
	    printf("%d",iiii[ii]);
	    outportb(DATA,iiii[ii]);
		pole[p]=iiii[ii];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'J':
      {
      for(int jj=0;jj<15;jj++)
	    {
	    printf("%d",jjjj[jj]);
	    outportb(DATA,jjjj[jj]);
		pole[p]=jjjj[jj];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'K':
      {
      for(int kk=0;kk<15;kk++)
	    {
	    printf("%d",kkkk[kk]);
	    outportb(DATA,kkkk[kk]);
		pole[p]=kkkk[kk];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'L':
      {
      for(int ll=0;ll<15;ll++)
	    {
	    printf("%d",llll[ll]);
	    outportb(DATA,llll[ll]);
		pole[p]=llll[ll];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'M':
      {
      for(int mm=0;mm<15;mm++)
	    {
	    printf("%d",mmmm[mm]);
	    outportb(DATA,mmmm[mm]);
		pole[p]=mmmm[mm];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'N':
      {
      for(int nnn=0;nnn<15;nnn++)
	    {
	    printf("%d",nnnn[nnn]);
	    outportb(DATA,nnnn[nnn]);
		pole[p]=nnnn[nnn];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'O':
      {
      for(int ooo=0;ooo<15;ooo++)
	    {
	    printf("%d",oooo[ooo]);
	    outportb(DATA,oooo[ooo]);
		pole[p]=oooo[ooo];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'P':
      {
      for(int ppp=0;ppp<15;ppp++)
	    {
	    printf("%d",pppp[ppp]);
	    outportb(DATA,pppp[ppp]);
		pole[p]=pppp[ppp];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'Q':
      {
      for(int qq=0;qq<15;qq++)
	    {
	    printf("%d",qqqq[qq]);
	    outportb(DATA,qqqq[qq]);
		pole[p]=qqqq[qq];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'R':
      {
      for(int rr=0;rr<15;rr++)
	    {
	    printf("%d",rrrr[rr]);
	    outportb(DATA,rrrr[rr]);
		pole[p]=rrrr[rr];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'S':
      {
      for(int sa=0;sa<15;sa++)
	    {
	    printf("%d",ssss[sa]);
	    outportb(DATA,ssss[sa]);
		pole[p]=ssss[sa];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'T':
      {
      for(int ta=0;ta<15;ta++)
	    {
	    printf("%d",tttt[ta]);
	    outportb(DATA,tttt[ta]);
		pole[p]=tttt[ta];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'U':
      {
      for(int uu=0;uu<15;uu++)
	    {
	    printf("%d",uuuu[uu]);
	    outportb(DATA,uuuu[uu]);
		pole[p]=uuuu[uu];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'V':
      {
      for(int vv=0;vv<15;vv++)
	    {
	    printf("%d",vvvv[vv]);
	    outportb(DATA,vvvv[vv]);
		pole[p]=vvvv[vv];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'W':
      {
      for(int ww=0;ww<15;ww++)
	    {
	    printf("%d",wwww[ww]);
	    outportb(DATA,wwww[ww]);
		pole[p]=wwww[ww];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'X':
      {
      for(int xxx=0;xxx<15;xxx++)
	    {
	    printf("%d",xxxx[xxx]);
	    outportb(DATA,xxxx[xxx]);
		pole[p]=xxxx[xxx];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'Y':
      {
      for(int yy=0;yy<15;yy++)
	    {
	    printf("%d",yyyy[yy]);
	    outportb(DATA,yyyy[yy]);
		pole[p]=yyyy[yy];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	   case 'Z':
      {
      for(int zz=0;zz<15;zz++)
	    {
	    printf("%d",zzzz[zz]);
	    outportb(DATA,zzzz[zz]);
		pole[p]=zzzz[zz];
	    outportb(CLK,0xFF);
	    outportb(CLK,0x00);
		p=p+1;
	    }
      }
	  break;
	}
  }
 }
 outportb(DATA,0x00);  //po zadání 4 znakù se urèí kam se pošlou 2 zbylé znaky (na místa A2)
 pole[p]=0xFF;       //uložení do pole
 p=p+1;               //dalsí index
 outportb(CLK,0xFF);  //hodinový signál
 outportb(CLK,0x00);
 printf("A2\n");
 outportb(DATA,0xFF);
 pole[p]=0xFF;
 p=p+1;
 outportb(CLK,0xFF);
 outportb(CLK,0x00);
 for(int ttl=0;ttl<3;ttl++) //zaplnìní zbylých bitù
 {
 outportb(DATA,0x00);
 pole[p]=0x00;
 outportb(CLK,0xFF);
 outportb(CLK,0x00);
 p=p+1;
 }
 do   //aby všechny 4 znaky svítily dokud budeme chtít => všech 72 bitù jsem uložil do pole které budu v cyklu posílat do alfanumerického displeje dokud nebude zmáèknut ESC
 {
  printf("ESC = KONEC \n");
  for(int pln=0;pln<72;pln++)
   {
    printf("%d",pole[pln]);
    outportb(DATA,pole[pln]);
    outportb(CLK,0xFF);
    outportb(CLK,0x00);
   }
   if(kbhit)
   {
    stisk=getch();
   }
    if(stisk==27) 
   {
    a=a+1;        
   }
  }while(a==0);
 break;
}
}
}
}
}

