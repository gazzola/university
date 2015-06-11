del [ \n\t]
ws {del}+
letra [A-Za-z]
digito [0-9]

id {letra}(_{letra}|_{digito}|{letra}|{digito})*
numint {digito}+
numfloat {digito}+((\.|e|\.e)?{digito}+)?
caractere \'.\'

iderro1 {letra}(_{letra}|_{digito}|{letra}|{digito})*_
iderro2 {digito}(_{letra}|_{digito}|{letra}|{digito})*
nferro {digito}+((,|e|,e)?{digito}+)?




%%
<<EOF>>		{printf("\n"); yyterminate();}
"\t"		{printf("\t"); ncols+=4;}
"\n"		{printf("\n"); nlines++;}
" "			{printf(" "); ncols++;}
";"			{printf("<';', SEMICOLON>"); ncols+=1; return SEMICOLON;}
","			{printf("<',', COMMA>"); ncols+=1; return COMMA;}
"["			{printf("<'[', B_OPEN>"); ncols+=1; return B_OPEN;}
"]"			{printf("<']', B_CLOSE>"); ncols+=1; return B_CLOSE;}
"{"			{printf("<'{', C_OPEN>"); ncols+=1; return C_OPEN;}
"}"			{printf("<'}', C_CLOSE>"); ncols+=1; return C_CLOSE;}
"("			{printf("<'(', P_OPEN>"); ncols+=1; return P_OPEN;}
")"			{printf("<')', P_CLOSE>"); ncols+=1; return P_CLOSE;}
"+"			{printf("<'+', PLUS>"); ncols+=1; return PLUS;}
"-"			{printf("<'-', MINUS>"); ncols+=1; return MINUS;}
"*"			{printf("<'*', MULT>"); ncols+=1; return MULT;}
"/"			{printf("<'/', DIV>"); ncols+=1; return DIV;}
"&"			{printf("<'&', OPE>"); ncols+=1; return OPE;}
"|"			{printf("<'|', OPOU>"); ncols+=1; return OPOU;}
"="			{printf("<'=', ASSIGN>"); ncols+=1; return ASSIGN;}
"<"			{printf("<'<', LT>"); ncols+=1; return LT;}
">"			{printf("<'>', GT>"); ncols+=1; return GT;}
"<="		{printf("<'<=', LE>"); ncols+=2; return LE;}
">="		{printf("<'>=', GE>"); ncols+=2; return GE;}
"=="		{printf("<'==', EQ>"); ncols+=2; return EQ;}
"char"		{printf("<, CHAR>"); ncols+=4; return CHAR;}
"int"		{printf("<INT>"); ncols+=3; return INT;}
"float"		{printf("<FLOAT>"); ncols+=5; return FLOAT;}
"bool"		{printf("<BOOL>"); ncols+=4; return BOOL;}
"main"		{printf("<MAIN>"); ncols+=4; return MAIN;}
"if"		{printf("<IF>"); ncols+=2; return IF;}
"then"		{printf("<THEN>"); ncols+=4; return THEN;}
"else"		{printf("<ELSE>"); ncols+=4; return ELSE;}
"while"		{printf("<WHILE>"); ncols+=5; return WHILE;}
"print"		{printf("<PRINT>"); ncols+=5; return PRINT;}
"return"	{printf("<RETURN>"); ncols+=6; return RETURN;}
"true"		{printf("<true, BOOLEANO>"); ncols+=4; yylval.tbool = true; return BOOLEANO;}
"false"		{printf("<false, BOOLEANO>"); ncols+=5; yylval.tbool = false; return BOOLEANO;}
{caractere} {printf("<%s, CARACTERE>", yytext); ncols+=9; yylval.tchar = yytext[1]; return CARACTERE;}
{numint}	{printf("<%s, NUM_INT>", yytext); ncols+=strlen(yytext); yylval.tint = atoi(yytext); return INTNUM;}
{numfloat}	{printf("<%s, NUM_FLOAT>", yytext); ncols+=strlen(yytext);; yylval.tdouble = atof(yytext);return FLOATNUM;}
{id}		{printf("<%s, ID>", yytext); int tam=strlen(yytext); ncols+=tam; yylval.tstring = new char[tam]; strcpy(yylval.tstring, yytext); if(tam <= 32) return ID; 
			printf("\nERRO LEXICO(%u, %u): id nao pode ter mais que 32 caracteres: `%s`\n", nlines, ncols, yytext); yyterminate();}
{iderro1}	{printf("\nERRO LEXICO(%u, %u): id nao pode terminar com _: `%s`\n", nlines, ncols, yytext); yyterminate();}
{iderro2}	{printf("\nERRO LEXICO(%u, %u): id nao pode comecar com digito: `%s`\n", nlines, ncols, yytext); yyterminate();}
{nferro}	{printf("\nERRO LEXICO(%u, %u): ponto flutuante nao pode ser definido por virgula: `%s`\n", nlines, ncols, yytext); yyterminate();}
.			{printf("\nERRO LEXICO(%u, %u): token não aceito na linguagem: `%s`\n", nlines, ncols, yytext); yyterminate();}
%%


int yywrap(){}
