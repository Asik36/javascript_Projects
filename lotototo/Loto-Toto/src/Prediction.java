public class Prediction{
    double winChance;
    double drawChance;
    double loseChance;
    public Prediction(int wins, int draws, int loses, int numOfGames){
        this.winChance = (winChance/numOfGames)*100;
        this.drawChance = (drawChance/numOfGames)*100;
        this.loseChance = (loseChance/numOfGames)*100;
    }


}