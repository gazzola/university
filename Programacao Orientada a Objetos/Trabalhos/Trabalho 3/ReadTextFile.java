import java.io.*;
import java.util.*;
import javax.swing.*;
import java.text.*;

class ReadTextFile extends FileAction{
	
	private Scanner input;
	private static ReadTextFile instance;


	private ReadTextFile(){
		this.action = "Read";
	}


	public static ReadTextFile getInstance(){
		if(instance == null)
			instance = new ReadTextFile();
		return instance;
	}


	public void openFile(String filename){
		try{
			input = new Scanner(new File(filename));
		}
		catch(FileNotFoundException err1){
			String msg = "Erro ao abrir o arquivo: "+err1;
			JOptionPane.showMessageDialog(null, msg);
		}
	}


	public String getContent(String filename){
		String text = "";
		try{
			BufferedReader input = new BufferedReader(new FileReader(filename));
			while(input.ready())
				text += input.readLine();
			input.close();
		}
		catch(IOException ioe){
			ioe.printStackTrace();
		}

		return text;
	}


	public String readContent(){
		this.supporters = new Supporter[RegistrySupporter.getSize()];
		String text = "";

		try{
			text = this.getTextAndSetDatas();
		}
		catch(NoSuchElementException err2){
			input.close();
			String msg = "Nao existe o elemento: "+err2;
			JOptionPane.showMessageDialog(null, msg);
		}
		catch(IllegalStateException err3){
			String msg = "Erro durante leitura do arquivo: "+err3;
			JOptionPane.showMessageDialog(null, msg);
		}

		return text;
	}


	public void closeFile(){
		if(input != null)
			input.close();
	}


	private String getTextAndSetDatas(){
		int count = 0;
		String text = "";

		while(input.hasNext()){

			//get text
			int id = input.nextInt();
			text += id+" ";

			String name = input.next();
			text += name+" ";

			String team = input.next();
			text += team+" ";

			String date = input.next();
			date += " "+input.next();
			date += " "+input.next();
			date += " "+input.next();
			date += " "+input.next();
			date += " "+input.next();
			text += date+" ";

			String cpf = input.next();
			text += cpf+" ";

			String occupation = input.next();
			text += occupation+" ";

			String school = input.next();
			text += school+" ";

			String temp = input.next();
			boolean tattoo = temp.equals("Sim") ? true : false;
			text += temp+" ";

			int numFights = input.nextInt();
			text += numFights+" ";

			int numExpulsions = input.nextInt();
			text += numExpulsions+" ";

			String hairSize = input.next();
			text += hairSize+" ";

			String hairColor = input.next();
			text += hairColor+" ";

			String skin = input.next();
			text += skin+" ";

			double height = input.nextDouble();
			text += height+" ";

			double weight = input.nextDouble();
			text += weight+" ";

			String organizationSup = input.next();
			text += organizationSup+" ";

			String posTattoo = input.next();
			text += posTattoo+" ";

			String funcName = input.next();
			text += funcName+"\n";


			//set datas
			Date birthDate = null;
			try{
				String pattern = "EEE MMM dd HH:mm:ss zzzz yyyy";  
				DateFormat df = new SimpleDateFormat(pattern);  
				birthDate = df.parse(date);
			}
			catch(ParseException ex){
				String msg = "Data fora do formato: "+ex.getMessage();
				JOptionPane.showMessageDialog(null, msg);
			}


			Supporter record = new Supporter(name, id, funcName);
			record.setTeam(team);
			record.setDateBirth(birthDate);
			record.setCpf(cpf);
			record.setOccupation(occupation);
			record.setScholarityLevel(school);
			record.setTattoo(tattoo);
			record.setNumFights(numFights);
			record.setNumExpulsions(numExpulsions);
			record.setHairSize(hairSize);
			record.setHairColor(hairColor);
			record.setPosTattoo(posTattoo);
			record.setSkin(skin);
			record.setHeight(height);
			record.setWeight(weight);
			record.setOrganizationSup(organizationSup);

			this.supporters[count] = record;
			count++;
		}

		return text;
	}

}