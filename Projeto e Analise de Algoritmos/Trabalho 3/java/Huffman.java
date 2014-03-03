import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.BufferedReader;
import java.util.Formatter;
import java.util.*;

public class Huffman extends Dicionario{

	private String texto, textoBinario="";
	private Heap heap;

	public Huffman(){
		this.texto = this.abrirArquivo();
		this.insereDicionario(this.texto);
		this.criarHeap(50);
		this.unirNodos();
	}


	public void comprimir(){
		Map<String, String> tabelaBinario = new HashMap<String, String>();
		Nodo raiz = this.heap.getNodo(0);
		raiz.percorreArvore(raiz, "", "");
		tabelaBinario = raiz.getTabelaBinario();

		for(int i=0; i<this.texto.length(); i++)
			this.textoBinario += tabelaBinario.get(this.texto.charAt(i)+"");
	}


	public void salvarArquivo(String file){
		try{
			Formatter output = new Formatter(file);
			output.format("%s \n", this.textoBinario);
			if(output != null)
           		output.close();
		}
		catch(SecurityException ae){ 
			System.err.println("Sem permissão de acesso");
			System.exit(1);
		}
		catch (FileNotFoundException aen){ 
			System.err.println("Não foi possível criar o arquivo");
			System.exit(1);
		}
	}


	public void gerarEstatisticas(){
		int tamanhoTexto = this.texto.length()*8;
		int tamanhoTextoBinario = this.textoBinario.length();
		double taxaDeCompressao = 100-((double)(tamanhoTextoBinario*100)/tamanhoTexto);
		System.out.println("Tamanho do texto original em bits: "+tamanhoTexto);
		System.out.println("Tamanho do texto compactado em bits: "+tamanhoTextoBinario);
		System.out.printf("Taxa de compactacao: %.2f%%\n", taxaDeCompressao);
	}


	private String abrirArquivo(){
		String linha = "";
		try{
			BufferedReader entrada = new BufferedReader(new FileReader("entrada.txt"));
			while(entrada.ready())
				linha += entrada.readLine();
			entrada.close();
		}
		catch(IOException ioe){  
			ioe.printStackTrace();
		}

		return linha;
	}


	private void criarHeap(int capacidade){
		this.heap = new Heap(capacidade);
		for(Map.Entry<Character, Integer> entry : dic.entrySet()) {
		    Character carac = entry.getKey();
		    Integer freq = entry.getValue();
			this.heap.insereElemento(new Nodo(carac.toString(), freq));
		}
	}


	private void unirNodos(){
		while(this.heap.getTamanho() > 1){
			Nodo dir = this.heap.extraiMin();
			Nodo esq = this.heap.extraiMin();
			Nodo raiz = new Nodo(esq.chave+dir.chave, esq.freq+dir.freq, esq, dir);
			this.heap.insereElemento(raiz);
		}
	}

	
	public static void main (String[] args){
		Huffman huff = new Huffman();
		huff.comprimir();
		huff.salvarArquivo("saida.txt");
		huff.gerarEstatisticas();

	}
	
}