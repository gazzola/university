import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
 
public class Main{
	 
	private void startServer(int port){
		try{
			Registry registry = LocateRegistry.createRegistry(port);
			registry.rebind("myMessage", new MessageImpl());
		} 
		catch(Exception e){
			e.printStackTrace();
		}
		
		System.out.println("DNS system is ready!\n");
	}


	private void generateHosts(){
		String s = "google.com";
		RegistryHost.set(s, new Host("178.165.16.10", s));

		s = "gmail.com";
		RegistryHost.set(s, new Host("198.054.234.112", s));

		s = "globo.com";
		RegistryHost.set(s, new Host("205.049.244.111", s));

		s = "ibm.com";
		RegistryHost.set(s, new Host("200.156.275.157", s));

		s = "facebook.com";
		RegistryHost.set(s, new Host("78.165.67.75", s));
	}
	 
	public static void main(String[] args){
		Main main = new Main();
		main.generateHosts();
		main.startServer(Integer.parseInt(args[0]));
	}
}