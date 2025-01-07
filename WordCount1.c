#include <stdio.h>
#include <string.h>

int main() {
    
    char s [1000];
    char word[100];
    
    
    printf("Enter the string : ");
    scanf(" %[^\n]",&s);
    
    printf("Enter the word to search :");
    scanf("%s",&word);

    char *ptr = s; 
    int count = 0;

    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr ++;
    }

    printf("The frequency of the word is: %d\n", count);

    return 0;
}
