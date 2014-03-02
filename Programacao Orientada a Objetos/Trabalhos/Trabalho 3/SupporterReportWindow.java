import javax.swing.*;
import java.awt.*;
import java.util.*;
import java.io.*;

public class SupporterReportWindow extends JFrame{
    
    private JLabel labelNavigator, labelFunctionary;
    private JTextArea report;
    private JScrollPane areaScrollPane;
    private Formatter output;
    private String outputText;

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
        this.reportFile("output.out");
        this.reportArea(content);
        
        setVisible(true);
        setSize(800, 600);

    }


    private void reportArea(Container content){
        this.report = new JTextArea();
        this.areaScrollPane = new JScrollPane(report);

        areaScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        areaScrollPane.setPreferredSize(new Dimension(250, 250));
        areaScrollPane.setBounds(new Rectangle(1, 40, 770, 500));
        content.add(areaScrollPane, null);

        report.append(this.outputText);
    }

    private void reportFile(String file){
        this.openFile(file);
        this.addText();
        this.closeFile();
    }


    private void openFile(String file){
            
        try{
            this.output = new Formatter(file);
        }
        catch(SecurityException se){
            System.err.println("Sem permissao de acesso: "+se.getMessage());
            System.exit(1);
        }
        catch (FileNotFoundException fnfe){
            System.err.println("Nao foi possivel criar o arquivo: "+fnfe.getMessage());
            System.exit(1);
        }
    }
    
    private void addText(){        
        this.output.format("%s \n", this.outputText);
    }

    
    private void closeFile(){
        if(this.output != null)
            this.output.close();
    }


    private void generateOutputText(){
        String text = "";
        String[] names = RegistrySupporter.GetAll();
        int size = RegistrySupporter.getSize();
        for(int i=0; i<size; i++){
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
        this.outputText = text;
    }

}

