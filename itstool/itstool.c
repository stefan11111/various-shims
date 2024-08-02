#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define MASK 00755
#define PATH_MAX 4096

static void mkdir_p_and_touch (char *path)
{
    for(char *ptr = strchr(path, '/'); ptr; ptr = strchr(ptr, '/')) {
        *ptr = '\0';
        mkdir(path, MASK);
        *ptr = '/';
        ptr++;
    }
    FILE *f = fopen(path, "w");
    fclose(f);
}

static void mkdir_p (char *path)
{
    char *tmp = strrchr(path, '/');
    if (tmp && *(tmp + 1) == '\0') {
        *tmp = '\0';
    }
    for(char *ptr = strchr(path, '/'); ptr; ptr = strchr(ptr, '/')) {
        *ptr = '\0';
        mkdir(path, MASK);
        *ptr = '/';
        ptr++;
    }
    mkdir(path, MASK);
}

int main(int argc, char **argv)
{
    if(argc < 2) {
        return 0;
    }

    char merge_flag = 0;

    for(char **p = argv; *p; p++) {
        if (!strncmp(*p, "-m", sizeof("-m") - 1) || !strncmp(*p, "--merge", sizeof("--merge") - 1)) {
            merge_flag = 1;
        }
    }

    if (merge_flag == 0) {
        for(char **p = argv; *p; p++) {
            if (!strncmp(*p, "-o", sizeof("-o") - 1) || !strncmp(*p, "--out", sizeof("--out") - 1)) {
                p++;
                mkdir_p_and_touch(*p);
                return 0;
            }
        }
        mkdir_p_and_touch(argv[argc - 1]);
        return 0;
    }

    while (strncmp(*argv, "-o", sizeof("-o") - 1) && strncmp(*argv, "--out", sizeof("--out") - 1)) {
        argv++;
    }
    argv++;
    mkdir_p(*argv);
    for(char **p = argv + 1; *p; p++) {
        char path[PATH_MAX + 2];
        char *ptr = stpncpy(path, *argv, PATH_MAX >> 1);
        *ptr = '/';
        ptr++;
        char *tmp = strrchr(*p, '/');
        tmp = tmp ? tmp + 1 : *p;
        *stpncpy(ptr, tmp, PATH_MAX >> 1) = '\0';
        FILE *f = fopen(path, "w");
        fclose(f);
    }
    return 0;
}
