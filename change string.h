void change(char str[], char str2[], int first) {
    for(int i = 0 ; i < strlen(str2) ; i++ ) {
        str[i + first] = str2[i];
    }
}

void swap_str_name(int x1, int y1, int x2, int y2, char str[40][110]) {
    char str1[7], str2[7];
    for(int i = 0 ; i < 6 ; i++ ) {
        str1[i] = str[hex[x1][y1].yname][hex[x1][y1].xname + i];
        str2[i] = str[hex[x2][y2].yname][hex[x2][y2].xname + i];
    }
    str1[6] = str2[6] = '\0';
    change(str[hex[x1][y1].yname], str2, hex[x1][y1].xname);
    change(str[hex[x2][y2].yname], str1, hex[x2][y2].xname);
}

void swap_str_type(int x1, int y1, int x2, int y2, char str[40][110]) {
    char str1[9], str2[9];
    for(int i = 0 ; i < 9 ; i++ ) {
        str1[i] = str[hex[x1][y1].ylight][hex[x1][y1].xlight + i];
        str2[i] = str[hex[x2][y2].ylight][hex[x2][y2].xlight + i];
    }
    str1[8] = str2[8] = '\0';
    change(str[hex[x1][y1].ylight], str2, hex[x1][y1].xlight);
    change(str[hex[x2][y2].ylight], str1, hex[x2][y2].xlight);
}
