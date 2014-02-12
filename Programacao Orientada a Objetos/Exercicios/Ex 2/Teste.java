public class Teste{

	public static void main(String[] args) {
		
		Cachorro cc1 = new Cachorro("Tobi");
		cc1.correr();
		cc1.correr();
		cc1.parar();
		System.out.println("CACHORRO:\n---------------------\n");
		cc1.barulho();
		System.out.println("Velocidade:"+cc1.getVelocidade()+"\n\n");


		Gato gt1 = new Gato("Lince");
		gt1.correr();
		gt1.correr();
		gt1.parar();
		System.out.println("GATO:\n---------------------\n");
		gt1.barulho();
		System.out.println("Velocidade:"+gt1.getVelocidade()+"\n\n");


		Cavalo cv1 = new Cavalo("Nieldo");
		cv1.correr();
		cv1.correr();
		cv1.parar();
		System.out.println("CAVALO:\n---------------------\n");
		cv1.barulho();
		System.out.println("Velocidade:"+cv1.getVelocidade()+"\n\n");


	}
	
}