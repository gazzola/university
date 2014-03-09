import javax.swing.*;
import java.awt.*;
import java.util.*;
import java.util.ArrayList;
import java.io.*;

public class SupporterReportWindow extends JFrame{
    
    private JLabel labelNavigator, labelFunctionary;
    private JTextArea report;
    private JScrollPane areaScrollPane;

    private String outputText, outputArea;
    private Supporter[] outputRecords = new Supporter[RegistrySupporter.getSize()];

    public SupporterReportWindow(boolean crescentOrder){

        super("SUPPORTER REPORT WINDOW");

        Container content = getContentPane();
        content.setLayout(null);

        String labelText = "Login -> Supporters -> Report";
        this.labelNavigator = new JLabel(labelText);
        this.labelNavigator.setBounds(new Rectangle(1,10,300,25));
        content.add(this.labelNavigator, null);

        labelText = "Logado como: "+LoginWindow.functionaryName;
        this.labelFunctionary = new JLabel(labelText);
        this.labelFunctionary.setBounds(new Rectangle(550,10,300,25));
        content.add(this.labelFunctionary, null);

        this.generateOutputText();
        this.reportTextFile("output.out");

        this.generateOutputObjects();
        this.reportObjectFile("output_object.bin");

        this.generateOutputArea();
        this.reportArea(content, this.outputArea);
        //this.reportArea(content, this.readTextFile("output.out"));
        //this.reportArea(content, this.readObjectFile("output_object.bin"));

        setVisible(true);
        setSize(800, 600);

    }

    private void setLog(String functionary, String action, String supporter){
        SystemLog log = SystemLog.getInstance();
        log.addData(functionary, action, supporter);
    }


    private void reportArea(Container content, String text){
        this.report = new JTextArea();
        this.areaScrollPane = new JScrollPane(report);

        areaScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        areaScrollPane.setPreferredSize(new Dimension(250, 250));
        areaScrollPane.setBounds(new Rectangle(1, 40, 770, 500));
        content.add(areaScrollPane, null);

        report.append(text);

        this.setLog(LoginWindow.functionaryName, "reportou na area", "todos torcedores");
    }


    private void reportTextFile(String file){
       try{
            FileAction textCreate = FileType.getFileType("Text").getFileAction("Create");
            textCreate.openFile(file);
            textCreate.addContent(this.outputText);
            textCreate.closeFile();
        }
        catch(FileException fe){
            String msg = fe.getMessage();
            JOptionPane.showMessageDialog(null, msg);
        }

        this.setLog(LoginWindow.functionaryName, "reportou no arquivo de texto", "todos torcedores");
    }


    private void reportObjectFile(String file){
        try{
            FileAction objCreate = FileType.getFileType("Object").getFileAction("Create");
            objCreate.openFile(file);
            objCreate.addContent(this.outputRecords);
            objCreate.closeFile();
        }
        catch(FileException fe){
            String msg = fe.getMessage();
            JOptionPane.showMessageDialog(null, msg);
        }

        this.setLog(LoginWindow.functionaryName, "reportou no arquivo de objeto", "todos torcedores");
    }


    private String readTextFile(String file){
        String text = "";
        try{
            FileAction textRead = FileType.getFileType("Text").getFileAction("Read");
            textRead.openFile(file);
            text = textRead.readContent();
            textRead.closeFile();
        }
        catch(FileException fe){
            String msg = fe.getMessage();
            JOptionPane.showMessageDialog(null, msg);
        }

        return text;
    }


    private String readObjectFile(String file){
        String text = "";
        try{
            FileAction objRead = FileType.getFileType("Object").getFileAction("Read");
            objRead.openFile(file);
            text = objRead.readContent();
            objRead.closeFile();
        }
        catch(FileException fe){
            String msg = fe.getMessage();
            JOptionPane.showMessageDialog(null, msg);
        }

        return text;
    }


    private void generateOutputObjects(){
        String[] names = RegistrySupporter.GetAll();

        for(int i=0; i<RegistrySupporter.getSize(); i++)
            this.outputRecords[i] = RegistrySupporter.Get(names[i]);
    }


    private void generateOutputArea(){
        String text = "";
        String[] names = RegistrySupporter.GetAll();
        for(int i=0; i<RegistrySupporter.getSize(); i++){
            Supporter objr = RegistrySupporter.Get(names[i]);
            String tattoo = (objr.hasTattoo()) ? "Sim" : "Nao";
            text += "ID: "+objr.getId()+"\n";
            text += "NOME: "+objr.getName()+"\n";
            text += "TIME: "+objr.getTeam()+"\n";
            text += "DATA DE NASCIMENTO: "+objr.getDateBirth()+"\n";
            text += "CPF: "+objr.getCpf()+"\n";
            text += "OCUPACAO: "+objr.getOccupation()+"\n";
            text += "NIVEL DE ESCOLARIDADE: "+objr.getScholarityLevel()+"\n";
            text += "TATUAGEM: "+tattoo+"\n";
            text += "NUMERO DE BRIGAS: "+objr.getNumFights()+"\n";
            text += "NUMERO DE EXPULSOES: "+objr.getNumExpulsions()+"\n";
            text += "TAMANHO DO CABELO: "+objr.getHairSize()+"\n";
            text += "COR DO CABELO: "+objr.getHairColor()+"\n";
            text += "COR DA PELE: "+objr.getSkin()+"\n";
            text += "ALTURA: "+objr.getHeight()+"\n";
            text += "PESO: "+objr.getWeight()+"\n";
            text += "TORCIDA ORGANIZADA: "+objr.getOrganizationSup()+"\n";
            text += "POSICAO DA TATUAGEM: "+objr.getPosTattoo()+"\n";
            text += "REGISTRADO POR: "+objr.getFuncName()+"\n";
            text += "\n------------------------------------------------------------------------------\n\n";
        }
        this.outputArea = text;
    }

    private void generateOutputText(){
        String text = "";
        String[] names = RegistrySupporter.GetAll();
        for(int i=0; i<RegistrySupporter.getSize(); i++){
            Supporter objr = RegistrySupporter.Get(names[i]);
            String tattoo = (objr.hasTattoo()) ? "Sim" : "Nao";
            text += objr.getId()+" ";
            text += objr.getName()+" ";
            text += objr.getTeam()+" ";
            text += objr.getDateBirth()+" ";
            text += objr.getCpf()+" ";
            text += objr.getOccupation()+" ";
            text += objr.getScholarityLevel()+" ";
            text += tattoo+" ";
            text += objr.getNumFights()+" ";
            text += objr.getNumExpulsions()+" ";
            text += objr.getHairSize()+" ";
            text += objr.getHairColor()+" ";
            text += objr.getSkin()+" ";
            text += objr.getHeight()+" ";
            text += objr.getWeight()+" ";
            text += objr.getOrganizationSup()+" ";
            text += objr.getPosTattoo()+" ";
            text += objr.getFuncName()+"\n";
        }
        this.outputText = text;
    }

}

