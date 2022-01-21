void change(char str[], char str2[], int first) {
    for(int i = 0 ; i < strlen(str2) ; i++ ) {
        str[i + first] = str2[i];
    }
}
