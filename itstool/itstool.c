#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc < 2) {
        return 0;
    }

    for(char **p = argv; *p; p++) {
        if (!strncmp(*p, "-o", sizeof("-o") - 1) || !strncmp(*p, "--out", sizeof("--out")) {
            p++;
            FILE *f = fopen(*p, "w");
            fclose(f);
            return 0;
        }
    }

    for(char **p = argv; *p; p++) {
        if (!strncmp(*p, "-m", sizeof("-m") - 1) || !strncmp(*p, "--merge", sizeof("--merge")) {
            p++;
            FILE *f = fopen(*p, "w");
            fclose(f);
            return 0;
        }
    }

    FILE *f = fopen(argv[argc - 1], "w");
    fclose(f);
    return 0;
}
