public enum MatchResult {
    WIN(1),
    DRAW(0),
    LOSE(-1);

    private final int symbol;

    MatchResult(int symbol) {
        this.symbol = symbol;
    }

    public int getSymbol() {
        return symbol;
    }
}
