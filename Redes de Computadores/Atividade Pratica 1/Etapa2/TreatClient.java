import java.io.*;
import java.net.*;
import java.util.*;
import java.text.*;


class TreatClient extends Thread{

	private Socket connSocket;
	static int qtdMessages = 0;

	public TreatClient(Socket connSocket){
		this.connSocket = connSocket;
	}


	private String formatDate(Date date){
		DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
		return dateFormat.format(date);
	}

	public void run(){

		String clientSentence;
		int idClient;
		CustomMessage cm;
		
		try{
			
			ObjectInputStream inFromClient = new ObjectInputStream(this.connSocket.getInputStream());
			
			cm = (CustomMessage) inFromClient.readObject();
			clientSentence = cm.getMessage();
			idClient = cm.getIdClient();

			qtdMessages++;
			Date dateNow = new Date();

			System.out.printf("Cliente %d disse: %s %d \nEnviada em: %s - Recebida em: %s\n\n", 
								idClient, clientSentence, qtdMessages,
								cm.getFormatedDate(), this.formatDate(dateNow));
	
			inFromClient.close();
			this.connSocket.close();

			try{
				Thread.sleep(1000);
			}
			catch(InterruptedException e){
				System.out.println("Interrupted.");
			}

		}
		catch(Exception e){
			System.out.println(e.getMessage());
		}

	}
	
}