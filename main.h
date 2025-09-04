#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>

const int SIZE_OF_BUF = 256;
const int ZERO = 0;
const int CNT_SYMBOLS = 256;


int my_puts(const char *str);

const char * my_strchr(const char *str, int c);

size_t my_strlen(const char *str);

char *my_strcpy(char * dst, const char * src);

char *my_strncpy(char * dst, const char * src, size_t n);

char *my_strcat(char * dst, const char * src);

char *my_strncat(char * dst, const char * src, size_t ssize);

char *my_fgets(char *str, int n, FILE *stream);

char *my_strdup(const char *s);

 void *my_recalloc(void *ptr, size_t new_size, size_t old_size);

ssize_t my_getline(char ** lineptr, size_t * n, FILE * stream);

const char * my_strstr(const char *haystack, const char *needle);

const char * my_strstr_2(const char *haystack, const char *needle);

int my_atoi(const char *nptr);

#endif //MAIN_H_