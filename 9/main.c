#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

int main(int argc, char const *argv[])
{
    char *name = malloc(sizeof(char) * 256);
    gethostname(name, 100);
    printf("%s\n\n\n",name);


    free(name);
    return 0;
}
