#include "test.h"

#include "main.h"

#include <stdlib.h>
#include <string.h>
#include <time.h>

const char MAX_LEN = 11;

void generate_random_string(char *buf) {
    int len = rand() % (MAX_LEN);

    char bukv[] = {'a', 'b', 'c'};

    for (int i = 0; i < len; ++i) {
        buf[i] = bukv[(size_t)rand() % sizeof(bukv)];
    }

    buf[len + 1] = '\0';

}

void test() {
    int cnt_test = 1e6;

    while (cnt_test-- > 0) {

        char haystack [MAX_LEN+1] = {};
        generate_random_string(haystack);

        char needle [MAX_LEN+1] = {};
        generate_random_string(needle);

        char * need = strstr(haystack, needle);
        const char * my = my_strstr(haystack, needle);
        if (need != my) {
            printf("%s %s\n", haystack, needle);
            printf("need: %p\n", need);
            printf("my: %p\n", my);
            printf("haystack: %p\n", haystack);
            break;
        }
    }
}