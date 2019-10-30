#include <stdio.h>
#include <string.h>
#include <Windows.h>

int main() {
    char fileName[31];
    char out[1500];
    char if_in[13];
    int yORn = 1;
    unsigned int lengthSub;
    int x = 0;
    char *answer;
    char *temp;
    char *ptr;
    FILE *fp;

    while (yORn == 1) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
        printf("Write name of the file: ");
        scanf("%s", fileName);
        fp = fopen(fileName, "r");
        fscanf(fp, "%[^\n]%*c", out);
        printf("%s\n", out);
        ptr = out;
        x = 0;
        printf("Enter the word to scan in this file: \n");
        scanf("%s", if_in);
        lengthSub = strlen(if_in);
        do {
            answer = strstr(ptr, if_in);
            if(answer != NULL) {
                temp = answer;
                *temp = '\0';
                printf("%s", ptr);
                answer += lengthSub;
                ptr = answer;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("%s" , if_in);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
                x++;
            }
        } while (answer != NULL);
        printf("%s \n", ptr);
        printf("Word: %s, occurs: %d time/s, in the: %s text.\n", if_in, x, fileName);
        printf("Do you want to repeat the process?(1 if YES/0 if NO)\n");
        scanf("%d", &yORn);
    }
    fclose(fp);
    printf("Thank You!");
    return 0;
}