import java.util.*;
import java.text.*;
import java.io.Serializable;

class CustomMessage implements Serializable{

	private int idClient;
	private String node;
	private String msg; 
	private Date date;

	public CustomMessage(int idClient, String node){
		this.idClient = idClient;
		this.node = node;
		this.date = new Date();
	}

	public void setMessage(String msg){
		this.msg = msg;
	}

	public int getIdClient(){
		return this.idClient;
	}

	public String getNode(){
		return this.node;
	}

	public String getMessage(){
		return this.msg;
	}

	public Date getDate(){
		return this.date;
	}

	public String getFormatedDate(){
		DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
		return dateFormat.format(this.date);
	}
	
}