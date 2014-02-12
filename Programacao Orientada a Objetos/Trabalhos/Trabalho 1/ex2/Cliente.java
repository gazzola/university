class Cliente{

	private String nome;
	private int idade, qtdMoedas;

	
	public void Cliente(){}


	public String getNome(){
		return this.nome;
	}

	public int getIdade(){
		return this.idade;
	}

	public int getQtdMoedas(){
		return this.qtdMoedas;
	}


	public Cliente setNome(String nome){
		this.nome = nome;
		return this;
	}

	public Cliente setIdade(int idade){
		this.idade = idade;
		return this;
	}

	public Cliente setQtdMoedas(int qtdMoedas){
		this.qtdMoedas = qtdMoedas;
		return this;
	}
	
}