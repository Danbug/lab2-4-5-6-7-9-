#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    if(argc != 2 ){
        // printf("You should pass as argument name of env that you want to delete\n");
        // printf("main.o EXAMPLE_ENV_NAME_TO_DELETE \n");
        clearenv();
    } else {
        unsetenv(argv[1]);
    }

    char *currentArray = NULL;
    int i = 0;

    // new check
    if(environ == NULL){
        return 0;
    }
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
