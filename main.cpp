#include "main.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int my_puts(const char *str) {
    assert(str != NULL);

    for ( ; *str != '\0'; ++str) {
        if (putchar(*str) == EOF) {
            return EOF;
        }
    }

    return 0;
}

const char * my_strchr(const char *str, int c) {
    assert(str != NULL);

    do {
        if (*str == c) {
            return str;
        }
    } while (*str++ != '\0');

    return NULL;
}

size_t my_strlen(const char *str) {
    assert(str != NULL);

    size_t size = 0;

    for ( ; *str != '\0'; ++str) {
        ++size;
    }

    return size;
}

char *my_strcpy(char * dst, const char * src) {
    assert(dst != NULL);
    assert(src != NULL);

    char * temp = dst;

    do {
        *dst++ = *src;
    } while (*src++ != '\0');

    return temp;
}

char *my_strncpy(char * dst, const char * src, size_t n) {
    assert(dst != NULL);
    assert(src != NULL);

    char * temp = dst;

    int i = 0;
    do {
        *dst++ = *src++;
    } while (*src != '\0' && i++ < n);

    while (i < n) {
        *dst++ = '\0';
        ++i;
    }

    return temp;
}

char *my_strcat(char * dst, const char * src) {
    assert(dst != NULL);
    assert(src != NULL);

    char * temp = dst;

    while (*dst++ != '\0') {
    }

    do {
        *dst++ = *src;
    } while (*src++ != '\0');

    return temp;
}

char *my_strncat(char * dst, const char * src, size_t ssize) {
    assert(dst != NULL);
    assert(src != NULL);

    char * temp = dst;

    while (*dst++ != '\0') {
    }

    int i = 0;
    do {
        *dst++ = *src++;
    } while (*src != '\0' && i++ < ssize);
    
    if (i < ssize) {
        *dst = '\0';
    }

    return temp;
}

char *my_fgets(char *str, int n, FILE *stream) {
    assert(str != NULL);

    int ch = getc(stream);
    if (ch == EOF) {
        return NULL;
    }

    int cnt = 0;
    while (ch != EOF and ch != '\n' and cnt++ != (n - 1)) {
        *str++ = ch; 
        ch = getc(stream);
    }
    *str = '\0';

    if (ferror(stream) != 0) {
        return NULL;
    }

    return str;
}

char *my_strdup(const char *s) {
    assert(s != NULL);

    char *point_on_s = (char*)calloc(my_strlen(s), sizeof(char));

    if (point_on_s == NULL) {
        return NULL;
    }

    point_on_s = my_strcpy(point_on_s, s);

    return point_on_s;

}

ssize_t my_getline(char ** lineptr, size_t * n, FILE * stream) {
    if (n == NULL || lineptr == NULL) {
        return -1;
    }
    
    if (*lineptr == NULL) {
        *n = 0;
    }

    int ch = 0;
    size_t size = 0;
    while ((ch = getc(stream)) != '\n' && ch != EOF) {
        if (*n < size + 1) {
            char * temp = (char*)realloc(*lineptr, (*n == 0) ? SIZE_OF_BUF : 2 * (*n));

            if (temp == NULL) {
                return -1;
            }

            *n = (*n == 0) ? SIZE_OF_BUF : 2 * (*n);
            *lineptr = temp;
        }

        **lineptr++ = ch;
        size++;
    }

    **lineptr = '\0';

    if (ferror(stream) != 0) {
        return -1;
    }

    return size;

}

//TODO recalloc (memset)


int main() {
    char buffer[1024] = {};

    printf("<%p>\n", fgets(buffer, 5, stdin));
    printf("<%p><%s>\n", buffer, buffer);

    return 0;
}