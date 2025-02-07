import javax.swing.*;
import java.awt.Color;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.concurrent.TimeUnit;
import java.util.Objects;


public class MyPanel extends JPanel {
    double speedX, speedY;
    boolean Dragged;
    Point lastLocation;
    int lastTime;
    int lastTick;


    public MyPanel() {
        lastTime = 0;
        lastLocation = this.getLocation();
    }

    public void update(int count,JFrame frame){
        if(!this.getDragged()){   
            this.setLocation((int)(this.getX()+this.getSpeedX()), (int)(this.getY()+this.getSpeedY()));
            }
        int deltaX = (this.getLocation().x - lastLocation.x); 
        int deltaY = (this.getLocation().y - lastLocation.y); 
        int deltaT = 0;
        if(lastLocation.x != this.getLocation().x && lastLocation.y != this.getLocation().y && count != lastTime){
        deltaT = (int) (count - lastTime);
        speedX = deltaX/deltaT;
        speedY = deltaY/deltaT;
        System.out.println(
            " speed x: " + speedX + " speed y: " + speedY
            +" deltaT: " + deltaT + " lastLocation (" + lastLocation.x + " , " + lastLocation.y + ")" +
            "("+this.getLocation().x + " , "+ this.getLocation().y+") " + deltaX + " "+deltaY
        );
        }else{speedX = 0;speedY = 0;}

            if(this.getLocation().x <=0 || this.getLocation().x+this.getWidth() >= frame.getWidth()){
                speedX = -speedX;
            }
            if(this.getLocation().y <=0 || this.getLocation().y+this.getHeight() >= frame.getHeight()){
                speedY = -speedY;
            }
            if (count%30==0 && (speedX != 0 || speedY != 0)){
                if(Math.abs(speedX)>Math.abs(speedY)){
                    if(speedX>0){
                    speedX -= 1;
                    }else{
                        speedX+=1;
                    }
                    if(speedY>0){
                        speedY -= 1;
                        }else{
                            speedY += 1;
                        }
                }else{
                    if(speedY>0){
                        speedY -= 1;
                        }else{
                            speedY+=1;
                        }
                        if(speedX>0){
                            speedX -= 1;
                        }else{
                            speedX += 1;
                        }
                }

            }
            

            
            


        
        lastTime = count;
        lastLocation = this.getLocation();

    }

    public boolean isDragged() {
        return this.Dragged;
    }

    public Point getLastLocation() {
        return this.lastLocation;
    }

    public void setLastLocation(Point lastLocation) {
        this.lastLocation = lastLocation;
    }



    public double getSpeedX() {
        return this.speedX;
    }

    public void setSpeedX(double speedX) {
        this.speedX = speedX;
    }

    public double getSpeedY() {
        return this.speedY;
    }

    public void setSpeedY(int speedY) {
        this.speedY = speedY;
    }


    public boolean getDragged() {
        return this.Dragged;
    }

    public void setDragged(boolean isDragged) {
        this.Dragged = isDragged;
    }



   
  




}
