import javax.swing.JFrame;
import java.awt.Color;


public class App {
    int WAIT_TIME = 3000;

    public static void main(String[] args) throws Exception {
        MyFrame frame = new MyFrame();
           
        

    }
    public boolean makeBricks(int small, int big, int goal) {
        boolean a = true;
          if(goal == 0){
          return true;
        }
        if(goal-big => 0){
          goal -= big;
          big -=1;
          a = false;
        }
        if(goal-samll => 0){
          goal -= small;
          small -=1;
          a = false;
        }
        if(a){
          return false;
        }
      
        return makeBricks(small,big,goal);
      }
}
