import java.io.*;
import java.util.*;
import javax.swing.*;

class CreateTextFile extends FileAction{
    
    private Formatter output;
    private static CreateTextFile instance;

    private CreateTextFile(){
        this.action = "Create";
    }

    public static FileAction getInstance(){
        if(instance == null)
            instance = new CreateTextFile();
        return instance;
    }

    public void openFile(String filename){            
        try{
            this.output = new Formatter(filename);
        }
        catch(SecurityException se){
            String msg = "Sem permissao de acesso: "+se.getMessage();
            JOptionPane.showMessageDialog(null, msg);
        }
        catch (FileNotFoundException fnfe){
            String msg = "Nao foi possivel criar o arquivo: "+fnfe.getMessage();
            JOptionPane.showMessageDialog(null, msg);
        }
        catch(Exception ex){
            String msg = "Erro: "+ex;
            JOptionPane.showMessageDialog(null, msg);
        }
    }
    
    public void addContent(String text){
        this.output.format("%s \n", text);
    }
    
    public void closeFile(){
        if(this.output != null)
            this.output.close();
    }

}