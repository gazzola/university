import java.util.*;
import javax.swing.*;
import java.text.*;

interface Log{
	public String getData();
	public void addData(String functionary, String action, String suppoter);
}

class SystemLog implements Log{
	
	private static SystemLog instance;
	private String filename;
	private String text;

	private SystemLog(String filename){
		this.filename = filename;
        this.text = this.readData(this.filename);
	}


	public static SystemLog getInstance(){
		if(instance == null)
			instance = new SystemLog("system.log");
		return instance;
	}


	public String getData(){
		return this.text;
	}


	public void addData(String functionary, String action, String suppoter){
		String data = functionary+" "+action+" "+suppoter+" - "+this.getCurrentDateAndTime()+"\n";
		this.text += data;
		this.writeData(this.filename);
	}


	private String getCurrentDateAndTime(){
		DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
		return dateFormat.format(new Date());
	}


	private String readData(String filename){
		String text = "";
		try{
            FileAction textRead = FileType.getFileType("Text").getFileAction("Read");
            text = textRead.getContent(filename);
        }
        catch(FileException fe){
            String msg = fe.getMessage();
            JOptionPane.showMessageDialog(null, msg);
        }
        return text;
	}


	private void writeData(String filename){
		try{
            FileAction textCreate = FileType.getFileType("Text").getFileAction("Create");
            textCreate.openFile(filename);
            textCreate.addContent(this.getData());
            textCreate.closeFile();
        }
        catch(FileException fe){
            String msg = fe.getMessage();
            JOptionPane.showMessageDialog(null, msg);
        }
	}

}