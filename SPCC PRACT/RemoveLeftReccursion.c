# include <stdio.h>
# include <string.h>

void removleftrecursion(char nt , char alpha[],char beta[]){

    printf("Left recursion detected :\n");
    printf("%c -> %s%c' \n",nt, beta,nt);
    printf("%c' -> %s%c' | espilon \n",nt,alpha,nt);    
}
int main(){
    char expr[]="A -> Aa | b";

    printf("Input : %s\n",expr);
    
    char nt , arrow[10], production[100];
    char alpha[100],beta[100];
    
    sscanf(expr,"%c %s %[^\n]",&nt,&arrow,&production);
    
    char *d=strchr(production,'|');

        *d='\0';
        char *left = production;
        char *right = d+1;
        
    
        // remove spaces 
        while (*left ==' ')left ++;
        while (*right ==' ')right ++;

        if (left[0]==nt){
            strcpy(alpha,left+1);
            strcpy(beta,right);
            removleftrecursion(nt,alpha,beta);
            
        }
        else {
            printf("No left recursion found.\n");
        }

    return 0 ;
    
}