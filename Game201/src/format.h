void clear_screen() {
    printf("\e[1;1H");
    printf("\e[2J");
}

void string_center(char* str, int line)
{
    int col = (120 - strlen(str)) / 2;
    printf("\e[%d;%dH%s", line, col, str);
}
