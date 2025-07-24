long long gridGame(int** grid, int gridSize, int* gridColSize) {
    long long top_sum = 0;
    for (int i = 0; i < *gridColSize; i++) {
        top_sum += grid[0][i];
    }

    long long bottom_sum = 0;
    long long min_max_sum = -1;

    for (int i = 0; i < *gridColSize; i++) {
        top_sum -= grid[0][i];
        long long max_sum = top_sum > bottom_sum ? top_sum : bottom_sum;
        if (min_max_sum == -1 || max_sum < min_max_sum) {
            min_max_sum = max_sum;
        }
        bottom_sum += grid[1][i];
    }

    return min_max_sum;
}
