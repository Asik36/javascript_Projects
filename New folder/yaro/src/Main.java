
import java.util.*;
import java.util.Scanner;

public class Main {
    private static final int LOTTO_MAX_NUMBER = 41; // Max number for Lotto
    private static final int NUMBERS_PER_COMBINATION = 6; // Numbers per Lotto selection
    private static List<Set<Integer>> allCombinations = new ArrayList<>();
    private static List<Set<Integer>> allConsecutive = new ArrayList<>();
    private static List<Set<Integer>> allMultiplication = new ArrayList<>();
    private static List<Set<Integer>> allSameFirst = new ArrayList<>();
    private static List<Set<Integer>> allSameLast = new ArrayList<>();
    private static List<Set<Integer>> allSameDifference = new ArrayList<>();

    private static Lotto validator = new Lotto();

    // checking 3 numbers with the same difference in number for example(5, 8, 11)
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean running = true;

        while (running) {
            System.out.println("Welcome to the Lottery App!");
            System.out.println("Please select an option:");
            System.out.println("1. Play Lotto");
            System.out.println("2. Play Toto");
            System.out.println("3. Exit");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    playLotto(scanner);  // Pass scanner to playLotto
                    break;
                case 2:
                    playToto();
                    break;
                case 3:
                    System.out.println("Thank you for using the Lottery App!");
                    running = false;
                    break;
                default:
                    System.out.println("Invalid choice, please try again.");
                    break;
            }
        }

        scanner.close();
    }

    public static void playLotto(Scanner scanner) {
        System.out.println("You selected Lotto!");

        // Generate all combinations
        generateCombinations(new HashSet<>(), 1);

        // Print sorted combinations with their probabilities
        for (Set<Integer> combo : allCombinations) {
            double probability = calculateProbability(combo);
            System.out.println("Combination: " + combo + ", Probability: " + probability + "%");
        }

        System.out.println("Total combinations generated: " + allCombinations.size());
        System.out.println("Total First generated: " + allSameFirst.size());
        System.out.println("Total Last generated: " + allSameLast.size());
        System.out.println("Total Consecutive generated: " + allConsecutive.size());
        System.out.println("Total Multiplication generated: " + allMultiplication.size());
        System.out.println("Total Diffrence generated: " + allSameDifference.size());
    }

    // Recursive method to generate combinations
    private static void generateCombinations(Set<Integer> currentCombination, int start) {
        if (currentCombination.size() == NUMBERS_PER_COMBINATION) {
            allCombinations.add(new HashSet<>(currentCombination));

            // Use the validator instance for all checks
            if (validator.checkConsecutive(currentCombination)) {
                allConsecutive.add(new HashSet<>(currentCombination));
            }
            if (validator.checkMultiplication(currentCombination)) {
                allMultiplication.add(new HashSet<>(currentCombination));
            }
            if (validator.checkSameFirst(currentCombination)) {
                allSameFirst.add(new HashSet<>(currentCombination));
            }
            if (validator.checkSameLast(currentCombination)) {
                allSameLast.add(new HashSet<>(currentCombination));
            }
            if (validator.checkSameDifference(currentCombination)) {
                allSameDifference.add(new HashSet<>(currentCombination));
            }

            return; // Return when we reach 6 numbers
        }

        // Iterate over numbers to build combinations
        for (int i = start; i <= LOTTO_MAX_NUMBER; i++) {
            currentCombination.add(i); // Add current number
            generateCombinations(currentCombination, i + 1); // Recur with the next number
            currentCombination.remove(i); // Remove number to backtrack
        }
    }


    public static double calculateProbability(Set<Integer> combo) {
        double score = 1.0; // Start with a baseline score of 1.0 (indicating a "neutral" probability)

        // Adjust the score based on detected patterns. Higher penalties for less desirable patterns
        if (validator.checkConsecutive(combo)) score *= 1.4;    // Penalize consecutive numbers
        if (validator.checkMultiplication(combo)) score *= 1.2; // Penalize multiplication patterns
        if (validator.checkSameFirst(combo)) score *= 1.15;     // Penalize same tens digit pattern
        if (validator.checkSameLast(combo)) score *= 1.15;      // Penalize same units digit pattern
        if (validator.checkSameDifference(combo)) score *= 1.3; // Penalize same difference pattern

        return 1 / score; // Return inverse so lower scores mean "better" combinations
    }
    public static Map<Set<Integer>, Double> calculateAllProbabilities(List<Set<Integer>> combinations) {
        Map<Set<Integer>, Double> probabilities = new HashMap<>();
        double totalScore = 0;

        // Step 1: Calculate raw scores and total score
        for (Set<Integer> combo : combinations) {
            double score = calculateProbability(combo);
            probabilities.put(combo, score);
            totalScore += score;
        }

        // Step 2: Normalize each score to a probability
        for (Set<Integer> combo : probabilities.keySet()) {
            double normalizedProbability = (probabilities.get(combo) / totalScore) * 100; // Convert to percentage
            probabilities.put(combo, normalizedProbability);
        }

        return probabilities;
    }



    public static void playToto() {
        // Placeholder for Toto game logic
        System.out.println("You selected Toto! Implement Toto logic here.");
    }
}

