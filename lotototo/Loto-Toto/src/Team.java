import java.util.ArrayList;
import java.util.List;


public class Team implements Comparable<Team>{
        private String name;
        private List<MatchResult> matches;
        private Prediction probabilities;
        public Team(String name, ArrayList<MatchResult> matches){
            this.name = name;
            this.matches = matches;
            this.probabilities = winningOdds();
        }
        public Prediction winningOdds(){
            int win = 0;
            int lose = 0;
            int draw = 0;
            
            for (MatchResult matchResult : matches) {
                if(matchResult == MatchResult.WIN){
                    win++;
                }else if(matchResult == MatchResult.LOSE){
                    lose++;
                }else{
                    draw++;
                }
            }
            return new Prediction(win, lose, draw, matches.size());
        }
        public String getName(){
            return name;
        }
        public Prediction getProbabilities(){
            return probabilities;
        }
        public List<MatchResult> getMatches(){
            return matches;
        }

    @Override
    public String toString() {
        return "{" +
            " name='" + getName() + "'" +
            ", matches='" + getMatches() + "'" +
            ", probabilities='" + getProbabilities() + "'" +
            "}";
    }

       
        @Override
        public int compareTo(Team o) {
        if(this.probabilities.winChance > o.probabilities.winChance)
            return 1;
        if(this.probabilities.winChance < o.probabilities.winChance)
            return -1;

        return 0;

        }

}
