#include <stdio.h>
int main()
{
    char ch[3];
    ch[0] = getc(stdin);
    ch[1] = getc(stdin);
    ch[2] = '\0';
    printf("%s\n", ch);
    return 0;
}
