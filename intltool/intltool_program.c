#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc < 2) {
        return 0;
    }

    if(argc == 2 && !strncmp(argv[1], "--version", sizeof("--version") - 1)) {
        printf("%s (intltool) 0.51.0\n", argv[0]);
        return 0;
    }

    for(char **p = argv; *p; p++) {
        if (!strncmp(*p, "-o", sizeof("-o") - 1)) {
            p++;
            (void)!fopen(*p, "w");
            return 0;
        }

        if (!strncmp(*p, "--output-file=", sizeof("--output-file=") - 1)) {
            (void)!fopen(*p + sizeof("--output-file=") - 1, "w");
            return 0;
        }
    }
    (void)!fopen(argv[argc - 1], "w");
    return 0;
}
