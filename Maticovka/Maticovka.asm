.NOLIST
.INCLUDE "m128def.inc"
.LIST
.EQU ULOZ = $220 ;ulozeni cisla do RAM
.CSEG
.MACRO porovnani ;podprogram na porovnavaní stisklých kláves
LDI R17,@0			;nastaveni do registru dale budu provnavst
LDI R16,0b11111110	
OUT PORTB,R16		
NOP					
IN R21,PINB
CPI R21,0b01111110	;bylo zmacknuto tlacitko
BRNE @1				;ne -> skoèi dal
RET					;ano -> vrati se
.ENDMACRO

.MACRO zobzazenicisla ;podprogram na zobrazeni cisla
CPI R16,@0
BRNE @1
LDI ZL,LOW(@2*2)
LDI ZH,HIGH(@2*2)
.ENDMACRO

.MACRO sloupec ;podprogram pro jeden sloupec maticove klavesnice
SBI PORTA,7
NOP NOP NOP
CBI PORTA,7
LPM R16,Z+
OUT PORTA,R16
CALL DELAY
.ENDMACRO

NASTAVENI:
LDI R24,LOW(RAMEND)		;zasobnik
OUT SPL,R24
LDI R24,HIGH(RAMEND)
OUT SPH,R24
LDI R16,0b11111111		;natavenu portu
OUT DDRA,R16
LDI R16,0b00001111		;nataveni klavesnice
OUT DDRB,R16
SER R16
OUT PORTB,R16

MAIN:
CALL KLAVESNICE	;nasteni klavesnice
CPI R17,10 ;byla stisknuta *
BREQ ZADANI


KLAVESNICE:		;identifikuji stisknutí klávesy
 TEST10:
 porovnani 10,TEST1
 TEST1:
 porovnani 1,TEST2
 TEST2:
 porovnani 2,TEST3
 TEST3:
 porovnani 3,TEST4
 TEST4:
 porovnani 4,TEST5
 TEST5:
 porovnani 5,TEST6
 TEST6:
 porovnani 6,TEST7
 TEST7:
 porovnani 7,TEST8
 TEST8:
 porovnani 8,TEST9
 TEST9:
 porovnani 9,TEST11
 TEST11:
 porovnani 11,TEST0
 TEST0:
 porovnani 0,KONEC
 KONEC:
 LDI R17,16 ;neni stisknuta zadna klavesa
 RET

ZADANI:
CALL ZADANICISLA
STS ULOZ,R17
CALL ZADANICISLA
STS ULOZ+1,R17
CALL ZADANICISLA
STS ULOZ+2,R17
CALL ZADANICISLA
STS ULOZ+3,R17
CALL ZADANICISLA
STS ULOZ+4,R17

ZADANICISLA:
CALL KLAVESNICE
CPI R17,16 ;nebyla stisknuta zadna klavesa
BREQ ZADANICISLA
CALL UVOLNENI
RET

UVOLNENI: ;osetreni zakmitu
CALL KLAVESNICE
CPI R17,16
BRNE UVOLNENI
RET

ZOBRAZ:
A:
LDS R16,ULOZ	;1. CISLO DO REGISTRU
CALL CISLO		;nacteni hodnot z db
CALL CYKLUS		;zobrazeni cisla
B:
LDS R16,ULOZ+1
CALL CISLO
CALL CYKLUS
C:
LDS R16,ULOZ+2
CALL CISLO
CALL CYKLUS
D:
LDS R16,ULOZ+3
CALL CISLO
CALL CYKLUS
E:
LDS R16,ULOZ+4
CALL CISLO
CALL CYKLUS
JMP MAIN

CISLO:
Z0:
zobzazenicisla 0,Z1,cislo0
Z1:
zobzazenicisla 1,Z2,cislo1
Z2:
zobzazenicisla 2,Z3,cislo2
Z3:
zobzazenicisla 3,Z4,cislo3
Z4:
zobzazenicisla 4,Z5,cislo4
Z5:
zobzazenicisla 5,Z6,cislo5
Z6:
zobzazenicisla 6,Z7,cislo6
Z7:
zobzazenicisla 7,Z8,cislo7
Z8:
zobzazenicisla 8,Z9,cislo8
Z9:
zobzazenicisla 9,END,cislo9
END:
RET

CYKLUS: ;zobrazeni hodnot
LDI R20,200
CYKLUS1:
DEC R20
BREQ ENDC
SBI PORTA,7
CALL DELAY
CBI PORTA,7
sloupec
sloupec
sloupec
sloupec
sloupec
JMP CYKLUS1
ENDC:
RET
  

DELAY:	;zpozdeni 1ms
LDI R18,21
LDI R19,198
L1:
DEC R19
BRNE L1
DEC R18
BRNE L1
NOP
RET
;kombinace
cislo0:.DB 0b00000000, 0b01000001, 0b00101110, 0b00110110, 0b00111010, 0b01000001
cislo1:.DB 0b00000000, 0b00111011, 0b00111101, 0b00000000, 0b00111111, 0b00111111
cislo2:.DB 0b00000000, 0b00111101, 0b00011110, 0b00101110, 0b00110110, 0b00111001
cislo3:.DB 0b00000000, 0b01011101, 0b00111110, 0b00110110, 0b00110110, 0b01001001
cislo4:.DB 0b00000000, 0b01100111, 0b01101011, 0b01101101, 0b00000000, 0b01101111
cislo5:.DB 0b00000000, 0b01011000, 0b00111010, 0b00111010, 0b00111010, 0b01000110
cislo6:.DB 0b00000000, 0b01000001, 0b00110110, 0b00110110, 0b00110110, 0b01001101
cislo7:.DB 0b00000000, 0b01111110, 0b00001110, 0b01110110, 0b01111010, 0b01111100
cislo8:.DB 0b00000000, 0b01001001, 0b00110110, 0b00110110, 0b00110110, 0b01001001
cislo9:.DB 0b00000000, 0b01011001, 0b00110110, 0b00110110, 0b00110110, 0b01000001

