import javax.swing.*;
import java.awt.Color;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.concurrent.TimeUnit;


public class App {

    final static int WIDTH = 618;
    final static int HEIGHT = 612;
    public static void main(String[] args) throws Exception {
        startUpGame();
    }

    public static void startUpGame(){
        JFrame frame = new JFrame();
        MyPanel panel= new MyPanel();  
        MouseAdapter handler = new MouseAdapter() {
            
            int dX;
            int dY;
            boolean bool = false;

            @Override
        public void mousePressed(MouseEvent e) {
        //    System.out.println(e.getPoint());

            if (panel.contains(e.getPoint())) {
        
                panel.setBackground(Color.red);
                panel.setSpeedX(0);
                panel.setSpeedY(0);
                dX = e.getLocationOnScreen().x - panel.getX();
                dY = e.getLocationOnScreen().y - panel.getY();
                bool = true;
                panel.setDragged(true);
            }
        }
        @Override
        public void mouseReleased(MouseEvent e) {
            // TODO Auto-generated method stub
            panel.setBackground(Color.gray);
            bool=false;
            panel.setDragged(false);

        }

        @Override
        public void mouseDragged(MouseEvent e) {
            Point mousPoint = new Point(e.getLocationOnScreen().x - dX, e.getLocationOnScreen().y - dY);
            if (bool) {
                if(frame.contains(mousPoint) &&
                frame.contains(new Point(e.getLocationOnScreen().x - dX + panel.getWidth(), e.getLocationOnScreen().y - dY)) &&
                frame.contains(new Point(e.getLocationOnScreen().x - dX , e.getLocationOnScreen().y - dY+panel.getHeight()))){
                panel.setLocation(mousPoint);
                
                dX = e.getLocationOnScreen().x - panel.getX();
                dY = e.getLocationOnScreen().y - panel.getY();
                
        
                }
                
            }

        }
   
    };
    
        panel.setBounds(40,80,50,50);    
        panel.setBackground(Color.gray);  

        MyPanel panel2= new MyPanel();  
        panel2.setBounds(40,80,50,50);    
        panel2.setBackground(Color.gray);  
        panel2.addMouseMotionListener(handler);
        panel2.addMouseListener(handler);


       
        panel.addMouseMotionListener(handler);
        panel.addMouseListener(handler);
        
        frame.add(panel);
        frame.setSize(WIDTH,HEIGHT);
        frame.setLocationRelativeTo(null);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);

        int count =0;

        while (true) {
            

            panel.update(count,frame);
            try{
            TimeUnit.MILLISECONDS.sleep(10);
            }catch (InterruptedException e){

            }
            count++;            
        }

    }
}


