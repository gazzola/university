public class Circulo extends FormaGeometrica{

	private static final double PI = 3.14159265359; 
	private double raio;


	public Circulo(){}

	public void calcArea(){
		this.area = PI*(raio*raio);
	}

	public void calcPerimetro(){
		this.perimetro = 2*PI*raio;
	}

	public void setRaio(double raio){
		this.raio = raio;
	}

}