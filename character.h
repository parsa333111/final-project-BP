/*
character :
1 = JW
2 = IL
3 = WG
4 = JS
5 = SH
6 = JB
7 = MS
8 = SG
*/
void print_char(int x) {
    if(x == 1) printf("JW");
    if(x == 2) printf("IL");
    if(x == 3) printf("WG");
    if(x == 4) printf("JS");
    if(x == 5) printf("SH");
    if(x == 6) printf("JB");
    if(x == 7) printf("MS");
    if(x == 8) printf("SG");
}

char *char_name_sus(int x) {
    if(x == 1) return "JW sus";
    if(x == 2) return "IL sus";
    if(x == 3) return "WG sus";
    if(x == 4) return "JS sus";
    if(x == 5) return "SH sus";
    if(x == 6) return "JB sus";
    if(x == 7) return "MS sus";
    if(x == 8) return "SG sus";
}

char *char_name_inn(int x) {
    if(x == 1) return "JW inn";
    if(x == 2) return "IL inn";
    if(x == 3) return "WG inn";
    if(x == 4) return "JS inn";
    if(x == 5) return "SH inn";
    if(x == 6) return "JB inn";
    if(x == 7) return "MS inn";
    if(x == 8) return "SG inn";
}
