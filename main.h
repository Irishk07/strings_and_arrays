#include <stdio.h>

const int SIZE_OF_BUF = 256;


int my_puts(const char *str);

const char * my_strchr(const char *str, int c);

size_t my_strlen(const char *str);

char *my_strcpy(char * dst, const char * src);

char *my_strncpy(char * dst, const char * src, size_t n);

char *my_strcat(char * dst, const char * src);

char *my_strncat(char * dst, const char * src, size_t ssize);

char *my_fgets(char *str, int n, FILE *stream);

char *my_strdup(const char *s);

ssize_t my_getline(char ** lineptr, size_t * n, FILE * stream);