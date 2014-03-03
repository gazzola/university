import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.*;
import javax.swing.JFrame;
import java.util.*;
import java.text.SimpleDateFormat;
import java.util.Arrays;

public class SupporterRegisterWindow extends JFrame implements ActionListener {
   
    private JLabel labelName, labelTeam, labelDate, labelCpf, labelOccupation, labelSchool, labelTattoo, labelNumFights, labelNumExpulsions, 
                   labelHairSize, labelHairColor, labelPosTattoo, labelSkin, labelHeight, labelWeight, labelOrganizationSup;
    private JLabel labelNavigator, labelFunctionary;

    private JComboBox fieldTeam, fieldTattoo, fieldSchool, fieldHairSize, fieldHairColor, fieldSkin;
    private JSpinner fieldDate, fieldNumFights, fieldNumExpulsions;
    private JTextField fieldName, fieldOccupation, fieldCpf, fieldPosTattoo, fieldHeight, fieldWeight, fieldOrganizationSup;

    private JButton buttonEndRegister;
    private SupporterWindow sw;

    private static int idCount = 0;
    private int xLabelInit=1, yLabelInit=50,
                xFieldInit=160, yFieldInit=50,
                widthLabel=300, widthField=120;


    public SupporterRegisterWindow(SupporterWindow sw){

        super("SUPPORTER REGISTER WINDOW");

        Container content = getContentPane();
        content.setLayout(null);

        this.sw = sw;
        

        String labelText = "Login -> Supporters -> Register";
        this.labelNavigator = new JLabel(labelText);
        this.labelNavigator.setBounds(new Rectangle(1,10,300,25));        
        content.add(this.labelNavigator, null);

        labelText = "Logado como: "+LoginWindow.functionaryName;
        this.labelFunctionary = new JLabel(labelText);
        this.labelFunctionary.setBounds(new Rectangle(550,10,300,25));
        content.add(this.labelFunctionary, null);
       
        this.setFields(content);

        
        setVisible(true);
        setSize(800, 600);

    }


    private void setFields(Container content){

        String labelText = "Nome:";
        this.labelName = new JLabel(labelText);
        this.labelName.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelName, null);

