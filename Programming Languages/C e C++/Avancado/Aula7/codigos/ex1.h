namespace ex1{
	
	template <class T>
	class Vetor{

		private:
			int currentIndex, size; //currentIndex = currentSize
			T *array;

		public:
			
			Vetor(int size){
				this->size = size;
				this->currentIndex = 0;
				this->array = new T[size];
			}


			void inserir(const T &elemento);
			int getIndice(const T &elemento); //procurarIndice
			bool contem(const T &elemento);
			void remover(const T &elemento);
			int getTamanho();
			void mostrar();
			void ordenar(bool (*func)(int, int));


			virtual ~Vetor(){
				delete this->array;
			}

			T &operator [] (int indice);

	};


	template <class T>
	T &Vetor<T>::operator[](int indice){
		return this->array[indice];
	}


	template <class T>
	void Vetor<T>::inserir(const T &elemento){
		if(this->currentIndex < this->size){
			this->array[this->currentIndex] = elemento;
			this->currentIndex++;
		}
		else{
			throw "Eita porra! o bagulio ta cheio o.O";
		}
	}


	template <class T>
	int Vetor<T>::getIndice(const T &elemento){
		for(int i=0; i<=this->currentIndex; i++){
			if(this->array[i] == elemento)
				return i;
		}

		return -1;
	}


	template <class T>
	bool Vetor<T>::contem(const T &elemento){
		for(int i=0; i<=this->currentIndex; i++){
			if(this->array[i] == elemento)
				return true;
		}

		return false;
	}


	template <class T>
	void Vetor<T>::remover(const T &elemento){

		int pos = this->getIndice(elemento);
		if(pos >= 0){
			for(int i=pos; i<this->currentIndex; i++)
				this->array[i] = this->array[i+1];
			this->currentIndex--;
		}
		else
			throw "Eita porra! o bagulio n existe  o.O";
	}

	
	template <class T>
	void Vetor<T>::mostrar(){
		for(int i=0; i<this->currentIndex; i++)
			std::cout << this->array[i] << " ";
		std::cout << std::endl;
	}



	template <class T>
	void Vetor<T>::ordenar(bool (*func)(int, int)){
		std::sort(this->array, this->array+this->currentIndex, func);
	}


	template <class T>
	int Vetor<T>::getTamanho(){
		return this->currentIndex;
	}

}