//count how many words in the word.list under ~/projects/yawl/yawl-0.3.2.03
#include <stdio.h>
#include <string.h>
#include "test.h"


/* Define globla variables */
t_yawl yawl; 


/* main function */
int main(void)
{
    FILE* fptr;

    init(); // initialize

    printf("Please choose what you want to do with the word text.\n");
    printf("Type 0 to count how many words in the.\n");
    printf("Type 1 to show the word with the largest size.\n");
    printf("Type 2 to show all the words in the list.\n");
    printf("Type 3 to search for that word in the list, Return its position if it is found. Otherwise, return not found.\n");



    E_SELECTION selection = E_DEFAULT;
    int user_input = 0;
    scanf("%d", &user_input);

    selection = (E_SELECTION)user_input;
    printf("Your selection is %d.\n",selection);
    if (E_SEARCH == selection) {
        printf("Please type in the word you want to search for.\n");
        scanf("%s",&yawl.target_str);
        printf("The word you want to search is %s.\n", yawl.target_str);
    };

    fptr = fopen("word.txt", "r");
    if (NULL == fptr) {
        printf("Not able to open the file\n");
    }
    else {
        int size=0;
        char myString[100];
        while(fgets(myString,100,fptr)) {
            for (int i=0;i<strlen(myString);i++) {

                if (E_LIST_ALL == selection) {
                    printf("%c",myString[i]);
                }
                /* replace any '\n' with '\0'  */
                if (myString[i] == '\n') {
                    myString[i] = '\0';
                };
            }
            size = strlen(myString);
            // printf("strlen - string size is %d\n", size);
            if (size > yawl.max_size) {
                yawl.max_size = size;
                strcpy(yawl.longest_str,myString);
            }
            
            if (E_SEARCH == selection) {
                // if (E_TRUE == compareString(&yawl.target_str, &myString)) {
                if (0 == strcmp(yawl.target_str, myString)) {
                    printf("The word - %s has been found at the %dth position in the list.\n", yawl.target_str, (yawl.cnt + 1));
                }
            }
            yawl.cnt++;
        }
        output(selection);
    }



    fclose(fptr);
    return 0;
}

void output(E_SELECTION selection) {
    switch(selection) {
        case E_COUNT_WORDS:
            printf("\nThere are %d words in total in the word list", yawl.cnt);
        break;
        case E_LONGEST:
            printf("\nMax size is %d and the word is %s", yawl.max_size, yawl.longest_str);
        break;
        case E_LIST_ALL:
            printf("\nAll the words have been printed out.");
        break;
        case E_SEARCH:
            printf("\nThe search has finished.");
        break;
        default:
            printf("Invalid selection");
        break;
    }
}

void init(void) {
    yawl.cnt = 0u;
    yawl.max_size = 0u;
    for (int i =0; i < sizeof(yawl.longest_str); i++) {
        /* initialize char array with null char */
        yawl.longest_str[i] = '\0';
        yawl.target_str[i] = '\0';
    }
}

// E_RESULT compareString(char str1[], char str2[]) {
//     /* default set to match */
//     E_RESULT match_result = E_TRUE;

//     /* compare string size first */
//     if (strlen(str1) == (strlen(str2))) {
//         /* compare string one by one */
//         for (int i = 0; i < strlen(str1); i++) {
//             if (str1[i] != str2[i] ) {
//                 /* not match */
//                 match_result = E_FALSE;
//                 break;
//             }
//         }
//     }
//     else {
//         /* not match */
//         match_result = E_FALSE;
//     }

//     return match_result;
// }


