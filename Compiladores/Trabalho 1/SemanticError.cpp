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


