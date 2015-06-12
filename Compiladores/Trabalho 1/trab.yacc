%{

#include <cctype>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;

// declarations that yacc needs to know:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(const char *s);




// typedefs and constants
typedef pair<int, int> ii;
typedef pair<string, int> si;

enum STTypes{
	ST_INT, ST_BOOL, ST_FLOAT, ST_CHAR, ST_VOID,
	ST_FUNC, ST_VAR, ST_CONST,  ST_CMD,
	ST_GLOBAL, ST_LOCAL
};

const int ST_UNKNOWN = -1;
const ii ST_UNKNOWN_TYPE = ii(ST_UNKNOWN, ST_UNKNOWN);
const int ST_UNKNOWN_SCOPE = ST_UNKNOWN;






// global variables
unsigned int nlines = 1;
unsigned int ncols	= 1;
unsigned int nscopes = ST_GLOBAL;
unsigned int mscope = ST_GLOBAL; // max scope
unsigned int tipoatual = 0;
unsigned int tiporetorno = ST_UNKNOWN;


// display errors
#include "errors.cpp"
SemanticError *semanticError = new SemanticError();
SyntaxError *syntaxError = new SyntaxError(); 


// symbol table definition and instance:
#include "SymbolTable.cpp"
SymbolTable *st = new SymbolTable();

Node *funcaoatual = NULL;
vector<Node> *codigo = new vector<Node>(); // todo o codigo



// helpers
#include "helpers.cpp"


%}


%union{
	int tint;
	char tchar;
	bool tbool;
	double tdouble;
	char* tstring;
	Node *tnode;
	vector<Node> *tvnode;
};

%define parse.error verbose

%token <tstring> ID
%token <tint> INTNUM 
%token <tdouble> FLOATNUM
%token <tchar> CARACTERE
%token <tbool> BOOLEANO


%token SEMICOLON COMMA
%token P_OPEN P_CLOSE B_OPEN B_CLOSE C_OPEN C_CLOSE
%token<tchar> PLUS MINUS MULT DIV POINTER
%token<tchar> OPE OPOU
%token ASSIGN LT GT LE GE EQ NEQ
%token INT FLOAT BOOL CHAR VOID TRUE FALSE
%token MAIN IF THEN ELSE WHILE PRINT RETURN


%left COMMA
%right ASSIGN
%left OPOU
%left OPE
%left EQ NEQ
%left LT GT LE GE
%left PLUS MINUS
%left MULT DIV
%left POINTER
%nonassoc P_OPEN P_CLOSE B_OPEN B_CLOSE
%nonassoc UMINUS


%type<tvnode> listaItens listaExp parametros
%type<tnode> item expAritmetica expLogica t2 t1 expressao
%type<tint> tipo


%%

programa		: 	declaracoes funcaoMain
				;


declaracoes		:	/* vazio */
				|	declaracoes declFuncao 
				|	declaracoes declrVariaveis 
				;


declrVariaveis	: tipo listaItens SEMICOLON { addListaVars($2); }
				;


declFuncao		:	tipo ID { addFunction($2, $1); } P_OPEN parametros { addParams($2, $5); } P_CLOSE C_OPEN corpoFuncao C_CLOSE SEMICOLON { closeFunction(); } 
				|	VOID ID { addFunction($2, ST_VOID); } P_OPEN parametros { addParams($2, $5); } P_CLOSE C_OPEN corpoFuncao C_CLOSE SEMICOLON { closeFunction(); } 
					/* regra adicionada para void */
				|	ID { syntaxError->missReturnType($1); } P_OPEN parametros P_CLOSE C_OPEN corpoFuncao P_CLOSE SEMICOLON {}
				;


funcaoMain		:	tipo MAIN { addFunction("main", $1); } P_OPEN P_CLOSE C_OPEN corpoFuncao C_CLOSE SEMICOLON { closeFunction(); }
				|	declFuncao { syntaxError->undefinedMain(); }
				;


listaItens		:	listaItens COMMA item	{ addItem($$, $3); }
				|	item	{ $$ = createItemVector($1); }
				|	item ASSIGN expressao { assignExpression($1, $3); $$ = createItemVector($1); } 
					/* regra adicionada para permitir atribuicoes na declaracao */
				;


item			:	ID { $$ = createItem($1, 1); } 
				|	ID B_OPEN INTNUM B_CLOSE { $$ = createItem($1, $3); }
				|	MULT item %prec POINTER { $$ = createItem($2->name, 0); }
				;


parametros		:	/* vazio */ { $$ = createItemVector(); }
				| 	tipo item 	{ $2->type.second = $1; $$ = createItemVector($2); }
				|	parametros COMMA tipo item { $4->type.second = $3; addItem($$, $4); }
				;


tipo			:	INT	{ $$ = ST_INT; tipoatual = ST_INT; }
				|	FLOAT { $$ = ST_FLOAT; tipoatual = ST_FLOAT; }
				|	BOOL { $$ = ST_BOOL; tipoatual = ST_BOOL; }
				|	CHAR { $$ = ST_CHAR; tipoatual = ST_CHAR; } 
					/* regra adicionada para permitir char */
				;


corpoFuncao		:	declaracoes comandos
				;


blocoComandos	:	C_OPEN comandos C_CLOSE
				|	C_OPEN comandos { syntaxError->missClose(); }
				;


comandos		:	/* vazio */
				|	comando SEMICOLON comandos
				;


