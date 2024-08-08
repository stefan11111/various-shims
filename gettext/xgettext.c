#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc < 2) {
        return 0;
    }

    if(argc == 2 && !strncmp(argv[1], "--version", sizeof("--version") - 1)) {
        printf("%s (GNU gettext-tools) 0.22.4\n", argv[0]);
        return 0;
    }

    for(char **p = argv; *p; p++) {
        if (!strncmp(*p, "-o", sizeof("-o") - 1)) {
            p++;
            FILE *f = fopen(*p, "w");
            fclose(f);
            return 0;
        }

        if (!strncmp(*p, "--output-file=", sizeof("--output-file=") - 1)) {
            FILE *f = fopen(*p + sizeof("--output-file=") - 1, "w");
            fclose(f);
            return 0;
        }

        if (!strncmp(*p, "-d", sizeof("-d") - 1)) {
            p++;
            char *dst = malloc(strlen(*p) + sizeof(".po"));
            *stpncpy(stpncpy(dst, *p, strlen(*p)), ".po", sizeof(".po") - 1) = '\0';
            FILE *f = fopen(dst, "w");
            fclose(f);
            free(dst);
            return 0;
        }

        if (!strncmp(*p, "--output-file=", sizeof("--output-file=") - 1)) {
            char *dst = malloc(strlen(*p + sizeof("--output-file=") - 1) + sizeof(".po"));
            *stpncpy(stpncpy(dst, *p + sizeof("--output-file=") - 1, strlen(*p)), ".po", sizeof(".po") - 1) = '\0';
            FILE *f = fopen(dst, "w");
            fclose(f);
            free(dst);
            return 0;
        }
    }

    FILE *f = fopen("messages.po", "w");
    fclose(f);
    return 0;
}
