//count how many words in the word.list under ~/projects/yawl/yawl-0.3.2.03
#include <stdio.h>

int main(void)
{
    FILE* fptr;
    printf("hello world\n");

    fptr = fopen("word.txt", "r");
    if (NULL == fptr) {
        printf("Not able to open the file\n");
    }
    else {
        int cnt=0;
        char myString[100];
        while(fgets(myString,100,fptr)) {
            printf("The string is %s", myString);
            cnt++;
        }
        printf("There are %d words in total in the word list", cnt);
    }



    fclose(fptr);
    return 0;
}
