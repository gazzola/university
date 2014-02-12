public class Quadrado extends FormaGeometrica{
 
	private double largura_altura;

	public Quadrado(){}

	public void calcArea(){
		this.area = largura_altura*largura_altura;
	}

	public void calcPerimetro(){
		this.perimetro = 4*largura_altura;
	}

	public void setLarguraAltura(double largura_altura){
		this.largura_altura = largura_altura;
	}

}