                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.6.0 #9615 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _LabTM_LCD_PrintString
                                     13 	.globl _LabTM_LCD_PrintChar
                                     14 	.globl _LabTM_LCD_SetPosition
                                     15 	.globl _LabTM_LCD_Init
                                     16 	.globl _strlen
                                     17 	.globl _free
                                     18 	.globl _malloc
                                     19 	.globl _TF2
                                     20 	.globl _EXF2
                                     21 	.globl _RCLK
                                     22 	.globl _TCLK
                                     23 	.globl _EXEN2
                                     24 	.globl _TR2
                                     25 	.globl _C_T2
                                     26 	.globl _CP_RL2
                                     27 	.globl _T2CON_7
                                     28 	.globl _T2CON_6
                                     29 	.globl _T2CON_5
                                     30 	.globl _T2CON_4
                                     31 	.globl _T2CON_3
                                     32 	.globl _T2CON_2
                                     33 	.globl _T2CON_1
                                     34 	.globl _T2CON_0
                                     35 	.globl _PT2
                                     36 	.globl _ET2
                                     37 	.globl _CY
                                     38 	.globl _AC
                                     39 	.globl _F0
                                     40 	.globl _RS1
                                     41 	.globl _RS0
                                     42 	.globl _OV
                                     43 	.globl _F1
                                     44 	.globl _P
                                     45 	.globl _PS
                                     46 	.globl _PT1
                                     47 	.globl _PX1
                                     48 	.globl _PT0
                                     49 	.globl _PX0
                                     50 	.globl _RD
                                     51 	.globl _WR
                                     52 	.globl _T1
                                     53 	.globl _T0
                                     54 	.globl _INT1
                                     55 	.globl _INT0
                                     56 	.globl _TXD
                                     57 	.globl _RXD
                                     58 	.globl _P3_7
                                     59 	.globl _P3_6
                                     60 	.globl _P3_5
                                     61 	.globl _P3_4
                                     62 	.globl _P3_3
                                     63 	.globl _P3_2
                                     64 	.globl _P3_1
                                     65 	.globl _P3_0
                                     66 	.globl _EA
                                     67 	.globl _ES
                                     68 	.globl _ET1
                                     69 	.globl _EX1
                                     70 	.globl _ET0
                                     71 	.globl _EX0
                                     72 	.globl _P2_7
                                     73 	.globl _P2_6
                                     74 	.globl _P2_5
                                     75 	.globl _P2_4
                                     76 	.globl _P2_3
                                     77 	.globl _P2_2
                                     78 	.globl _P2_1
                                     79 	.globl _P2_0
                                     80 	.globl _SM0
                                     81 	.globl _SM1
                                     82 	.globl _SM2
                                     83 	.globl _REN
                                     84 	.globl _TB8
                                     85 	.globl _RB8
                                     86 	.globl _TI
                                     87 	.globl _RI
                                     88 	.globl _P1_7
                                     89 	.globl _P1_6
                                     90 	.globl _P1_5
                                     91 	.globl _P1_4
                                     92 	.globl _P1_3
                                     93 	.globl _P1_2
                                     94 	.globl _P1_1
                                     95 	.globl _P1_0
                                     96 	.globl _TF1
                                     97 	.globl _TR1
                                     98 	.globl _TF0
                                     99 	.globl _TR0
                                    100 	.globl _IE1
                                    101 	.globl _IT1
                                    102 	.globl _IE0
                                    103 	.globl _IT0
                                    104 	.globl _P0_7
                                    105 	.globl _P0_6
                                    106 	.globl _P0_5
                                    107 	.globl _P0_4
                                    108 	.globl _P0_3
                                    109 	.globl _P0_2
                                    110 	.globl _P0_1
                                    111 	.globl _P0_0
                                    112 	.globl _TH2
                                    113 	.globl _TL2
                                    114 	.globl _RCAP2H
                                    115 	.globl _RCAP2L
                                    116 	.globl _T2CON
                                    117 	.globl _B
                                    118 	.globl _ACC
                                    119 	.globl _PSW
                                    120 	.globl _IP
                                    121 	.globl _P3
                                    122 	.globl _IE
                                    123 	.globl _P2
                                    124 	.globl _SBUF
                                    125 	.globl _SCON
                                    126 	.globl _P1
                                    127 	.globl _TH1
                                    128 	.globl _TH0
                                    129 	.globl _TL1
                                    130 	.globl _TL0
                                    131 	.globl _TMOD
                                    132 	.globl _TCON
                                    133 	.globl _PCON
                                    134 	.globl _DPH
                                    135 	.globl _DPL
                                    136 	.globl _SP
                                    137 	.globl _P0
                                    138 	.globl _ADC
                                    139 	.globl _LED
                                    140 	.globl _aligned_alloc_PARM_2
                                    141 	.globl _i
                                    142 	.globl _value
                                    143 	.globl _buffer
                                    144 	.globl _read
                                    145 	.globl _disp_binary_as_dec_str
                                    146 	.globl _read_temperature
                                    147 	.globl _read_potentiometer
                                    148 	.globl _check_potentiometer
                                    149 	.globl _LCD_clear
                                    150 	.globl _disp_temperature_val
                                    151 	.globl _reverse_str
                                    152 	.globl _handle_interrupt
                                    153 ;--------------------------------------------------------
                                    154 ; special function registers
                                    155 ;--------------------------------------------------------
                                    156 	.area RSEG    (ABS,DATA)
      000000                        157 	.org 0x0000
                           000080   158 G$P0$0$0 == 0x0080
                           000080   159 _P0	=	0x0080
                           000081   160 G$SP$0$0 == 0x0081
                           000081   161 _SP	=	0x0081
                           000082   162 G$DPL$0$0 == 0x0082
                           000082   163 _DPL	=	0x0082
                           000083   164 G$DPH$0$0 == 0x0083
                           000083   165 _DPH	=	0x0083
                           000087   166 G$PCON$0$0 == 0x0087
                           000087   167 _PCON	=	0x0087
                           000088   168 G$TCON$0$0 == 0x0088
                           000088   169 _TCON	=	0x0088
                           000089   170 G$TMOD$0$0 == 0x0089
                           000089   171 _TMOD	=	0x0089
                           00008A   172 G$TL0$0$0 == 0x008a
                           00008A   173 _TL0	=	0x008a
                           00008B   174 G$TL1$0$0 == 0x008b
                           00008B   175 _TL1	=	0x008b
                           00008C   176 G$TH0$0$0 == 0x008c
                           00008C   177 _TH0	=	0x008c
                           00008D   178 G$TH1$0$0 == 0x008d
                           00008D   179 _TH1	=	0x008d
                           000090   180 G$P1$0$0 == 0x0090
                           000090   181 _P1	=	0x0090
                           000098   182 G$SCON$0$0 == 0x0098
                           000098   183 _SCON	=	0x0098
                           000099   184 G$SBUF$0$0 == 0x0099
                           000099   185 _SBUF	=	0x0099
                           0000A0   186 G$P2$0$0 == 0x00a0
                           0000A0   187 _P2	=	0x00a0
                           0000A8   188 G$IE$0$0 == 0x00a8
                           0000A8   189 _IE	=	0x00a8
                           0000B0   190 G$P3$0$0 == 0x00b0
                           0000B0   191 _P3	=	0x00b0
                           0000B8   192 G$IP$0$0 == 0x00b8
                           0000B8   193 _IP	=	0x00b8
                           0000D0   194 G$PSW$0$0 == 0x00d0
                           0000D0   195 _PSW	=	0x00d0
                           0000E0   196 G$ACC$0$0 == 0x00e0
                           0000E0   197 _ACC	=	0x00e0
                           0000F0   198 G$B$0$0 == 0x00f0
                           0000F0   199 _B	=	0x00f0
                           0000C8   200 G$T2CON$0$0 == 0x00c8
                           0000C8   201 _T2CON	=	0x00c8
                           0000CA   202 G$RCAP2L$0$0 == 0x00ca
                           0000CA   203 _RCAP2L	=	0x00ca
                           0000CB   204 G$RCAP2H$0$0 == 0x00cb
                           0000CB   205 _RCAP2H	=	0x00cb
                           0000CC   206 G$TL2$0$0 == 0x00cc
                           0000CC   207 _TL2	=	0x00cc
                           0000CD   208 G$TH2$0$0 == 0x00cd
                           0000CD   209 _TH2	=	0x00cd
                                    210 ;--------------------------------------------------------
                                    211 ; special function bits
                                    212 ;--------------------------------------------------------
                                    213 	.area RSEG    (ABS,DATA)
      000000                        214 	.org 0x0000
                           000080   215 G$P0_0$0$0 == 0x0080
                           000080   216 _P0_0	=	0x0080
                           000081   217 G$P0_1$0$0 == 0x0081
                           000081   218 _P0_1	=	0x0081
                           000082   219 G$P0_2$0$0 == 0x0082
                           000082   220 _P0_2	=	0x0082
                           000083   221 G$P0_3$0$0 == 0x0083
                           000083   222 _P0_3	=	0x0083
                           000084   223 G$P0_4$0$0 == 0x0084
                           000084   224 _P0_4	=	0x0084
                           000085   225 G$P0_5$0$0 == 0x0085
                           000085   226 _P0_5	=	0x0085
                           000086   227 G$P0_6$0$0 == 0x0086
                           000086   228 _P0_6	=	0x0086
                           000087   229 G$P0_7$0$0 == 0x0087
                           000087   230 _P0_7	=	0x0087
                           000088   231 G$IT0$0$0 == 0x0088
                           000088   232 _IT0	=	0x0088
                           000089   233 G$IE0$0$0 == 0x0089
                           000089   234 _IE0	=	0x0089
                           00008A   235 G$IT1$0$0 == 0x008a
                           00008A   236 _IT1	=	0x008a
                           00008B   237 G$IE1$0$0 == 0x008b
                           00008B   238 _IE1	=	0x008b
                           00008C   239 G$TR0$0$0 == 0x008c
                           00008C   240 _TR0	=	0x008c
                           00008D   241 G$TF0$0$0 == 0x008d
                           00008D   242 _TF0	=	0x008d
                           00008E   243 G$TR1$0$0 == 0x008e
                           00008E   244 _TR1	=	0x008e
                           00008F   245 G$TF1$0$0 == 0x008f
                           00008F   246 _TF1	=	0x008f
                           000090   247 G$P1_0$0$0 == 0x0090
                           000090   248 _P1_0	=	0x0090
                           000091   249 G$P1_1$0$0 == 0x0091
                           000091   250 _P1_1	=	0x0091
                           000092   251 G$P1_2$0$0 == 0x0092
                           000092   252 _P1_2	=	0x0092
                           000093   253 G$P1_3$0$0 == 0x0093
                           000093   254 _P1_3	=	0x0093
                           000094   255 G$P1_4$0$0 == 0x0094
                           000094   256 _P1_4	=	0x0094
                           000095   257 G$P1_5$0$0 == 0x0095
                           000095   258 _P1_5	=	0x0095
                           000096   259 G$P1_6$0$0 == 0x0096
                           000096   260 _P1_6	=	0x0096
                           000097   261 G$P1_7$0$0 == 0x0097
                           000097   262 _P1_7	=	0x0097
                           000098   263 G$RI$0$0 == 0x0098
                           000098   264 _RI	=	0x0098
                           000099   265 G$TI$0$0 == 0x0099
                           000099   266 _TI	=	0x0099
                           00009A   267 G$RB8$0$0 == 0x009a
                           00009A   268 _RB8	=	0x009a
                           00009B   269 G$TB8$0$0 == 0x009b
                           00009B   270 _TB8	=	0x009b
                           00009C   271 G$REN$0$0 == 0x009c
                           00009C   272 _REN	=	0x009c
                           00009D   273 G$SM2$0$0 == 0x009d
                           00009D   274 _SM2	=	0x009d
                           00009E   275 G$SM1$0$0 == 0x009e
                           00009E   276 _SM1	=	0x009e
                           00009F   277 G$SM0$0$0 == 0x009f
                           00009F   278 _SM0	=	0x009f
                           0000A0   279 G$P2_0$0$0 == 0x00a0
                           0000A0   280 _P2_0	=	0x00a0
                           0000A1   281 G$P2_1$0$0 == 0x00a1
                           0000A1   282 _P2_1	=	0x00a1
                           0000A2   283 G$P2_2$0$0 == 0x00a2
                           0000A2   284 _P2_2	=	0x00a2
                           0000A3   285 G$P2_3$0$0 == 0x00a3
                           0000A3   286 _P2_3	=	0x00a3
                           0000A4   287 G$P2_4$0$0 == 0x00a4
                           0000A4   288 _P2_4	=	0x00a4
                           0000A5   289 G$P2_5$0$0 == 0x00a5
                           0000A5   290 _P2_5	=	0x00a5
                           0000A6   291 G$P2_6$0$0 == 0x00a6
                           0000A6   292 _P2_6	=	0x00a6
                           0000A7   293 G$P2_7$0$0 == 0x00a7
                           0000A7   294 _P2_7	=	0x00a7
                           0000A8   295 G$EX0$0$0 == 0x00a8
                           0000A8   296 _EX0	=	0x00a8
                           0000A9   297 G$ET0$0$0 == 0x00a9
                           0000A9   298 _ET0	=	0x00a9
                           0000AA   299 G$EX1$0$0 == 0x00aa
                           0000AA   300 _EX1	=	0x00aa
                           0000AB   301 G$ET1$0$0 == 0x00ab
                           0000AB   302 _ET1	=	0x00ab
                           0000AC   303 G$ES$0$0 == 0x00ac
                           0000AC   304 _ES	=	0x00ac
                           0000AF   305 G$EA$0$0 == 0x00af
                           0000AF   306 _EA	=	0x00af
                           0000B0   307 G$P3_0$0$0 == 0x00b0
                           0000B0   308 _P3_0	=	0x00b0
                           0000B1   309 G$P3_1$0$0 == 0x00b1
                           0000B1   310 _P3_1	=	0x00b1
                           0000B2   311 G$P3_2$0$0 == 0x00b2
                           0000B2   312 _P3_2	=	0x00b2
                           0000B3   313 G$P3_3$0$0 == 0x00b3
                           0000B3   314 _P3_3	=	0x00b3
                           0000B4   315 G$P3_4$0$0 == 0x00b4
                           0000B4   316 _P3_4	=	0x00b4
                           0000B5   317 G$P3_5$0$0 == 0x00b5
                           0000B5   318 _P3_5	=	0x00b5
                           0000B6   319 G$P3_6$0$0 == 0x00b6
                           0000B6   320 _P3_6	=	0x00b6
                           0000B7   321 G$P3_7$0$0 == 0x00b7
                           0000B7   322 _P3_7	=	0x00b7
                           0000B0   323 G$RXD$0$0 == 0x00b0
                           0000B0   324 _RXD	=	0x00b0
                           0000B1   325 G$TXD$0$0 == 0x00b1
                           0000B1   326 _TXD	=	0x00b1
                           0000B2   327 G$INT0$0$0 == 0x00b2
                           0000B2   328 _INT0	=	0x00b2
                           0000B3   329 G$INT1$0$0 == 0x00b3
                           0000B3   330 _INT1	=	0x00b3
                           0000B4   331 G$T0$0$0 == 0x00b4
                           0000B4   332 _T0	=	0x00b4
                           0000B5   333 G$T1$0$0 == 0x00b5
                           0000B5   334 _T1	=	0x00b5
                           0000B6   335 G$WR$0$0 == 0x00b6
                           0000B6   336 _WR	=	0x00b6
                           0000B7   337 G$RD$0$0 == 0x00b7
                           0000B7   338 _RD	=	0x00b7
                           0000B8   339 G$PX0$0$0 == 0x00b8
                           0000B8   340 _PX0	=	0x00b8
                           0000B9   341 G$PT0$0$0 == 0x00b9
                           0000B9   342 _PT0	=	0x00b9
                           0000BA   343 G$PX1$0$0 == 0x00ba
                           0000BA   344 _PX1	=	0x00ba
                           0000BB   345 G$PT1$0$0 == 0x00bb
                           0000BB   346 _PT1	=	0x00bb
                           0000BC   347 G$PS$0$0 == 0x00bc
                           0000BC   348 _PS	=	0x00bc
                           0000D0   349 G$P$0$0 == 0x00d0
                           0000D0   350 _P	=	0x00d0
                           0000D1   351 G$F1$0$0 == 0x00d1
                           0000D1   352 _F1	=	0x00d1
                           0000D2   353 G$OV$0$0 == 0x00d2
                           0000D2   354 _OV	=	0x00d2
                           0000D3   355 G$RS0$0$0 == 0x00d3
                           0000D3   356 _RS0	=	0x00d3
                           0000D4   357 G$RS1$0$0 == 0x00d4
                           0000D4   358 _RS1	=	0x00d4
                           0000D5   359 G$F0$0$0 == 0x00d5
                           0000D5   360 _F0	=	0x00d5
                           0000D6   361 G$AC$0$0 == 0x00d6
                           0000D6   362 _AC	=	0x00d6
                           0000D7   363 G$CY$0$0 == 0x00d7
                           0000D7   364 _CY	=	0x00d7
                           0000AD   365 G$ET2$0$0 == 0x00ad
                           0000AD   366 _ET2	=	0x00ad
                           0000BD   367 G$PT2$0$0 == 0x00bd
                           0000BD   368 _PT2	=	0x00bd
                           0000C8   369 G$T2CON_0$0$0 == 0x00c8
                           0000C8   370 _T2CON_0	=	0x00c8
                           0000C9   371 G$T2CON_1$0$0 == 0x00c9
                           0000C9   372 _T2CON_1	=	0x00c9
                           0000CA   373 G$T2CON_2$0$0 == 0x00ca
                           0000CA   374 _T2CON_2	=	0x00ca
                           0000CB   375 G$T2CON_3$0$0 == 0x00cb
                           0000CB   376 _T2CON_3	=	0x00cb
                           0000CC   377 G$T2CON_4$0$0 == 0x00cc
                           0000CC   378 _T2CON_4	=	0x00cc
                           0000CD   379 G$T2CON_5$0$0 == 0x00cd
                           0000CD   380 _T2CON_5	=	0x00cd
                           0000CE   381 G$T2CON_6$0$0 == 0x00ce
                           0000CE   382 _T2CON_6	=	0x00ce
                           0000CF   383 G$T2CON_7$0$0 == 0x00cf
                           0000CF   384 _T2CON_7	=	0x00cf
                           0000C8   385 G$CP_RL2$0$0 == 0x00c8
                           0000C8   386 _CP_RL2	=	0x00c8
                           0000C9   387 G$C_T2$0$0 == 0x00c9
                           0000C9   388 _C_T2	=	0x00c9
                           0000CA   389 G$TR2$0$0 == 0x00ca
                           0000CA   390 _TR2	=	0x00ca
                           0000CB   391 G$EXEN2$0$0 == 0x00cb
                           0000CB   392 _EXEN2	=	0x00cb
                           0000CC   393 G$TCLK$0$0 == 0x00cc
                           0000CC   394 _TCLK	=	0x00cc
                           0000CD   395 G$RCLK$0$0 == 0x00cd
                           0000CD   396 _RCLK	=	0x00cd
                           0000CE   397 G$EXF2$0$0 == 0x00ce
                           0000CE   398 _EXF2	=	0x00ce
                           0000CF   399 G$TF2$0$0 == 0x00cf
                           0000CF   400 _TF2	=	0x00cf
                                    401 ;--------------------------------------------------------
                                    402 ; overlayable register banks
                                    403 ;--------------------------------------------------------
                                    404 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        405 	.ds 8
                                    406 ;--------------------------------------------------------
                                    407 ; overlayable bit register bank
                                    408 ;--------------------------------------------------------
                                    409 	.area BIT_BANK	(REL,OVR,DATA)
      000020                        410 bits:
      000020                        411 	.ds 1
                           008000   412 	b0 = bits[0]
                           008100   413 	b1 = bits[1]
                           008200   414 	b2 = bits[2]
                           008300   415 	b3 = bits[3]
                           008400   416 	b4 = bits[4]
                           008500   417 	b5 = bits[5]
                           008600   418 	b6 = bits[6]
                           008700   419 	b7 = bits[7]
                                    420 ;--------------------------------------------------------
                                    421 ; internal ram data
                                    422 ;--------------------------------------------------------
                                    423 	.area DSEG    (DATA)
                           000000   424 G$read$0$0==.
      000008                        425 _read::
      000008                        426 	.ds 1
                           000001   427 G$buffer$0$0==.
      000009                        428 _buffer::
      000009                        429 	.ds 3
                           000004   430 G$value$0$0==.
      00000C                        431 _value::
      00000C                        432 	.ds 4
                           000008   433 G$i$0$0==.
      000010                        434 _i::
      000010                        435 	.ds 2
                           00000A   436 Lmain.aligned_alloc$size$1$26==.
      000012                        437 _aligned_alloc_PARM_2:
      000012                        438 	.ds 2
                           00000C   439 Lmain.reverse_str$length$1$86==.
      000014                        440 _reverse_str_length_1_86:
      000014                        441 	.ds 1
                           00000D   442 Lmain.reverse_str$temp$1$86==.
      000015                        443 _reverse_str_temp_1_86:
      000015                        444 	.ds 1
                                    445 ;--------------------------------------------------------
                                    446 ; overlayable items in internal ram 
                                    447 ;--------------------------------------------------------
                                    448 ;--------------------------------------------------------
                                    449 ; Stack segment in internal ram 
                                    450 ;--------------------------------------------------------
                                    451 	.area	SSEG
      000026                        452 __start__stack:
      000026                        453 	.ds	1
                                    454 
                                    455 ;--------------------------------------------------------
                                    456 ; indirectly addressable internal ram data
                                    457 ;--------------------------------------------------------
                                    458 	.area ISEG    (DATA)
                                    459 ;--------------------------------------------------------
                                    460 ; absolute internal ram data
                                    461 ;--------------------------------------------------------
                                    462 	.area IABS    (ABS,DATA)
                                    463 	.area IABS    (ABS,DATA)
                                    464 ;--------------------------------------------------------
                                    465 ; bit data
                                    466 ;--------------------------------------------------------
                                    467 	.area BSEG    (BIT)
                                    468 ;--------------------------------------------------------
                                    469 ; paged external ram data
                                    470 ;--------------------------------------------------------
                                    471 	.area PSEG    (PAG,XDATA)
                                    472 ;--------------------------------------------------------
                                    473 ; external ram data
                                    474 ;--------------------------------------------------------
                                    475 	.area XSEG    (XDATA)
                           00FA00   476 G$LED$0$0 == 0xfa00
                           00FA00   477 _LED	=	0xfa00
                           00F8C0   478 G$ADC$0$0 == 0xf8c0
                           00F8C0   479 _ADC	=	0xf8c0
                                    480 ;--------------------------------------------------------
                                    481 ; absolute external ram data
                                    482 ;--------------------------------------------------------
                                    483 	.area XABS    (ABS,XDATA)
                                    484 ;--------------------------------------------------------
                                    485 ; external initialized ram data
                                    486 ;--------------------------------------------------------
                                    487 	.area XISEG   (XDATA)
                                    488 	.area HOME    (CODE)
                                    489 	.area GSINIT0 (CODE)
                                    490 	.area GSINIT1 (CODE)
                                    491 	.area GSINIT2 (CODE)
                                    492 	.area GSINIT3 (CODE)
                                    493 	.area GSINIT4 (CODE)
                                    494 	.area GSINIT5 (CODE)
                                    495 	.area GSINIT  (CODE)
                                    496 	.area GSFINAL (CODE)
                                    497 	.area CSEG    (CODE)
                                    498 ;--------------------------------------------------------
                                    499 ; interrupt vector 
                                    500 ;--------------------------------------------------------
                                    501 	.area HOME    (CODE)
      000000                        502 __interrupt_vect:
      000000 02 00 09         [24]  503 	ljmp	__sdcc_gsinit_startup
      000003 02 03 D9         [24]  504 	ljmp	_handle_interrupt
                                    505 ;--------------------------------------------------------
                                    506 ; global & static initialisations
                                    507 ;--------------------------------------------------------
                                    508 	.area HOME    (CODE)
                                    509 	.area GSINIT  (CODE)
                                    510 	.area GSFINAL (CODE)
                                    511 	.area GSINIT  (CODE)
                                    512 	.globl __sdcc_gsinit_startup
                                    513 	.globl __sdcc_program_startup
                                    514 	.globl __start__stack
                                    515 	.globl __mcs51_genXINIT
                                    516 	.globl __mcs51_genXRAMCLEAR
                                    517 	.globl __mcs51_genRAMCLEAR
                                    518 	.area GSFINAL (CODE)
      000062 02 00 06         [24]  519 	ljmp	__sdcc_program_startup
                                    520 ;--------------------------------------------------------
                                    521 ; Home
                                    522 ;--------------------------------------------------------
                                    523 	.area HOME    (CODE)
                                    524 	.area HOME    (CODE)
      000006                        525 __sdcc_program_startup:
      000006 02 00 65         [24]  526 	ljmp	_main
                                    527 ;	return from main will return to caller
                                    528 ;--------------------------------------------------------
                                    529 ; code
                                    530 ;--------------------------------------------------------
                                    531 	.area CSEG    (CODE)
                                    532 ;------------------------------------------------------------
                                    533 ;Allocation info for local variables in function 'main'
                                    534 ;------------------------------------------------------------
                           000000   535 	G$main$0$0 ==.
                           000000   536 	C$main.c$28$0$0 ==.
                                    537 ;	main.c:28: void main(void) {
                                    538 ;	-----------------------------------------
                                    539 ;	 function main
                                    540 ;	-----------------------------------------
      000065                        541 _main:
                           000007   542 	ar7 = 0x07
                           000006   543 	ar6 = 0x06
                           000005   544 	ar5 = 0x05
                           000004   545 	ar4 = 0x04
                           000003   546 	ar3 = 0x03
                           000002   547 	ar2 = 0x02
                           000001   548 	ar1 = 0x01
                           000000   549 	ar0 = 0x00
                           000000   550 	C$main.c$29$1$67 ==.
                                    551 ;	main.c:29: LabTM_LCD_Init();                   /* Inicjalizacja wyswietlacza LCD */
      000065 12 05 1E         [24]  552 	lcall	_LabTM_LCD_Init
                           000003   553 	C$main.c$30$1$67 ==.
                                    554 ;	main.c:30: LabTM_LCD_SetPosition(1, 1);        /* Ustawienie kursora w 1 linii, na 1 znaku */
      000068 75 16 01         [24]  555 	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
      00006B 75 82 01         [24]  556 	mov	dpl,#0x01
      00006E 12 05 AB         [24]  557 	lcall	_LabTM_LCD_SetPosition
                           00000C   558 	C$main.c$31$1$67 ==.
                                    559 ;	main.c:31: LabTM_LCD_PrintChar('A');           /* Wyswietlenie znaku */
      000071 75 82 41         [24]  560 	mov	dpl,#0x41
      000074 12 05 9C         [24]  561 	lcall	_LabTM_LCD_PrintChar
                           000012   562 	C$main.c$32$1$67 ==.
                                    563 ;	main.c:32: LabTM_LCD_SetPosition(2, 1);        /* Ustawienie kursora w 2 linii, na 1 znaku */
      000077 75 16 01         [24]  564 	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
      00007A 75 82 02         [24]  565 	mov	dpl,#0x02
      00007D 12 05 AB         [24]  566 	lcall	_LabTM_LCD_SetPosition
                           00001B   567 	C$main.c$33$1$67 ==.
                                    568 ;	main.c:33: LabTM_LCD_PrintString("Test");      /* Wyswietlenie ciagu znakow */
      000080 90 0A 31         [24]  569 	mov	dptr,#___str_0
      000083 75 F0 80         [24]  570 	mov	b,#0x80
      000086 12 05 50         [24]  571 	lcall	_LabTM_LCD_PrintString
                           000024   572 	C$main.c$35$1$67 ==.
                                    573 ;	main.c:35: do {                                /* Wykonuj dzialania w nieskonczonej petli */
      000089                        574 00101$:
                           000024   575 	C$main.c$57$2$68 ==.
                                    576 ;	main.c:57: ADC = 0x0D;                     /* Przeslij adres czujnika temperatury */
      000089 90 F8 C0         [24]  577 	mov	dptr,#_ADC
      00008C 74 0D            [12]  578 	mov	a,#0x0d
      00008E F0               [24]  579 	movx	@dptr,a
                           00002A   580 	C$main.c$58$1$67 ==.
                                    581 ;	main.c:58: } while(1);                         /* Warunek nieskonczonej petli */
      00008F 80 F8            [24]  582 	sjmp	00101$
                           00002C   583 	C$main.c$59$1$67 ==.
                           00002C   584 	XG$main$0$0 ==.
      000091 22               [24]  585 	ret
                                    586 ;------------------------------------------------------------
                                    587 ;Allocation info for local variables in function 'disp_binary_as_dec_str'
                                    588 ;------------------------------------------------------------
                                    589 ;val                       Allocated to registers r7 
                                    590 ;------------------------------------------------------------
                           00002D   591 	G$disp_binary_as_dec_str$0$0 ==.
                           00002D   592 	C$main.c$62$1$67 ==.
                                    593 ;	main.c:62: void disp_binary_as_dec_str(unsigned char val) {
                                    594 ;	-----------------------------------------
                                    595 ;	 function disp_binary_as_dec_str
                                    596 ;	-----------------------------------------
      000092                        597 _disp_binary_as_dec_str:
      000092 AF 82            [24]  598 	mov	r7,dpl
                           00002F   599 	C$main.c$63$1$70 ==.
                                    600 ;	main.c:63: i = 0;                              /* Podstaw domyslna wartosc iteratora */
      000094 E4               [12]  601 	clr	a
      000095 F5 10            [12]  602 	mov	_i,a
      000097 F5 11            [12]  603 	mov	(_i + 1),a
                           000034   604 	C$main.c$64$1$70 ==.
                                    605 ;	main.c:64: buffer = malloc(sizeof(char)*4);    /* Utworz buffer na 3-cyfrowa wartosc dziesietna */
      000099 90 00 04         [24]  606 	mov	dptr,#0x0004
      00009C C0 07            [24]  607 	push	ar7
      00009E 12 07 20         [24]  608 	lcall	_malloc
      0000A1 AD 82            [24]  609 	mov	r5,dpl
      0000A3 AE 83            [24]  610 	mov	r6,dph
      0000A5 D0 07            [24]  611 	pop	ar7
      0000A7 8D 09            [24]  612 	mov	_buffer,r5
      0000A9 8E 0A            [24]  613 	mov	(_buffer + 1),r6
      0000AB 75 0B 00         [24]  614 	mov	(_buffer + 2),#0x00
                           000049   615 	C$main.c$65$1$70 ==.
                                    616 ;	main.c:65: while(val != 0) {                   /* Algorytm wydzielania cyfr - dopoki wartosc jest rozna od 0 */
      0000AE                        617 00101$:
      0000AE EF               [12]  618 	mov	a,r7
      0000AF 60 30            [24]  619 	jz	00103$
                           00004C   620 	C$main.c$66$2$71 ==.
                                    621 ;	main.c:66: buffer[i] = (val % 10) + '0';   /* Wyciagnij cyfre z wartosci, zamien ja na reprezentujacy
      0000B1 E5 10            [12]  622 	mov	a,_i
      0000B3 25 09            [12]  623 	add	a,_buffer
      0000B5 FC               [12]  624 	mov	r4,a
      0000B6 E5 11            [12]  625 	mov	a,(_i + 1)
      0000B8 35 0A            [12]  626 	addc	a,(_buffer + 1)
      0000BA FD               [12]  627 	mov	r5,a
      0000BB AE 0B            [24]  628 	mov	r6,(_buffer + 2)
      0000BD 75 F0 0A         [24]  629 	mov	b,#0x0a
      0000C0 EF               [12]  630 	mov	a,r7
      0000C1 84               [48]  631 	div	ab
      0000C2 AB F0            [24]  632 	mov	r3,b
      0000C4 74 30            [12]  633 	mov	a,#0x30
      0000C6 2B               [12]  634 	add	a,r3
      0000C7 FB               [12]  635 	mov	r3,a
      0000C8 8C 82            [24]  636 	mov	dpl,r4
      0000CA 8D 83            [24]  637 	mov	dph,r5
      0000CC 8E F0            [24]  638 	mov	b,r6
      0000CE 12 06 D4         [24]  639 	lcall	__gptrput
                           00006C   640 	C$main.c$68$2$71 ==.
                                    641 ;	main.c:68: val /= 10;                      /* Przesun wartosc o 1 znak w lewo, usuwajac cyfre jednosci */
      0000D1 75 F0 0A         [24]  642 	mov	b,#0x0a
      0000D4 EF               [12]  643 	mov	a,r7
      0000D5 84               [48]  644 	div	ab
      0000D6 FF               [12]  645 	mov	r7,a
                           000072   646 	C$main.c$69$2$71 ==.
                                    647 ;	main.c:69: i++;                            /* Zwieksz iterator */
      0000D7 05 10            [12]  648 	inc	_i
      0000D9 E4               [12]  649 	clr	a
      0000DA B5 10 D1         [24]  650 	cjne	a,_i,00101$
      0000DD 05 11            [12]  651 	inc	(_i + 1)
      0000DF 80 CD            [24]  652 	sjmp	00101$
      0000E1                        653 00103$:
                           00007C   654 	C$main.c$71$1$70 ==.
                                    655 ;	main.c:71: buffer[i] = '\0';                   /* Zaznacz koniec ciagu znakowego - bufor zawiera wartosc zapisana od tylu*/
      0000E1 E5 10            [12]  656 	mov	a,_i
      0000E3 25 09            [12]  657 	add	a,_buffer
      0000E5 FD               [12]  658 	mov	r5,a
      0000E6 E5 11            [12]  659 	mov	a,(_i + 1)
      0000E8 35 0A            [12]  660 	addc	a,(_buffer + 1)
      0000EA FE               [12]  661 	mov	r6,a
      0000EB AF 0B            [24]  662 	mov	r7,(_buffer + 2)
      0000ED 8D 82            [24]  663 	mov	dpl,r5
      0000EF 8E 83            [24]  664 	mov	dph,r6
      0000F1 8F F0            [24]  665 	mov	b,r7
      0000F3 E4               [12]  666 	clr	a
      0000F4 12 06 D4         [24]  667 	lcall	__gptrput
                           000092   668 	C$main.c$72$1$70 ==.
                                    669 ;	main.c:72: reverse_str(buffer);                /* Odwroc bufor aby otrzymac prawidlowa kolejnosc */
      0000F7 85 09 82         [24]  670 	mov	dpl,_buffer
      0000FA 85 0A 83         [24]  671 	mov	dph,(_buffer + 1)
      0000FD 85 0B F0         [24]  672 	mov	b,(_buffer + 2)
      000100 12 03 72         [24]  673 	lcall	_reverse_str
                           00009E   674 	C$main.c$73$1$70 ==.
                                    675 ;	main.c:73: LabTM_LCD_PrintString(buffer);      /* Wyswietl zawartosc bufora */
      000103 85 09 82         [24]  676 	mov	dpl,_buffer
      000106 85 0A 83         [24]  677 	mov	dph,(_buffer + 1)
      000109 85 0B F0         [24]  678 	mov	b,(_buffer + 2)
      00010C 12 05 50         [24]  679 	lcall	_LabTM_LCD_PrintString
                           0000AA   680 	C$main.c$74$1$70 ==.
                                    681 ;	main.c:74: free(buffer);                       /* Zwolnij bufor */
      00010F AD 09            [24]  682 	mov	r5,_buffer
      000111 AE 0A            [24]  683 	mov	r6,(_buffer + 1)
      000113 AF 0B            [24]  684 	mov	r7,(_buffer + 2)
      000115 8D 82            [24]  685 	mov	dpl,r5
      000117 8E 83            [24]  686 	mov	dph,r6
      000119 8F F0            [24]  687 	mov	b,r7
      00011B 12 04 1E         [24]  688 	lcall	_free
                           0000B9   689 	C$main.c$75$1$70 ==.
                           0000B9   690 	XG$disp_binary_as_dec_str$0$0 ==.
      00011E 22               [24]  691 	ret
                                    692 ;------------------------------------------------------------
                                    693 ;Allocation info for local variables in function 'read_temperature'
                                    694 ;------------------------------------------------------------
                           0000BA   695 	G$read_temperature$0$0 ==.
                           0000BA   696 	C$main.c$78$1$70 ==.
                                    697 ;	main.c:78: unsigned char read_temperature(void) {
                                    698 ;	-----------------------------------------
                                    699 ;	 function read_temperature
                                    700 ;	-----------------------------------------
      00011F                        701 _read_temperature:
                           0000BA   702 	C$main.c$79$1$73 ==.
                                    703 ;	main.c:79: ADC = 0x0D;         /* Przeslij adres czunika temperatury (kanal 6) */
      00011F 90 F8 C0         [24]  704 	mov	dptr,#_ADC
      000122 74 0D            [12]  705 	mov	a,#0x0d
      000124 F0               [24]  706 	movx	@dptr,a
                           0000C0   707 	C$main.c$81$1$73 ==.
                                    708 ;	main.c:81: return ADC;         /* Zwrocenie wartosci zakodowanej w skali przetwornika */
      000125 E0               [24]  709 	movx	a,@dptr
                           0000C1   710 	C$main.c$82$1$73 ==.
                           0000C1   711 	XG$read_temperature$0$0 ==.
      000126 F5 82            [12]  712 	mov	dpl,a
      000128 22               [24]  713 	ret
                                    714 ;------------------------------------------------------------
                                    715 ;Allocation info for local variables in function 'read_potentiometer'
                                    716 ;------------------------------------------------------------
                           0000C4   717 	G$read_potentiometer$0$0 ==.
                           0000C4   718 	C$main.c$85$1$73 ==.
                                    719 ;	main.c:85: unsigned char read_potentiometer(void) {
                                    720 ;	-----------------------------------------
                                    721 ;	 function read_potentiometer
                                    722 ;	-----------------------------------------
      000129                        723 _read_potentiometer:
                           0000C4   724 	C$main.c$86$1$75 ==.
                                    725 ;	main.c:86: ADC = 0x0C;         /* Przeslij adres potencjometru (kanal 5) */
      000129 90 F8 C0         [24]  726 	mov	dptr,#_ADC
      00012C 74 0C            [12]  727 	mov	a,#0x0c
      00012E F0               [24]  728 	movx	@dptr,a
                           0000CA   729 	C$main.c$88$1$75 ==.
                                    730 ;	main.c:88: return ADC;         /* Zwrocenie wartosci zakodowanej w skali przetwornika */
      00012F E0               [24]  731 	movx	a,@dptr
                           0000CB   732 	C$main.c$89$1$75 ==.
                           0000CB   733 	XG$read_potentiometer$0$0 ==.
      000130 F5 82            [12]  734 	mov	dpl,a
      000132 22               [24]  735 	ret
                                    736 ;------------------------------------------------------------
                                    737 ;Allocation info for local variables in function 'check_potentiometer'
                                    738 ;------------------------------------------------------------
                           0000CE   739 	G$check_potentiometer$0$0 ==.
                           0000CE   740 	C$main.c$92$1$75 ==.
                                    741 ;	main.c:92: void check_potentiometer(void) {
                                    742 ;	-----------------------------------------
                                    743 ;	 function check_potentiometer
                                    744 ;	-----------------------------------------
      000133                        745 _check_potentiometer:
                           0000CE   746 	C$main.c$93$1$77 ==.
                                    747 ;	main.c:93: read = read_potentiometer();    /* Odczytaj wartosc z potencjometru zakodowana na 8 bitach */
      000133 12 01 29         [24]  748 	lcall	_read_potentiometer
      000136 85 82 08         [24]  749 	mov	_read,dpl
                           0000D4   750 	C$main.c$94$1$77 ==.
                                    751 ;	main.c:94: LED = read;                   /* Zapal odpowiednie bity */
      000139 90 FA 00         [24]  752 	mov	dptr,#_LED
      00013C E5 08            [12]  753 	mov	a,_read
      00013E F0               [24]  754 	movx	@dptr,a
                           0000DA   755 	C$main.c$95$1$77 ==.
                           0000DA   756 	XG$check_potentiometer$0$0 ==.
      00013F 22               [24]  757 	ret
                                    758 ;------------------------------------------------------------
                                    759 ;Allocation info for local variables in function 'LCD_clear'
                                    760 ;------------------------------------------------------------
                           0000DB   761 	G$LCD_clear$0$0 ==.
                           0000DB   762 	C$main.c$98$1$77 ==.
                                    763 ;	main.c:98: void LCD_clear(void) {
                                    764 ;	-----------------------------------------
                                    765 ;	 function LCD_clear
                                    766 ;	-----------------------------------------
      000140                        767 _LCD_clear:
                           0000DB   768 	C$main.c$99$1$79 ==.
                                    769 ;	main.c:99: LabTM_LCD_SetPosition(1, 1);                /* Ustaw kursor w 1 linii, na 1 znaku */
      000140 75 16 01         [24]  770 	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
      000143 75 82 01         [24]  771 	mov	dpl,#0x01
      000146 12 05 AB         [24]  772 	lcall	_LabTM_LCD_SetPosition
                           0000E4   773 	C$main.c$100$1$79 ==.
                                    774 ;	main.c:100: LabTM_LCD_PrintString("                ");  /* Wyczysc ekran wyswietlajac same spacje */
      000149 90 0A 36         [24]  775 	mov	dptr,#___str_1
      00014C 75 F0 80         [24]  776 	mov	b,#0x80
      00014F 12 05 50         [24]  777 	lcall	_LabTM_LCD_PrintString
                           0000ED   778 	C$main.c$101$1$79 ==.
                                    779 ;	main.c:101: LabTM_LCD_SetPosition(2, 1);                /* Ustaw kursor w 2 linii, na 1 znaku */
      000152 75 16 01         [24]  780 	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
      000155 75 82 02         [24]  781 	mov	dpl,#0x02
      000158 12 05 AB         [24]  782 	lcall	_LabTM_LCD_SetPosition
                           0000F6   783 	C$main.c$102$1$79 ==.
                                    784 ;	main.c:102: LabTM_LCD_PrintString("                ");  /* Wyczysc ekran wyswietlajac same spacje */
      00015B 90 0A 36         [24]  785 	mov	dptr,#___str_1
      00015E 75 F0 80         [24]  786 	mov	b,#0x80
      000161 12 05 50         [24]  787 	lcall	_LabTM_LCD_PrintString
                           0000FF   788 	C$main.c$103$1$79 ==.
                                    789 ;	main.c:103: LabTM_LCD_SetPosition(1, 1);                /* Ustaw kursor w 1 linii, na 1 znaku */
      000164 75 16 01         [24]  790 	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
      000167 75 82 01         [24]  791 	mov	dpl,#0x01
      00016A 12 05 AB         [24]  792 	lcall	_LabTM_LCD_SetPosition
                           000108   793 	C$main.c$104$1$79 ==.
                           000108   794 	XG$LCD_clear$0$0 ==.
      00016D 22               [24]  795 	ret
                                    796 ;------------------------------------------------------------
                                    797 ;Allocation info for local variables in function 'disp_temperature_val'
                                    798 ;------------------------------------------------------------
                                    799 ;adc_read                  Allocated to registers r7 
                                    800 ;temp                      Allocated to registers r7 
                                    801 ;------------------------------------------------------------
                           000109   802 	G$disp_temperature_val$0$0 ==.
                           000109   803 	C$main.c$107$1$79 ==.
                                    804 ;	main.c:107: void disp_temperature_val(unsigned char adc_read) {
                                    805 ;	-----------------------------------------
                                    806 ;	 function disp_temperature_val
                                    807 ;	-----------------------------------------
      00016E                        808 _disp_temperature_val:
      00016E AF 82            [24]  809 	mov	r7,dpl
                           00010B   810 	C$main.c$111$1$81 ==.
                                    811 ;	main.c:111: LabTM_LCD_SetPosition(2, 1);            /* Ustaw kursor w 2 linii, na 1 znaku */
      000170 75 16 01         [24]  812 	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
      000173 75 82 02         [24]  813 	mov	dpl,#0x02
      000176 C0 07            [24]  814 	push	ar7
      000178 12 05 AB         [24]  815 	lcall	_LabTM_LCD_SetPosition
      00017B D0 07            [24]  816 	pop	ar7
                           000118   817 	C$main.c$112$1$81 ==.
                                    818 ;	main.c:112: value = adc_read*2.5f;                      /* Pomnozyc odczyt przez napiecie referencyjne (2.5 V) */
      00017D 8F 82            [24]  819 	mov	dpl,r7
      00017F 12 09 6F         [24]  820 	lcall	___uchar2fs
      000182 AC 82            [24]  821 	mov	r4,dpl
      000184 AD 83            [24]  822 	mov	r5,dph
      000186 AE F0            [24]  823 	mov	r6,b
      000188 FF               [12]  824 	mov	r7,a
      000189 C0 04            [24]  825 	push	ar4
      00018B C0 05            [24]  826 	push	ar5
      00018D C0 06            [24]  827 	push	ar6
      00018F C0 07            [24]  828 	push	ar7
      000191 90 00 00         [24]  829 	mov	dptr,#0x0000
      000194 75 F0 20         [24]  830 	mov	b,#0x20
      000197 74 40            [12]  831 	mov	a,#0x40
      000199 12 05 D0         [24]  832 	lcall	___fsmul
      00019C 85 82 0C         [24]  833 	mov	_value,dpl
      00019F 85 83 0D         [24]  834 	mov	(_value + 1),dph
      0001A2 85 F0 0E         [24]  835 	mov	(_value + 2),b
      0001A5 F5 0F            [12]  836 	mov	(_value + 3),a
      0001A7 E5 81            [12]  837 	mov	a,sp
      0001A9 24 FC            [12]  838 	add	a,#0xfc
      0001AB F5 81            [12]  839 	mov	sp,a
                           000148   840 	C$main.c$113$1$81 ==.
                                    841 ;	main.c:113: value /= 256;                           /* Podzielic przez gorny zakres ADC zeby dokonac konwersji na napiecie w V */
      0001AD E4               [12]  842 	clr	a
      0001AE C0 E0            [24]  843 	push	acc
      0001B0 C0 E0            [24]  844 	push	acc
      0001B2 74 80            [12]  845 	mov	a,#0x80
      0001B4 C0 E0            [24]  846 	push	acc
      0001B6 74 43            [12]  847 	mov	a,#0x43
      0001B8 C0 E0            [24]  848 	push	acc
      0001BA 85 0C 82         [24]  849 	mov	dpl,_value
      0001BD 85 0D 83         [24]  850 	mov	dph,(_value + 1)
      0001C0 85 0E F0         [24]  851 	mov	b,(_value + 2)
      0001C3 E5 0F            [12]  852 	mov	a,(_value + 3)
      0001C5 12 08 AC         [24]  853 	lcall	___fsdiv
      0001C8 85 82 0C         [24]  854 	mov	_value,dpl
      0001CB 85 83 0D         [24]  855 	mov	(_value + 1),dph
      0001CE 85 F0 0E         [24]  856 	mov	(_value + 2),b
      0001D1 F5 0F            [12]  857 	mov	(_value + 3),a
      0001D3 E5 81            [12]  858 	mov	a,sp
      0001D5 24 FC            [12]  859 	add	a,#0xfc
      0001D7 F5 81            [12]  860 	mov	sp,a
                           000174   861 	C$main.c$114$1$81 ==.
                                    862 ;	main.c:114: value *= 100;                           /* Pomnozyc razy 100 (1*C = 0.01V) aby obliczyc temperature w stopniach C */
      0001D9 C0 0C            [24]  863 	push	_value
      0001DB C0 0D            [24]  864 	push	(_value + 1)
      0001DD C0 0E            [24]  865 	push	(_value + 2)
      0001DF C0 0F            [24]  866 	push	(_value + 3)
      0001E1 90 00 00         [24]  867 	mov	dptr,#0x0000
      0001E4 75 F0 C8         [24]  868 	mov	b,#0xc8
      0001E7 74 42            [12]  869 	mov	a,#0x42
      0001E9 12 05 D0         [24]  870 	lcall	___fsmul
      0001EC 85 82 0C         [24]  871 	mov	_value,dpl
      0001EF 85 83 0D         [24]  872 	mov	(_value + 1),dph
      0001F2 85 F0 0E         [24]  873 	mov	(_value + 2),b
      0001F5 F5 0F            [12]  874 	mov	(_value + 3),a
      0001F7 E5 81            [12]  875 	mov	a,sp
      0001F9 24 FC            [12]  876 	add	a,#0xfc
      0001FB F5 81            [12]  877 	mov	sp,a
                           000198   878 	C$main.c$117$1$81 ==.
                                    879 ;	main.c:117: buffer = malloc(sizeof(char)*17);       /* Utworzenie bufforu na cala linie wyswietlacza LCD */
      0001FD 90 00 11         [24]  880 	mov	dptr,#0x0011
      000200 12 07 20         [24]  881 	lcall	_malloc
      000203 AE 82            [24]  882 	mov	r6,dpl
      000205 AF 83            [24]  883 	mov	r7,dph
      000207 8E 09            [24]  884 	mov	_buffer,r6
      000209 8F 0A            [24]  885 	mov	(_buffer + 1),r7
      00020B 75 0B 00         [24]  886 	mov	(_buffer + 2),#0x00
                           0001A9   887 	C$main.c$118$1$81 ==.
                                    888 ;	main.c:118: value *= 100;                           /* Pomnozenie wartosci razy 100 do wyciagniecia wartosci ulamkowej
      00020E C0 0C            [24]  889 	push	_value
      000210 C0 0D            [24]  890 	push	(_value + 1)
      000212 C0 0E            [24]  891 	push	(_value + 2)
      000214 C0 0F            [24]  892 	push	(_value + 3)
      000216 90 00 00         [24]  893 	mov	dptr,#0x0000
      000219 75 F0 C8         [24]  894 	mov	b,#0xc8
      00021C 74 42            [12]  895 	mov	a,#0x42
      00021E 12 05 D0         [24]  896 	lcall	___fsmul
      000221 85 82 0C         [24]  897 	mov	_value,dpl
      000224 85 83 0D         [24]  898 	mov	(_value + 1),dph
      000227 85 F0 0E         [24]  899 	mov	(_value + 2),b
      00022A F5 0F            [12]  900 	mov	(_value + 3),a
      00022C E5 81            [12]  901 	mov	a,sp
      00022E 24 FC            [12]  902 	add	a,#0xfc
      000230 F5 81            [12]  903 	mov	sp,a
                           0001CD   904 	C$main.c$120$1$81 ==.
                                    905 ;	main.c:120: temp = (unsigned char)value;            /* Zapisz wartosc istotna do konwersji pomijajac zbedna czesc ulamkowa
      000232 85 0C 82         [24]  906 	mov	dpl,_value
      000235 85 0D 83         [24]  907 	mov	dph,(_value + 1)
      000238 85 0E F0         [24]  908 	mov	b,(_value + 2)
      00023B E5 0F            [12]  909 	mov	a,(_value + 3)
      00023D 12 09 7A         [24]  910 	lcall	___fs2uchar
      000240 AF 82            [24]  911 	mov	r7,dpl
                           0001DD   912 	C$main.c$122$1$81 ==.
                                    913 ;	main.c:122: for(i = 0; i < 2; i++) {                /* Przekonwertuj i zapisz czesc ulamkowa temperatury w buforze */
      000242 E4               [12]  914 	clr	a
      000243 F5 10            [12]  915 	mov	_i,a
      000245 F5 11            [12]  916 	mov	(_i + 1),a
      000247                        917 00107$:
                           0001E2   918 	C$main.c$123$2$82 ==.
                                    919 ;	main.c:123: buffer[i] = (temp % 10) + '0';      /* Wyciagnij cyfre i zapisz ja za pomoca znaku ja reprezentujacego */
      000247 E5 10            [12]  920 	mov	a,_i
      000249 25 09            [12]  921 	add	a,_buffer
      00024B FC               [12]  922 	mov	r4,a
      00024C E5 11            [12]  923 	mov	a,(_i + 1)
      00024E 35 0A            [12]  924 	addc	a,(_buffer + 1)
      000250 FD               [12]  925 	mov	r5,a
      000251 AE 0B            [24]  926 	mov	r6,(_buffer + 2)
      000253 75 F0 0A         [24]  927 	mov	b,#0x0a
      000256 EF               [12]  928 	mov	a,r7
      000257 84               [48]  929 	div	ab
      000258 AB F0            [24]  930 	mov	r3,b
      00025A 74 30            [12]  931 	mov	a,#0x30
      00025C 2B               [12]  932 	add	a,r3
      00025D FB               [12]  933 	mov	r3,a
      00025E 8C 82            [24]  934 	mov	dpl,r4
      000260 8D 83            [24]  935 	mov	dph,r5
      000262 8E F0            [24]  936 	mov	b,r6
      000264 12 06 D4         [24]  937 	lcall	__gptrput
                           000202   938 	C$main.c$124$2$82 ==.
                                    939 ;	main.c:124: temp /= 10;                         /* Przesun wartosc o jedno miejsce w prawo, usuwajac liczbe jednosci */
      000267 75 F0 0A         [24]  940 	mov	b,#0x0a
      00026A EF               [12]  941 	mov	a,r7
      00026B 84               [48]  942 	div	ab
      00026C FF               [12]  943 	mov	r7,a
                           000208   944 	C$main.c$122$1$81 ==.
                                    945 ;	main.c:122: for(i = 0; i < 2; i++) {                /* Przekonwertuj i zapisz czesc ulamkowa temperatury w buforze */
      00026D 05 10            [12]  946 	inc	_i
      00026F E4               [12]  947 	clr	a
      000270 B5 10 02         [24]  948 	cjne	a,_i,00126$
      000273 05 11            [12]  949 	inc	(_i + 1)
      000275                        950 00126$:
      000275 C3               [12]  951 	clr	c
      000276 E5 10            [12]  952 	mov	a,_i
      000278 94 02            [12]  953 	subb	a,#0x02
      00027A E5 11            [12]  954 	mov	a,(_i + 1)
      00027C 64 80            [12]  955 	xrl	a,#0x80
      00027E 94 80            [12]  956 	subb	a,#0x80
      000280 40 C5            [24]  957 	jc	00107$
                           00021D   958 	C$main.c$126$1$81 ==.
                                    959 ;	main.c:126: buffer[i] = '.';                        /* Zapisz separator dziesietny */
      000282 E5 10            [12]  960 	mov	a,_i
      000284 25 09            [12]  961 	add	a,_buffer
      000286 FC               [12]  962 	mov	r4,a
      000287 E5 11            [12]  963 	mov	a,(_i + 1)
      000289 35 0A            [12]  964 	addc	a,(_buffer + 1)
      00028B FD               [12]  965 	mov	r5,a
      00028C AE 0B            [24]  966 	mov	r6,(_buffer + 2)
      00028E 8C 82            [24]  967 	mov	dpl,r4
      000290 8D 83            [24]  968 	mov	dph,r5
      000292 8E F0            [24]  969 	mov	b,r6
      000294 74 2E            [12]  970 	mov	a,#0x2e
      000296 12 06 D4         [24]  971 	lcall	__gptrput
                           000234   972 	C$main.c$127$1$81 ==.
                                    973 ;	main.c:127: i++;                                    /* Zwieksz iterator */
      000299 05 10            [12]  974 	inc	_i
      00029B E4               [12]  975 	clr	a
      00029C B5 10 02         [24]  976 	cjne	a,_i,00128$
      00029F 05 11            [12]  977 	inc	(_i + 1)
      0002A1                        978 00128$:
                           00023C   979 	C$main.c$128$1$81 ==.
                                    980 ;	main.c:128: while(value != 0) {                     /* Przekonwertuj i zapisz czesc calkowita temperatury w buforze */
      0002A1                        981 00102$:
      0002A1 85 0C F0         [24]  982 	mov	b,_value
      0002A4 E5 0D            [12]  983 	mov	a,(_value + 1)
      0002A6 42 F0            [12]  984 	orl	b,a
      0002A8 E5 0E            [12]  985 	mov	a,(_value + 2)
      0002AA 42 F0            [12]  986 	orl	b,a
      0002AC E5 0F            [12]  987 	mov	a,(_value + 3)
      0002AE 54 7F            [12]  988 	anl	a,#0x7F
      0002B0 45 F0            [12]  989 	orl	a,b
      0002B2 60 30            [24]  990 	jz	00104$
                           00024F   991 	C$main.c$129$2$83 ==.
                                    992 ;	main.c:129: buffer[i] = (temp % 10) + '0';      /* Wyciagnij cyfre i zapisz ja za pomoca znaku ja reprezentujacego */
      0002B4 E5 10            [12]  993 	mov	a,_i
      0002B6 25 09            [12]  994 	add	a,_buffer
      0002B8 FC               [12]  995 	mov	r4,a
      0002B9 E5 11            [12]  996 	mov	a,(_i + 1)
      0002BB 35 0A            [12]  997 	addc	a,(_buffer + 1)
      0002BD FD               [12]  998 	mov	r5,a
      0002BE AE 0B            [24]  999 	mov	r6,(_buffer + 2)
      0002C0 75 F0 0A         [24] 1000 	mov	b,#0x0a
      0002C3 EF               [12] 1001 	mov	a,r7
      0002C4 84               [48] 1002 	div	ab
      0002C5 AB F0            [24] 1003 	mov	r3,b
      0002C7 74 30            [12] 1004 	mov	a,#0x30
      0002C9 2B               [12] 1005 	add	a,r3
      0002CA FB               [12] 1006 	mov	r3,a
      0002CB 8C 82            [24] 1007 	mov	dpl,r4
      0002CD 8D 83            [24] 1008 	mov	dph,r5
      0002CF 8E F0            [24] 1009 	mov	b,r6
      0002D1 12 06 D4         [24] 1010 	lcall	__gptrput
                           00026F  1011 	C$main.c$130$2$83 ==.
                                   1012 ;	main.c:130: temp /= 10;                         /* Przesun wartosc o jedno miejsce w prawo, usuwajac liczbe jednosci */
      0002D4 75 F0 0A         [24] 1013 	mov	b,#0x0a
      0002D7 EF               [12] 1014 	mov	a,r7
      0002D8 84               [48] 1015 	div	ab
      0002D9 FF               [12] 1016 	mov	r7,a
                           000275  1017 	C$main.c$131$2$83 ==.
                                   1018 ;	main.c:131: i++;                                /* Zwieksz iterator */
      0002DA 05 10            [12] 1019 	inc	_i
      0002DC E4               [12] 1020 	clr	a
      0002DD B5 10 C1         [24] 1021 	cjne	a,_i,00102$
      0002E0 05 11            [12] 1022 	inc	(_i + 1)
      0002E2 80 BD            [24] 1023 	sjmp	00102$
      0002E4                       1024 00104$:
                           00027F  1025 	C$main.c$133$1$81 ==.
                                   1026 ;	main.c:133: if(i == 4) {                            /* Jesli iterator wynosi 4 (czesc calkowita pomiaru wynosila 0) */
      0002E4 74 04            [12] 1027 	mov	a,#0x04
      0002E6 B5 10 06         [24] 1028 	cjne	a,_i,00131$
      0002E9 E4               [12] 1029 	clr	a
      0002EA B5 11 02         [24] 1030 	cjne	a,(_i + 1),00131$
      0002ED 80 02            [24] 1031 	sjmp	00132$
      0002EF                       1032 00131$:
      0002EF 80 1F            [24] 1033 	sjmp	00106$
      0002F1                       1034 00132$:
                           00028C  1035 	C$main.c$134$2$84 ==.
                                   1036 ;	main.c:134: buffer[i] = '0';                    /* Zapisz czesc calkowita jako 0 */
      0002F1 E5 10            [12] 1037 	mov	a,_i
      0002F3 25 09            [12] 1038 	add	a,_buffer
      0002F5 FD               [12] 1039 	mov	r5,a
      0002F6 E5 11            [12] 1040 	mov	a,(_i + 1)
      0002F8 35 0A            [12] 1041 	addc	a,(_buffer + 1)
      0002FA FE               [12] 1042 	mov	r6,a
      0002FB AF 0B            [24] 1043 	mov	r7,(_buffer + 2)
      0002FD 8D 82            [24] 1044 	mov	dpl,r5
      0002FF 8E 83            [24] 1045 	mov	dph,r6
      000301 8F F0            [24] 1046 	mov	b,r7
      000303 74 30            [12] 1047 	mov	a,#0x30
      000305 12 06 D4         [24] 1048 	lcall	__gptrput
                           0002A3  1049 	C$main.c$135$2$84 ==.
                                   1050 ;	main.c:135: i++;                                /* Zwieksz iterator */
      000308 05 10            [12] 1051 	inc	_i
      00030A E4               [12] 1052 	clr	a
      00030B B5 10 02         [24] 1053 	cjne	a,_i,00133$
      00030E 05 11            [12] 1054 	inc	(_i + 1)
      000310                       1055 00133$:
      000310                       1056 00106$:
                           0002AB  1057 	C$main.c$137$1$81 ==.
                                   1058 ;	main.c:137: buffer[i] = '\0';                       /* Zaznacz koniec ciagu znakowego - bufor zawiera wartosc zapisana od tylu*/
      000310 E5 10            [12] 1059 	mov	a,_i
      000312 25 09            [12] 1060 	add	a,_buffer
      000314 FD               [12] 1061 	mov	r5,a
      000315 E5 11            [12] 1062 	mov	a,(_i + 1)
      000317 35 0A            [12] 1063 	addc	a,(_buffer + 1)
      000319 FE               [12] 1064 	mov	r6,a
      00031A AF 0B            [24] 1065 	mov	r7,(_buffer + 2)
      00031C 8D 82            [24] 1066 	mov	dpl,r5
      00031E 8E 83            [24] 1067 	mov	dph,r6
      000320 8F F0            [24] 1068 	mov	b,r7
      000322 E4               [12] 1069 	clr	a
      000323 12 06 D4         [24] 1070 	lcall	__gptrput
                           0002C1  1071 	C$main.c$138$1$81 ==.
                                   1072 ;	main.c:138: reverse_str(buffer);                    /* Odwroc bufor aby otrzymac prawidlowa kolejnosc */
      000326 85 09 82         [24] 1073 	mov	dpl,_buffer
      000329 85 0A 83         [24] 1074 	mov	dph,(_buffer + 1)
      00032C 85 0B F0         [24] 1075 	mov	b,(_buffer + 2)
      00032F 12 03 72         [24] 1076 	lcall	_reverse_str
                           0002CD  1077 	C$main.c$141$1$81 ==.
                                   1078 ;	main.c:141: LabTM_LCD_SetPosition(1, 1);            /* Ustaw kursor w 1 linii, na 1 znaku */
      000332 75 16 01         [24] 1079 	mov	_LabTM_LCD_SetPosition_PARM_2,#0x01
      000335 75 82 01         [24] 1080 	mov	dpl,#0x01
      000338 12 05 AB         [24] 1081 	lcall	_LabTM_LCD_SetPosition
                           0002D6  1082 	C$main.c$142$1$81 ==.
                                   1083 ;	main.c:142: LabTM_LCD_PrintString("Temperatura");   /* Wyswietl napis "Temperatura" */
      00033B 90 0A 47         [24] 1084 	mov	dptr,#___str_2
      00033E 75 F0 80         [24] 1085 	mov	b,#0x80
      000341 12 05 50         [24] 1086 	lcall	_LabTM_LCD_PrintString
                           0002DF  1087 	C$main.c$143$1$81 ==.
                                   1088 ;	main.c:143: LabTM_LCD_SetPosition(2, 4);            /* Ustaw kursor w 2 linii, na 6 znaku (centrowanie wyniku pomiaru) */
      000344 75 16 04         [24] 1089 	mov	_LabTM_LCD_SetPosition_PARM_2,#0x04
      000347 75 82 02         [24] 1090 	mov	dpl,#0x02
      00034A 12 05 AB         [24] 1091 	lcall	_LabTM_LCD_SetPosition
                           0002E8  1092 	C$main.c$144$1$81 ==.
                                   1093 ;	main.c:144: LabTM_LCD_PrintString(buffer);          /* Wyswietl zawartosc bufora */
      00034D 85 09 82         [24] 1094 	mov	dpl,_buffer
      000350 85 0A 83         [24] 1095 	mov	dph,(_buffer + 1)
      000353 85 0B F0         [24] 1096 	mov	b,(_buffer + 2)
      000356 12 05 50         [24] 1097 	lcall	_LabTM_LCD_PrintString
                           0002F4  1098 	C$main.c$145$1$81 ==.
                                   1099 ;	main.c:145: LabTM_LCD_PrintString(" *C");           /* Wyswietl jednostke */
      000359 90 0A 53         [24] 1100 	mov	dptr,#___str_3
      00035C 75 F0 80         [24] 1101 	mov	b,#0x80
      00035F 12 05 50         [24] 1102 	lcall	_LabTM_LCD_PrintString
                           0002FD  1103 	C$main.c$146$1$81 ==.
                                   1104 ;	main.c:146: free(buffer);                           /* Zwolnij bufor */
      000362 AD 09            [24] 1105 	mov	r5,_buffer
      000364 AE 0A            [24] 1106 	mov	r6,(_buffer + 1)
      000366 AF 0B            [24] 1107 	mov	r7,(_buffer + 2)
      000368 8D 82            [24] 1108 	mov	dpl,r5
      00036A 8E 83            [24] 1109 	mov	dph,r6
      00036C 8F F0            [24] 1110 	mov	b,r7
      00036E 12 04 1E         [24] 1111 	lcall	_free
                           00030C  1112 	C$main.c$147$1$81 ==.
                           00030C  1113 	XG$disp_temperature_val$0$0 ==.
      000371 22               [24] 1114 	ret
                                   1115 ;------------------------------------------------------------
                                   1116 ;Allocation info for local variables in function 'reverse_str'
                                   1117 ;------------------------------------------------------------
                                   1118 ;str                       Allocated to registers r5 r6 r7 
                                   1119 ;length                    Allocated with name '_reverse_str_length_1_86'
                                   1120 ;temp                      Allocated with name '_reverse_str_temp_1_86'
                                   1121 ;------------------------------------------------------------
                           00030D  1122 	G$reverse_str$0$0 ==.
                           00030D  1123 	C$main.c$150$1$81 ==.
                                   1124 ;	main.c:150: void reverse_str(char str[]) {
                                   1125 ;	-----------------------------------------
                                   1126 ;	 function reverse_str
                                   1127 ;	-----------------------------------------
      000372                       1128 _reverse_str:
                           00030D  1129 	C$main.c$153$1$86 ==.
                                   1130 ;	main.c:153: length = strlen(str);               /* Odczytaj dlugosc ciagu znakowego */
      000372 AD 82            [24] 1131 	mov	r5,dpl
      000374 AE 83            [24] 1132 	mov	r6,dph
      000376 AF F0            [24] 1133 	mov	r7,b
      000378 C0 07            [24] 1134 	push	ar7
      00037A C0 06            [24] 1135 	push	ar6
      00037C C0 05            [24] 1136 	push	ar5
      00037E 12 08 94         [24] 1137 	lcall	_strlen
      000381 AB 82            [24] 1138 	mov	r3,dpl
      000383 D0 05            [24] 1139 	pop	ar5
      000385 D0 06            [24] 1140 	pop	ar6
      000387 D0 07            [24] 1141 	pop	ar7
      000389 8B 14            [24] 1142 	mov	_reverse_str_length_1_86,r3
                           000326  1143 	C$main.c$154$1$86 ==.
                                   1144 ;	main.c:154: i = 0;                              /* Ustaw domyslna wartosc iteratora */
      00038B E4               [12] 1145 	clr	a
      00038C F5 10            [12] 1146 	mov	_i,a
      00038E F5 11            [12] 1147 	mov	(_i + 1),a
                           00032B  1148 	C$main.c$155$1$86 ==.
                                   1149 ;	main.c:155: while(i <= length / 2) {            /* Dopoki iterator przechodzi przez lewa polowe ciagu znakowego */
      000390 E5 14            [12] 1150 	mov	a,_reverse_str_length_1_86
      000392 C3               [12] 1151 	clr	c
      000393 13               [12] 1152 	rrc	a
      000394 FC               [12] 1153 	mov	r4,a
      000395                       1154 00101$:
      000395 8C 01            [24] 1155 	mov	ar1,r4
      000397 E4               [12] 1156 	clr	a
      000398 FA               [12] 1157 	mov	r2,a
      000399 20 E7 3C         [24] 1158 	jb	acc.7,00104$
                           000337  1159 	C$main.c$156$2$87 ==.
                                   1160 ;	main.c:156: temp = str[i];                  /* Zapisz znak po lewej do zmiennej tymczasowej */
      00039C 8D 82            [24] 1161 	mov	dpl,r5
      00039E 8E 83            [24] 1162 	mov	dph,r6
      0003A0 8F F0            [24] 1163 	mov	b,r7
      0003A2 12 09 82         [24] 1164 	lcall	__gptrget
      0003A5 F5 15            [12] 1165 	mov	_reverse_str_temp_1_86,a
                           000342  1166 	C$main.c$157$2$87 ==.
                                   1167 ;	main.c:157: str[i] = str[length - i - 1];   /* Nadpisz znak po lewej znakiem po prawej */
      0003A7 A8 14            [24] 1168 	mov	r0,_reverse_str_length_1_86
      0003A9 79 00            [12] 1169 	mov	r1,#0x00
      0003AB 18               [12] 1170 	dec	r0
      0003AC B8 FF 01         [24] 1171 	cjne	r0,#0xff,00113$
      0003AF 19               [12] 1172 	dec	r1
      0003B0                       1173 00113$:
      0003B0 E8               [12] 1174 	mov	a,r0
      0003B1 2D               [12] 1175 	add	a,r5
      0003B2 F8               [12] 1176 	mov	r0,a
      0003B3 E9               [12] 1177 	mov	a,r1
      0003B4 3E               [12] 1178 	addc	a,r6
      0003B5 F9               [12] 1179 	mov	r1,a
      0003B6 8F 02            [24] 1180 	mov	ar2,r7
      0003B8 88 82            [24] 1181 	mov	dpl,r0
      0003BA 89 83            [24] 1182 	mov	dph,r1
      0003BC 8A F0            [24] 1183 	mov	b,r2
      0003BE 12 09 82         [24] 1184 	lcall	__gptrget
      0003C1 FB               [12] 1185 	mov	r3,a
      0003C2 8D 82            [24] 1186 	mov	dpl,r5
      0003C4 8E 83            [24] 1187 	mov	dph,r6
      0003C6 8F F0            [24] 1188 	mov	b,r7
      0003C8 12 06 D4         [24] 1189 	lcall	__gptrput
                           000366  1190 	C$main.c$158$2$87 ==.
                                   1191 ;	main.c:158: str[length - i - 1] = temp;     /* Nadpisz znak po prawej zapisanym znakiem ktory byl po lewej */
      0003CB 88 82            [24] 1192 	mov	dpl,r0
      0003CD 89 83            [24] 1193 	mov	dph,r1
      0003CF 8A F0            [24] 1194 	mov	b,r2
      0003D1 E5 15            [12] 1195 	mov	a,_reverse_str_temp_1_86
      0003D3 12 06 D4         [24] 1196 	lcall	__gptrput
      0003D6 80 BD            [24] 1197 	sjmp	00101$
      0003D8                       1198 00104$:
                           000373  1199 	C$main.c$160$1$86 ==.
                           000373  1200 	XG$reverse_str$0$0 ==.
      0003D8 22               [24] 1201 	ret
                                   1202 ;------------------------------------------------------------
                                   1203 ;Allocation info for local variables in function 'handle_interrupt'
                                   1204 ;------------------------------------------------------------
                           000374  1205 	G$handle_interrupt$0$0 ==.
                           000374  1206 	C$main.c$163$1$86 ==.
                                   1207 ;	main.c:163: void handle_interrupt(void) __interrupt(0) {
                                   1208 ;	-----------------------------------------
                                   1209 ;	 function handle_interrupt
                                   1210 ;	-----------------------------------------
      0003D9                       1211 _handle_interrupt:
      0003D9 C0 20            [24] 1212 	push	bits
      0003DB C0 E0            [24] 1213 	push	acc
      0003DD C0 F0            [24] 1214 	push	b
      0003DF C0 82            [24] 1215 	push	dpl
      0003E1 C0 83            [24] 1216 	push	dph
      0003E3 C0 07            [24] 1217 	push	(0+7)
      0003E5 C0 06            [24] 1218 	push	(0+6)
      0003E7 C0 05            [24] 1219 	push	(0+5)
      0003E9 C0 04            [24] 1220 	push	(0+4)
      0003EB C0 03            [24] 1221 	push	(0+3)
      0003ED C0 02            [24] 1222 	push	(0+2)
      0003EF C0 01            [24] 1223 	push	(0+1)
      0003F1 C0 00            [24] 1224 	push	(0+0)
      0003F3 C0 D0            [24] 1225 	push	psw
      0003F5 75 D0 00         [24] 1226 	mov	psw,#0x00
                           000393  1227 	C$main.c$164$1$89 ==.
                                   1228 ;	main.c:164: read = read_temperature();  /* Odczytanie wartosci temperatury jako wartosc z zakresu ADC */
      0003F8 12 01 1F         [24] 1229 	lcall	_read_temperature
                           000396  1230 	C$main.c$165$1$89 ==.
                                   1231 ;	main.c:165: disp_temperature_val(read); /* Konwersja i wyswietlenie odczytu jako wartosc w stopniach C */
      0003FB 85 82 08         [24] 1232 	mov  _read,dpl
      0003FE 12 01 6E         [24] 1233 	lcall	_disp_temperature_val
      000401 D0 D0            [24] 1234 	pop	psw
      000403 D0 00            [24] 1235 	pop	(0+0)
      000405 D0 01            [24] 1236 	pop	(0+1)
      000407 D0 02            [24] 1237 	pop	(0+2)
      000409 D0 03            [24] 1238 	pop	(0+3)
      00040B D0 04            [24] 1239 	pop	(0+4)
      00040D D0 05            [24] 1240 	pop	(0+5)
      00040F D0 06            [24] 1241 	pop	(0+6)
      000411 D0 07            [24] 1242 	pop	(0+7)
      000413 D0 83            [24] 1243 	pop	dph
      000415 D0 82            [24] 1244 	pop	dpl
      000417 D0 F0            [24] 1245 	pop	b
      000419 D0 E0            [24] 1246 	pop	acc
      00041B D0 20            [24] 1247 	pop	bits
                           0003B8  1248 	C$main.c$166$1$89 ==.
                           0003B8  1249 	XG$handle_interrupt$0$0 ==.
      00041D 32               [24] 1250 	reti
                                   1251 	.area CSEG    (CODE)
                                   1252 	.area CONST   (CODE)
                           000000  1253 Fmain$__str_0$0$0 == .
      000A31                       1254 ___str_0:
      000A31 54 65 73 74           1255 	.ascii "Test"
      000A35 00                    1256 	.db 0x00
                           000005  1257 Fmain$__str_1$0$0 == .
      000A36                       1258 ___str_1:
      000A36 20 20 20 20 20 20 20  1259 	.ascii "                "
             20 20 20 20 20 20 20
             20 20
      000A46 00                    1260 	.db 0x00
                           000016  1261 Fmain$__str_2$0$0 == .
      000A47                       1262 ___str_2:
      000A47 54 65 6D 70 65 72 61  1263 	.ascii "Temperatura"
             74 75 72 61
      000A52 00                    1264 	.db 0x00
                           000022  1265 Fmain$__str_3$0$0 == .
      000A53                       1266 ___str_3:
      000A53 20 2A 43              1267 	.ascii " *C"
      000A56 00                    1268 	.db 0x00
                                   1269 	.area XINIT   (CODE)
                                   1270 	.area CABS    (ABS,CODE)
