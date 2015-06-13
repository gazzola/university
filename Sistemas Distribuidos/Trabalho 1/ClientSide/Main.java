import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.*; 

public class Main{
	 
	private void search(String ip, int port){
		
		Scanner input = new Scanner(System.in);
		System.out.println("Type a domain name for get a ip adress.\n");

		while(true){

			String domain = input.next();

			try{
				Registry myRegistry = LocateRegistry.getRegistry(ip, port);
				Message impl = (Message) myRegistry.lookup("myMessage");
				System.out.println("IP Adress: " + impl.getIpOf(domain));
			} 
			catch(Exception e){
				e.printStackTrace();
			}
		}
	}
	 
	public static void main(String[] args){
		Main main = new Main();
		main.search(args[0], Integer.parseInt(args[1]));
	}
}