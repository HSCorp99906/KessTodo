#include "../include/todo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    while (1) {
        printf("\033[96mroot@kesstodo~$ ");

        char input[250];
        fgets(input, 250, stdin);

        if (input[0] == 'q') {
            return 0;
        } else if (input[0] == 'a') {
            printf("Enter Todo (250 Chars Max): ");
            char todo[250];
            fgets(todo, 250, stdin);

            system("touch .todo");
            FILE* fp = fopen(".todo", "a");
            fputs(todo, fp);
            fclose(fp);

            printf("%s Todo Added!\n", OK);
        } else if (input[0] == 'l') {
            if (access(".todo", F_OK) != 0) {
                printf("%s", NOTOK);
                printf(" \033[96mYou have not added any todo's yet!\n");
                continue;
            }


            FILE* fp = fopen(".todo", "r");

            char todoBuf[250];

            fseek(fp, 0, SEEK_END);
            size_t size = ftell(fp);
            fseek(fp, 0, SEEK_SET);

            if (size <= 1) {
                exit(1);
            }

            int index = 1;

            while (fgets(todoBuf, 250, fp)) {
                printf("%d) %s", index, todoBuf);
                ++index;
            }
        }
    }
}
