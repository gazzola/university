
abstract class Animal {
	
	private String nome;
	protected int velocidade = 0;



	protected void setNome(String nome){
		this.nome = nome;
	}

	protected String getNome(){
		return this.nome;
	}

	protected int getVelocidade(){
		return this.velocidade;
	}

	public abstract void barulho();
	public abstract void correr();
	public abstract void parar();

}
