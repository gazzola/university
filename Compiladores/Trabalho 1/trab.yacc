%{

#include <cctype>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// stuff from flex that bison needs to know about:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(const char *s);


// symbol table definition and instance:
#include "SymbolTable.cpp"
SymbolTable *st = new SymbolTable();

unsigned int nlines = 1;
unsigned int ncols	= 1;
unsigned int nscopes = 1;
unsigned int tipoatual;


%}


%union{
	int tint;
	char tchar;
	double tdouble;
	char* tstring;
	Node *tnode;
	vector<string> *tvecstr;
};


%token <tstring> ID
%token <tint> INTNUM 
%token <tdouble> FLOATNUM


%token<tstring> SEMICOLON COMMA
%token<tstring> P_OPEN P_CLOSE B_OPEN B_CLOSE C_OPEN C_CLOSE
%token<tstring> PLUS MINUS MULT DIV POINTER
%token<tstring> OPE OPOU
%token<tstring> ASSIGN LT GT LE GE EQ
%token<tstring> INT FLOAT BOOL
%token<tstring> MAIN IF THEN ELSE WHILE PRINT RETURN


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

%type<tvecstr> listaItens
%type<tstring> item


%%

programa	: 	declaracoes funcaoMain
			;


declaracoes	:	/* vazio */
			|	declaracoes tipo declFuncao
			|	declaracoes tipo declrVariaveis
			;


declrVariaveis	: listaItens SEMICOLON {	for(int i=0; i<(int) $1->size(); i++){
												if(!st->add(new Node($1->at(i), ii(ST_VAR, tipoatual), nscopes, nlines)))
													printf("\nERRO SEMANTICO: variavel `%s` ja foi declarada!\n", $1->at(i).c_str());
											}
										}
				;


declFuncao	:	ID {*($1+strlen($1)-1)='\0';if(!st->add(new Node($1, ii(ST_FUNC, tipoatual), ST_GLOBAL, nlines)))
					printf("\nERRO SEMANTICO: funcao `%s` ja foi declarada!\n", $1);} 
					P_OPEN {nscopes++;} parametros P_CLOSE C_OPEN corpoFuncao C_CLOSE SEMICOLON
			;


funcaoMain	:	tipo MAIN P_OPEN {nscopes++;} P_CLOSE C_OPEN corpoFuncao C_CLOSE SEMICOLON
			;


listaItens	:	listaItens COMMA item	{$$->push_back($3);}
			|	item	{$$ = new vector<string>(); $$->push_back($1);}
			;


item		:	ID {*($1+strlen($1)-1)='\0'; $$ = $1;} 
			|	ID B_OPEN INTNUM B_CLOSE {*($1+strlen($1)-1)='\0'; $$ = $1;}
			|	MULT item %prec POINTER {$$ = $2;}
			;


parametros	:	/* vazio */
			| 	tipo item
			|	parametros COMMA tipo item
			;


tipo		:	INT	{tipoatual = ST_INT;}
			|	FLOAT {tipoatual = ST_FLOAT;}
			|	BOOL {tipoatual = ST_BOOL;}
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

listaExp		:	ID
				|	ID COMMA listaExp
				;


expLogica		:	expLogica OPE expLogica
				|	expLogica OPOU expLogica
				|	ID OPE	ID
				|	ID OPOU	ID
				|	expAritmetica opComparacao expAritmetica
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