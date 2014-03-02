import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Formatter;

public class Principal {

	public void Principal(){
		
	}
	
	
	public void openFile(){
		
		try{
			Formatter output = new Formatter("Huffman.txt");
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
	
	public static void main (String[] args){
		
		/*Heap h1 = new Heap(50);
		
		Nodo n9 = new Nodo(" ", 8);
		Nodo n8 = new Nodo(" ", 15);
		Nodo n7 = new Nodo(" ", 12);
		Nodo n6 = new Nodo(" ", 6);
		Nodo n5 = new Nodo(" ", 13);
		Nodo n4 = new Nodo(" ", 8, n8, n9);
		Nodo n3 = new Nodo(" ", 5, n6, n7);
		Nodo n2 = new Nodo(" ", 7, n4, n5);
		Nodo n1 = new Nodo(" ", 3, n2, n3);
		
		h1.insereElemento(n1);
		h1.insereElemento(n2);
		h1.insereElemento(n3);
		h1.insereElemento(n4);
		h1.insereElemento(n5);
		h1.insereElemento(n6);
		h1.insereElemento(n7);
		h1.insereElemento(n8);
		h1.insereElemento(n9);
		
		h1.mostraHeap();


		Nodo menor = h1.extraiMin();
		System.out.printf("\n\n%s\n\n", menor);


		h1.mostraHeap();*/
	}
	
}