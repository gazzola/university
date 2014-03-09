import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.*;
import javax.swing.JFrame;
import java.util.*;

public class LoginWindow extends JFrame implements ActionListener {
   
    private JLabel labelUser, labelPass, labelNavigator;
    private JTextField fieldUser;
    private JPasswordField fieldPass;
    private JButton buttonSign, buttonExit;
    public static String functionaryName;

    public LoginWindow(){

        super("LOGIN WINDOW");
       
        Container content = getContentPane();
        content.setLayout(null);
       
        Font font = new Font("Serif", Font.PLAIN, 30);
        content.setFont(font);   

       
        String labelText = "Login";
        this.labelNavigator = new JLabel(labelText);
        this.labelNavigator.setBounds(new Rectangle(1,10,200,25));
        content.add(this.labelNavigator, null);
       
        labelText = "Usuario:";
        this.labelUser = new JLabel(labelText);
        this.labelUser.setBounds(new Rectangle(1,50,100,25));
        content.add(this.labelUser, null);

        labelText = "Senha:";
        this.labelPass = new JLabel(labelText);
        this.labelPass.setBounds(new Rectangle(1,90,100,25));
        content.add(this.labelPass, null);



        this.fieldUser = new JTextField();
        this.fieldUser.setBounds(new Rectangle(80,50,120,25));
        content.add(this.fieldUser, null);

        this.fieldPass = new JPasswordField(10);
        this.fieldPass.setBounds(new Rectangle(80,90,120,25));
        content.add(this.fieldPass, null);

       

        this.buttonSign = new JButton("Entrar");
        this.buttonSign.setBounds(new Rectangle(1,150,100,25));
        content.add(this.buttonSign, null);
       
        this.buttonSign.setActionCommand("OK");
        this.buttonSign.addActionListener(this);

       
        this.buttonExit = new JButton("Sair");
        this.buttonExit.setBounds(new Rectangle(110,150,100,25));
        content.add(this.buttonExit, null);
       
        this.buttonExit.setActionCommand("EXIT");
        this.buttonExit.addActionListener(this);
    
       
        setVisible(true);
    }


    public void actionPerformed(ActionEvent e){
        String comando = (String) e.getActionCommand();
       
        if(comando.equals("EXIT")){
            System.exit(1);
        }
        else if(comando.equals("OK")){

            String user = this.fieldUser.getText();
            String pass = new String(this.fieldPass.getPassword());

            if(!RegistryFunctionary.isSet(user))
                JOptionPane.showMessageDialog(null, "Usuario ou Senha Incorretos!!");
            else if(RegistryFunctionary.Get(user).equals(pass)){
                this.functionaryName = user;
                new SupporterWindow();
            }
            else
                JOptionPane.showMessageDialog(null, "Usuario ou Senha Incorretos!");
        }
    }


    public static void main(String[] args){        
        RegistryFunctionary.Set("mark", "mark");
        RegistryFunctionary.Set("jose", "jose");

        LoginWindow janela = new LoginWindow();
        janela.setSize(400, 400);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
    }

}
