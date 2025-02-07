import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;
import java.util.TreeSet;

public class LottoGame {
    private static final int MAX_NUMBER = 49;
    private static final int NUMBERS_PER_COMBINATION = 6; 
    LottoCanculator LottoCanculator;
    HashSet<TreeSet<Integer>> history;
    HashSet<TreeSet<Integer>> userInputs;

    LottoGame(){
        LottoCanculator = new LottoCanculator( MAX_NUMBER , NUMBERS_PER_COMBINATION);
        history = getRandomTickets(10);
        userInputs = new HashSet<TreeSet<Integer>>();
    }
    public void gameLoop(){
        int oddsOfEvenCombinations = 0;
        int oddsOfallCombinations = 0;
        int primeCombinations = 0;
        int rangeCombination = 0;
        boolean isExit = false;
        System.out.println("wellcome to lotto!");
        System.out.println("prvious combinations:");
        printHashSet(history);

        while (!isExit) {
        System.out.println("enter \"0\" to exit");
        System.out.println("Please enter a Combination of " + NUMBERS_PER_COMBINATION + " (betweeen 1 and " + MAX_NUMBER + ")");
        Scanner input = new Scanner(System.in);
        int userInput = 0;
        TreeSet<Integer> userCombination = new TreeSet<Integer>();
        int count = NUMBERS_PER_COMBINATION;

        

        while(count > 0){
            userInput = input.nextInt();
            if(userInput== 0){
                isExit = true;
                break;
            }
            if(userInput <= 0 || userInput > MAX_NUMBER || userCombination.contains(userInput)){
                System.out.println("Invalid number! Please enter a number between 1 and 49");
            }else{
                userCombination.add(userInput);
                count--;
            }
            
        }
        userInputs.add(userCombination);
        
        if(!isExit){
                oddsOfallCombinations = LottoCanculator.calculateCombination(MAX_NUMBER,NUMBERS_PER_COMBINATION)/userInputs.size();

            System.out.println("there is 1 in " + oddsOfallCombinations+ " chances of getting this combination!");
            
            if(LottoCanculator.isEvenCombination(userCombination)){
                oddsOfEvenCombinations = LottoCanculator.evenCombinations(MAX_NUMBER,NUMBERS_PER_COMBINATION)/userInputs.size();
                System.out.println("there is 1 in " + oddsOfEvenCombinations + " chances of getting this combination using even filter!");
            }else{
                System.out.println("even filter has 0 chance of getting this combination");
            }
            if(LottoCanculator.isPrimeCombination(userCombination)){
                primeCombinations = LottoCanculator.primeCombinations(MAX_NUMBER, NUMBERS_PER_COMBINATION)/userInputs.size();
                System.out.println("there is 1 in " + primeCombinations + " chances of getting this combination using prime filter!");
            } else{
                System.out.println("range filter has 0 chance of getting this combination");
            }
            if(LottoCanculator.isWithinRange(userCombination,10)){
                rangeCombination = LottoCanculator.rangeCombination(MAX_NUMBER, NUMBERS_PER_COMBINATION,10)/userInputs.size();
                System.out.println("there is 1 in " + rangeCombination + " chances of getting this combination using range filter!");
            } else{
                System.out.println("range filter has 0 chance of getting this combination");
            }
        }
    }
}


    public HashSet<TreeSet<Integer>> getRandomTickets(int num){
        Random random = new Random();
        HashSet<TreeSet<Integer>> hashSet = new HashSet<TreeSet<Integer>>();
        for(int i = 0; i < num; i++){
            TreeSet<Integer> ticket = new TreeSet<Integer>();
            while(ticket.size() < 6){
                ticket.add(random.nextInt(49) + 1);
            }
        hashSet.add(ticket);
        }
        return hashSet;
    }
    public void printHashSet(HashSet<TreeSet<Integer>> hashSet){
        for(TreeSet<Integer> ticket : hashSet){
            System.out.println(ticket);
        }
       
    }

    public double calculatePercentage(double a,double b) {
        if(b ==0){
            return 0;
        }
        return ((a / b) * 100);
    }
    


}
