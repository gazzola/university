public class Teste{

	public static void main(String[] args) {
		
		Circulo c1 = new Circulo();
		c1.setRaio(2.0);
		c1.calcArea();
		c1.calcPerimetro();
		double area = c1.getArea();
		double perimetro = c1.getPerimetro();

		System.out.println("CIRCULO:\n-------------------");
		System.out.println("Area: "+area+"\nPerimetro: "+perimetro+"\n\n");



		Retangulo r1  = new Retangulo();
		r1.setLargura(2.0);
		r1.setAltura(3.0);
		r1.calcArea();
		r1.calcPerimetro();
		area = r1.getArea();
		perimetro = r1.getPerimetro();

		System.out.println("RETANGULO:\n-------------------");
		System.out.println("Area: "+area+"\nPerimetro: "+perimetro+"\n\n");



		Quadrado q1  = new Quadrado();
		q1.setLarguraAltura(2.0);
		q1.calcArea();
		q1.calcPerimetro();
		area = q1.getArea();
		perimetro = q1.getPerimetro();

		System.out.println("QUADRADO:\n-------------------");
		System.out.println("Area: "+area+"\nPerimetro: "+perimetro+"\n\n");


	}

}