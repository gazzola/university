import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.*; 

public class Main{
	 
	private void search(int port){
		
		Scanner input = new Scanner(System.in);
		System.out.println("Type a domain name for get a ip adress.\n");

		while(true){

			String domain = input.next();

			try{
				Registry myRegistry = LocateRegistry.getRegistry("127.0.0.1", port);
				Message impl = (Message) myRegistry.lookup("myMessage");
				String ip = impl.getIpOf(domain);
				System.out.println("IP Adress: " + ip);
			} 
			catch(Exception e){
				e.printStackTrace();
			}
		}
	}
	 
	public static void main(String[] args){
		Main main = new Main();
		main.search(Integer.parseInt(args[0]));
	}
}