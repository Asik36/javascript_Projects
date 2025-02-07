// Class representing a single soccer match
class TotoMatch {
    private String homeTeam;
    private String awayTeam;
    private Map<MatchResult, Double> historicalProbabilities;

    public TotoMatch(String homeTeam, String awayTeam) {
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
