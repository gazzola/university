%{

#include <cctype>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// stuff from flex that bison needs to know about:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(const char *s);


// symbol table definition and instance:
#include "SymbolTable.cpp"
SymbolTable *st = new SymbolTable();

%}


%union{
	int tint;
	char tchar;
	double tdouble;
	char* tstring;
};


%token <tstring> ID
%token <tint> INTNUM 
%token <tdouble> FLOATNUM


%token<tint> SEMICOLON COMMA
%token<tint> P_OPEN P_CLOSE B_OPEN B_CLOSE C_OPEN C_CLOSE
%token<tint> PLUS MINUS MULT DIV POINTER
%token<tint> OPE OPOU
%token<tint> ASSIGN LT GT LE GE EQ
%token<tint> INT FLOAT BOOL
%token<tint> MAIN IF THEN ELSE WHILE PRINT RETURN


%left COMMA
%right ASSIGN
%left OPOU
%left OPE
%left EQ
%left LT GT LE GE
%left PLUS MINUS
%left MULT DIV
%left POINTER
%nonassoc P_OPEN P_CLOSE B_OPEN B_CLOSE


%%

programa	: 	declaracoes funcaoMain SEMICOLON
			;


declaracoes	:	/* vazio */
			|	declaracoes tipo declFuncao SEMICOLON
			|	declaracoes tipo declrVariaveis SEMICOLON
			;


declrVariaveis	:	/* vazio */ 
				|	listaItens 
				;


declFuncao	:	ID P_OPEN parametros P_CLOSE C_OPEN corpoFuncao C_CLOSE
			;


funcaoMain	:	tipo MAIN P_OPEN P_CLOSE C_OPEN corpoFuncao C_CLOSE
			;
			

listaItens	:	listaItens COMMA item
			|	item
			;


item		:	ID
			|	ID B_OPEN INTNUM B_CLOSE
			|	MULT item %prec POINTER
			;


parametros	:	/* vazio */
			| 	tipo item
			|	parametros COMMA tipo item
			;


tipo		:	INT	
			|	FLOAT
			|	BOOL
			;


corpoFuncao	:	declaracoes comandos
			;


blocoComandos	:	C_OPEN comandos C_CLOSE
				;


comandos	:	/* vazio */
			|	comando SEMICOLON comandos
			;


comando 	:	atribuicao
			|	retorno
			|	seEntao
			|	impressao
			|	enquanto
			;


atribuicao	:	ID ASSIGN expressao
			|	ID B_OPEN INTNUM B_CLOSE ASSIGN expressao
			;


expressao	:	expAritmetica
			|	expLogica
			;


expAritmetica	:	expAritmetica PLUS t1
				|	expAritmetica MINUS t1
				|	t1
				;


t1				:	t1 MULT f
				|	t1 DIV f
				|	f
				;


f 				:	P_OPEN expAritmetica P_CLOSE
				|	ID
				|	ID P_OPEN listaItens P_CLOSE
				|	ID B_OPEN INTNUM B_CLOSE
				|	INTNUM
				|	FLOATNUM
				;


expLogica		:	expLogica OPE expLogica
				|	expLogica OPOU expLogica
				|	ID OPE	ID
				|	ID OPOU	ID
				|	t2
				;


t2				:	expAritmetica opComparacao expAritmetica
				;


opComparacao	:	LT
				|	GT
				|	LE
				|	GE
				|	EQ
				;


seEntao			:	IF P_OPEN expLogica P_CLOSE THEN blocoComandos ELSE blocoComandos
				;


enquanto 		:	WHILE P_OPEN expLogica P_CLOSE blocoComandos
				;


impressao		:	PRINT expAritmetica
				;


retorno			:	RETURN expAritmetica
				;	

%%

#include "trab.lex.cpp"


int main(){
	yyparse();
}

void yyerror(const char *s){
	cout << endl << s << endl;
}