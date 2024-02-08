all :  Yacc_CSV_Data.tab.c Yacc_CSV_Data.tab.h  lex.yy.c

Yacc_CSV_Data.tab.c  Yacc_CSV_Data.tab.h : Yacc_CSV_Data.y
	win_bison.exe -d Yacc_CSV_Data.y
	
lex.yy.c : Lex_LOG_Data.L  Yacc_CSV_Data.tab.h
	win_flex.exe Lex_LOG_Data.L
