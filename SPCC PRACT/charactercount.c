
# include <stdio.h>
# include<string.h>

int main(){
    
    char s[100];
    int count = 0;
    
    printf("Enter the input string :");
    scanf("%[^\n]",&s);
    
    for (int i=0 ; s[i]!='\0';i++){
        if (s[i]!=' '){
            count++;
        }
        
    }
    printf("count is %d",count);
    
    return 0; 
}