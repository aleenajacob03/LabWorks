import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
class build extends JFrame implements ActionListener{
    JFrame window;
    JPanel red,yellow,green,buttons,lights;
    JRadioButton rBtn,yBtn,gBtn;
    ButtonGroup bg=new ButtonGroup();
    Font txtFont=new Font("SansSerif", Font.BOLD, 30);
    build(){
        window=new JFrame("Traffic Lights Colour Generator");
        window.setSize(600,400);
        window.setLayout(new GridLayout(2,1));
        red=new JPanel();
        red.setSize(200,200);
        yellow=new JPanel();
        yellow.setSize(200,200);
        green=new JPanel();
        green.setSize(200,200);
        lights=new JPanel();
        lights.setLayout(new GridLayout(1,3));
        lights.add(red);
        lights.add(yellow);
        lights.add(green);
        buttons=new JPanel();
        buttons.setSize(300,100);
        rBtn=new JRadioButton("Red");
        gBtn=new JRadioButton("Green");
        yBtn=new JRadioButton("Yellow");
        rBtn.setFont(txtFont);
        gBtn.setFont(txtFont);
        yBtn.setFont(txtFont);
        bg.add(rBtn);
        bg.add(yBtn);
        bg.add(gBtn);
        buttons.add(rBtn);
        buttons.add(yBtn);
        buttons.add(gBtn);
        rBtn.addActionListener(this);
        gBtn.addActionListener(this);
        yBtn.addActionListener(this);
        window.add(lights);
        window.add(buttons);
        window.setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
        String s=e.getActionCommand();
        red.setBackground(null);
        green.setBackground(null);
        yellow.setBackground(null);
        System.out.println(s);
        if(s.equals("Red")){
            red.setBackground(new Color(255,0,0));
        }
        if(s.equals("Green")){
            green.setBackground(new Color(71, 237, 85));
        }
        if(s.equals("Yellow")){
            yellow.setBackground(new Color(230, 207, 0));
        }
    }
}
public class traffic {
    public static void main(String[] args) {
        build traffic=new build();
    }
}
