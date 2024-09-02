#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    for (char **p = argv; *p; p++) {
        if (!strncmp(*p, "--force", sizeof("--force") - 1)) {
            FILE *f = fopen("po/Makefile.in.in", "a");
            if (!f) {
                return 0;
            }
            fprintf(f, "%s", "# INTLTOOL_MAKEFILE\n");
            fclose(f);
            return 0;
        }
    }
    return 0;
}
