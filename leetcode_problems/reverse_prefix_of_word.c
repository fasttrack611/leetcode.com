char* reversePrefix(char* word, char ch) {
    int len = strlen(word);
    int found_idx = -1;
    for (int i = 0; i < len; i++) {
        if (word[i] == ch) {
            found_idx = i;
            break;
        }
    }

    if (found_idx != -1) {
        int left = 0;
        int right = found_idx;
        while (left < right) {
            char temp = word[left];
            word[left] = word[right];
            word[right] = temp;
            left++;
            right--;
        }
    }

    return word;
}
