class SemanticError{

	public:
		SemanticError(){};
		virtual ~SemanticError(){};

		void redeclaration(string of, string x){
			cout << endl << "ERRO SEMANTICO: " << of;
			cout << " '" << x << "'" << " ja foi declarada!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}


		void undeclaration(string of, string x){
			cout << endl << "ERRO SEMANTICO: " << of;
			cout << " '" << x << "'" << " nao foi declarada!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

		void incompatible(string of, string x, string y){
			cout << endl << "ERRO SEMANTICO: " << of << " imcompativeis";
			cout << " das vars '" << x << "' e '" << y << "'!";
			cout << " linha: " << nlines << "." << endl;
			exit(0);
		}

		void arrayBound(string x){
			cout << endl << "ERRO SEMANTICO: valor do indice da var";
			cout << " '" << x << "' fora dos limites do array!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

		void unexpectedReturnType(string x){
			cout << endl << "ERRO SEMANTICO: " << "tipos imcompativeis";
			cout << " entre funcao '" << x << "' e seu retorno!";
			cout << " linha: " << nlines << "." << endl;
			exit(0);
		}

		void unexpectedReturnDimension(string x){
			cout << endl << "ERRO SEMANTICO: " << "dimensoes imcompativeis";
			cout << " entre funcao '" << x << "' e seu retorno!";
			cout << " linha: " << nlines << "." << endl;
			exit(0);
		}

		void incompatibleParameters(string of, string f, string g){
			cout << endl << "ERRO SEMANTICO: " << of << " de parametros da funcao " << f;
			cout << " e sua chamada " << g << " sao diferentes!";
			cout << " linha: " << nlines << "." << endl;
			exit(0);
		}

};


class SyntaxError{

	public:
		SyntaxError(){};
		virtual ~SyntaxError(){};

		void missReturnType(string x){
			cout << endl << "ERRO SINTATICO: a funcao";
			cout << " '" << x << "' deve ter um tipo de retorno!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

		void missReturnExpression(string x){
			cout << endl << "ERRO SINTATICO: a funcao";
			cout << " '" << x << "' deve ter um retorno!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

		void missClose(){
			cout << endl << "ERRO SINTATICO:";
			cout << " um bloco de ver fechado por '}'!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

		void indexType(string x){
			cout << endl << "ERRO SINTATICO: nao pode haver um";
			cout << " '" << x << "' como indice de um array!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

		void missLogicExpression(string x){
			cout << endl << "ERRO SINTATICO: nao ha uma expressao logica na condicao do";
			cout << " '" << x << "'!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

		void missAritmeticExpression(string x){
			cout << endl << "ERRO SINTATICO: nao ha uma expressao aritmetica no";
			cout << " '" << x << "'!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

		void undefinedMain(){
			cout << endl << "ERRO SINTATICO:";
			cout << " nao ha uma declaracao da funcao main!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

		void multiplesMain(){
			cout << endl << "ERRO SINTATICO:";
			cout << " ha mais de uma declaracao da funcao main!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

};