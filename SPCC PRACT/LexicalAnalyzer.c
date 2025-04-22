# include<stdio.h>
#include<string.h>
#include<ctype.h>


int main (){

    char s[1000];

    printf("Enter a string :");
    scanf("%[^\n]",&s);

    int i =0;
    int j ;
    char lexeme[1000];

    while (s[i] != '\0'){

        while (isspace(s[i])){
            i++;
        }
        
        // Check for keywords and identifiers
        if (isalpha(s[i])){
            
            j = i ;

            while(isalnum(s[j])){
                j++;
            }
            strncpy(lexeme,&s[i], j - i);
            lexeme[j - i]='\0';
            
            if (strcmp(lexeme,"if")==0 || strcmp(lexeme,"else")==0 || strcmp(lexeme,"while")==0 || strcmp(lexeme,"for")==0){
                printf("Token : %s Type : Keyword\n", lexeme);
            }
            else {
                printf("Token : %s Type : Identifier\n", lexeme);
            }
            i = j; 
        }

        // checking for digit (s)

        if (isdigit(s[i])){

            j=i;

            while(isdigit(s[j])){
                j++;
            }
            strncpy(lexeme,&s[i],j - i);
            lexeme[j - i ]='\0';
                
            printf("Token : %s type : CONSTANT\n", lexeme);
            i=j;
        }
        // checking for operators
        
        if(s[i]=='+'){
            printf("Token : + Type : Operator\n");
            i++;
        }
        if (s[i]=='-'){
            printf("Token : - Type : Operator\n");
            i++;
        }
        if (s[i]=='='){
            printf("Token : = Type : Operator\n");
            i++;
        }
        if (s[i]=='('){
            printf("Token : ( Type : Operator\n");
            i++;
        }
        if (s[i]==')'){
            printf("Token : ) Type : Operator\n");
            i++;
        }

    }


    return 0;
}