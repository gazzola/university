import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.*;
import javax.swing.JFrame;
import java.util.*;
import java.util.List;
import java.util.Arrays;

public class SupporterWindow extends JFrame implements ActionListener {
   
    private JLabel labelRegister, labelEdit, labelReport, labelNavigator, labelFunctionary;
    protected JComboBox fieldSupporter;
    private JButton buttonRegister, buttonEdit, buttonReport;


    public SupporterWindow(){

        super("SUPPORTER WINDOW");
       
        Container content = getContentPane();
        content.setLayout(null);
       
        String labelText = "Login -> Supporters";
        this.labelNavigator = new JLabel(labelText);
        this.labelNavigator.setBounds(new Rectangle(1,10,200,25));
        content.add(this.labelNavigator, null);

        labelText = "Logado como: "+LoginWindow.functionaryName;
        this.labelFunctionary = new JLabel(labelText);
        this.labelFunctionary.setBounds(new Rectangle(250,10,300,25));
        content.add(this.labelFunctionary, null);
       
        labelText = "Registrar Torcedor:";
        this.labelRegister = new JLabel(labelText);
        this.labelRegister.setBounds(new Rectangle(1,50,300,25));
        content.add(this.labelRegister, null);

        labelText = "Editar Torcedor:";
        this.labelEdit = new JLabel(labelText);
        this.labelEdit.setBounds(new Rectangle(1,120,300,25));
        content.add(this.labelEdit, null);

        labelText = "Gerar Relatorio:";
        this.labelReport = new JLabel(labelText);
        this.labelReport.setBounds(new Rectangle(1,190,300,25));
        content.add(this.labelReport, null);


        String[] supporters = {"Nenhum Torcedor Registrado"};
        if(!RegistrySupporter.isEmpty()){
            supporters = RegistrySupporter.GetAll();
            supporters = this.removeElements(supporters, LoginWindow.functionaryName);
        }


        this.fieldSupporter = new JComboBox(supporters);
        this.fieldSupporter.setBounds(new Rectangle(1,150,250,25));
        this.fieldSupporter.setSelectedIndex(0);
        content.add(this.fieldSupporter, null);



        this.buttonRegister = new JButton("OK");
        this.buttonRegister.setBounds(new Rectangle(1,80,100,25));
        content.add(this.buttonRegister, null);
       
        this.buttonRegister.setActionCommand("REGISTRAR");
        this.buttonRegister.addActionListener(this);



        this.buttonRegister = new JButton("OK");
        this.buttonRegister.setBounds(new Rectangle(260,150,100,25));
        content.add(this.buttonRegister, null);
       
        this.buttonRegister.setActionCommand("EDITAR");
        this.buttonRegister.addActionListener(this);



        this.buttonRegister = new JButton("OK");
        this.buttonRegister.setBounds(new Rectangle(1,220,100,25));
        content.add(this.buttonRegister, null);
       
        this.buttonRegister.setActionCommand("VISUALIZAR");
        this.buttonRegister.addActionListener(this);

        
        setVisible(true);
        setSize(400, 450);

    }


    private String[] removeElements(String[] input, String functionary) {
        List result = new LinkedList();

        for(String i : input)
            if(RegistrySupporter.Get(i).getFuncName().equals(functionary))
                result.add(i);

        if(result.size() == 0)
            result.add("Nenhum Torcedor Registrado");

        return (String[]) result.toArray(new String[result.size()]);
    }


    public void actionPerformed(ActionEvent e){
        String comando = (String) e.getActionCommand();
       
        if(comando.equals("REGISTRAR")){
            new SupporterRegisterWindow(this);
        }
        else if(comando.equals("EDITAR")){
            String sup = (String) this.fieldSupporter.getSelectedItem();
            if(sup.equals("Nenhum Torcedor Registrado"))
                JOptionPane.showMessageDialog(null, "Selecione um torcedor valido!");
            else
                new SupporterEditWindow(this, sup);
        }
        else if(comando.equals("VISUALIZAR")){
            new SupporterReportWindow(false);
        }
       
    }

}
