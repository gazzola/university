abstract class FormaGeometrica{

	double area, perimetro;

	public abstract void calcArea();
	public abstract void calcPerimetro();
	
	protected double getArea(){
		return this.area;
	}

	protected double getPerimetro(){
		return this.perimetro;
	}

}