class Aluno {
	
	private String nome, curso;
	private int idade, matricula;
	private double altura;
	private Curso objc;

	public Aluno(String curso){

		this.objc = new Curso(curso, "UNIPAMPA", 7, 25);
		this.setCurso(curso);

	}

	
	public String getNome(){
		return this.nome;
	}

	public String getCurso(){
		return this.curso;
	}

	public int getIdade(){
		return this.idade;
	}

	public int getMatricula(){
		return this.matricula;
	}

	public double getAltura(){
		return this.altura;
	}



	public void setNome(String nome){
		this.nome = nome;
	}

	public void setCurso(String curso){
		this.curso = curso;
	}

	public void setIdade(int idade){
		this.idade = idade;
	}

	public void setMatricula(int matricula){
		this.matricula = matricula;
	}

	public void setAltura(double altura){
		this.altura = altura;

	}



	public void exibeDados(){

		System.out.println("DADOS DO ALUNO:");
		System.out.println(this.getNome());
		System.out.println(this.getIdade());
		System.out.println(this.getAltura());
		System.out.println(this.getMatricula());
		System.out.println(this.getCurso());
		System.out.println("\n\nDADOS DO CURSO:");
		System.out.println(this.objc.getCurso());
		System.out.println(this.objc.getUniversidade());
		System.out.println(this.objc.getAnos());
		System.out.println(this.objc.getQtdCadeiras());
		System.out.println(this.objc.getCod());

	}

}



