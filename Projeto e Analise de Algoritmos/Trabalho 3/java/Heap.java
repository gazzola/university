import java.util.Vector;
import java.lang.*;


public class Heap {

	private Vector<Nodo> vetor = new Vector<Nodo>();
	private int capacidade = 0;
	private Nodo inf = new Nodo("", 999999);
	private Nodo min = new Nodo("", -1);

	public Heap(int capacidade){
		this.capacidade = capacidade;
	}
	
	private boolean existeNodo(int pos){
		return (pos < this.vetor.size());
	}

	private Nodo getPai(int pos){
		if(this.existeNodo((pos-1)/2))
			return (Nodo) this.vetor.elementAt((pos-1)/2);
		return this.inf;
	}
	
	private Nodo getFilhoEsq(int pos){
		if(this.existeNodo((pos)*2 + 1))
			return (Nodo) this.vetor.elementAt((pos)*2 + 1);
		return this.inf;
	}
	
	private Nodo getFilhoDir(int pos){
		if(this.existeNodo((pos)*2 + 2))
			return (Nodo) this.vetor.elementAt((pos)*2 + 2);
		return this.inf;
	}
	
	private Nodo getElemento(int pos){
		if(this.existeNodo(pos))
			return (Nodo) this.vetor.elementAt((pos));
		return this.min;
	}
	
	private void moveAcima(int pos){
		while(getPai(pos).freq > getElemento(pos).freq && pos > 0 ){
			Nodo temp = getElemento(pos);
			this.vetor.set(pos, getPai(pos));			
			this.vetor.set((pos-1)/2, temp);
			pos = (pos-1)/2;
		}
	}
	
	private void moveAbaixo(int pos){
		while(getElemento(pos).freq > getFilhoEsq(pos).freq || getElemento(pos).freq > getFilhoDir(pos).freq){
			
			Nodo temp = getElemento(pos);
			
			int minpos;
			if(getFilhoEsq(pos).freq < getFilhoDir(pos).freq)
				minpos = pos*2 + 1;
			else
				minpos = pos*2 + 2;
			
			if(minpos > (this.vetor.size()-1))
				break;
						
			this.vetor.set(pos, getElemento(minpos));			
			this.vetor.set(minpos, temp);
			pos = minpos;

			if(!existeFilhos(pos))
				break;
		}
	}

	/*private void moveAbaixo(int pos){
		if(this.existeFilhos(pos)){
			while(getElemento(pos).freq > getFilhoEsq(pos).freq || getElemento(pos).freq > getFilhoDir(pos).freq){
				
				Nodo temp = getElemento(pos);
				
				int minpos;
				if(getFilhoEsq(pos).freq < getFilhoDir(pos).freq)
					minpos = pos*2 + 1;
				else
					minpos = pos*2 + 2;
				
				if(minpos > (this.vetor.size()-1))
					break;
							
				this.vetor.set(pos, getElemento(minpos));			
				this.vetor.set(minpos, temp);
				pos = minpos;

				if(!existeFilhos(pos))
					break;
			}
		}
	}*/

	private boolean existeFilhos(int pos){
		return ((pos*2 + 1) <=  (this.vetor.size()-1) && (pos*2 + 2) <= (this.vetor.size()-1));
	}

	public Nodo extraiMin(){
		Nodo temp = (Nodo) this.vetor.elementAt(0);
		int pos = this.vetor.size()-1;
		this.vetor.set(0, this.getElemento(pos));
		this.vetor.remove(pos);
		this.moveAbaixo(0);
		return temp;
	}

	public void insereElemento(Nodo nodo){
		this.vetor.add(nodo);
		int pos = this.vetor.size()-1;
		this.moveAcima(pos);
	}
	

	public void mostraHeap(){
		int count = 1;
		int nl = 2;
		for(int i=0; i<this.vetor.size(); i++){
			System.out.printf("%s | ", this.vetor.elementAt(i));
			count++;
			if(count == nl){
				System.out.printf("\n");
				nl *= 2;
			}
			
		}
		System.out.printf("\n");
	}

	public int getTamanho(){
		return this.vetor.size();
	}

	public Nodo getNodo(int pos){
		return (Nodo) this.vetor.elementAt(pos);
	}

}