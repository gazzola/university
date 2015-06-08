%{

#include <cctype>
#include <cstdio>
#include <iostream>
#include <cstdlib>

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
%nonassoc P_OPEN P_CLOSE B_OPEN B_CLOSE


%%

input 	:
		| input programa
      	;

programa	: 	declaracoes
			;

declaracoes	:	/* vazio */
			|	declaracoes tipo declFuncao
			|	declaracoes tipo declrVariaveis
			;

declrVariaveis	:	/* vazio */
				|	listaItens SEMICOLON declaracoes
				;

declFuncao	:	ID P_OPEN parametros P_CLOSE C_OPEN corpoFuncao C_CLOSE SEMICOLON
			|	MAIN P_OPEN P_CLOSE C_OPEN corpoFuncao C_CLOSE SEMICOLON
			;


listaItens	:	item COMMA listaItens
			|	item
			;

item		:	ID
			|	ID B_OPEN INTNUM B_CLOSE
			|	POINTER item
			;

parametros	:	/* vazio */
			| 	tipo item
			|	tipo item COMMA parametros
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
				|	ID P_OPEN listaExp P_CLOSE
				|	ID B_OPEN INTNUM B_CLOSE
				|	INTNUM
				|	FLOATNUM
				;

listaExp		:	/* vazio */
				|	ID COMMA listaExp
				|	ID
				;


expLogica		:	expLogica opLogico expLogica
				|	t2
				;

t2				:	expAritmetica opComparacao expAritmetica
				|	ID
				;

opLogico		:	OPE
				|	OPOU
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
	cout << s << endl;
}