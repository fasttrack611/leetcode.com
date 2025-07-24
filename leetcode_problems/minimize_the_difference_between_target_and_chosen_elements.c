int minimizeTheDifference(int** mat, int matSize, int* matColSize, int target) {
    bool dp[5001] = {false};
    dp[0] = true;

    for (int i = 0; i < matSize; i++) {
        bool new_dp[5001] = {false};
        for (int j = 0; j < *matColSize; j++) {
            for (int k = 0; k <= 5000; k++) {
                if (dp[k] && k + mat[i][j] <= 5000) {
                    new_dp[k + mat[i][j]] = true;
                }
            }
        }
        for (int k = 0; k <= 5000; k++) {
            dp[k] = new_dp[k];
        }
    }

    int min_diff = INT_MAX;
    for (int i = 0; i <= 5000; i++) {
        if (dp[i]) {
            int diff = abs(i - target);
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
    }

    return min_diff;
}
