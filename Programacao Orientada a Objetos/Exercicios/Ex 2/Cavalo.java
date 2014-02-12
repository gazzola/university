
public class Cavalo extends Animal{

	public Cavalo(String nome){
		this.setNome(nome);
	}	
	
	public void barulho(){
		System.out.println("Ufuuh Ufuuh!");
	}

	public void correr(){
		this.velocidade += 30;
	}

	public void parar(){
		if(this.velocidade-15 > 0)
			this.velocidade -= 15;
		else
			this.velocidade = 0;
	}

}
