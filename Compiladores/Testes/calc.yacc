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



// precedencia retirade de:
// http://en.wikipedia.org/wiki/Operators_in_C_and_C


// tabela de simbolos:
#include "SymbolTable.cpp"
SymbolTable *st = new SymbolTable();

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

%type <tint> expr

%%

input 	: 
      	| input line NL                      
      	;

line 	: expr 	{printf("resultado = %d\n",$1);}
     	;


expr	:	expr PLUS expr	{$$ = $1 + $3;}
		|	expr MINUS expr	{$$ = $1 - $3;}
		|	expr MULT expr	{$$ = $1 * $3;}
		|	expr DIV expr	{$$ = $1 / $3;}
		|	P_OPEN expr P_CLOSE	{$$ = $2;}
		|	INTNUM	{$$ = yylval.tint;}
		;

%%

#include "calc.lex.cpp"


int main(){
	yyparse();
}

void yyerror(const char *s){
	cout << s << endl;
}