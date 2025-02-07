import java.math.BigInteger;
import java.util.*;


public class LottoCanculator {
    private int max_numbers;
    private int numbers_per_combination;
    public LottoCanculator(int max_numbers, int numbers_per_combination){
        this.max_numbers = max_numbers;
        this.numbers_per_combination = numbers_per_combination;
    }



    
    public int calculateCombination(int n , int r) {
        int result = 1;
        for (int i = 1; i <= r; i++) {
            result = result * (n - i + 1) / i;
        }
        return result;
    }
    public int rangeCombination(int n , int r, int range){
        return calculateCombination(n, range)*(r-r%10);
    }
    public boolean isWithinRange(TreeSet<Integer> combination, int range) {

        int min = combination.first(); 
        int max = combination.last();   

        return (max - min) <= range;
    }
    

    public int evenCombinations(int n , int r) {
        return calculateCombination(n/2, r);
    }
    public boolean isEvenCombination(TreeSet<Integer> combination){
        for (Integer integer : combination) {
            if(integer%2 != 0) {
                return false;
        }
    }
    return true;

    }
 

    public int primeCombinations(int n , int r){
        int primeCount = 0;
        for (int i = 0; i < n; i++) {
            if(isPrime(i)){
                primeCount++;
            }
            
        }
        return calculateCombination(n-primeCount, 3)*calculateCombination(primeCount,3); 


    }
    public boolean isPrimeCombination(TreeSet<Integer> combination){
        int count = 3;
        for (Integer integer : combination) {
            if(isPrime(integer) && count > 0) {
                count--;
            }
        }
        return count == 0;
    }
    private boolean isPrime(int n){
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;

    }

}
