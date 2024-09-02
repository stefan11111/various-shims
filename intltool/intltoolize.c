#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    for (char **p = argv, *p; p++) {
        if (!strncmp(p, "--force", sizeof("--force") - 1)) {
            FILE *f = fopen("po/Makefile.in.in", "w");
            if (f) {
                fclose(f);
            }
            return 0;
        }
    }
    return 0;
}
