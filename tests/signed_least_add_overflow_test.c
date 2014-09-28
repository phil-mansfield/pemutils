#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>

#include "overflow.h"

#define LEN(xs) ((int)(sizeof(xs) / sizeof(xs[0])))

bool add_overflow_int_least8_test() {
    struct {int_fast32_t x, y; bool res;} tests[15] = {
        {1, 2, false},
        {-3, -42, false},
        {0, 0, false},
        {-5, 10, false},
        {10, -5, false},
        {INT_LEAST8_MIN, -1, true},
        {INT_LEAST8_MIN, 0, false},
        {-1, INT_LEAST8_MIN, true},
        {0, INT_LEAST8_MIN, false},
        {INT_LEAST8_MAX, 1, true},
        {INT_LEAST8_MAX, 0, false},
        {1, INT_LEAST8_MAX, true},
        {0, INT_LEAST8_MAX, false},
        {INT_LEAST8_MAX, INT_LEAST8_MAX, true},
        {INT_LEAST8_MIN, INT_LEAST8_MIN, true}
    };

    bool res = true;

    for (int i = 0; i < LEN(tests); i++) {
        if (add_overflow_int_least8(tests[i].x, tests[i].y) != tests[i].res) {
            res = false;
            fprintf(stderr, "Failed test %d: add_overflow_int64(%"PRId8", "
                    "%"PRId8"). Expected %d, got %d\n.",
                    i + 1, tests[i].x, tests[i].y, tests[i].res, !tests[i].res);
        }
    }

    return res;
}

int main() {
    if (!add_overflow_int_least8_test()) { return 1; }
    return 0;
}
