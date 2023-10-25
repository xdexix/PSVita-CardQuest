void start_screen() {

// card quest
printf("\e[90m"); printf("\e[1;1H");
printf("\e[11;6H  ,----..                                           ,----..                                           ___   ");
printf("\e[12;6H /   /   \\                         ,---,           /   /   \\                                        ,--.'|_  ");
printf("\e[13;6H|   :     :             __  ,-.  ,---.'|          /   .     :            ,--,                       |  | :,'");
printf("\e[14;6H.   |  ;. /           ,' ,'/ /|  |   | :         .   /   ;.  \\         ,'_ /|             .--.--.   :  : ' :");
printf("\e[15;6H.   ; /--`   ,--.--.  '  | |' |  |   | |        .   ;   /  ` ;    .--. |  | :    ,---.   /  /    '.;__,'  / ");
printf("\e[16;6H;   | ;     /       \\ |  |   ,',--.__| |        ;   |  ; \\ ; |  ,'_ /| :  . |   /     \\ |  :  /`./|  |   |  ");
printf("\e[17;6H|   : |    .--.  .-. |'  :  / /   ,'   |        |   :  | ; | '  |  ' | |  . .  /    /  ||  :  ;_  :__,'| :");
printf("\e[18;6H.   | '___  \\__\\/: . .|  | ' .   '  /  |        .   |  ' ' ' :  |  | ' |  | | .    ' / | \\  \\    `. '  : |__   ");
printf("\e[19;6H'   ; : .'| ,"" .--.; | ;  : | '   ; |:|          '   ;  \\; /  |  :  | : ;  ; | '   ;   /|  `----.   \\|  | '.'|");
printf("\e[20;6H'   | '/  :/  /  ,.  ||  , ; |   | '/  '         \\   \\  ',  . \\ '  :  `--'   \\'   |  / | /  /`--'  /;  :    ;");
printf("\e[21;6H|   :    /;  :   .'   \\---'  |   :    :|          ;   :      ; |:  ,      .-./|   :    |'--'.     / |  ,   /");
printf("\e[22;6H \\   \\ .' |  ,     .-./       \\   \\  /             \\   \\ .'`--""  `--`----'     \\   \\  /   `--'---'   ---`-'");
printf("\e[23;6H  `---`    `--`---'            `----'               `---`                       `----'                    ");
printf("\e[0m");

// tap to play
string_center("____________________________________________________________", 36);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 37);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 38);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 39);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 40);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 41);
string_center("              \e[47m\e[30m|  ____  __   ____    ____  __     ____  __     __   _  _  |\e[0m", 42);
string_center("              \e[47m\e[30m| (_  _)/ _\\ (  _ \\  (_  _)/  \\   (  _ \\(  )   / _\\ ( \\/ ) |\e[0m", 43);
string_center("              \e[47m\e[30m|   )( /    \\ ) __/    )( (  O )   ) __// (_/\\/    \\ )  /  |\e[0m", 44);
string_center("              \e[47m\e[30m|  (__)\\_/\\_/(__)     (__) \\__/   (__)  \\____/\\_/\\_/(__/   |\e[0m", 45);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 46);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 47);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 48);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 49);
string_center("              \e[47m\e[30m|                                                          |\e[0m", 50);
string_center("              \e[47m\e[30m|__________________________________________________________|\e[0m", 51);
}

void rules_screen() {

// rules
printf("\e[90m");
string_center(" _____            _              ", 15);
string_center("|  __ \\          | |             ", 16);
string_center("| |__) |  _   _  | |   ___   ___ ", 17);
string_center("|  _  /  | | | | | |  / _ \\ / __|", 18);
string_center("| | \\ \\  | |_| | | | |  __/ \\__ \\", 19);
string_center("|_|  \\_\\  \\__,_| |_|  \\___| |___/", 20);
printf("\e[0m");
}

