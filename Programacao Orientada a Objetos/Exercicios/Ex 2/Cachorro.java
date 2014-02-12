
public class Cachorro extends Animal{

	public Cachorro(String nome){
		this.setNome(nome);
	}	
	
	public void barulho(){
		System.out.println("Au Au Au!");
	}

	public void correr(){
		this.velocidade += 15;
	}

	public void parar(){
		if(this.velocidade-10 > 0)
			this.velocidade -= 10;
		else
			this.velocidade = 0;
	}

}
