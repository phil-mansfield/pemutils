#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>

#include "overflow.h"

#define LEN(xs) ((int)(sizeof(xs) / sizeof(xs[0])))

bool add_overflow_int_fast32_test() {
    struct {int_fast32_t x, y; bool res;} tests[15] = {
        {1, 2, false},
        {-3, -42, false},
        {0, 0, false},
        {-5, 10, false},
        {10, -5, false},
        {INT_FAST32_MIN, -1, true},
        {INT_FAST32_MIN, 0, false},
        {-1, INT_FAST32_MIN, true},
        {0, INT_FAST32_MIN, false},
        {INT_FAST32_MAX, 1, true},
        {INT_FAST32_MAX, 0, false},
        {1, INT_FAST32_MAX, true},
        {0, INT_FAST32_MAX, false},
        {INT_FAST32_MAX, INT_FAST32_MAX, true},
        {INT_FAST32_MIN, INT_FAST32_MIN, true}
    };

    bool res = true;

    for (int i = 0; i < LEN(tests); i++) {
        if (add_overflow_int_fast32(tests[i].x, tests[i].y) != tests[i].res) {
            res = false;
            fprintf(stderr, "Failed test %d: add_overflow_int64(%"PRId32", "
                    "%"PRId32"). Expected %d, got %d\n.",
                    i + 1, tests[i].x, tests[i].y, tests[i].res, !tests[i].res);
        }
    }

    return res;
}

int main() {
    if (!add_overflow_int_fast32_test()) { return 1; }
    return 0;
}
