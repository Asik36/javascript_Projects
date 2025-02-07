import java.util.Random;
public class App {
    public static void main(String[] args) throws Exception {
        Random rnd = new Random();
        int[] arr = new int[rnd.nextInt(5) + 5];
        int a = 0;
        for (int i = 0 ; i < arr.length; i++){
            arr[i] = rnd.nextInt(10)+1;
            System.out.print(arr[i] + ", ");
            a += arr[i];
        }
        
     System.out.println();

    System.out.println(a);

    }
}
// [0,4,2,6,4,3,6,7]
//  0 1 2 3 4 5 6 7