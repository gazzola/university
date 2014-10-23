import java.io.*;
import java.net.*;
import java.util.*;
import java.text.*;


class TreatClient extends Thread{

	private Socket connSocket;
	static int qtdClients = 0;
	static int qtdMessages = 0;

	public TreatClient(Socket connSocket){
		this.connSocket = connSocket;
	}


	private String getDiffDate(Date dateNow, Date dateClient){
		long diff = dateNow.getTime() - dateClient.getTime();
		long diffSeconds = diff / 1000 % 60;
		long diffMinutes = diff / (60 * 1000) % 60;
		return  diffMinutes + "min e " + diffSeconds + "s.";
	}

	private String formatDate(Date date){
		DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
		return dateFormat.format(date);
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

			if(cm.getIdClient() == CustomMessage.UNKNOWN_CLIENT){	// se cliente ainda nao tem id, atribui um para ele
				qtdClients++;
				outToClient.writeObject(new CustomMessage(qtdClients, "server"));
			}
			else{

				clientSentence = cm.getMessage();
				idClient = cm.getIdClient();
				capSequence = clientSentence.toUpperCase() + "\n";

				sm = new CustomMessage(0, "server");
				sm.setMessage(capSequence);

				qtdMessages++;
				Date dateNow = new Date();

				System.out.println("Cliente "+idClient+" disse: "+clientSentence+" - "+qtdMessages);
				System.out.println("Enviada em: "+cm.getFormatedDate()+" - Recebida em:"+this.formatDate(dateNow));
				System.out.println("Atraso: "+getDiffDate(dateNow, cm.getDate())+"\n\n");
				
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