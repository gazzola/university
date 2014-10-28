import java.io.*;
import java.net.*;
import java.util.*;

class Client{

	private String host;
	private int port;
	private int id;

	public Client(String host, int port, int id){
		this.host = host;
		this.port = port;
		this.id = id;
	}

	public void run() throws Exception{
		
		Socket clientSocket = null;

		try{
			while(true){
				clientSocket = new Socket(this.host, this.port);
				ObjectOutputStream outToServer = new ObjectOutputStream(clientSocket.getOutputStream());

				String hostName = clientSocket.getInetAddress().getHostName();
				CustomMessage cm = new CustomMessage(id, hostName);
				cm.setMessage("msg");
				outToServer.writeObject(cm);
			}
		}
		catch(Exception e){
			System.out.println(e.getMessage());
		}
		
	}


	public static void main(String[] args) throws Exception{
		
		if(args.length < 2){
			System.out.println("Passe o numero da porta e o id do cliente como argumentos!");
			return;
		}

		Integer p = Integer.parseInt(args[0]);
		Integer id = Integer.parseInt(args[1]);
		new Client("127.0.0.1", p, id).run();
	}
}