void wl_screen(int player, int comp) {

    // draw
    if (player == comp) {
        printf("\e[90m");
        string_center(" _____                            ", 31);
        string_center("|  __ \\                           ", 32);
        string_center("| |  | |  _ __    __ _  __      __", 33);
        string_center("| |  | | | '__|  / _` | \\ \\ /\\ / /", 34);
        string_center("| |__| | | |    | (_| |  \\ V  V / ", 35);
        string_center("|_____/  |_|     \\__,_|   \\_/\\_/  ", 36);
        printf("\e[0m");
    }

    // you win
    else if (player > comp) {
        printf("\e[32m");
        string_center("__     __                               _         ", 31);
        string_center("\\ \\   / /                              (_)        ", 32);
        string_center(" \\ \\_/ /    ___    _   _    __      __  _   _ __  ", 33);
        string_center("  \\   /    / _ \\  | | | |   \\ \\ /\\ / / | | | '_ \\", 34);
        string_center("   | |    | (_) | | |_| |    \\ V  V /  | | | | | |", 35);
        string_center("   |_|     \\___/   \\__,_|     \\_/\\_/   |_| |_| |_|", 36);
        printf("\e[0m");
    }

    // you lose
    else {
        printf("\e[31m");
        string_center("__     __                    _                     ", 31);
        string_center("\\ \\   / /                   | |                    ", 32);
        string_center(" \\ \\_/ /    ___    _   _    | |   ___    ___    ___", 33);
        string_center("  \\   /    / _ \\  | | | |   | |  / _ \\  / __|  / _ \\", 34);
        string_center("   | |    | (_) | | |_| |   | | | (_) | \\__ \\ |  __/", 35);
        string_center("   |_|     \\___/   \\__,_|   |_|  \\___/  |___/  \\___|", 36);
        printf("\e[0m");
    }
    string_center("The continue will be automatically in 5 sec ...", 38);
    sceKernelDelayThread(5 * SEC);
}

void print_card(char nom, int suit, int pos_x, int pos_y) {  
          
    printf("\e[%d;%dH.------.", pos_y, pos_x); pos_y += 1;
    switch(suit)
    {
        case 0: // crervy
            printf("\e[%d;%dH|%c     |", pos_y, pos_x, nom); pos_y += 1;
            printf("\e[%d;%dH| .--. |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| \e[31m(\\/)\e[0m |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| :\e[31m\\/\e[0m: |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| '--' |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH|     %c|", pos_y, pos_x, nom); pos_y += 1;
            break;
        case 1: // bubny
            printf("\e[%d;%dH|%c     |", pos_y, pos_x, nom); pos_y += 1;
            printf("\e[%d;%dH| .--. |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| :\e[31m/\\\e[0m: |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| :\e[31m\\/\e[0m: |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| '--' |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH|     %c|", pos_y, pos_x, nom); pos_y += 1;
            break;
        case 2: // piki
            printf("\e[%d;%dH|%c     |", pos_y, pos_x, nom); pos_y += 1;
            printf("\e[%d;%dH| .--. |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| :\e[90m/\\\e[0m: |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| \e[90m(__)\e[0m |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| '--' |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH|     %c|", pos_y, pos_x, nom); pos_y += 1;
            break;
        case 3: // trefy
            printf("\e[%d;%dH|%c     |", pos_y, pos_x, nom); pos_y += 1;
            printf("\e[%d;%dH| .--. |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| :\e[90m()\e[0m: |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| \e[90m()()\e[0m |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| '--' |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH|     %c|", pos_y, pos_x, nom); pos_y += 1;
            break;
        case 4:
            printf("\e[%d;%dH|      |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| .--. |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| :  : |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| :  : |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH| '--' |", pos_y, pos_x); pos_y += 1;
            printf("\e[%d;%dH|      |", pos_y, pos_x); pos_y += 1;
            break;
        default: break;
    }
    printf("\e[%d;%dH`------'", pos_y, pos_x); pos_y += 1;
}

