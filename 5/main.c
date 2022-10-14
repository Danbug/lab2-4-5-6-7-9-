#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    if(argc != 2 ){
        printf("You should pass as argument name of env var\n");
        printf("main.o EXAMPLE_ENV\n");
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

    int j = 0;
    while(tmpRes[j] != '\0'){
        printf("%c", tmpRes[j]);
        j++;
    }
    printf("\n");

    return 0;
}
