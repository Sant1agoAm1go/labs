#include "mystring.h"

size_t mystrlen(const char *s) {
    int res = 0;
    while (*s) {
        ++s, ++res;
    }
    return res;
}
