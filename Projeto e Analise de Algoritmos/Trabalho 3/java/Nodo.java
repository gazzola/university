import java.util.*;

public class Nodo {

	public String chave;
	public int freq;
	public Nodo esq, dir;
	private Map<String, String> tabelaBinario = new HashMap<String, String>();

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

	public void percorreArvore(Nodo nodo, String direcao, String texto){
		if(nodo == null)
			return;

		texto += direcao;
		if(nodo.chave.length() == 1)
			this.tabelaBinario.put(nodo.chave, texto);


		percorreArvore(nodo.esq, "0", texto);
		percorreArvore(nodo.dir, "1", texto);
	}

	public Map<String, String> getTabelaBinario(){
		return this.tabelaBinario;
	}

}