public class Retangulo extends FormaGeometrica{
 
	private double largura, altura;

	public Retangulo(){}

	public void calcArea(){
		this.area = largura*altura;
	}

	public void calcPerimetro(){
		this.perimetro = (2*largura) + (2*altura);
	}

	public void setLargura(double largura){
		this.largura = largura;
	}

	public void setAltura(double altura){
		this.altura = altura;
	}

}