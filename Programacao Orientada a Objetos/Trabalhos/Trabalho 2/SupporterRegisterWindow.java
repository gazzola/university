import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.*;
import javax.swing.JFrame;
import java.util.*;
import java.text.SimpleDateFormat;
import java.util.Arrays;

public class SupporterRegisterWindow extends JFrame implements ActionListener {
   
    private JLabel labelName, labelTeam, labelDate, labelCpf, labelOccupation, labelSchool, labelTattoo, labelNumFights, labelNumExpulsions, labelNavigator;
    private JComboBox fieldTeam, fieldTattoo, fieldSchool;
    private JSpinner fieldDate, fieldNumFights, fieldNumExpulsions;
    private JTextField fieldName, fieldOccupation, fieldCpf;
    private JButton buttonEndRegister;
    private SupporterWindow sw;
    private static int idCount = 0;

    public SupporterRegisterWindow(SupporterWindow sw){

        super("SUPPORTER REGISTER WINDOW");

        Container content = getContentPane();
        content.setLayout(null);

        this.sw = sw;
        

        String labelText = "Login -> Supporters -> Register";
        this.labelNavigator = new JLabel(labelText);
        this.labelNavigator.setBounds(new Rectangle(1,10,300,25));
        content.add(this.labelNavigator, null);
       

        labelText = "Nome:";
        this.labelName = new JLabel(labelText);
        this.labelName.setBounds(new Rectangle(1,50,300,25));
        content.add(this.labelName, null);

        this.fieldName = new JTextField();
        this.fieldName.setBounds(new Rectangle(160,50,120,25));
        content.add(this.fieldName, null);


        labelText = "Time:";
        this.labelTeam = new JLabel(labelText);
        this.labelTeam.setBounds(new Rectangle(1,90,300,25));
        content.add(this.labelTeam, null);

        String[] teams = {"Caxias", "Gremio", "Internacional", "Juventude"};
        this.fieldTeam = new JComboBox(teams);
        this.fieldTeam.setBounds(new Rectangle(160,90,120,25));
        this.fieldTeam.setSelectedIndex(0);
        content.add(this.fieldTeam, null);


        labelText = "Data de Nascimento:";
        this.labelDate = new JLabel(labelText);
        this.labelDate.setBounds(new Rectangle(1,130,300,25));
        content.add(this.labelDate, null);

        Date now = new Date();  
        SpinnerDateModel model = new SpinnerDateModel(now, null, now, Calendar.DAY_OF_WEEK);  
        this.fieldDate = new JSpinner(model);
        this.fieldDate.setEditor(new JSpinner.DateEditor(this.fieldDate, "dd/MM/yyyy"));
        this.fieldDate.setBounds(new Rectangle(160,130,120,25));
        content.add(this.fieldDate, null);


        labelText = "CPF:";
        this.labelCpf = new JLabel(labelText);
        this.labelCpf.setBounds(new Rectangle(1,170,300,25));
        content.add(this.labelCpf, null);

        this.fieldCpf = new JTextField();
        this.fieldCpf.setBounds(new Rectangle(160,170,120,25));
        content.add(this.fieldCpf, null);


        labelText = "Ocupacao:";
        this.labelOccupation = new JLabel(labelText);
        this.labelOccupation.setBounds(new Rectangle(1,210,300,25));
        content.add(this.labelOccupation, null);

        this.fieldOccupation = new JTextField();
        this.fieldOccupation.setBounds(new Rectangle(160,210,120,25));
        content.add(this.fieldOccupation, null);


        labelText = "Nivel de Escolaridade:";
        this.labelSchool = new JLabel(labelText);
        this.labelSchool.setBounds(new Rectangle(1,250,300,25));
        content.add(this.labelSchool, null);

        String[] school = {"Nenhum", "Fundamental", "Medio", "Superior"};
        this.fieldSchool = new JComboBox(school);
        this.fieldSchool.setBounds(new Rectangle(160,250,120,25));
        this.fieldSchool.setSelectedIndex(0);
        content.add(this.fieldSchool, null);


        labelText = "Tatuagem:";
        this.labelTattoo = new JLabel(labelText);
        this.labelTattoo.setBounds(new Rectangle(1,290,300,25));
        content.add(this.labelTattoo, null);


        String[] tattos = {"Sim", "Nao"};
        this.fieldTattoo = new JComboBox(tattos);
        this.fieldTattoo.setBounds(new Rectangle(160,290,120,25));
        this.fieldTattoo.setSelectedIndex(0);
        content.add(this.fieldTattoo, null);


        labelText = "Numero de Brigas:";
        this.labelNumFights = new JLabel(labelText);
        this.labelNumFights.setBounds(new Rectangle(1,330,300,25));
        content.add(this.labelNumFights, null);

        this.fieldNumFights = new JSpinner();
        this.fieldNumFights.setBounds(new Rectangle(160,330,120,25));
        content.add(this.fieldNumFights, null);


        labelText = "Numero de Expulsoes:";
        this.labelNumExpulsions = new JLabel(labelText);
        this.labelNumExpulsions.setBounds(new Rectangle(1,370,300,25));
        content.add(this.labelNumExpulsions, null);

        this.fieldNumExpulsions = new JSpinner();
        this.fieldNumExpulsions.setBounds(new Rectangle(160,370,120,25));
        content.add(this.fieldNumExpulsions, null);



        this.buttonEndRegister = new JButton("Registrar");
        this.buttonEndRegister.setBounds(new Rectangle(1,410,100,25));
        content.add(this.buttonEndRegister, null);
       
        this.buttonEndRegister.setActionCommand("FIMREGISTRO");
        this.buttonEndRegister.addActionListener(this);

        
        setVisible(true);
        setSize(400, 500);

    }


    public void actionPerformed(ActionEvent e){
        String comando = (String) e.getActionCommand();
       
        if(comando.equals("FIMREGISTRO")){

            String name = this.fieldName.getText();
            String team = (String) this.fieldTeam.getSelectedItem();
            Date date = (Date) this.fieldDate.getValue();
            String cpf = this.fieldCpf.getText();
            String occupation = this.fieldOccupation.getText();
            String school = (String) this.fieldSchool.getSelectedItem();
            String tat = (String) this.fieldTattoo.getSelectedItem();
            boolean tattoo = (tat.equals("Sim")) ?true: false;
            int numFights = (Integer) this.fieldNumFights.getValue();
            int numExpulsions = (Integer) this.fieldNumExpulsions.getValue();
            
            //SimpleDateFormat formatter = new SimpleDateFormat("dd/MM/yyyy");
            //String dateBirth = formatter.format(date);

            Supporter sup = new Supporter(name, idCount, LoginWindow.functionaryName);
            sup.setTeam(team);
            sup.setDateBirth(date);
            sup.setCpf(cpf);
            sup.setOccupation(occupation);
            sup.setScholarityLevel(school);
            sup.setTattoo(tattoo);
            sup.setNumFights(numFights);
            sup.setNumExpulsions(numExpulsions);

            String nameok = name.replaceAll("\\s+", "");
            RegistrySupporter.Set(nameok, sup);
            idCount++;


            //String[] sups = RegistrySupporter.GetAll();
            //JOptionPane.showMessageDialog(null, Arrays.toString(sups));
            this.sw.fieldSupporter.setSelectedItem("Nenhum Torcedor Registrado");
            boolean removeCombo = (this.sw.fieldSupporter.getSelectedItem().equals("Nenhum Torcedor Registrado"));
            if(removeCombo)
                this.sw.fieldSupporter.removeItemAt(0);
            this.sw.fieldSupporter.addItem(name);
            
        }
       
    }

}

