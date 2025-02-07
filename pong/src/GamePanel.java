import java.awt.*;
import java.awt.event.*;
import java.util.*;
import javax.swing.*;

public class GamePanel extends JPanel implements Runnable {
    static final int GAME_WIDTH = 1000;
	static final int GAME_HEIGHT = (int)(GAME_WIDTH * (0.5555));
	static final Dimension SCREEN_SIZE = new Dimension(GAME_WIDTH,GAME_HEIGHT);
    static final int Ball_DIMETER = 20;
    

    GamePanel(){
        this.setPreferredSize(SCREEN_SIZE);
        this.setFocusable(true);
        
    }


    public void newBall(){

    }
    public void newPaddles(){

    }
    public void paint(Graphics g){

    }
    public void draw(Graphics g){
        
    }
    public void move(){

    }
    public void checkColliesion(){

    }
    public void run(){

    }
    public class AL extends KeyAdapter{
        public void keyPressed(KeyEvent e){

        }
        public void keyReleased(KeyEvent e){
            
        }

    }
}
