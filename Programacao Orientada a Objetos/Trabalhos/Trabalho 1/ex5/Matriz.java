import java.util.*;
import java.util.Arrays;
import javax.swing.JOptionPane;

class Matriz{

	private int[][] matriz;
	private int x, y;
	private static int id;

	public Matriz(){
		this.setId();
	}
	
	public void setDimensions(int x, int y){
		this.x = x;
		this.y = y;
		this.matriz = new int[x][y];
	}

	private void setId(){
		this.id++;
	}

	public void setMatrix(){

		int res = JOptionPane.showConfirmDialog(null, "Deseja que o sistema complete automaticamente a matriz?");
		
		if(res == JOptionPane.YES_OPTION){
			Random gerador = new Random(); 
			int i, j;
			for(i=0; i<this.x; i++)
				for(j=0; j<this.y; j++)
					this.matriz[i][j] = gerador.nextInt(10);
		}
		else{
			int i, j;
			for(i=0; i<this.x; i++)
				for(j=0; j<this.y; j++)
					this.matriz[i][j] = Integer.parseInt(JOptionPane.showInputDialog(null, "Digite um inteiro para a posicao ["+i+"]["+j+"] da matriz "+this.id+" : "));
		}

	}

	public int[][] getMatrix(){
		return this.matriz;
	}


	public void showMatrix(){
		String message = "MATRIZ "+this.id+":\n"+Arrays.deepToString(this.matriz);
		JOptionPane.showMessageDialog(null, message);
	}


	public void calcMultiplication(Matriz matrix1, Matriz matrix2){

		int[][] m1 = matrix1.getMatrix();
		int[][] m2 = matrix2.getMatrix();

		int i, j, n;
		for(i=0; i<this.x; i++)
			for(j=0; j<this.y; j++)
				for(n=0; n<this.y; n++)
					this.matriz[i][j] += m1[i][n]*m2[n][j];

	}

}