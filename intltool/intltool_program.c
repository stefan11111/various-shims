#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc == 2 && !strcmp(argv[1], "--version")) {
        printf("%s (GNU gettext-tools) 0.22.4\n", argv[0]);
        return 0;
    }

    FILE *f = fopen(argv[argc - 1], "w");
    fclose(f);
    return 0;
}
