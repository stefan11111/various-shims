#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc == 2 && !strcmp(argv[1], "--version")) {
        printf("%s (GNU gettext-tools) 0.22.4\n", argv[0]);
        return 0;
    }

    int index = 0;

    for(int i = 1; i <= argc; i++) {
        if(!strcmp(argv[i - 1], "-o")) {
            index = i;
            break;
        }
    }

    if(index == 0) {
        return 0;
    }

    FILE *f = fopen(argv[index], "w");
    fclose(f);
    return 0;
}
