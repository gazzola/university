import java.util.*;

class Main{

	public static void main(String[] args){

		Scanner input = new Scanner(System.in);
		int n = input.nextInt();
		while(n > 0){
			double x = input.nextDouble();
			System.out.printf("%7.3f\n", x);
			n--;
		}
	}

};