        this.fieldName = new JTextField();
        this.fieldName.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldName, null);


        yLabelInit += 40;
        yFieldInit += 40;

        labelText = "Time:";
        this.labelTeam = new JLabel(labelText);
        this.labelTeam.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));        
        content.add(this.labelTeam, null);

        String[] teams = {"Caxias", "Gremio", "Internacional", "Juventude"};
        this.fieldTeam = new JComboBox(teams);
        this.fieldTeam.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        this.fieldTeam.setSelectedIndex(0);
        content.add(this.fieldTeam, null);


        yLabelInit += 40;
        yFieldInit += 40;

        labelText = "Data de Nascimento:";
        this.labelDate = new JLabel(labelText);
        this.labelDate.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelDate, null);

        Date now = new Date();  
        SpinnerDateModel model = new SpinnerDateModel(now, null, now, Calendar.DAY_OF_WEEK);  
        this.fieldDate = new JSpinner(model);
        this.fieldDate.setEditor(new JSpinner.DateEditor(this.fieldDate, "dd/MM/yyyy"));
        this.fieldDate.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldDate, null);


        yLabelInit += 40;
        yFieldInit += 40;

        labelText = "CPF:";
        this.labelCpf = new JLabel(labelText);
        this.labelCpf.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelCpf, null);

        this.fieldCpf = new JTextField();
        this.fieldCpf.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldCpf, null);


        yLabelInit += 40;
        yFieldInit += 40;

        labelText = "Ocupacao:";
        this.labelOccupation = new JLabel(labelText);
        this.labelOccupation.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelOccupation, null);

        this.fieldOccupation = new JTextField();
        this.fieldOccupation.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldOccupation, null);


        yLabelInit += 40;
        yFieldInit += 40;

        labelText = "Nivel de Escolaridade:";
        this.labelSchool = new JLabel(labelText);
        this.labelSchool.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelSchool, null);

        String[] school = {"Nenhum", "Fundamental", "Medio", "Superior"};
        this.fieldSchool = new JComboBox(school);
        this.fieldSchool.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        this.fieldSchool.setSelectedIndex(0);
        content.add(this.fieldSchool, null);


        yLabelInit += 40;
        yFieldInit += 40;

        labelText = "Tatuagem:";
        this.labelTattoo = new JLabel(labelText);
        this.labelTattoo.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelTattoo, null);


        String[] tattos = {"Sim", "Nao"};
        this.fieldTattoo = new JComboBox(tattos);
        this.fieldTattoo.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        this.fieldTattoo.setSelectedIndex(0);
        this.fieldTattoo.setActionCommand("VERTATUAGEM");
        this.fieldTattoo.addActionListener(this);
        content.add(this.fieldTattoo, null);


        yLabelInit += 40;
        yFieldInit += 40;

        labelText = "Numero de Brigas:";
        this.labelNumFights = new JLabel(labelText);
        this.labelNumFights.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelNumFights, null);

        this.fieldNumFights = new JSpinner();
        this.fieldNumFights.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldNumFights, null);


        yLabelInit += 40;
        yFieldInit += 40;

        labelText = "Numero de Expulsoes:";
        this.labelNumExpulsions = new JLabel(labelText);
        this.labelNumExpulsions.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelNumExpulsions, null);

        this.fieldNumExpulsions = new JSpinner();
        this.fieldNumExpulsions.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldNumExpulsions, null);



        // 2 COLUMN:

        this.resetCoords();
        xLabelInit += 400;
        xFieldInit += 400; 


        labelText = "Tamanho do Cabelo:";
        this.labelHairSize = new JLabel(labelText);
        this.labelHairSize.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelHairSize, null);

        String[] hairsize = {"Curto", "Medio", "Longo", "Nenhum"};
        this.fieldHairSize = new JComboBox(hairsize);
        this.fieldHairSize.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        this.fieldHairSize.setSelectedIndex(0);
        this.fieldHairSize.setActionCommand("VERCABELO");
        this.fieldHairSize.addActionListener(this);
        content.add(this.fieldHairSize, null);

        yLabelInit += 40;
        yFieldInit += 40;


        labelText = "Cor do Cabelo:";
        this.labelHairSize = new JLabel(labelText);
        this.labelHairSize.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelHairSize, null);

        String[] haircolor = {"Branco", "Preto", "Castanho", "Loiro", "Ruivo", "Outro"};
        this.fieldHairColor = new JComboBox(haircolor);
        this.fieldHairColor.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        this.fieldHairColor.setSelectedIndex(0);
        content.add(this.fieldHairColor, null);

        yLabelInit += 40;
        yFieldInit += 40;


        labelText = "Cor da Pele:";
        this.labelSkin = new JLabel(labelText);
        this.labelSkin.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelSkin, null);

        String[] skin = {"Muito clara", "Clara", "Caucasiano", "Escura", "Muito escura"};
        this.fieldSkin = new JComboBox(skin);
        this.fieldSkin.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        this.fieldSkin.setSelectedIndex(0);
        content.add(this.fieldSkin, null);

        yLabelInit += 40;
        yFieldInit += 40;
        

        labelText = "Altura:";
        this.labelHeight = new JLabel(labelText);
        this.labelHeight.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelHeight, null);

        this.fieldHeight = new JTextField("0");
        this.fieldHeight.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldHeight, null);

        yLabelInit += 40;
        yFieldInit += 40;


        labelText = "Peso:";
        this.labelWeight = new JLabel(labelText);
        this.labelWeight.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelWeight, null);

        this.fieldWeight = new JTextField("0");
        this.fieldWeight.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldWeight, null);

        yLabelInit += 40;
        yFieldInit += 40;


        labelText = "Torcida Orgnizada:";
        this.labelOrganizationSup = new JLabel(labelText);
        this.labelOrganizationSup.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelOrganizationSup, null);

        this.fieldOrganizationSup = new JTextField();
        this.fieldOrganizationSup.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldOrganizationSup, null);

        yLabelInit += 40;
        yFieldInit += 40;


        labelText = "Posicao da Tatuagem:";
        this.labelPosTattoo = new JLabel(labelText);
        this.labelPosTattoo.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.labelPosTattoo, null);

        this.fieldPosTattoo = new JTextField();
        this.fieldPosTattoo.setBounds(new Rectangle(xFieldInit,yFieldInit,widthField,25));
        content.add(this.fieldPosTattoo, null);
        
        yLabelInit += 40;
        yFieldInit += 40;


        this.buttonEndRegister = new JButton("Registrar");
        this.buttonEndRegister.setBounds(new Rectangle(xLabelInit,yLabelInit,widthLabel,25));
        content.add(this.buttonEndRegister, null);
       
        this.buttonEndRegister.setActionCommand("FIMREGISTRO");
        this.buttonEndRegister.addActionListener(this);
    }


    public void actionPerformed(ActionEvent e){
        String comando = (String) e.getActionCommand();
       
        if(comando.equals("FIMREGISTRO")){
            try{
                this.saveDatas();
                this.replaceSwCombo();
            }
            catch(EmptyFieldException efe){
                String msg = "ERRO! "+efe;
                JOptionPane.showMessageDialog(null, msg);
            }
            catch(NegativeNumberException nne){
                String msg = "ERRO! "+nne;
                JOptionPane.showMessageDialog(null, msg);
            }
            catch(NumberFormatException nfe){
                String msg = "ERRO! NumberFormatException: campo `altura` ou `peso` fora do formato";
                if(nfe.getMessage().equals("empty String"))
                    msg = "ERRO! NumberFormatException: campo `altura` ou `peso` vazio"; 
                JOptionPane.showMessageDialog(null, msg);
            }
            catch(SupporterAlreadyRegisteredException sare){
                String msg = "ERRO! "+sare;
                JOptionPane.showMessageDialog(null, msg);
            }
            catch(Exception ex){
                String msg = "ERRO! "+ex;
                JOptionPane.showMessageDialog(null, msg);
            }
        }
        else if(comando.equals("VERTATUAGEM")){
            String tat = (String) this.fieldTattoo.getSelectedItem();
            this.fieldPosTattoo.setEditable(!tat.equals("Nao"));
        }
       
    }


    private void saveDatas() throws EmptyFieldException, NegativeNumberException, NumberFormatException, SupporterAlreadyRegisteredException{
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
        String hairSize = (String) this.fieldHairSize.getSelectedItem();
        String hairColor = (String) this.fieldHairColor.getSelectedItem();
        String skin = (String) this.fieldSkin.getSelectedItem();
        double height = Double.parseDouble(this.fieldHeight.getText());
        double weight = Double.parseDouble(this.fieldWeight.getText());
        String organizationSup = this.fieldOrganizationSup.getText();
        String posTattoo = (tattoo) ? this.fieldPosTattoo.getText() : "Sem tatuagem";

        if(name.equals(""))
            throw new EmptyFieldException("Campo `nome` vazio");
        else if(cpf.equals(""))
            throw new EmptyFieldException("Campo `CPF` vazio");
        else if(occupation.equals(""))
            throw new EmptyFieldException("Campo `ocupacao` vazio");
        else if(organizationSup.equals(""))
            throw new EmptyFieldException("Campo `torcida organizada` vazio");


        if(numFights < 0)
            throw new NegativeNumberException("Campo `numero de brigas` negativo");
        else if(numExpulsions < 0)
            throw new NegativeNumberException("Campo `numero de expulsoes` negativo");
        else if(height < 0)
            throw new NegativeNumberException("Campo `altura` negativo");
        else if(weight < 0)
            throw new NegativeNumberException("Campo `peso` negativo");



        Supporter sup = new Supporter(name, idCount, LoginWindow.functionaryName);
        sup.setTeam(team);
        sup.setDateBirth(date);
        sup.setCpf(cpf);
        sup.setOccupation(occupation);
        sup.setScholarityLevel(school);
        sup.setTattoo(tattoo);
        sup.setNumFights(numFights);
        sup.setNumExpulsions(numExpulsions);
        sup.setHairSize(hairSize);
        sup.setHairColor(hairColor);
        sup.setPosTattoo(posTattoo);
        sup.setSkin(skin);
        sup.setHeight(height);
        sup.setWeight(weight);
        sup.setOrganizationSup(organizationSup);

        String nameok = name.replaceAll("\\s+", "");
        if(!RegistrySupporter.isSet(name)){
            RegistrySupporter.Set(nameok, sup);
            idCount++;
        }
        else
            throw new SupporterAlreadyRegisteredException("Torcedo ja existente, por favor troque o nome dele");
        
    }


    private void replaceSwCombo(){
        this.sw.fieldSupporter.setSelectedItem("Nenhum Torcedor Registrado");
        boolean removeCombo = (this.sw.fieldSupporter.getSelectedItem().equals("Nenhum Torcedor Registrado"));
        if(removeCombo)
            this.sw.fieldSupporter.removeItemAt(0);
        this.sw.fieldSupporter.addItem(this.fieldName.getText());
    }


    private void resetCoords(){
        xLabelInit=1;
        yLabelInit=50;
        xFieldInit=160;
        yFieldInit=50; 
        widthLabel=300;
        widthField=120;
    }

}

