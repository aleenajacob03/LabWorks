import java.awt.*; 
import java.awt.event.*; 
import javax.swing.*;
class buildCalculator extends JFrame implements ActionListener{
    JFrame window;
    JPanel buttonPanel,resultPanel;
    JButton[] button=new JButton[10];
    JButton addBtn, subBtn, mulBtn, modBtn, eqBtn,delBtn;
    JLabel exp;
    JTextField result;
    int op1, op2;
    String op,number;
    buildCalculator(){
        Font txtFont=new Font("SansSerif", Font.BOLD, 20);
        window=new JFrame("Calculator");
        window.setBounds(300, 500, 300, 500);
        window.setLayout(new GridLayout(2,1));
        buttonPanel=new JPanel();
        resultPanel=new JPanel();
        exp=new JLabel();
        result=new JTextField("");
        result.setFont(txtFont);
        result.setEditable(false);
        for (int i=0;i<10;i++) {
            button[i]=new JButton(""+i);
            button[i].addActionListener(this);
        }
        for (int i=1;i<=3;i++) {
            buttonPanel.add(button[i]);
        }
        addBtn=new JButton("+");
        addBtn.addActionListener(this);
        buttonPanel.add(addBtn);
        for (int i=4;i<=6;i++) {
            buttonPanel.add(button[i]);
        }
        subBtn=new JButton("-");
        subBtn.addActionListener(this);
        buttonPanel.add(subBtn);
        for (int i=7;i<=9;i++) {
            buttonPanel.add(button[i]);
        }
        mulBtn=new JButton("*");
        mulBtn.addActionListener(this);
        buttonPanel.add(mulBtn);
        modBtn=new JButton("%");
        modBtn.addActionListener(this);
        buttonPanel.add(modBtn);
        buttonPanel.add(button[0]);
        delBtn=new JButton("DEL");
        delBtn.addActionListener(this);
        buttonPanel.add(delBtn);
        eqBtn=new JButton("=");
        eqBtn.addActionListener(this);
        buttonPanel.add(eqBtn);
        buttonPanel.setLayout(new GridLayout(4, 4));
        resultPanel.add(result);
        resultPanel.add(exp);
        resultPanel.setLayout(new GridLayout(4,1));
        window.add(resultPanel);
        window.add(buttonPanel);
        window.setVisible(true);
    }
    public void actionPerformed(ActionEvent e) {
        String s=e.getActionCommand();
        System.out.print(s);
        if (Character.isDigit(s.charAt(0)) || e.getActionCommand()=="."){ 
            number=result.getText()+s;
            result.setText(number);
        }
        else if (s.charAt(0)!='=' && !s.equals("DEL")){
            op1=Integer.parseInt(result.getText());
            op=s;
            exp.setText(op1+op);
            result.setText("");
        } 
        else if (s.charAt(0)=='='){
            op2=Integer.parseInt(result.getText());
            exp.setText((exp.getText())+""+op2);
            switch(op) {
                case ("+"):result.setText(""+(op1+op2));
                            break;
                case ("-"):result.setText(""+(op1-op2)); 
                            break;
                case ("*"):result.setText(""+(op1*op2)); 
                            break;
                case ("%"): try {
                                if(op2==0)
                                    throw new ArithmeticException();
                                    result.setText(""+(op1%op2)); 
                                    break;
                            }
                            catch(ArithmeticException ae) {
                                    JOptionPane.showMessageDialog(window, "Division by zero not possible");
                            }
            }
        } 
        else if(s.equals("DEL")){
            result.setText("");
        }
    }
}
public class calculator{
    public static void main(String[] args) {
        buildCalculator calc=new buildCalculator();
    }
}
