#include<stdio.h>
char smallest_character(char str[], char c) {
    int i = 0;
    while(str[i] != '\0'){
        if(c < str[i])
            return str[i];
        i++;
    }
    return str[0];
}
int main(){
    char str[5]="cfjpv";
    char str2[3]="cck";
    if ('c' == smallest_character(str,'a'))
        printf("pass case1\n");
    if ('f' == smallest_character(str,'c'))
        printf("pass case2\n");
    if ('c' == smallest_character(str,'z'))
        printf("pass case3\n");
    if ('k' == smallest_character(str2,'f'))
        printf("pass case4\n");
    return 0 ;
}
