import java.awt.*;
import java.awt.event.*;
class drawing extends Frame{
	drawing(){
		setTitle("Drawing Shapes");
		setSize(500,500);
		setVisible(true);
	}
	public static void main(String[] args){
		new drawing();
	}
	public void paint(Graphics g){
		g.drawLine(100,80,350,80);
		g.drawRect(140,140,50,100);
		g.drawOval(140,340,100,80);
	}
}
 


