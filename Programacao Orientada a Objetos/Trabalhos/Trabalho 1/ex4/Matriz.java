import java.util.*;
import java.util.Arrays;
import javax.swing.JOptionPane;

class Matriz{

	private int[][] matriz;
	private int[][] repeats;
	private int x,y;

	public Matriz(){}
	
	public void setDimensions(){

		this.x = Integer.parseInt(JOptionPane.showInputDialog("Digite a primeira dimensao da matriz:"));
		this.y = Integer.parseInt(JOptionPane.showInputDialog("Digite a segunda dimensao da matriz:"));
		this.matriz = new int[this.x][this.y];
		
	}

	public void setMatrix(){
		
		int i, j;
		for(i=0; i<this.x; i++)
			for(j=0; j<this.y; j++)
				this.matriz[i][j] = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite um inteiro para a posicao ["+i+"]["+j+"] da matriz: "));

	}

	public void showMatrix(){
		String message = "MATRIZ:\n"+Arrays.deepToString(this.matriz);
		JOptionPane.showMessageDialog(null, message);
	}


	public void calcMatrix(){

		int count_x = 0;
		int elem, count_y;

		
		this.repeats = new int[this.x][this.y];

		while(count_x < this.x){
			count_y = 0;
			while(count_y < this.y){
				elem = this.matriz[count_x][count_y];
				this.repeats[count_x][count_y] = getRepeats(elem);
				count_y++;
			}	
			count_x++;
		}

	}


	private int getRepeats(int elem){
		
		int i,j;
		int total = 0;
		
		for(i=0; i<this.x; i++)
			for(j=0; j<this.y; j++)
				if(this.matriz[i][j] == elem)
					total++;

		return total;

	}


	public void showRepeats(){

		String message = "ELEMENTOS REPETIDOS:\n";

		int[] history;
		history = new int[this.x*this.y];

		int i, j, count = 0;
		for(i=0; i<this.x; i++){
			for(j=0; j<this.y; j++){
				if(this.inArray(history, this.matriz[i][j]) == false)
					if(this.repeats[i][j] > 1)
						message += this.matriz[i][j]+": "+this.repeats[i][j]+"\n";
				history[count] = this.matriz[i][j];
				count++;
			}
		}

		JOptionPane.showMessageDialog(null, message);
	}


	public boolean inArray(int[] arr, int needle){
		int i;
		for(i=0; i<arr.length; i++)
			if(arr[i] == needle)
				return true;
		return false;
	}

}