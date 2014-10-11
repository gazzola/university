import java.io.*;
import java.net.*;
import java.util.*;

class Client{

	private String host;
	private int port;
	private int id;

	public Client(String host, int port){
		this.host = host;
		this.port = port;
	}

	private void run() throws Exception{

		System.out.println("Digite uma mensagem ou `STOP` para parar");

		String sentence, capSentence;
		int id = this.getIdFromServer();
		CustomMessage cm;

		try{
			while(true){
				BufferedReader inFromUser = new BufferedReader(new InputStreamReader(System.in));
				Socket clientSocket = new Socket(this.host, this.port);
				
				ObjectOutputStream outToServer = new ObjectOutputStream(clientSocket.getOutputStream());
				ObjectInputStream inFromServer = new ObjectInputStream(clientSocket.getInputStream());
				
				sentence = inFromUser.readLine();
				if(sentence.equalsIgnoreCase("STOP"))
					break;

				String hostName = clientSocket.getInetAddress().getHostName();
				cm = new CustomMessage(id, hostName);
				cm.setMessage(sentence + "\n");
				outToServer.writeObject(cm);

				cm = (CustomMessage) inFromServer.readObject();
				capSentence = cm.getMessage();
				System.out.println("Servidor respondeu: " + capSentence);

				clientSocket.close();
			}
		}
		catch(Exception e){
			System.out.println(e.getMessage());
		} 

	}

	private int getIdFromServer() throws Exception{

		CustomMessage cm;
		Socket idSocket = new Socket(this.host, this.port);
		ObjectOutputStream outToServerId = new ObjectOutputStream(idSocket.getOutputStream());
		ObjectInputStream inFromServerId = new ObjectInputStream(idSocket.getInputStream());

		cm = new CustomMessage(-1, "localhost");
		outToServerId.writeObject(cm);

		cm = (CustomMessage) inFromServerId.readObject();
		return cm.getIdClient();
	}


	public static void main(String[] args) throws Exception{
		
		if(args.length == 0){
			System.out.println("Passe o numero da porta como argumento!");
			return;
		}

		Integer p = Integer.parseInt(args[0]);
		Client c1 = new Client("127.0.0.1", p);
		c1.run();
	}
}