import java.awt.*;
import java.awt.event.*;

public class keyevents extends MouseMotionAdapter{
	Frame f;
	keyevents(){
		f = new Frame("Mouse Motion Adapter");
		f.addMouseMotionListener(this);
		f.setSize(400,400);
		f.setLayout(null);
		f.setVisible(true);
	}
	public void mouseDragged(MouseEvent e) {
		Graphics g = f.getGraphics();
		g.setColor(Color.RED);
		g.fillOval(e.getX(),e.getY(),20,20);
	}
	public static void main(String[] args) {
		new keyevents();
	}
}

