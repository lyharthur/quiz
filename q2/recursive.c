#include<stdio.h>
char smallest_character_r(char str[], char c, int index) {
    if(str[index] == '\0') return str[0];
    if(str[index] > c) return str[index];
    else  return smallest_character_r(str,c,index+1);
}
int main(){
    char str[5]="cfjpv";
    char str2[3]="cck";
    if ('c' == smallest_character_r(str,'a',0))
        printf("pass case1_r\n");
    if ('f' == smallest_character_r(str,'c',0))
        printf("pass case2_r\n");
    if ('c' == smallest_character_r(str,'z',0))
        printf("pass case3_r\n");
    if ('k' == smallest_character_r(str2,'f',0))
        printf("pass case4_r\n");
    return 0 ;
}
