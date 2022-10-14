#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    if(argc != 3 ){
        printf("You should pass as argument name of env and it's key\n");
        printf("main.o EXAMPLE_ENVNAME example_env_value\n");
        return -1;
    }

    int result = setenv(argv[1], argv[2], 1);
    if(result == -1){
        printf("FATAL ERROR!\n");
        return -1;
    }

    char * tmpRes = getenv(argv[1]);
    // memcpy?
    if(tmpRes == NULL){
        printf("Not exist!\n");
        return 0;
    }

    if(tmpRes[0] == NULL){
        printf("Empty env\n");
        return 0;
    }

    printf("%s=",argv[1]);
    int j = 0;
    while(tmpRes[j] != '\0'){
        printf("%c", tmpRes[j]);
        j++;
    }
    printf("\n");

    return 0;
}
