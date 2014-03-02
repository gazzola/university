public class Nodo {

	String chave;
	int freq;
	Nodo esq, dir;
	
	public Nodo(String chave, int freq){
		this.chave = chave;
		this.freq = freq;
		 this.esq = null;
		 this.dir = null;
	}
	
	public Nodo(String chave, int freq, Nodo esq, Nodo dir){
		this.chave = chave;
		this.freq = freq;
		this.esq = esq;
		this.dir = dir;
	}
	
	public String toString (){
		return chave + "-" + freq;
	}
	
	public void mostraNodo(Nodo nodo){
		if (nodo == null)
			return;
		
		mostraNodo(nodo.esq);
		System.out.printf("%s", nodo);
		mostraNodo(nodo.dir);
	}
}