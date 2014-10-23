import java.io.*;
import java.net.*;
import java.util.*;


class Server{

	private int port;
	private int qtdClients;
	//private ArrayList<Client> clients; 
	//distribuir mensagem pra todos os clientes

	public Server(int port){
		this.port = port;
		this.qtdClients = 0;
	}

	public void run() throws Exception{

		String clientSentence;
		String capSequence;
		int idClient;
		CustomMessage cm, sm;

		try{

			ServerSocket svSocket = new ServerSocket(this.port);
			System.out.println("Servidor rodando na porta " + this.port);

			while(true){

				Socket connSocket = svSocket.accept();
				ObjectOutputStream outToClient = new ObjectOutputStream(connSocket.getOutputStream());
				ObjectInputStream inFromClient = new ObjectInputStream(connSocket.getInputStream());

				cm = (CustomMessage) inFromClient.readObject();

				if(cm.getIdClient() == CustomMessage.UNKNOWN_CLIENT){
					this.qtdClients++;
					sm = new CustomMessage(this.qtdClients, "server");
					outToClient.writeObject(sm);
				}
				else{

					clientSentence = cm.getMessage();
					idClient = cm.getIdClient();
					capSequence = clientSentence.toUpperCase() + "\n";

					sm = new CustomMessage(0, "server");
					sm.setMessage(capSequence);

					System.out.println("Cliente "+idClient+" disse: "+clientSentence);
					outToClient.writeObject(sm);
					
				}

				outToClient.close(); 
				inFromClient.close(); 
				connSocket.close(); 
			}

		}
		catch(Exception e){
			System.out.println(e.getMessage());
		}

	}


	public static void main(String[] args) throws Exception{

		if(args.length == 0){
			System.out.println("Passe o numero da porta como argumento!");
			return;
		}

		Integer p = Integer.parseInt(args[0]);
		Server s1 = new Server(p);
		s1.run();
	}
	
}