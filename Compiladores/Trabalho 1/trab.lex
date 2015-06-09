%{
unsigned int nlines = 1;
unsigned int ncols	= 1;
%}



del [ \n\t]
ws {del}+
letra [A-Za-z]
digito [0-9]

id {letra}(_{letra}|_{digito}|{letra}|{digito})*
numint {digito}+
numfloat {digito}+((\.|e|\.e)?{digito}+)?


iderro1 {letra}(_{letra}|_{digito}|{letra}|{digito})*_
iderro2 {digito}(_{letra}|_{digito}|{letra}|{digito})*
nferro {digito}+((,|e|,e)?{digito}+)?




%%
<<EOF>>		{printf("\n"); yyterminate();}
"\t"		{printf("\t"); ncols+=4;}
"\n"		{printf("\n"); nlines++;}
" "			{printf(" "); ncols++;}
";"			{printf(";"); ncols+=1; return SEMICOLON;}
","			{printf(","); ncols+=1; return COMMA;}
"["			{printf("["); ncols+=1; return B_OPEN;}
"]"			{printf("]"); ncols+=1; return B_CLOSE;}
"{"			{printf("{"); ncols+=1; return C_OPEN;}
"}"			{printf("}"); ncols+=1; return C_CLOSE;}
"("			{printf("("); ncols+=1; return P_OPEN;}
")"			{printf(")"); ncols+=1; return P_CLOSE;}
"+"			{printf("+"); ncols+=1; return PLUS;}
"-"			{printf("-"); ncols+=1; return MINUS;}
"*"			{printf("*"); ncols+=1; return MULT;}
"/"			{printf("/"); ncols+=1; return DIV;}
"&"			{printf("&"); ncols+=1; return OPE;}
"|"			{printf("|"); ncols+=1; return OPOU;}
"="			{printf("="); ncols+=1; return ASSIGN;}
"<"			{printf("<"); ncols+=1; return LT;}
">"			{printf(">"); ncols+=1; return GT;}
"<="		{printf("<="); ncols+=2; return LE;}
">="		{printf(">="); ncols+=2; return GE;}
"=="		{printf("=="); ncols+=2; return EQ;}
"int"		{printf("INT"); ncols+=3; return INT;}
"float"		{printf("FLOAT"); ncols+=5; return FLOAT;}
"bool"		{printf("BOOL"); ncols+=4; return BOOL;}
"main"		{printf("MAIN"); ncols+=4; return MAIN;}
"if"		{printf("IF"); ncols+=2; return IF;}
"then"		{printf("THEN"); ncols+=4; return THEN;}
"else"		{printf("ELSE"); ncols+=4; return ELSE;}
"while"		{printf("WHILE"); ncols+=5; return WHILE;}
"print"		{printf("PRINT"); ncols+=5; return PRINT;}
"return"	{printf("RETURN"); ncols+=6; return RETURN;}
{numint}	{printf("NUM_INT"); ncols+=strlen(yytext); yylval.tint = atoi(yytext); return INTNUM;}
{numfloat}	{printf("NUM_FLOAT"); ncols+=strlen(yytext);; yylval.tdouble = atof(yytext);return FLOATNUM;}
{id}		{printf("ID"); ncols+=strlen(yytext);; yylval.tstring = yytext; if(strlen(yytext) <= 32) return ID; 
			printf("\nERRO LEXICO(%u, %u): id nao pode ter mais que 32 caracteres: `%s`\n", nlines, ncols, yytext); yyterminate();}
{iderro1}	{printf("\nERRO LEXICO(%u, %u): id nao pode terminar com _: `%s`\n", nlines, ncols, yytext); yyterminate();}
{iderro2}	{printf("\nERRO LEXICO(%u, %u): id nao pode comecar com digito: `%s`\n", nlines, ncols, yytext); yyterminate();}
{nferro}	{printf("\nERRO LEXICO(%u, %u): ponto flutuante nao pode ser definido por virgula: `%s`\n", nlines, ncols, yytext); yyterminate();}
.			{printf("\nERRO LEXICO(%u, %u): token não aceito na linguagem: `%s`\n", nlines, ncols, yytext); yyterminate();}
%%


int yywrap(){}
