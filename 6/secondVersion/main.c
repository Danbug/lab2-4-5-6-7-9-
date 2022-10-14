#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    if(argc != 3 ){
        printf("You should pass as argument name of env and it's key\n");
        printf("main.o EXAMPLE_ENVNAME example_env_value\n");
        return -1;
    }
    char *initStr = malloc(sizeof(char) * 256);
    if(initStr == NULL){
        printf("Memory allocation err!\n");
        return -1;
    }

    char *cToStr = malloc(sizeof(char) * 2);
    cToStr[0] = '=';
    cToStr[1] = '\0';

    strcpy(initStr, argv[1]);
    strcat(initStr, cToStr);
    strcat(initStr, argv[2]);

    int result = putenv(initStr);
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
