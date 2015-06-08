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
// #include "SymbolTable.cpp"
// SymbolTable *st = new SymbolTable();

%}


%union{
	int tint;
	double tdouble;
	char* tstring;
};


%token <tstring> ID
%token <tint> INTNUM 
%token <tdouble> FLOATNUM


%token SEMICOLON COMMA
%token P_OPEN P_CLOSE B_OPEN B_CLOSE C_OPEN C_CLOSE
%token PLUS MINUS MULT DIV
%token OPE OPOU
%token ASSIGN LT GT LE GE EQ
%token INT FLOAT BOOL
%token MAIN IF THEN ELSE WHILE PRINT RETURN
%token NL

%left COMMA
%right ASSIGN
%left OPOU
%left OPE
%left EQ
%left LT GT LE GE
%left PLUS MINUS
%left MULT DIV
%nonassoc P_OPEN P_CLOSE B_OPEN B_CLOSE

%type<tint> programa declaracoes declrVariaveis declFuncao
%type<tint> funcaoMain listaItens item parametros tipo
%type<tint> corpoFuncao blocoComandos comandos comando
%type<tint> atribuicao expressao expAritmetica expLogica
%type<tint> t1 f t2 opLogico opComparacao
%type<tint> seEntao While impressao retorno


%%

input 	:
		| input programa NL
      	;

programa	:	declaracoes
			;

declaracoes	:	declrVariaveis declaracoes
			|	declFuncao declaracoes
			;

declrVariaveis	:	tipo listaItens	SEMICOLON declrVariaveis
				|	/* vazio */
				;

declFuncao	:	tipo ID P_OPEN parametros P_CLOSE C_OPEN corpoFuncao C_CLOSE
			;

funcaoMain	:	tipo MAIN P_OPEN P_CLOSE C_OPEN corpoFuncao C_CLOSE
			;

listaItens	:	item COMMA listaItens
			|	item
			;

item		:	ID
			|	ID B_OPEN INTNUM B_CLOSE
			;

parametros	:	tipo item COMMA parametros
			| 	tipo item
			|	/* vazio */
			;

tipo		:	INT	
			|	FLOAT
			|	BOOL
			;

corpoFuncao	:	declaracoes comandos
			;

blocoComandos	:	C_OPEN comandos C_CLOSE
				;

comandos	:	comandos SEMICOLON comandos
			|	/* vazio */
			;

comando 	:	atribuicao
			|	retorno
			|	seEntao
			|	impressao
			|	While
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

t1				:	t1 PLUS f
				|	t1 DIV f
				|	f
				;

f 				:	P_OPEN expAritmetica P_CLOSE
				|	ID
				|	ID B_OPEN INTNUM B_CLOSE
				|	INTNUM
				|	FLOATNUM
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

While 			:	WHILE P_OPEN expLogica P_CLOSE blocoComandos
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