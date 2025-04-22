
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char word1[10], word2[10];
    int locctr = 0;

    fp = fopen("input.asm", "r");
    if (fp == NULL) {
        printf("File not found.\n");
        return 1;
    }

    

    printf("Intermediate Code:\n");

    while (!feof(fp)) {
        int count = fscanf(fp, "%s %s", word1, word2);

        // START case
        if (strcmp(word1, "START") == 0) {
            locctr = atoi(word2);
            printf("Program starts at address: %d\n", locctr);
            continue;
        }

        // ADD instruction
        if (strcmp(word1, "ADD") == 0) {
            printf("%d -- 03 %s\n", locctr, word2); // 03 for ADD
            locctr++;
            continue;
        }
        if (strcmp(word1, "SUB") == 0) {
            printf("%d -- 06 %s\n", locctr, word2); // 03 for ADD
            locctr++;
            continue;
        }

        // HLT instruction
        if (strcmp(word1, "HLT") == 0) {
            printf("%d -- 09        --HALT found\n", locctr); // 06 for HLT
            locctr++;
            continue;
        }
    }

        

    fclose(fp);
    return 0;
}

