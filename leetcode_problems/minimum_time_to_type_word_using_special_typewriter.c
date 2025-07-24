int minTimeToType(char* word) {
    int time = 0;
    char current = 'a';
    for (int i = 0; i < strlen(word); i++) {
        int diff = abs(word[i] - current);
        time += (diff < 13 ? diff : 26 - diff) + 1;
        current = word[i];
    }
    return time;
}
