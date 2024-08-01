#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

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
            char *ptr = strrchr(*p, '/');
            if (ptr) {
                *ptr = '\0';
                mkdir(*p, 00644);
                ptr++;
            }
            else {
                ptr = *p;
            }

            FILE *f = fopen(ptr, "w");
            fclose(f);
            return 0;
        }

        if (!strncmp(*p, "--output-file=", sizeof("--output-file=") - 1)) {
            char *pptr = *p;
            pptr += sizeof("--output-file=") - 1;
            char *ptr = strrchr(pptr, '/');
            if (ptr) {
                *ptr = '\0';
                mkdir(pptr, 00644);
                ptr++;
            }
            else {
                ptr = pptr;
            }

            FILE *f = fopen(ptr, "w");
            fclose(f);
            return 0;
        }
    }

    char *ptr = strrchr(argv[argc - 1], '/');
    if (ptr) {
        *ptr = '\0';
        mkdir(argv[argc - 1], 00644);
        ptr++;
    }
    else {
        ptr = argv[argc - 1];
    }

    FILE *f = fopen(ptr, "w");
    fclose(f);
    return 0;
}
