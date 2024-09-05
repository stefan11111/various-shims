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
            fprintf(f, "# INTLTOOL_MAKEFILE\n"
                       "all:\n"
                       "\n"
                       "clean:\n"
                       "\n"
                       "install:\n"
                       "\n"
                       "uninstall:\n"
                       "\n"
                       "PHONY: all clean install uninstall\n");
            return 0;
        }
    }
    return 0;
}
