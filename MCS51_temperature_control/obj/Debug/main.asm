;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.6.0 #9615 (MINGW32)
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _LabTM_LCD_PrintString
	.globl _LabTM_LCD_PrintChar
	.globl _LabTM_LCD_SetPosition
	.globl _LabTM_LCD_Init
	.globl _strlen
	.globl _free
	.globl _malloc
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _PT2
	.globl _ET2
	.globl _CY
	.globl _AC
	.globl _F0
	.globl _RS1
	.globl _RS0
	.globl _OV
	.globl _F1
	.globl _P
	.globl _PS
	.globl _PT1
	.globl _PX1
	.globl _PT0
	.globl _PX0
	.globl _RD
	.globl _WR
	.globl _T1
	.globl _T0
	.globl _INT1
	.globl _INT0
	.globl _TXD
	.globl _RXD
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _EA
	.globl _ES
	.globl _ET1
	.globl _EX1
	.globl _ET0
	.globl _EX0
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _SM0
	.globl _SM1
	.globl _SM2
	.globl _REN
	.globl _TB8
	.globl _RB8
	.globl _TI
	.globl _RI
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _TF1
	.globl _TR1
	.globl _TF0
	.globl _TR0
	.globl _IE1
	.globl _IT1
	.globl _IE0
	.globl _IT0
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _TH2
	.globl _TL2
	.globl _RCAP2H
	.globl _RCAP2L
	.globl _T2CON
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _IP
	.globl _P3
	.globl _IE
	.globl _P2
	.globl _SBUF
	.globl _SCON
	.globl _P1
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _ADC
	.globl _LED
	.globl _aligned_alloc_PARM_2
	.globl _i
	.globl _value
	.globl _buffer
	.globl _read
	.globl _disp_binary_as_dec_str
	.globl _read_temperature
	.globl _read_potentiometer
	.globl _check_potentiometer
	.globl _LCD_clear
	.globl _disp_temperature_val
	.globl _reverse_str
	.globl _handle_interrupt
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0$0$0 == 0x0080
_P0	=	0x0080
G$SP$0$0 == 0x0081
_SP	=	0x0081
G$DPL$0$0 == 0x0082
_DPL	=	0x0082
G$DPH$0$0 == 0x0083
_DPH	=	0x0083
G$PCON$0$0 == 0x0087
_PCON	=	0x0087
G$TCON$0$0 == 0x0088
_TCON	=	0x0088
G$TMOD$0$0 == 0x0089
_TMOD	=	0x0089
G$TL0$0$0 == 0x008a
_TL0	=	0x008a
G$TL1$0$0 == 0x008b
_TL1	=	0x008b
G$TH0$0$0 == 0x008c
_TH0	=	0x008c
G$TH1$0$0 == 0x008d
_TH1	=	0x008d
G$P1$0$0 == 0x0090
_P1	=	0x0090
G$SCON$0$0 == 0x0098
_SCON	=	0x0098
G$SBUF$0$0 == 0x0099
_SBUF	=	0x0099
G$P2$0$0 == 0x00a0
_P2	=	0x00a0
G$IE$0$0 == 0x00a8
_IE	=	0x00a8
G$P3$0$0 == 0x00b0
_P3	=	0x00b0
G$IP$0$0 == 0x00b8
_IP	=	0x00b8
G$PSW$0$0 == 0x00d0
_PSW	=	0x00d0
G$ACC$0$0 == 0x00e0
_ACC	=	0x00e0
G$B$0$0 == 0x00f0
_B	=	0x00f0
G$T2CON$0$0 == 0x00c8
_T2CON	=	0x00c8
G$RCAP2L$0$0 == 0x00ca
_RCAP2L	=	0x00ca
G$RCAP2H$0$0 == 0x00cb
_RCAP2H	=	0x00cb
G$TL2$0$0 == 0x00cc
_TL2	=	0x00cc
G$TH2$0$0 == 0x00cd
_TH2	=	0x00cd
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
G$P0_0$0$0 == 0x0080
_P0_0	=	0x0080
G$P0_1$0$0 == 0x0081
_P0_1	=	0x0081
G$P0_2$0$0 == 0x0082
_P0_2	=	0x0082
G$P0_3$0$0 == 0x0083
_P0_3	=	0x0083
G$P0_4$0$0 == 0x0084
_P0_4	=	0x0084
G$P0_5$0$0 == 0x0085
_P0_5	=	0x0085
G$P0_6$0$0 == 0x0086
_P0_6	=	0x0086
G$P0_7$0$0 == 0x0087
_P0_7	=	0x0087
G$IT0$0$0 == 0x0088
_IT0	=	0x0088
G$IE0$0$0 == 0x0089
_IE0	=	0x0089
G$IT1$0$0 == 0x008a
_IT1	=	0x008a
G$IE1$0$0 == 0x008b
_IE1	=	0x008b
G$TR0$0$0 == 0x008c
_TR0	=	0x008c
G$TF0$0$0 == 0x008d
_TF0	=	0x008d
G$TR1$0$0 == 0x008e
_TR1	=	0x008e
G$TF1$0$0 == 0x008f
_TF1	=	0x008f
G$P1_0$0$0 == 0x0090
_P1_0	=	0x0090
G$P1_1$0$0 == 0x0091
_P1_1	=	0x0091
G$P1_2$0$0 == 0x0092
_P1_2	=	0x0092
G$P1_3$0$0 == 0x0093
_P1_3	=	0x0093
G$P1_4$0$0 == 0x0094
_P1_4	=	0x0094
G$P1_5$0$0 == 0x0095
_P1_5	=	0x0095
G$P1_6$0$0 == 0x0096
_P1_6	=	0x0096
G$P1_7$0$0 == 0x0097
_P1_7	=	0x0097
G$RI$0$0 == 0x0098
_RI	=	0x0098
G$TI$0$0 == 0x0099
_TI	=	0x0099
G$RB8$0$0 == 0x009a
_RB8	=	0x009a
G$TB8$0$0 == 0x009b
_TB8	=	0x009b
G$REN$0$0 == 0x009c
_REN	=	0x009c
G$SM2$0$0 == 0x009d
_SM2	=	0x009d
G$SM1$0$0 == 0x009e
_SM1	=	0x009e
G$SM0$0$0 == 0x009f
_SM0	=	0x009f
G$P2_0$0$0 == 0x00a0
_P2_0	=	0x00a0
G$P2_1$0$0 == 0x00a1
_P2_1	=	0x00a1
G$P2_2$0$0 == 0x00a2
_P2_2	=	0x00a2
G$P2_3$0$0 == 0x00a3
_P2_3	=	0x00a3
G$P2_4$0$0 == 0x00a4
_P2_4	=	0x00a4
G$P2_5$0$0 == 0x00a5
_P2_5	=	0x00a5
G$P2_6$0$0 == 0x00a6
_P2_6	=	0x00a6
G$P2_7$0$0 == 0x00a7
_P2_7	=	0x00a7
G$EX0$0$0 == 0x00a8
_EX0	=	0x00a8
G$ET0$0$0 == 0x00a9
_ET0	=	0x00a9
G$EX1$0$0 == 0x00aa
_EX1	=	0x00aa
G$ET1$0$0 == 0x00ab
_ET1	=	0x00ab
G$ES$0$0 == 0x00ac
_ES	=	0x00ac
G$EA$0$0 == 0x00af
_EA	=	0x00af
G$P3_0$0$0 == 0x00b0
_P3_0	=	0x00b0
G$P3_1$0$0 == 0x00b1
_P3_1	=	0x00b1
G$P3_2$0$0 == 0x00b2
_P3_2	=	0x00b2
G$P3_3$0$0 == 0x00b3
_P3_3	=	0x00b3
G$P3_4$0$0 == 0x00b4
_P3_4	=	0x00b4
G$P3_5$0$0 == 0x00b5
_P3_5	=	0x00b5
G$P3_6$0$0 == 0x00b6
_P3_6	=	0x00b6
G$P3_7$0$0 == 0x00b7
_P3_7	=	0x00b7
G$RXD$0$0 == 0x00b0
_RXD	=	0x00b0
G$TXD$0$0 == 0x00b1
_TXD	=	0x00b1
G$INT0$0$0 == 0x00b2
_INT0	=	0x00b2
G$INT1$0$0 == 0x00b3
_INT1	=	0x00b3
G$T0$0$0 == 0x00b4
_T0	=	0x00b4
G$T1$0$0 == 0x00b5
_T1	=	0x00b5
G$WR$0$0 == 0x00b6
_WR	=	0x00b6
G$RD$0$0 == 0x00b7
_RD	=	0x00b7
G$PX0$0$0 == 0x00b8
_PX0	=	0x00b8
G$PT0$0$0 == 0x00b9
_PT0	=	0x00b9
G$PX1$0$0 == 0x00ba
_PX1	=	0x00ba
G$PT1$0$0 == 0x00bb
_PT1	=	0x00bb
G$PS$0$0 == 0x00bc
_PS	=	0x00bc
G$P$0$0 == 0x00d0
_P	=	0x00d0
G$F1$0$0 == 0x00d1
_F1	=	0x00d1
G$OV$0$0 == 0x00d2
_OV	=	0x00d2
G$RS0$0$0 == 0x00d3
_RS0	=	0x00d3
G$RS1$0$0 == 0x00d4
_RS1	=	0x00d4
G$F0$0$0 == 0x00d5
_F0	=	0x00d5
G$AC$0$0 == 0x00d6
_AC	=	0x00d6
G$CY$0$0 == 0x00d7
_CY	=	0x00d7
G$ET2$0$0 == 0x00ad
_ET2	=	0x00ad
G$PT2$0$0 == 0x00bd
_PT2	=	0x00bd
G$T2CON_0$0$0 == 0x00c8
_T2CON_0	=	0x00c8
G$T2CON_1$0$0 == 0x00c9
_T2CON_1	=	0x00c9
G$T2CON_2$0$0 == 0x00ca
_T2CON_2	=	0x00ca
G$T2CON_3$0$0 == 0x00cb
_T2CON_3	=	0x00cb
G$T2CON_4$0$0 == 0x00cc
_T2CON_4	=	0x00cc
G$T2CON_5$0$0 == 0x00cd
_T2CON_5	=	0x00cd
G$T2CON_6$0$0 == 0x00ce
_T2CON_6	=	0x00ce
G$T2CON_7$0$0 == 0x00cf
_T2CON_7	=	0x00cf
G$CP_RL2$0$0 == 0x00c8
_CP_RL2	=	0x00c8
G$C_T2$0$0 == 0x00c9
_C_T2	=	0x00c9
G$TR2$0$0 == 0x00ca
_TR2	=	0x00ca
G$EXEN2$0$0 == 0x00cb
_EXEN2	=	0x00cb
G$TCLK$0$0 == 0x00cc
_TCLK	=	0x00cc
G$RCLK$0$0 == 0x00cd
_RCLK	=	0x00cd
G$EXF2$0$0 == 0x00ce
_EXF2	=	0x00ce
G$TF2$0$0 == 0x00cf
_TF2	=	0x00cf
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; overlayable bit register bank
;--------------------------------------------------------
	.area BIT_BANK	(REL,OVR,DATA)
