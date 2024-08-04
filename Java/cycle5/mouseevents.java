import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class mouseevents implements MouseListener,ActionListener
{
    static JFrame frame;
    static JTextField text;
    public static void main(String[] args)
    {
        frame = new JFrame("Mouse Event Recogniser");
        frame.setBackground(Color.white);
        frame.setSize(500,500);
        frame.setLayout(null);
        text = new JTextField();
        text.setBounds(0,0,500,50);
        frame.add(text);
        JButton exit = new JButton("Exit");
        exit.setBounds(200,400,60,30);
        frame.add(exit);
        mouseevents obj = new mouseevents();
        frame.addMouseListener(obj);
        exit.addActionListener(obj);
        frame.setVisible(true);

    }

    @Override

    public void actionPerformed(ActionEvent e)
    {
        frame.dispose();
    }
    @Override

    public void mouseEntered(MouseEvent e)
    {
        text.setText("");
        text.setText("Current Status: Mouse entered the frame from point ");
        text.setText(text.getText()+"("+e.getX()+","+e.getY()+")");
    }
    @Override
    public void mouseExited(MouseEvent e)
    {
        text.setText("");
        text.setText("Current Status: Mouse exited the frame from point ");    
        text.setText(text.getText()+"("+e.getX()+","+e.getY()+")");
    }
    @Override
    public void mouseReleased(MouseEvent e)
    {
        text.setText("");
        String button="Right";
        if(e.getButton() == MouseEvent.BUTTON1)
            button = "Left";
        text.setText("Current Status: "+button + " button released at point ");
        text.setText(text.getText() +"("+e.getX() + "," + e.getY()+")");
    }
    @Override
    public void mousePressed(MouseEvent e)
    {
        text.setText("");
        String button = "Right";
        if(e.getButton() == MouseEvent.BUTTON1)
            button = "Left";
        text.setText("Current Status: "+button + " button pressed at point ");
        text.setText(text.getText() +"("+ e.getX() + "," + e.getY()+")");    
    }
    @Override
    public void mouseClicked(MouseEvent e)
    {
        text.setText("");
        String button = "Right";
        if(e.getButton() == MouseEvent.BUTTON1)
            button = "Left";
        text.setText("Current Status: "+button + " button clicked at point ");
        text.setText(text.getText() +"("+ e.getX() + " " + e.getY()+")");    
    }

}
 

