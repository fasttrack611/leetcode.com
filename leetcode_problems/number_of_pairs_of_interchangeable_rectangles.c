long long interchangeableRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize) {
    long long count = 0;
    for (int i = 0; i < rectanglesSize; i++) {
        for (int j = i + 1; j < rectanglesSize; j++) {
            if ((long long)rectangles[i][0] * rectangles[j][1] == (long long)rectangles[i][1] * rectangles[j][0]) {
                count++;
            }
        }
    }
    return count;
}
