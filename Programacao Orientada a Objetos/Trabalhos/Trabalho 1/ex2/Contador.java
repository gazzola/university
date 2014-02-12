class Contador{
	
	private int[] moedas;
	private String nome;
	private int maior;


	public void Contador(){}


	public String getNome(){
		return this.nome;
	}

	public int getMaior(){
		return this.maior;
	}

	public void setMoedas(int[] moedas){
		this.moedas = moedas;
	}

	public void setNome(String nome){
		this.nome = nome;
	}

	private void setMaior(int maior){
		this.maior = maior;
	}

	public void calculaMaior(){

		int maior = this.moedas[0];
		int i;
		for(i=1; i<moedas.length; i++)
			if(maior < moedas[i])
				maior = moedas[i];

		this.setMaior(maior); 

	}


}