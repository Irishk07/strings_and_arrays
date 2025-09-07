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

        char haystack [MAX_LEN + 1] = {};
        generate_random_string(haystack);

        char needle [MAX_LEN + 1] = {};
        generate_random_string(needle);

        char * need = strstr(haystack, needle);
        const char * my = my_strstr_mur(haystack, needle);
        if (need != my) {
            printf("%s %s\n", haystack, needle);
            printf("need: %p\n", need);
            printf("my: %p\n", my);
            printf("haystack: %p\n", haystack);
            break;
        }
    }
}

void test_ncmp() {
    int cnt_test = 1e6;

    while (cnt_test-- > 0) {

        char s1 [MAX_LEN + 1] = {};
        generate_random_string(s1);

        char s2 [MAX_LEN + 1] = {};
        generate_random_string(s2);

        int cnt = rand() % (MAX_LEN);

        int ref = strncmp(s1, s2, cnt);
        int my = my_strncmp(s1, s2, cnt);
        
        bool err = false;

        if (ref == 0 || my == 0) {
            if (ref != my) {
                err = true;
            }
        }
        else if ((ref / abs(ref)) != (my / abs(my))) {
            err = true;
        }

        if (err) {
            printf("%s %s\n", s1, s2);
            printf("ref: %d\n", ref);
            printf("my: %d\n", my);
            printf("n: %d\n", cnt);
            break;
        }
    }
}