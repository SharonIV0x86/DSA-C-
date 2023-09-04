#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MATCH_SCORE = 1;
const int MISMATCH_SCORE = -1;
const int GAP_SCORE = -2;

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

int needlemanWunsch(const string& seq1, const string& seq2) {
    int m = seq1.length();
    int n = seq2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i * GAP_SCORE;
    }

    for (int j = 0; j <= n; j++) {
        dp[0][j] = j * GAP_SCORE;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int match = dp[i - 1][j - 1] + (seq1[i - 1] == seq2[j - 1] ? MATCH_SCORE : MISMATCH_SCORE);
            int gapSeq1 = dp[i - 1][j] + GAP_SCORE;
            int gapSeq2 = dp[i][j - 1] + GAP_SCORE;
            dp[i][j] = max(match, gapSeq1, gapSeq2);
        }
    }

    return dp[m][n];
}

int main() {
    string sequence1 = "ACGT";
    string sequence2 = "AGCT";

    int alignmentScore = needlemanWunsch(sequence1, sequence2);

    cout << "Alignment Score: " << alignmentScore << endl;

    return 0;
}
