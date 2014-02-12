import java.util.*;

class Teste{

	public static void main(String[] args) {
		
		Cliente obj1 = new Cliente();
		obj1.setNome("Joao").setIdade(18);


		Scanner input = new Scanner(System.in);

		int[] moedas;
		int loops = 4;
		moedas = new int[loops];

		System.out.println("Digite "+loops+" valores para colocar no vetor:");
		int i=0;
		while(i<loops){
			moedas[i] = input.nextInt();
			i++;
		}


		Contador obj4 = new Contador();
		obj4.setNome("Jesus");
		obj4.setMoedas(moedas);
		obj4.calculaMaior();

		obj1.setQtdMoedas(obj4.getMaior());


		String message = "O contador "+obj4.getNome()+" verificou que a maior qtd de moedas eh: "+ obj4.getMaior();
		System.out.println(message);

	}

}