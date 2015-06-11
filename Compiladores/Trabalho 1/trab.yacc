%{

#include <cctype>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>

using namespace std;

// declarations that yacc needs to know:
extern int yylex();
extern int yyparse();
extern FILE *yyin;
void yyerror(const char *s);


// symbol table definition and instance:
#include "SymbolTable.cpp"

// helpers
#include "helpers.cpp"





SymbolTable *st = new SymbolTable();

unsigned int nlines = 1;
unsigned int ncols	= 1;
unsigned int nscopes = ST_GLOBAL;
unsigned int mscope = ST_GLOBAL; // max scope
unsigned int tipoatual = 0;
Node *funcaoatual = NULL;
vector<Node> *codigo = new vector<Node>(); // todo o codigo

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
%token ASSIGN LT GT LE GE EQ
%token INT FLOAT BOOL CHAR TRUE FALSE
%token MAIN IF THEN ELSE WHILE PRINT RETURN


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

%type<tvnode> declaracoes declFuncao declrVariaveis funcaoMain
%type<tvnode> listaItens parametros comandos comando blocoComandos 
%type<tvnode> atribuicao seEntao enquanto impressao retorno corpoFuncao
%type<tnode> item expAritmetica expLogica t2 t1 expressao 
%type<tint> tipo


%%

programa		: 	declaracoes funcaoMain {appendVector($1, $2); appendVector(codigo, $1);}
				;


declaracoes		:	/* vazio */ {$$ = new vector<Node>();}
				|	declaracoes declFuncao {appendVector($$, $2);}
				|	declaracoes declrVariaveis {appendVector($$, $2);}
				;


declrVariaveis	: tipo listaItens SEMICOLON {	for(int i=0; i<(int) $2->size(); i++){
													$2->at(i).scope = nscopes;
													if(!st->add(&($2->at(i)))){
														printf("\nERRO SEMANTICO: variavel `%s` ja foi declarada na linha %d!\n", $2->at(i).name.c_str(), $2->at(i).line);
														exit(0);
													}
												}
												delete $2;

												$$ = new vector<Node>();
												appendVector($$, $2);
											}
				;


declFuncao		:	tipo ID {if(!st->add(new Node($2, 1, ii(ST_FUNC, $1), ST_GLOBAL, nlines))){
								printf("\nERRO SEMANTICO: funcao `%s` ja foi declarada na linha %d!\n", $2, st->get($2, ST_GLOBAL)->line); 
								exit(0);
							}
							funcaoatual = st->get($2, ST_GLOBAL);} 
					P_OPEN {mscope++; nscopes=mscope;} 
					parametros {	
									Node *fun = st->get($2, ST_GLOBAL);
									for(int i=0; i<(int) $6->size(); i++){
										$6->at(i).scope = nscopes;
										if(!st->add(&($6->at(i)))){
											printf("\nERRO SEMANTICO: parametro `%s` ja foi declarado na linha %d!\n", $6->at(i).name.c_str(), $6->at(i).line);
											exit(0);
										}
										else
											fun->addParam(&($6->at(i)));
									}
									delete $6;
								}
					P_CLOSE C_OPEN corpoFuncao C_CLOSE SEMICOLON {
						nscopes = ST_GLOBAL; 
						funcaoatual = NULL;
						$$ = new vector<Node>(); $$->push_back(*st->get($2, ST_GLOBAL)); appendVector($$, $10);
					} 
				|	ID {printf("\nERRO SINTATICO: a funcao `%s` deve ter um tipo de retorno! linha:%d\n", $1, nlines);  exit(0);} P_OPEN parametros P_CLOSE C_OPEN corpoFuncao P_CLOSE SEMICOLON {}
				;


funcaoMain		:	tipo MAIN {if(!st->add(new Node("main", 1, ii(ST_FUNC, $1), ST_GLOBAL, nlines))){
								printf("\nERRO SEMANTICO: funcao `main` ja foi declarada na linha %d!\n", st->get("main", ST_GLOBAL)->line); 
								exit(0);
							}

					funcaoatual = st->get("main", ST_GLOBAL);} 
					P_OPEN {mscope++; nscopes = mscope;} P_CLOSE C_OPEN corpoFuncao C_CLOSE SEMICOLON {
						nscopes = ST_GLOBAL; 
						funcaoatual = NULL;
						$$ = new vector<Node>(); $$->push_back(*st->get("main", ST_GLOBAL)); appendVector($$, $8);
					}
				;


listaItens		:	listaItens COMMA item	{$$->push_back(*$3);}
				|	item	{$$ = new vector<Node>(); $$->push_back(*$1);}
				|	item ASSIGN expressao { $$ = new vector<Node>(); 
												// if is a pointer
												while($1->dim == 0)
													$1 = st->get($1->name, $1->scope);

												if($1->type.second == $3->type.second)
													if($1->dim == $3->dim)
														$1->setValue($3->getValue());
													else{ printf("\nERRO SEMANTICO: dimensoes incompativeis das vars `%s` e `%s`! na linha %d\n", $1->name.c_str(), $3->name.c_str(), nlines); exit(0); }
												else{ printf("\nERRO SEMANTICO: tipos incompativeis das vars `%s` e `%s`! na linha %d\n", $1->name.c_str(), $3->name.c_str(), nlines); exit(0); }
												$$->push_back(*$1); 
											} 
					/* regra adicionada para permitir atribuicoes na declaracao */
				;


item			:	ID {$$ = new Node($1, 1, ii(ST_VAR, tipoatual), UNKNOWN_SCOPE, nlines);} 
				|	ID B_OPEN INTNUM B_CLOSE {$$ = new Node($1, $3, ii(ST_VAR, tipoatual), UNKNOWN_SCOPE, nlines);}
				|	MULT item %prec POINTER {$$ = new Node($2->name, 0, ii(ST_VAR, tipoatual), UNKNOWN_SCOPE, nlines);}
				;


parametros		:	/* vazio */ {$$ = new vector<Node>();}
				| 	tipo item 	{$$ = new vector<Node>(); $2->type = ii(ST_VAR, $1); $$->push_back(*$2);}
				|	parametros COMMA tipo item {$4->type = ii(ST_VAR, $3); $$->push_back(*$4);}
				;


tipo			:	INT	{$$ = ST_INT; tipoatual = ST_INT;}
				|	FLOAT {$$ = ST_FLOAT; tipoatual = ST_FLOAT;}
				|	BOOL {$$ = ST_BOOL; tipoatual = ST_BOOL;}
				|	CHAR {$$ = ST_CHAR; tipoatual = ST_CHAR;} /* regra adicionada para permitir char */
				;


corpoFuncao		:	declaracoes comandos {$$ = new vector<Node>(); appendVector($1, $2); appendVector($$, $1);}
				;


blocoComandos	:	C_OPEN comandos C_CLOSE {$$ = new vector<Node>(); appendVector($$, $2);}
				|	C_OPEN comandos {printf("\nERRO SINTATICO: um bloco deve ser fechado por '}! linha:%d\n", nlines);  exit(0);}
				;


comandos		:	/* vazio */ {$$ = new vector<Node>();}
				|	comando SEMICOLON comandos {appendVector($1, $3); $$ = $1;}
				;


comando 		:	atribuicao {$$ = $1;}
				|	retorno {$$ = $1;}
				|	seEntao {$$ = $1;}
				|	impressao {$$ = $1;}
				|	enquanto {$$ = $1;}
				;


atribuicao		:	ID ASSIGN expressao {Node *n = (st->get($1, nscopes) != NULL) ? st->get($1, nscopes) : st->get($1, ST_GLOBAL);
											if(n != NULL){

												// if is a pointer
												while($3->dim == 0)
													$3 = st->get($3->name, $3->scope);

												if($3->type.second == n->type.second){
													if($3->dim == n->dim)
														n->setValue($3->getValue());
													else{ printf("\nERRO SEMANTICO: dimensoes incompativeis das vars `%s` e `%s`! na linha %d\n", n->name.c_str(), $3->name.c_str(), nlines); exit(0);}
												}
												else{ printf("\nERRO SEMANTICO: tipos incompativeis das vars `%s` e `%s`! na linha %d\n", n->name.c_str(), $3->name.c_str(), nlines); exit(0);}
											} 
											else{ printf("\nERRO SEMANTICO: variavel `%s` nao foi declarada! linha:%d\n", $1, nlines); exit(0);}

											$$ = new vector<Node>();
											$$->push_back(*n);
										}
				|	ID B_OPEN INTNUM B_CLOSE ASSIGN expressao {Node *n = (st->get($1, nscopes) != NULL) ? st->get($1, nscopes) : st->get($1, ST_GLOBAL);
															if(n != NULL){
																if($6->type.second == n->type.second){
																	if(n->dim == 1)
																		n->setValue($6->getValue());
																	else { printf("\nERRO SEMANTICO: dimensoes incompativeis das vars `%s` e `%s`! na linha %d\n", n->name.c_str(), $6->name.c_str(), nlines); exit(0);}
																}
																else {printf("\nERRO SEMANTICO: tipos incompativeis das vars `%s` e `%s`! na linha %d\n", n->name.c_str(), $6->name.c_str(), nlines); exit(0);}
															} 
															else {printf("\nERRO SEMANTICO: variavel `%s` nao foi declarada! linha:%d\n", $1, nlines); exit(0);}
															}
				;


expressao		:	expAritmetica {$$ = $1;}
				|	expLogica {$$ = $1;}
				;


expAritmetica	:	expAritmetica PLUS expAritmetica { assignValue($$, $1, $3, "+", nlines);  }
				|	expAritmetica MINUS expAritmetica { assignValue($$, $1, $3, "-", nlines); }
				|	expAritmetica MULT expAritmetica { assignValue($$, $1, $3, "*", nlines); }
				|	expAritmetica DIV expAritmetica { assignValue($$, $1, $3, "/", nlines); }
				|	t1 {$$ = $1;}
				;


t1 				:	P_OPEN expAritmetica P_CLOSE {$$ = $2;}
				|	ID {Node *n = (st->get($1, nscopes) != NULL) ? st->get($1, nscopes) : st->get($1, ST_GLOBAL);
						if(n != NULL) $$ = n; 
						else{ printf("\nERRO SEMANTICO: variavel `%s` nao foi declarada! linha:%d\n", $1, nlines); exit(0);}
						}
				|	ID P_OPEN listaExp P_CLOSE {if(st->get($1, ST_GLOBAL) != NULL) $$ = st->get($1, ST_GLOBAL); else{ printf("\nERRO SEMANTICO: funcao `%s` nao foi declarada! linha:%d\n", $1, nlines); exit(0); }}
				|	ID B_OPEN INTNUM B_CLOSE {	Node *n = (st->get($1, nscopes) != NULL) ? st->get($1, nscopes) : st->get($1, ST_GLOBAL);
												if(n != NULL) 
													if(n->dim > $3){
														$$ = new Node(n->name, 1, n->type, n->scope, n->line);
														$$->setValue(n->getValue());
													}
													else{ printf("\nERRO SEMANTICO: valor do indice da var `%s` maior que o array! linha:%d\n", $1, nlines); exit(0);}
												else{ printf("\nERRO SEMANTICO: variavel `%s` nao foi declarada! linha:%d\n", $1, nlines); $1, exit(0);}
											}
				|	ID B_OPEN FLOATNUM B_CLOSE {printf("\nERRO SINTATICO: nao pode haver um ponto flutuante como indice de uma array! linha:%d\n", nlines); exit(0);}
				|	ID B_OPEN CARACTERE B_CLOSE {printf("\nERRO SINTATICO: nao pode haver um caractere como indice de uma array! linha:%d\n", nlines); exit(0);}
				|	ID B_OPEN BOOLEANO B_CLOSE {printf("\nERRO SINTATICO: nao pode haver um booleano como indice de uma array! linha:%d\n", nlines); exit(0);}
				|	INTNUM {$$ = new Node(1, ii(ST_CONST, ST_INT)); $$->setValue($1);}
				|	FLOATNUM {$$ = new Node(1, ii(ST_CONST, ST_FLOAT)); $$->setValue($1);}
				|	CARACTERE {$$ = new Node(1, ii(ST_CONST, ST_CHAR)); $$->setValue($1);}
				|	BOOLEANO {$$ = new Node(1, ii(ST_CONST, ST_BOOL)); $$->setValue($1);}
				;

listaExp		:	ID {if(st->get($1, nscopes) == NULL) printf("\nERRO SEMANTICO: variavel `%s` nao foi declarada! linha:%d\n", $1, nlines);}
				|	ID COMMA listaExp {if(st->get($1, nscopes) == NULL) printf("\nERRO SEMANTICO: variavel `%s` nao foi declarada! linha:%d\n", $1, nlines);}
				;


expLogica		:	expLogica OPE expLogica { assignValue($$, $1, $3, "&", nlines); }
				|	expLogica OPOU expLogica { assignValue($$, $1, $3, "|", nlines); }
				|   expAritmetica LT expAritmetica { assignValue($$, $1, $3, "<", nlines); }
				|   expAritmetica GT expAritmetica { assignValue($$, $1, $3, ">", nlines); }
				|   expAritmetica LE expAritmetica { assignValue($$, $1, $3, "<=", nlines); }
				|   expAritmetica GE expAritmetica { assignValue($$, $1, $3, ">=", nlines); }
				|   expAritmetica EQ expAritmetica { assignValue($$, $1, $3, "==", nlines); }
				|	t2 OPE	t2 { assignValue($$, $1, $3, "&", nlines); }
				|	t2 OPOU	t2 { assignValue($$, $1, $3, "|", nlines); }
				;

t2				:	BOOLEANO {$$ = new Node(1, ii(ST_CONST, ST_BOOL)); $$->setValue($1);}
				|	ID {if(st->get($1, nscopes) != NULL) $$ = st->get($1, nscopes); else printf("\nERRO SEMANTICO: variavel `%s` nao foi declarada! linha:%d\n", $1, nlines);}
				|	ID B_OPEN INTNUM B_CLOSE {	Node *n = (st->get($1, nscopes) != NULL) ? st->get($1, nscopes) : st->get($1, ST_GLOBAL);
												if(n != NULL) 
													if(n->dim > $3) $$ = n;
													else{ printf("\nERRO SEMANTICO: valor do indice da var `%s` maior que o array! linha:%d\n", $1, nlines); exit(0);}
												else{ printf("\nERRO SEMANTICO: variavel `%s` nao foi declarada! linha:%d\n", $1, nlines); exit(0);}
											}
				;



seEntao			:	IF P_OPEN expLogica P_CLOSE THEN blocoComandos ELSE blocoComandos {$$ = new vector<Node>(); 
																					  Node *n = new Node("if", -1, ii(ST_CMD, ST_UNKNOWN), nscopes, nlines);
																					  $$->push_back(*n);
																					  $$->push_back(*$3);
																					  appendVector($$, $6);
																					  appendVector($$, $8);
																					}
				|	IF P_OPEN t2 P_CLOSE THEN blocoComandos ELSE blocoComandos {$$ = new vector<Node>(); 
																				  Node *n = new Node("if", -1, ii(ST_CMD, ST_UNKNOWN), nscopes, nlines);
																				  $$->push_back(*n);
																				  $$->push_back(*$3);
																				  appendVector($$, $6);
																				  appendVector($$, $8);
																				}
				|	IF P_OPEN P_CLOSE THEN blocoComandos ELSE blocoComandos {printf("\nERRO SINTATICO: nao ha uma expressao logica na condicao do if! linha:%d\n", nlines); exit(0);}
				;


enquanto 		:	WHILE P_OPEN expLogica P_CLOSE blocoComandos {$$ = new vector<Node>();
																  Node *n = new Node("while", -1, ii(ST_CMD, ST_UNKNOWN), nscopes, nlines);
																  $$->push_back(*n);
																  $$->push_back(*$3);
																  appendVector($$, $5);
																}
				|	WHILE P_OPEN t2 P_CLOSE blocoComandos {$$ = new vector<Node>(); 
															  Node *n = new Node("while", -1, ii(ST_CMD, ST_UNKNOWN), nscopes, nlines);
															  $$->push_back(*n);
															  $$->push_back(*$3);
															  appendVector($$, $5);
															}
				|	WHILE P_OPEN P_CLOSE blocoComandos {printf("\nERRO SINTATICO: nao ha uma expressao logica na condicao do while! linha:%d\n", nlines); exit(0);}
				;


impressao		:	PRINT expAritmetica {$$ = new vector<Node>(); 
										  Node *n = new Node("print", -1, ii(ST_CMD, ST_UNKNOWN), nscopes, nlines);
										  $$->push_back(*n);
										  $$->push_back(*$2);
										}
				;


retorno			:	RETURN expAritmetica {	$$ = new vector<Node>(); 
											Node *n = new Node("return", -1, ii(ST_CMD, ST_UNKNOWN), nscopes, nlines);
										    $$->push_back(*n);
										 	$$->push_back(*$2);
											if(funcaoatual->type.second != $2->type.second) 
												printf("\nERRO SEMANTICO: tipos incompativeis entre declaracao e retorno da funcao `%s`\n", funcaoatual->name.c_str());
										}
				;	

%%

#include "trab.lex.cpp"


void interpretarCodigo(vector<Node> *v){
	//todo
}



int main(){

	string hr = "---------------------";

	cout << "TOKENS E LEXEMAS:" << endl << hr << endl;
	yyparse();

	
	cout << endl << endl;


	cout << "TABELA DE SIMBOLOS:" << endl << hr << endl; 
	st->print();


	// Node *n = st->get("seila", ST_GLOBAL);
	// if(n != NULL)
	// 	cout << n->name << "[" << n->dim << "]" << endl;



	// executa o programa
	interpretarCodigo(codigo);

	// libera a memoria
	delete codigo;
}





void yyerror(const char *s){
	cout << endl << s << endl;
	exit(0);
}