comando 		:	atribuicao
				|	retorno
				|	seEntao
				|	impressao
				|	enquanto 
				;


atribuicao		:	ID ASSIGN expressao { assignExpression($1, $3); }
				|	ID B_OPEN INTNUM B_CLOSE ASSIGN expressao { assignExpression($1, $3, $6); }
				;


expressao		:	expAritmetica { $$ = $1; }
				|	expLogica { $$ = $1; }
				;


expAritmetica	:	expAritmetica PLUS expAritmetica { assignValue($$, $1, $3, "+"); }
				|	expAritmetica MINUS expAritmetica { assignValue($$, $1, $3, "-"); }
				|	expAritmetica MULT expAritmetica { assignValue($$, $1, $3, "*"); }
				|	expAritmetica DIV expAritmetica { assignValue($$, $1, $3, "/"); }
				|	t1 { $$ = $1; }
				;


t1 				:	P_OPEN expAritmetica P_CLOSE { $$ = $2; }
				|	ID { $$ = getItem($1, "variavel"); }
				|	ID P_OPEN listaExp P_CLOSE {$$ = getItem($1, "funcao"); verifyParameters($$, $3);}
				|	ID B_OPEN INTNUM B_CLOSE { $$ = getItem($1, $3, "variavel"); }
				|	ID B_OPEN FLOATNUM B_CLOSE { syntaxError->indexType("ponto flutuante"); }
				|	ID B_OPEN CARACTERE B_CLOSE { syntaxError->indexType("caractere"); }
				|	ID B_OPEN BOOLEANO B_CLOSE { syntaxError->indexType("booleano"); }
				|	MINUS INTNUM %prec UMINUS { $$ = createConstNode(ST_INT, -$2); }
				|	MINUS FLOATNUM %prec UMINUS { $$ = createConstNode(ST_FLOAT, -$2); }
				|	INTNUM { $$ = createConstNode(ST_INT, $1); }
				|	FLOATNUM { $$ = createConstNode(ST_FLOAT, $1); }
				|	CARACTERE { $$ = createConstNode(ST_CHAR, $1); }
				|	BOOLEANO { $$ = createConstNode(ST_BOOL, $1); }
				;

listaExp		:	expAritmetica { $$ = createItemVector($1); }
				|	listaExp COMMA expAritmetica{ addItem($$, $3); }
				;


expLogica		:	expLogica OPE expLogica { assignValue($$, $1, $3, "&"); }
				|	expLogica OPOU expLogica { assignValue($$, $1, $3, "|"); }
				|   expAritmetica LT expAritmetica { assignValue($$, $1, $3, "<"); }
				|   expAritmetica GT expAritmetica { assignValue($$, $1, $3, ">"); }
				|   expAritmetica LE expAritmetica { assignValue($$, $1, $3, "<="); }
				|   expAritmetica GE expAritmetica { assignValue($$, $1, $3, ">="); }
				|   expAritmetica EQ expAritmetica { assignValue($$, $1, $3, "=="); }
				|   expAritmetica NEQ expAritmetica { assignValue($$, $1, $3, "!="); }
				|	t2 OPE	t2 { assignValue($$, $1, $3, "&"); }
				|	t2 OPOU	t2 { assignValue($$, $1, $3, "|"); }
				;

t2				:	BOOLEANO { $$ = createConstNode(ST_BOOL, $1); }
				|	ID { $$ = getItem($1, "variavel"); }
				|	ID B_OPEN INTNUM B_CLOSE { $$ = getItem($1, $3, "variavel"); }
				;



seEntao			:	IF P_OPEN expLogica P_CLOSE THEN blocoComandos ELSE blocoComandos 
				|	IF P_OPEN t2 P_CLOSE THEN blocoComandos ELSE blocoComandos
				|	IF P_OPEN P_CLOSE THEN blocoComandos ELSE blocoComandos { syntaxError->missLogicExpression("if"); }
				;


enquanto 		:	WHILE P_OPEN expLogica P_CLOSE blocoComandos
				|	WHILE P_OPEN t2 P_CLOSE blocoComandos
				|	WHILE P_OPEN P_CLOSE blocoComandos { syntaxError->missLogicExpression("while"); }
				;


impressao		:	PRINT expAritmetica
				|	PRINT /* vazio */ { syntaxError->missAritmeticExpression("print"); }
				;


retorno			:	RETURN expAritmetica { verifyReturn(funcaoatual, $2); }
				|	RETURN /* vazio */ { syntaxError->missAritmeticExpression("return"); }
				;	

%%

#include "trab.lex.cpp"


void interpretarCodigo(vector<Node> *v){
	//todo
}



int main(){

	const string hr = "---------------------";

	cout << "TOKENS E LEXEMAS:" << endl << hr << endl;
	yyparse();

	
	cout << endl << endl;


	cout << "TABELA DE SIMBOLOS:" << endl << hr << endl; 
	st->print();


	Node *n = st->get("seila", ST_GLOBAL);
	if(n != NULL){
		cout << n->name << "[" << n->dim << "]" << endl;
		for(int i=0; i<n->dim; i++)
			cout << n->name << "[" << i << "] = " << n->getValue(i) << endl;
	}

	// executa o programa
	interpretarCodigo(codigo);

	// libera a memoria
	delete codigo;
}





void yyerror(const char *s){
	cout << endl << s << endl;
	exit(0);
}