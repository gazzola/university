import java.io.*;
import java.util.*;
import javax.swing.*;

public class CreateObjectFile extends FileAction{

	private ObjectOutputStream output;
	private static CreateObjectFile instance;

	private CreateObjectFile(){
		this.action = "Create";
	}

	public static CreateObjectFile getInstance(){
		if(instance == null)
			instance = new CreateObjectFile();
		return instance;
	}

	public void openFile(String filename){
		try{
			this.output = new ObjectOutputStream(new FileOutputStream(filename));
		}
		catch(IOException err1){
			String msg = "Erro ao abrir o arquivo: "+err1;
            JOptionPane.showMessageDialog(null, msg);
		}
	}

	public void addContent(Supporter[] supporters){
		for(int i=0; i<supporters.length; i++){
			Supporter record = (Supporter) supporters[i];
			try{
				this.output.writeObject(record);
			}
			catch(SecurityException se){
	            String msg = "Sem permissao de acesso: "+se.getMessage();
	            JOptionPane.showMessageDialog(null, msg);
	        }
	        catch (FileNotFoundException fnfe){
	            String msg = "Nao foi possivel criar o arquivo: "+fnfe.getMessage();
	            JOptionPane.showMessageDialog(null, msg);
	        }
			catch(NoSuchElementException nsee){
				String msg = "Entrada invalida: "+nsee.getMessage();
				JOptionPane.showMessageDialog(null, msg);
			}
			catch(Exception ex){
	            String msg = "Erro: "+ex;
	            JOptionPane.showMessageDialog(null, msg);
	        }
		}
	}

	public void closeFile(){
		try{
			if(this.output != null)
				this.output.close();
		}
		catch(IOException err3){
			String msg = "Erro ao fechar arquivo";
            JOptionPane.showMessageDialog(null, msg);
		}
	}

}