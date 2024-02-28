typedef union {
    symbol      *sym ;      /* symbol table pointer       */
    structdef   *sdef;      /* structure definition       */
    char        yychar[C51_NAME_MAX+1];
    sym_link    *lnk ;      /* declarator  or specifier   */
    int         yyint;      /* integer value returned     */
    value       *val ;      /* for integer constant       */
    initList    *ilist;     /* initial list               */
	designation *dsgn;      /* designator                 */
    const char  *yyinline;  /* inlined assembler code     */
    ast         *asts;      /* expression tree            */
} YYSTYPE;
#define	IDENTIFIER	257
#define	TYPE_NAME	258
#define	CONSTANT	259
#define	STRING_LITERAL	260
#define	SIZEOF	261
#define	TYPEOF	262
#define	PTR_OP	263
#define	INC_OP	264
#define	DEC_OP	265
#define	LEFT_OP	266
#define	RIGHT_OP	267
#define	LE_OP	268
#define	GE_OP	269
#define	EQ_OP	270
#define	NE_OP	271
#define	AND_OP	272
#define	OR_OP	273
#define	MUL_ASSIGN	274
#define	DIV_ASSIGN	275
#define	MOD_ASSIGN	276
#define	ADD_ASSIGN	277
#define	SUB_ASSIGN	278
#define	LEFT_ASSIGN	279
#define	RIGHT_ASSIGN	280
#define	AND_ASSIGN	281
#define	XOR_ASSIGN	282
#define	OR_ASSIGN	283
#define	TYPEDEF	284
#define	EXTERN	285
#define	STATIC	286
#define	AUTO	287
#define	REGISTER	288
#define	CODE	289
#define	EEPROM	290
#define	INTERRUPT	291
#define	SFR	292
#define	SFR16	293
#define	SFR32	294
#define	AT	295
#define	SBIT	296
#define	REENTRANT	297
#define	USING	298
#define	XDATA	299
#define	DATA	300
#define	IDATA	301
#define	PDATA	302
#define	VAR_ARGS	303
#define	CRITICAL	304
#define	NONBANKED	305
#define	BANKED	306
#define	SHADOWREGS	307
#define	WPARAM	308
#define	CHAR	309
#define	SHORT	310
#define	INT	311
#define	LONG	312
#define	SIGNED	313
#define	UNSIGNED	314
#define	FLOAT	315
#define	DOUBLE	316
#define	FIXED16X16	317
#define	CONST	318
#define	VOLATILE	319
#define	VOID	320
#define	BIT	321
#define	STRUCT	322
#define	UNION	323
#define	ENUM	324
#define	RANGE	325
#define	FAR	326
#define	CASE	327
#define	DEFAULT	328
#define	IF	329
#define	ELSE	330
#define	SWITCH	331
#define	WHILE	332
#define	DO	333
#define	FOR	334
#define	GOTO	335
#define	CONTINUE	336
#define	BREAK	337
#define	RETURN	338
#define	NAKED	339
#define	JAVANATIVE	340
#define	OVERLAY	341
#define	INLINEASM	342
#define	IFX	343
#define	ADDRESS_OF	344
#define	GET_VALUE_AT_ADDRESS	345
#define	SPIL	346
#define	UNSPIL	347
#define	GETHBIT	348
#define	GETABIT	349
#define	GETBYTE	350
#define	GETWORD	351
#define	BITWISEAND	352
#define	UNARYMINUS	353
#define	IPUSH	354
#define	IPOP	355
#define	PCALL	356
#define	ENDFUNCTION	357
#define	JUMPTABLE	358
#define	RRC	359
#define	RLC	360
#define	CAST	361
#define	CALL	362
#define	PARAM	363
#define	NULLOP	364
#define	BLOCK	365
#define	LABEL	366
#define	RECEIVE	367
#define	SEND	368
#define	ARRAYINIT	369
#define	DUMMY_READ_VOLATILE	370
#define	ENDCRITICAL	371
#define	SWAP	372
#define	INLINE	373
#define	RESTRICT	374


extern YYSTYPE yylval;
