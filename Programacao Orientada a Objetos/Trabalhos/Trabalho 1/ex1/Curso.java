class Curso{

	private String curso, universidade;
	private int anos, qtdCadeiras;
	private static int codigo = 0;

	
	public Curso(String nome, String uni, int anos, int qtd){
		this.setCurso(nome);
		this.setUniversidade(uni);
		this.setAnos(anos);
		this.setQtdCadeiras(qtd);
		this.setCodigo();
	}


	public String getCurso(){
		return this.curso;
	}

	public String getUniversidade(){
		return this.universidade;
	}

	public int getAnos(){
		return this.anos;
	}

	public int getQtdCadeiras(){
		return this.qtdCadeiras;
	}

	public int getCod(){
		return this.codigo;
	}
	

	private void setCurso(String curso){
		this.curso = curso;
	}

	private void setUniversidade(String universidade){
		this.universidade = universidade;
	}

	private void setAnos(int anos){
		this.anos = anos;
	}

	private void setQtdCadeiras(int value){
		this.qtdCadeiras = value;
	}

	private void setCodigo(){
		this.codigo += 1;
	}

}



