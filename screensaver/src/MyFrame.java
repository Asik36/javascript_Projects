import javax.swing.JFrame;
import java.awt.Color;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.KeyEvent;
import java.util.Timer;
import java.util.TimerTask;

public class MyFrame extends JFrame implements KeyListener, MouseListener{

        

    MyFrame(){
        this.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        this.setUndecorated(true);
        this.setExtendedState(JFrame.MAXIMIZED_BOTH); 
        this.addKeyListener(this);
        this.addMouseListener(this);
        //this.setSize(420,420);
        this.getContentPane().setBackground(new Color(0,0,0));
        this.setLocationRelativeTo(null);
        this.setVisible(true);
        
    }
    public void hideTimer(){
        this.setVisible(false);
        Timer timer = new Timer();
        TimerTask task = new TimerTask(){
           
            @Override
            public void run() {
                setVisible(true);                
                timer.cancel();
            }
        };
        timer.schedule(task, 3000);
    }
    @Override
    public void keyTyped(KeyEvent e) {
        hideTimer();
    }
    @Override
    public void keyPressed(KeyEvent e) {

    }
    @Override
    public void keyReleased(KeyEvent e) {
     
    }

    @Override
    public void mouseClicked(MouseEvent e) {
        hideTimer();
    }
    @Override
    public void mousePressed(MouseEvent e) {
    }
    @Override
    public void mouseReleased(MouseEvent e) {
    }
    @Override
    public void mouseEntered(MouseEvent e) {
        hideTimer();
    }
    @Override
    public void mouseExited(MouseEvent e) {
        hideTimer();

    }
}
