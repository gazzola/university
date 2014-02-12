import javax.swing.*;
import java.awt.*;
import java.util.*;

public class SupporterReportWindow extends JFrame{
    
    private JLabel labelNavigator;
    private JTextArea report;
    private JScrollPane areaScrollPane;

    public SupporterReportWindow(boolean crescentOrder){

        super("SUPPORTER REPORT WINDOW");

        Container content = getContentPane();
        content.setLayout(null);


        String labelText = "Login -> Supporters -> Report";
        this.labelNavigator = new JLabel(labelText);
        this.labelNavigator.setBounds(new Rectangle(1,10,300,25));
        content.add(this.labelNavigator, null);
       

        this.report = new JTextArea();
        this.areaScrollPane = new JScrollPane(report);

        areaScrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        areaScrollPane.setPreferredSize(new Dimension(250, 250));
        areaScrollPane.setBounds(new Rectangle(1, 40, 370, 350));
        content.add(areaScrollPane, null);


        String texto = "";
        String[] names = RegistrySupporter.GetAll();
        int size = RegistrySupporter.getSize();

        if(crescentOrder){
            for(int i=size-1; i>=0; i--){
                Supporter objr = RegistrySupporter.Get(names[i]);
                String tattoo = (objr.hasTattoo()) ? "Sim" : "Nao";
                texto += "ID: "+objr.getId()+"\n";
                texto += "NOME: "+objr.getName()+"\n";
                texto += "TIME: "+objr.getTeam()+"\n";
                texto += "DATA DE NASCIMENTO: "+objr.getDateBirth()+"\n";
                texto += "CPF: "+objr.getCpf()+"\n";
                texto += "OCUPACAO: "+objr.getOccupation()+"\n";
                texto += "NIVEL DE ESCOLARIDADE: "+objr.getScholarityLevel()+"\n";
                texto += "TATUAGEM: "+tattoo+"\n";
                texto += "NUMERO DE BRIGAS: "+objr.getNumFights()+"\n";
                texto += "NUMERO DE EXPULSOES: "+objr.getNumExpulsions()+"\n";
                texto += "REGISTRADO POR: "+objr.getFuncName()+"\n";
                texto += "\n------------------------------------------------------------------------------\n\n";
            }
            report.append(texto);
        }
        else{
            for(int i=0; i<size; i++){
                Supporter objr = RegistrySupporter.Get(names[i]);
                String tattoo = (objr.hasTattoo()) ? "Sim" : "Nao";
                texto += "ID: "+objr.getId()+"\n";
                texto += "NOME: "+objr.getName()+"\n";
                texto += "TIME: "+objr.getTeam()+"\n";
                texto += "DATA DE NASCIMENTO: "+objr.getDateBirth()+"\n";
                texto += "CPF: "+objr.getCpf()+"\n";
                texto += "OCUPACAO: "+objr.getOccupation()+"\n";
                texto += "NIVEL DE ESCOLARIDADE: "+objr.getScholarityLevel()+"\n";
                texto += "TATUAGEM: "+tattoo+"\n";
                texto += "NUMERO DE BRIGAS: "+objr.getNumFights()+"\n";
                texto += "NUMERO DE EXPULSOES: "+objr.getNumExpulsions()+"\n";
                texto += "REGISTRADO POR: "+objr.getFuncName()+"\n";
                texto += "\n------------------------------------------------------------------------------\n\n";
            }
            report.append(texto);
        }
        
        
        setVisible(true);
        setSize(400, 450);

    }

}

