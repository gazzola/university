class Teste{
	
	public static void main(String[] args) {
		
		Matriz matrix = new Matriz();
		matrix.setDimensions(4, 4);
		matrix.setMatrix();
		matrix.showMatrix();

		Matriz matrix2 = new Matriz();
		matrix2.setDimensions(4, 4);
		matrix2.setMatrix();
		matrix2.showMatrix();

		Matriz matrix3 = new Matriz();
		matrix3.setDimensions(4, 4);
		matrix3.calcMultiplication(matrix, matrix2);
		matrix3.showMatrix();

	}

}