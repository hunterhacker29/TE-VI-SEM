
// Word Count Program 

#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char s [1000];
    char word[1000];


    printf("Enter a string : ");
    scanf("%[^\n]",&s);

    printf("Enter a word to count : ");
    scanf("%s",&word);

   
    printf("\nYou entered string: %s", s);
    printf("\nYou entered word: %s", word);
  
    char *ptr = s ;
    int count = 0;

    while ((ptr=strstr(ptr, word))!=NULL) {

       count++;
       ptr++;
    }

    printf("The frequency of the word is: %d\n", count); 


    return 0;
}