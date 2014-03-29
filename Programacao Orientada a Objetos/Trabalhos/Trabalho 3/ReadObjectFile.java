import java.io.*;
import java.util.*;
import javax.swing.*;

class ReadObjectFile extends FileAction{
	
	private ObjectInputStream input;
	private static ReadObjectFile instance;


	private ReadObjectFile(){
		this.action = "Read";
	}

	public static ReadObjectFile getInstance(){
		if(instance == null)
			instance = new ReadObjectFile();
		return instance;
	}


	public void openFile(String filename){
		try{
			input = new ObjectInputStream(new FileInputStream(filename));
		}
		catch(IOException err1){
			String msg = "Erro ao abrir o arquivo: "+err1;
            JOptionPane.showMessageDialog(null, msg);
		}
	}


	public String readContent(){
		
		Supporter record;
		String text = "";

		try{
			while(true){

				//if(inputStream.avaliable() > 0) is a solution for not show the NullPointerException

				record = (Supporter) input.readObject();
				String tattoo = (record.hasTattoo()) ? "Sim" : "Nao";
	            text += "ID: "+record.getId()+"\n";
	            text += "NOME: "+record.getName()+"\n";
	            text += "TIME: "+record.getTeam()+"\n";
	            text += "DATA DE NASCIMENTO: "+record.getDateBirth()+"\n";
	            text += "CPF: "+record.getCpf()+"\n";
	            text += "OCUPACAO: "+record.getOccupation()+"\n";
	            text += "NIVEL DE ESCOLARIDADE: "+record.getScholarityLevel()+"\n";
	            text += "TATUAGEM: "+tattoo+"\n";
	            text += "NUMERO DE BRIGAS: "+record.getNumFights()+"\n";
	            text += "NUMERO DE EXPULSOES: "+record.getNumExpulsions()+"\n";
	            text += "TAMANHO DO CABELO: "+record.getHairSize()+"\n";
	            text += "COR DO CABELO: "+record.getHairColor()+"\n";
	            text += "COR DA PELE: "+record.getSkin()+"\n";
	            text += "ALTURA: "+record.getHeight()+"\n";
	            text += "PESO: "+record.getWeight()+"\n";
	            text += "TORCIDA ORGANIZADA: "+record.getOrganizationSup()+"\n";
	            text += "POSICAO DA TATUAGEM: "+record.getPosTattoo()+"\n";
	            text += "REGISTRADO POR: "+record.getFuncName()+"\n";
	            text += "\n------------------------------------------------------------------------------\n\n";

	            this.supporters.add(record);
			}
		}
		catch(NullPointerException errx){
			String msg = "O arquivo esta vazio: "+errx;
            JOptionPane.showMessageDialog(null, msg);
		}
		catch(EOFException err2){
			return text;
		}
		catch(ClassNotFoundException err3){
			String msg = "Nao foi possivel criar o objeto: "+err3;
            JOptionPane.showMessageDialog(null, msg);
		}
		catch(IOException err4){
			String msg = "Erro durante leitura do arquivo: "+err4;
            JOptionPane.showMessageDialog(null, msg);
		}

		return text;
	}


	public void closeFile(){
		try{
			if(input != null)
				input.close();
		}
		catch(IOException err5){
			String msg = "Nao foi possivel fechar o arquivo: "+err5;
            JOptionPane.showMessageDialog(null, msg);
		}
	}

}