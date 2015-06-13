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

		void unkownOperator(string x){
			cout << endl << "ERRO SINTATICO:";
			cout << " operador '" << x << "' nao conhecido!";
			cout << " linha: " << nlines << "." << endl;
			exit(0); 
		}

};