bits:
	.ds 1
	b0 = bits[0]
	b1 = bits[1]
	b2 = bits[2]
	b3 = bits[3]
	b4 = bits[4]
	b5 = bits[5]
	b6 = bits[6]
	b7 = bits[7]
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
G$read$0$0==.
_read::
	.ds 1
G$buffer$0$0==.
_buffer::
	.ds 3
G$value$0$0==.
_value::
	.ds 4
G$i$0$0==.
_i::
	.ds 2
Lmain.aligned_alloc$size$1$26==.
_aligned_alloc_PARM_2:
	.ds 2
Lmain.reverse_str$length$1$86==.
_reverse_str_length_1_86:
	.ds 1
Lmain.reverse_str$temp$1$86==.
_reverse_str_temp_1_86:
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
G$LED$0$0 == 0xfa00
_LED	=	0xfa00
G$ADC$0$0 == 0xf8c0
_ADC	=	0xf8c0
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
	ljmp	_handle_interrupt
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	ljmp	_main
;	return from main will return to caller
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
	G$main$0$0 ==.
	C$main.c$28$0$0 ==.
;	main.c:28: void main(void) {
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	C$main.c$29$1$67 ==.
;	main.c:29: LabTM_LCD_Init();                   /* Inicjalizacja wyswietlacza LCD */
	lcall	_LabTM_LCD_Init
	C$main.c$30$1$67 ==.
;	main.c:30: LabTM_LCD_SetPosition(1, 1);        /* Ustawienie kursora w 1 linii, na 1 znaku */
	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
	mov	dpl,#0x01
	lcall	_LabTM_LCD_SetPosition
	C$main.c$31$1$67 ==.
;	main.c:31: LabTM_LCD_PrintChar('A');           /* Wyswietlenie znaku */
	mov	dpl,#0x41
	lcall	_LabTM_LCD_PrintChar
	C$main.c$32$1$67 ==.
;	main.c:32: LabTM_LCD_SetPosition(2, 1);        /* Ustawienie kursora w 2 linii, na 1 znaku */
	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
	mov	dpl,#0x02
	lcall	_LabTM_LCD_SetPosition
	C$main.c$33$1$67 ==.
;	main.c:33: LabTM_LCD_PrintString("Test");      /* Wyswietlenie ciagu znakow */
	mov	dptr,#___str_0
	mov	b,#0x80
	lcall	_LabTM_LCD_PrintString
	C$main.c$35$1$67 ==.
;	main.c:35: do {                                /* Wykonuj dzialania w nieskonczonej petli */
00101$:
	C$main.c$57$2$68 ==.
;	main.c:57: ADC = 0x0D;                     /* Przeslij adres czujnika temperatury */
	mov	dptr,#_ADC
	mov	a,#0x0d
	movx	@dptr,a
	C$main.c$58$1$67 ==.
;	main.c:58: } while(1);                         /* Warunek nieskonczonej petli */
	sjmp	00101$
	C$main.c$59$1$67 ==.
	XG$main$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'disp_binary_as_dec_str'
;------------------------------------------------------------
;val                       Allocated to registers r7 
;------------------------------------------------------------
	G$disp_binary_as_dec_str$0$0 ==.
	C$main.c$62$1$67 ==.
;	main.c:62: void disp_binary_as_dec_str(unsigned char val) {
;	-----------------------------------------
;	 function disp_binary_as_dec_str
;	-----------------------------------------
_disp_binary_as_dec_str:
	mov	r7,dpl
	C$main.c$63$1$70 ==.
;	main.c:63: i = 0;                              /* Podstaw domyslna wartosc iteratora */
	clr	a
	mov	_i,a
	mov	(_i + 1),a
	C$main.c$64$1$70 ==.
;	main.c:64: buffer = malloc(sizeof(char)*4);    /* Utworz buffer na 3-cyfrowa wartosc dziesietna */
	mov	dptr,#0x0004
	push	ar7
	lcall	_malloc
	mov	r5,dpl
	mov	r6,dph
	pop	ar7
	mov	_buffer,r5
	mov	(_buffer + 1),r6
	mov	(_buffer + 2),#0x00
	C$main.c$65$1$70 ==.
;	main.c:65: while(val != 0) {                   /* Algorytm wydzielania cyfr - dopoki wartosc jest rozna od 0 */
00101$:
	mov	a,r7
	jz	00103$
	C$main.c$66$2$71 ==.
;	main.c:66: buffer[i] = (val % 10) + '0';   /* Wyciagnij cyfre z wartosci, zamien ja na reprezentujacy
	mov	a,_i
	add	a,_buffer
	mov	r4,a
	mov	a,(_i + 1)
	addc	a,(_buffer + 1)
	mov	r5,a
	mov	r6,(_buffer + 2)
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	r3,b
	mov	a,#0x30
	add	a,r3
	mov	r3,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrput
	C$main.c$68$2$71 ==.
;	main.c:68: val /= 10;                      /* Przesun wartosc o 1 znak w lewo, usuwajac cyfre jednosci */
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	r7,a
	C$main.c$69$2$71 ==.
;	main.c:69: i++;                            /* Zwieksz iterator */
	inc	_i
	clr	a
	cjne	a,_i,00101$
	inc	(_i + 1)
	sjmp	00101$
00103$:
	C$main.c$71$1$70 ==.
;	main.c:71: buffer[i] = '\0';                   /* Zaznacz koniec ciagu znakowego - bufor zawiera wartosc zapisana od tylu*/
	mov	a,_i
	add	a,_buffer
	mov	r5,a
	mov	a,(_i + 1)
	addc	a,(_buffer + 1)
	mov	r6,a
	mov	r7,(_buffer + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	C$main.c$72$1$70 ==.
;	main.c:72: reverse_str(buffer);                /* Odwroc bufor aby otrzymac prawidlowa kolejnosc */
	mov	dpl,_buffer
	mov	dph,(_buffer + 1)
	mov	b,(_buffer + 2)
	lcall	_reverse_str
	C$main.c$73$1$70 ==.
;	main.c:73: LabTM_LCD_PrintString(buffer);      /* Wyswietl zawartosc bufora */
	mov	dpl,_buffer
	mov	dph,(_buffer + 1)
	mov	b,(_buffer + 2)
	lcall	_LabTM_LCD_PrintString
	C$main.c$74$1$70 ==.
;	main.c:74: free(buffer);                       /* Zwolnij bufor */
	mov	r5,_buffer
	mov	r6,(_buffer + 1)
	mov	r7,(_buffer + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	_free
	C$main.c$75$1$70 ==.
	XG$disp_binary_as_dec_str$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_temperature'
;------------------------------------------------------------
	G$read_temperature$0$0 ==.
	C$main.c$78$1$70 ==.
;	main.c:78: unsigned char read_temperature(void) {
;	-----------------------------------------
;	 function read_temperature
;	-----------------------------------------
_read_temperature:
	C$main.c$79$1$73 ==.
;	main.c:79: ADC = 0x0D;         /* Przeslij adres czunika temperatury (kanal 6) */
	mov	dptr,#_ADC
	mov	a,#0x0d
	movx	@dptr,a
	C$main.c$81$1$73 ==.
;	main.c:81: return ADC;         /* Zwrocenie wartosci zakodowanej w skali przetwornika */
	movx	a,@dptr
	C$main.c$82$1$73 ==.
	XG$read_temperature$0$0 ==.
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'read_potentiometer'
;------------------------------------------------------------
	G$read_potentiometer$0$0 ==.
	C$main.c$85$1$73 ==.
;	main.c:85: unsigned char read_potentiometer(void) {
;	-----------------------------------------
;	 function read_potentiometer
;	-----------------------------------------
_read_potentiometer:
	C$main.c$86$1$75 ==.
;	main.c:86: ADC = 0x0C;         /* Przeslij adres potencjometru (kanal 5) */
	mov	dptr,#_ADC
	mov	a,#0x0c
	movx	@dptr,a
	C$main.c$88$1$75 ==.
;	main.c:88: return ADC;         /* Zwrocenie wartosci zakodowanej w skali przetwornika */
	movx	a,@dptr
	C$main.c$89$1$75 ==.
	XG$read_potentiometer$0$0 ==.
	mov	dpl,a
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'check_potentiometer'
;------------------------------------------------------------
	G$check_potentiometer$0$0 ==.
	C$main.c$92$1$75 ==.
;	main.c:92: void check_potentiometer(void) {
;	-----------------------------------------
;	 function check_potentiometer
;	-----------------------------------------
_check_potentiometer:
	C$main.c$93$1$77 ==.
;	main.c:93: read = read_potentiometer();    /* Odczytaj wartosc z potencjometru zakodowana na 8 bitach */
	lcall	_read_potentiometer
	mov	_read,dpl
	C$main.c$94$1$77 ==.
;	main.c:94: LED = read;                   /* Zapal odpowiednie bity */
	mov	dptr,#_LED
	mov	a,_read
	movx	@dptr,a
	C$main.c$95$1$77 ==.
	XG$check_potentiometer$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_clear'
;------------------------------------------------------------
	G$LCD_clear$0$0 ==.
	C$main.c$98$1$77 ==.
;	main.c:98: void LCD_clear(void) {
;	-----------------------------------------
;	 function LCD_clear
;	-----------------------------------------
_LCD_clear:
	C$main.c$99$1$79 ==.
;	main.c:99: LabTM_LCD_SetPosition(1, 1);                /* Ustaw kursor w 1 linii, na 1 znaku */
	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
	mov	dpl,#0x01
	lcall	_LabTM_LCD_SetPosition
	C$main.c$100$1$79 ==.
;	main.c:100: LabTM_LCD_PrintString("                ");  /* Wyczysc ekran wyswietlajac same spacje */
	mov	dptr,#___str_1
	mov	b,#0x80
	lcall	_LabTM_LCD_PrintString
	C$main.c$101$1$79 ==.
;	main.c:101: LabTM_LCD_SetPosition(2, 1);                /* Ustaw kursor w 2 linii, na 1 znaku */
	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
	mov	dpl,#0x02
	lcall	_LabTM_LCD_SetPosition
	C$main.c$102$1$79 ==.
;	main.c:102: LabTM_LCD_PrintString("                ");  /* Wyczysc ekran wyswietlajac same spacje */
	mov	dptr,#___str_1
	mov	b,#0x80
	lcall	_LabTM_LCD_PrintString
	C$main.c$103$1$79 ==.
;	main.c:103: LabTM_LCD_SetPosition(1, 1);                /* Ustaw kursor w 1 linii, na 1 znaku */
	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
	mov	dpl,#0x01
	lcall	_LabTM_LCD_SetPosition
	C$main.c$104$1$79 ==.
	XG$LCD_clear$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'disp_temperature_val'
;------------------------------------------------------------
;adc_read                  Allocated to registers r7 
;temp                      Allocated to registers r7 
;------------------------------------------------------------
	G$disp_temperature_val$0$0 ==.
	C$main.c$107$1$79 ==.
;	main.c:107: void disp_temperature_val(unsigned char adc_read) {
;	-----------------------------------------
;	 function disp_temperature_val
;	-----------------------------------------
_disp_temperature_val:
	mov	r7,dpl
	C$main.c$111$1$81 ==.
;	main.c:111: LabTM_LCD_SetPosition(2, 1);            /* Ustaw kursor w 2 linii, na 1 znaku */
	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
	mov	dpl,#0x02
	push	ar7
	lcall	_LabTM_LCD_SetPosition
	pop	ar7
	C$main.c$112$1$81 ==.
;	main.c:112: value = adc_read*2.5f;                      /* Pomnozyc odczyt przez napiecie referencyjne (2.5 V) */
	mov	dpl,r7
	lcall	___uchar2fs
	mov	r4,dpl
	mov	r5,dph
	mov	r6,b
	mov	r7,a
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	dptr,#0x0000
	mov	b,#0x20
	mov	a,#0x40
	lcall	___fsmul
	mov	_value,dpl
	mov	(_value + 1),dph
	mov	(_value + 2),b
	mov	(_value + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	C$main.c$113$1$81 ==.
;	main.c:113: value /= 256;                           /* Podzielic przez gorny zakres ADC zeby dokonac konwersji na napiecie w V */
	clr	a
	push	acc
	push	acc
	mov	a,#0x80
	push	acc
	mov	a,#0x43
	push	acc
	mov	dpl,_value
	mov	dph,(_value + 1)
	mov	b,(_value + 2)
	mov	a,(_value + 3)
	lcall	___fsdiv
	mov	_value,dpl
	mov	(_value + 1),dph
	mov	(_value + 2),b
	mov	(_value + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	C$main.c$114$1$81 ==.
;	main.c:114: value *= 100;                           /* Pomnozyc razy 100 (1*C = 0.01V) aby obliczyc temperature w stopniach C */
	push	_value
	push	(_value + 1)
	push	(_value + 2)
	push	(_value + 3)
	mov	dptr,#0x0000
	mov	b,#0xc8
	mov	a,#0x42
	lcall	___fsmul
	mov	_value,dpl
	mov	(_value + 1),dph
	mov	(_value + 2),b
	mov	(_value + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	C$main.c$117$1$81 ==.
;	main.c:117: buffer = malloc(sizeof(char)*17);       /* Utworzenie bufforu na cala linie wyswietlacza LCD */
	mov	dptr,#0x0011
	lcall	_malloc
	mov	r6,dpl
	mov	r7,dph
	mov	_buffer,r6
	mov	(_buffer + 1),r7
	mov	(_buffer + 2),#0x00
	C$main.c$118$1$81 ==.
;	main.c:118: value *= 100;                           /* Pomnozenie wartosci razy 100 do wyciagniecia wartosci ulamkowej
	push	_value
	push	(_value + 1)
	push	(_value + 2)
	push	(_value + 3)
	mov	dptr,#0x0000
	mov	b,#0xc8
	mov	a,#0x42
	lcall	___fsmul
	mov	_value,dpl
	mov	(_value + 1),dph
	mov	(_value + 2),b
	mov	(_value + 3),a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	C$main.c$120$1$81 ==.
;	main.c:120: temp = (unsigned char)value;            /* Zapisz wartosc istotna do konwersji pomijajac zbedna czesc ulamkowa
	mov	dpl,_value
	mov	dph,(_value + 1)
	mov	b,(_value + 2)
	mov	a,(_value + 3)
	lcall	___fs2uchar
	mov	r7,dpl
	C$main.c$122$1$81 ==.
;	main.c:122: for(i = 0; i < 2; i++) {                /* Przekonwertuj i zapisz czesc ulamkowa temperatury w buforze */
	clr	a
	mov	_i,a
	mov	(_i + 1),a
00107$:
	C$main.c$123$2$82 ==.
;	main.c:123: buffer[i] = (temp % 10) + '0';      /* Wyciagnij cyfre i zapisz ja za pomoca znaku ja reprezentujacego */
	mov	a,_i
	add	a,_buffer
	mov	r4,a
	mov	a,(_i + 1)
	addc	a,(_buffer + 1)
	mov	r5,a
	mov	r6,(_buffer + 2)
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	r3,b
	mov	a,#0x30
	add	a,r3
	mov	r3,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrput
	C$main.c$124$2$82 ==.
;	main.c:124: temp /= 10;                         /* Przesun wartosc o jedno miejsce w prawo, usuwajac liczbe jednosci */
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	r7,a
	C$main.c$122$1$81 ==.
;	main.c:122: for(i = 0; i < 2; i++) {                /* Przekonwertuj i zapisz czesc ulamkowa temperatury w buforze */
	inc	_i
	clr	a
	cjne	a,_i,00126$
	inc	(_i + 1)
00126$:
	clr	c
	mov	a,_i
	subb	a,#0x02
	mov	a,(_i + 1)
	xrl	a,#0x80
	subb	a,#0x80
	jc	00107$
	C$main.c$126$1$81 ==.
;	main.c:126: buffer[i] = '.';                        /* Zapisz separator dziesietny */
	mov	a,_i
	add	a,_buffer
	mov	r4,a
	mov	a,(_i + 1)
	addc	a,(_buffer + 1)
	mov	r5,a
	mov	r6,(_buffer + 2)
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,#0x2e
	lcall	__gptrput
	C$main.c$127$1$81 ==.
;	main.c:127: i++;                                    /* Zwieksz iterator */
	inc	_i
	clr	a
	cjne	a,_i,00128$
	inc	(_i + 1)
00128$:
	C$main.c$128$1$81 ==.
;	main.c:128: while(value != 0) {                     /* Przekonwertuj i zapisz czesc calkowita temperatury w buforze */
00102$:
	mov	b,_value
	mov	a,(_value + 1)
	orl	b,a
	mov	a,(_value + 2)
	orl	b,a
	mov	a,(_value + 3)
	anl	a,#0x7F
	orl	a,b
	jz	00104$
	C$main.c$129$2$83 ==.
;	main.c:129: buffer[i] = (temp % 10) + '0';      /* Wyciagnij cyfre i zapisz ja za pomoca znaku ja reprezentujacego */
	mov	a,_i
	add	a,_buffer
	mov	r4,a
	mov	a,(_i + 1)
	addc	a,(_buffer + 1)
	mov	r5,a
	mov	r6,(_buffer + 2)
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	r3,b
	mov	a,#0x30
	add	a,r3
	mov	r3,a
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrput
	C$main.c$130$2$83 ==.
;	main.c:130: temp /= 10;                         /* Przesun wartosc o jedno miejsce w prawo, usuwajac liczbe jednosci */
	mov	b,#0x0a
	mov	a,r7
	div	ab
	mov	r7,a
	C$main.c$131$2$83 ==.
;	main.c:131: i++;                                /* Zwieksz iterator */
	inc	_i
	clr	a
	cjne	a,_i,00102$
	inc	(_i + 1)
	sjmp	00102$
00104$:
	C$main.c$133$1$81 ==.
;	main.c:133: if(i == 4) {                            /* Jesli iterator wynosi 4 (czesc calkowita pomiaru wynosila 0) */
	mov	a,#0x04
	cjne	a,_i,00131$
	clr	a
	cjne	a,(_i + 1),00131$
	sjmp	00132$
00131$:
	sjmp	00106$
00132$:
	C$main.c$134$2$84 ==.
;	main.c:134: buffer[i] = '0';                    /* Zapisz czesc calkowita jako 0 */
	mov	a,_i
	add	a,_buffer
	mov	r5,a
	mov	a,(_i + 1)
	addc	a,(_buffer + 1)
	mov	r6,a
	mov	r7,(_buffer + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,#0x30
	lcall	__gptrput
	C$main.c$135$2$84 ==.
;	main.c:135: i++;                                /* Zwieksz iterator */
	inc	_i
	clr	a
	cjne	a,_i,00133$
	inc	(_i + 1)
00133$:
00106$:
	C$main.c$137$1$81 ==.
;	main.c:137: buffer[i] = '\0';                       /* Zaznacz koniec ciagu znakowego - bufor zawiera wartosc zapisana od tylu*/
	mov	a,_i
	add	a,_buffer
	mov	r5,a
	mov	a,(_i + 1)
	addc	a,(_buffer + 1)
	mov	r6,a
	mov	r7,(_buffer + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	clr	a
	lcall	__gptrput
	C$main.c$138$1$81 ==.
;	main.c:138: reverse_str(buffer);                    /* Odwroc bufor aby otrzymac prawidlowa kolejnosc */
	mov	dpl,_buffer
	mov	dph,(_buffer + 1)
	mov	b,(_buffer + 2)
	lcall	_reverse_str
	C$main.c$141$1$81 ==.
;	main.c:141: LabTM_LCD_SetPosition(1, 1);            /* Ustaw kursor w 1 linii, na 1 znaku */
	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
	mov	dpl,#0x01
	lcall	_LabTM_LCD_SetPosition
	C$main.c$142$1$81 ==.
;	main.c:142: LabTM_LCD_PrintString("Temperatura");   /* Wyswietl napis "Temperatura" */
	mov	dptr,#___str_2
	mov	b,#0x80
	lcall	_LabTM_LCD_PrintString
	C$main.c$143$1$81 ==.
;	main.c:143: LabTM_LCD_SetPosition(2, 4);            /* Ustaw kursor w 2 linii, na 6 znaku (centrowanie wyniku pomiaru) */
	mov	_LabTM_LCD_SetPosition_PARM_2,#0x04
	mov	dpl,#0x02
	lcall	_LabTM_LCD_SetPosition
	C$main.c$144$1$81 ==.
;	main.c:144: LabTM_LCD_PrintString(buffer);          /* Wyswietl zawartosc bufora */
	mov	dpl,_buffer
	mov	dph,(_buffer + 1)
	mov	b,(_buffer + 2)
	lcall	_LabTM_LCD_PrintString
	C$main.c$145$1$81 ==.
;	main.c:145: LabTM_LCD_PrintString(" *C");           /* Wyswietl jednostke */
	mov	dptr,#___str_3
	mov	b,#0x80
	lcall	_LabTM_LCD_PrintString
	C$main.c$146$1$81 ==.
;	main.c:146: free(buffer);                           /* Zwolnij bufor */
	mov	r5,_buffer
	mov	r6,(_buffer + 1)
	mov	r7,(_buffer + 2)
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	_free
	C$main.c$147$1$81 ==.
	XG$disp_temperature_val$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'reverse_str'
;------------------------------------------------------------
;str                       Allocated to registers r5 r6 r7 
;length                    Allocated with name '_reverse_str_length_1_86'
;temp                      Allocated with name '_reverse_str_temp_1_86'
;------------------------------------------------------------
	G$reverse_str$0$0 ==.
	C$main.c$150$1$81 ==.
;	main.c:150: void reverse_str(char str[]) {
;	-----------------------------------------
;	 function reverse_str
;	-----------------------------------------
_reverse_str:
	C$main.c$153$1$86 ==.
;	main.c:153: length = strlen(str);               /* Odczytaj dlugosc ciagu znakowego */
	mov	r5,dpl
	mov	r6,dph
	mov	r7,b
	push	ar7
	push	ar6
	push	ar5
	lcall	_strlen
	mov	r3,dpl
	pop	ar5
	pop	ar6
	pop	ar7
	mov	_reverse_str_length_1_86,r3
	C$main.c$154$1$86 ==.
;	main.c:154: i = 0;                              /* Ustaw domyslna wartosc iteratora */
	clr	a
	mov	_i,a
	mov	(_i + 1),a
	C$main.c$155$1$86 ==.
;	main.c:155: while(i <= length / 2) {            /* Dopoki iterator przechodzi przez lewa polowe ciagu znakowego */
	mov	a,_reverse_str_length_1_86
	clr	c
	rrc	a
	mov	r4,a
00101$:
	mov	ar1,r4
	clr	a
	mov	r2,a
	jb	acc.7,00104$
	C$main.c$156$2$87 ==.
;	main.c:156: temp = str[i];                  /* Zapisz znak po lewej do zmiennej tymczasowej */
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	_reverse_str_temp_1_86,a
	C$main.c$157$2$87 ==.
;	main.c:157: str[i] = str[length - i - 1];   /* Nadpisz znak po lewej znakiem po prawej */
	mov	r0,_reverse_str_length_1_86
	mov	r1,#0x00
	dec	r0
	cjne	r0,#0xff,00113$
	dec	r1
00113$:
	mov	a,r0
	add	a,r5
	mov	r0,a
	mov	a,r1
	addc	a,r6
	mov	r1,a
	mov	ar2,r7
	mov	dpl,r0
	mov	dph,r1
	mov	b,r2
	lcall	__gptrget
	mov	r3,a
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrput
	C$main.c$158$2$87 ==.
;	main.c:158: str[length - i - 1] = temp;     /* Nadpisz znak po prawej zapisanym znakiem ktory byl po lewej */
	mov	dpl,r0
	mov	dph,r1
	mov	b,r2
	mov	a,_reverse_str_temp_1_86
	lcall	__gptrput
	sjmp	00101$
00104$:
	C$main.c$160$1$86 ==.
	XG$reverse_str$0$0 ==.
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'handle_interrupt'
;------------------------------------------------------------
	G$handle_interrupt$0$0 ==.
	C$main.c$163$1$86 ==.
;	main.c:163: void handle_interrupt(void) __interrupt(0) {
;	-----------------------------------------
;	 function handle_interrupt
;	-----------------------------------------
_handle_interrupt:
	push	bits
	push	acc
	push	b
	push	dpl
	push	dph
	push	(0+7)
	push	(0+6)
	push	(0+5)
	push	(0+4)
	push	(0+3)
	push	(0+2)
	push	(0+1)
	push	(0+0)
	push	psw
	mov	psw,#0x00
	C$main.c$164$1$89 ==.
;	main.c:164: read = read_temperature();  /* Odczytanie wartosci temperatury jako wartosc z zakresu ADC */
	lcall	_read_temperature
	C$main.c$165$1$89 ==.
;	main.c:165: disp_temperature_val(read); /* Konwersja i wyswietlenie odczytu jako wartosc w stopniach C */
	mov  _read,dpl
	lcall	_disp_temperature_val
	pop	psw
	pop	(0+0)
	pop	(0+1)
	pop	(0+2)
	pop	(0+3)
	pop	(0+4)
	pop	(0+5)
	pop	(0+6)
	pop	(0+7)
	pop	dph
	pop	dpl
	pop	b
	pop	acc
	pop	bits
	C$main.c$166$1$89 ==.
	XG$handle_interrupt$0$0 ==.
	reti
	.area CSEG    (CODE)
	.area CONST   (CODE)
Fmain$__str_0$0$0 == .
___str_0:
	.ascii "Test"
	.db 0x00
Fmain$__str_1$0$0 == .
___str_1:
	.ascii "                "
	.db 0x00
Fmain$__str_2$0$0 == .
___str_2:
	.ascii "Temperatura"
	.db 0x00
Fmain$__str_3$0$0 == .
___str_3:
	.ascii " *C"
	.db 0x00
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
