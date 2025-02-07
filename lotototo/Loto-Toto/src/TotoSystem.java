import java.util.*;


// Enum for match results

// Class representing a single soccer match
class Match {
    private String homeTeam;
    private String awayTeam;
    private Map<MatchResult, Double> historicalProbabilities;

    public Match(String homeTeam, String awayTeam) {
        this.homeTeam = homeTeam;
        this.awayTeam = awayTeam;
        this.historicalProbabilities = new EnumMap<>(MatchResult.class);
    }

    public void setHistoricalProbabilities(double winProb, double drawProb, double loseProb) {
        historicalProbabilities.put(MatchResult.WIN, winProb);
        historicalProbabilities.put(MatchResult.DRAW, drawProb);
        historicalProbabilities.put(MatchResult.LOSE, loseProb);
    }

    public double getProbability(MatchResult result) {
        return historicalProbabilities.getOrDefault(result, 0.0);
    }

    @Override
    public String toString() {
        return homeTeam + " vs " + awayTeam;
    }
}


// Class representing a Toto form with multiple predictions
class TotoForm {
    private TreeSet<Team> teams;

    private static final int MATCHES_PER_FORM = 16;
    private static final int NUM_OF_PAST_GAMES = 5;

    public TotoForm() {
        int i = 1;
        teams = new TreeSet<Team>(); 
        Team t;
        for(i = 1; i <= MATCHES_PER_FORM; i++){
            t = new Team("Team "+ i,generateRandomMatchList());
            teams.add(t);
            
            
        }

       System.out.println(teams);
        
    }
    public ArrayList<MatchResult> generateRandomMatchList(){
        ArrayList<MatchResult> matches = new ArrayList<MatchResult>();
        for(int i = 0; i < NUM_OF_PAST_GAMES; i++){
            matches.add(generateRandomMatch());
        }
        return matches;
    }
    public MatchResult generateRandomMatch(){
        Random random = new Random();
        return MatchResult.values()[random.nextInt(MatchResult.values().length)];

    }
    

    
    
}

public class TotoSystem {
    public static void main(String[] args) {
        new TotoForm();
     
    }
}