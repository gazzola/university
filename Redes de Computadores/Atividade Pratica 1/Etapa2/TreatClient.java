import java.io.*;
import java.net.*;
import java.util.*;


class TreatClient extends Thread{

	private Socket connSocket;
	static int qtdClients = 0;

	public TreatClient(Socket connSocket){
		this.connSocket = connSocket;
	}

	public void run(){

		String clientSentence;
		String capSequence;
		int idClient;
		CustomMessage cm, sm;
		
		try{
			ObjectOutputStream outToClient = new ObjectOutputStream(this.connSocket.getOutputStream());
			ObjectInputStream inFromClient = new ObjectInputStream(this.connSocket.getInputStream());

			cm = (CustomMessage) inFromClient.readObject();

			if(cm.getIdClient() == -1){	// se cliente ainda nao tem id, atribui um para ele
				qtdClients++;
				outToClient.writeObject(new CustomMessage(qtdClients, "server"));
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
			this.connSocket.close();
		}
		catch(Exception e){
			System.out.println(e.getMessage());
		}

	}
	
}