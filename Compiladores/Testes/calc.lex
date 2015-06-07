%option yylineno

del [ \t]
ws {del}+
letra [A-Za-z]
digito [0-9]
id {letra}(_{letra}|_{digito}|{letra}|{digito})*
numint {digito}+(e{digito}+)?
numfloat {digito}*(\.|e|\.e)?{digito}*


%%
{ws}		{}
";"			{return SEMICOLON;}
","			{return COMMA;}
"["			{return B_OPEN;}
"]"			{return B_CLOSE;}
"{"			{return C_OPEN;}
"}"			{return C_CLOSE;}
"("			{printf("achou (\n");return P_OPEN;}
")"			{return P_CLOSE;}
"+"			{return PLUS;}
"-"			{return MINUS;}
"*"			{return MULT;}
"/"			{return DIV;}
"&"			{return OPE;}
"|"			{return OPOU;}
"="			{return ASSIGN;}
"<"			{return LT;}
">"			{return GT;}
"<="		{return LE;}
">="		{return GE;}
"=="		{return EQ;}
"int"		{return INT;}
"float"		{return FLOAT;}
"bool"		{return BOOL;}
"main"		{return MAIN;}
"if"		{return IF;}
"then"		{return THEN;}
"else"		{return ELSE;}
"while"		{return WHILE;}
"print"		{return PRINT;}
"return"	{return RETURN;}
"\n"		{return NL;}
{numint}	{yylval.tint = atoi(yytext); return INTNUM;}
{numfloat}	{yylval.tdouble = atof(yytext);return FLOATNUM;}
{id}		{yylval.tstring = yytext; return ID;}
.			{printf("erro lexico : %s\n", yytext);}
%%


int yywrap(){}
