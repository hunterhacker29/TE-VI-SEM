#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Enter the number of rules: ");
    scanf("%d", &n);
    getchar(); // To consume newline character after scanf

    char rules[10][10];
    //input should be 
    // Rule 1: E->E+E
    // Rule 2: E->a

    printf("Enter the rules:\n");
    for (int i = 0; i < n; i++) {
        printf("Rule %d: ", i + 1);
        fgets(rules[i], sizeof(rules[i]), stdin);
        if (rules[i][strlen(rules[i]) - 1] == '\n') {
            rules[i][strlen(rules[i]) - 1] = '\0';  // Remove newline
        }
    }

    //input should be 
    char input[] = "a+a$";

    printf("\nInput string: %s\n", input);
    printf("\nStack\t\tInput\t\tOperation\n");
    printf("-----\t\t------\t\t---------\n");

    char stack[100];
    int top = -1, ipindex = 0;
    stack[++top] = '$';

    while (1) {
        // Print current stack, input, and operation
        printf("%.*s\t\t%s\t\t", top + 1, stack, &input[ipindex]);

        if (input[ipindex] != '\0') {
            stack[++top] = input[ipindex++];  // Shift
            printf("Shift\n");

            // Print after shift
            printf("%.*s\t\t%s\t\tShift\n", top + 1, stack, &input[ipindex]);

            int reduced = 1;
            while (reduced) {
                reduced = 0;

                // Rule: E -> E+E
                if (top >= 2 && stack[top - 2] == 'E' && stack[top - 1] == '+' && stack[top] == 'E') {
                    stack[top - 2] = 'E';
                    top -= 2;
                    reduced = 1;
                    // Print after reduction
                    printf("%.*s\t\t%s\t\tReduce by E->E+E\n", top + 1, stack, &input[ipindex]);
                }

                // Rule: E -> E*E
                else if (top >= 2 && stack[top - 2] == 'E' && stack[top - 1] == '*' && stack[top] == 'E') {
                    stack[top - 2] = 'E';
                    top -= 2;
                    reduced = 1;
                    // Print after reduction
                    printf("%.*s\t\t%s\t\tReduce by E->E*E\n", top + 1, stack, &input[ipindex]);
                }

                // Rule: E -> a
                else if (stack[top] == 'a') {
                    stack[top] = 'E';
                    reduced = 1;
                    // Print after reduction
                    printf("%.*s\t\t%s\t\tReduce by E->a\n", top + 1, stack, &input[ipindex]);
                }

                // Rule: E -> b
                else if (stack[top] == 'b') {
                    stack[top] = 'E';
                    reduced = 1;
                    // Print after reduction
                    printf("%.*s\t\t%s\t\tReduce by E->b\n", top + 1, stack, &input[ipindex]);
                }
            }
        } else {
            break;
        }
    }

    // Final result check
    if (stack[0] == '$' && stack[1] == 'E' && top == 1) {
        printf("$E\t\t$\t\tAccepted\n");
    } else {
        printf("\nRejected\n");
    }

    return 0;
}
