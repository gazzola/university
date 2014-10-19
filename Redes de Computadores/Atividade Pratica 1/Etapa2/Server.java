import java.io.*;
import java.net.*;
import java.util.*;


class Server extends Thread{

	private int port;

	public Server(int port){
		this.port = port;

		try{

			ServerSocket svSocket = new ServerSocket(this.port);
			System.out.println("Servidor rodando na porta " + this.port);

			while(true){
				Socket connSocket = svSocket.accept();
				new TreatClient(connSocket).start();
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