del [ \n\t]
ws {del}+
letra [A-Za-z]
digito [0-9]
id {letra}(_{letra}|_{digito}|{letra}|{digito})*
numint {digito}+(e{digito}+)?
numfloat {digito}+(\.|e|\.e)?{digito}*


%%
{ws}		{}
";"			{printf(";\n"); return SEMICOLON;}
","			{printf(",\n"); return COMMA;}
"["			{printf("[\n"); return B_OPEN;}
"]"			{printf("]\n"); return B_CLOSE;}
"{"			{printf("{\n"); return C_OPEN;}
"}"			{printf("}\n"); return C_CLOSE;}
"("			{printf("(\n"); return P_OPEN;}
")"			{printf(")\n"); return P_CLOSE;}
"+"			{printf("+\n"); return PLUS;}
"-"			{printf("-\n"); return MINUS;}
"*"			{printf("*\n"); return MULT;}
"/"			{printf("/\n"); return DIV;}
"&"			{printf("&\n"); return OPE;}
"|"			{printf("|\n"); return OPOU;}
"="			{printf("=\n"); return ASSIGN;}
"<"			{printf("<\n"); return LT;}
">"			{printf(">\n"); return GT;}
"<="		{printf("<=\n"); return LE;}
">="		{printf(">=\n"); return GE;}
"=="		{printf("==\n"); return EQ;}
"int"		{printf("int\n"); return INT;}
"float"		{printf("float\n"); return FLOAT;}
"bool"		{printf("bool\n"); return BOOL;}
"main"		{printf("main\n"); return MAIN;}
"if"		{printf("if\n"); return IF;}
"then"		{printf("then\n"); return THEN;}
"else"		{printf("else\n"); return ELSE;}
"while"		{printf("while\n"); return WHILE;}
"print"		{printf("print\n"); return PRINT;}
"return"	{printf("return\n"); return RETURN;}
{numint}	{printf("NUM_INT\n"); yylval.tint = atoi(yytext); return INTNUM;}
{numfloat}	{printf("NUM_FLOAT\n"); yylval.tdouble = atof(yytext);return FLOATNUM;}
{id}		{printf("ID\n"); yylval.tstring = yytext; return ID;}
.			{printf("erro lexico : %s\n", yytext);}
%%


int yywrap(){}
