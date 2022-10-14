#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    char *currentArray = NULL;
    int i = 0;
    while(environ[i] != NULL){
        currentArray = environ[i];
        int j = 0;
        while(currentArray[j] != '\0'){
            printf("%c", currentArray[j]);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
