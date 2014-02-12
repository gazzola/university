
public class Gato extends Animal{

	public Gato(String nome){
		this.setNome(nome);
	}	
	
	public void barulho(){
		System.out.println("Miau Miau!");
	}

	public void correr(){
		this.velocidade += 10;
	}

	public void parar(){
		if(this.velocidade-5 > 0)
			this.velocidade -= 5;
		else
			this.velocidade = 0;
	}

}
