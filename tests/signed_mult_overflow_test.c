#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>

#include "overflow.h"

#define LEN(xs) ((int)(sizeof(xs) / sizeof(xs[0])))

bool mult_overflow_int64_test() {
    struct {int64_t x, y; bool res;} tests[25] = {
        {1, 1, false},
        {-1, -1, false},
        {0, 0, false},
        {-1, 1, false},
        {1, -1, false},
        {3, 5, false},
        {-4, -4, false},
        {-18, 2, false},
        {9, -3, false},
        {INT64_MIN, -1, true},
        {INT64_MIN, 1, false},
        {INT64_MIN, 0, false},
        {-1, INT64_MIN, true},
        {1, INT64_MIN, false},
        {0, INT64_MIN, false},
        {INT64_MAX, 1, false},
        {INT64_MAX, -1, false},
        {INT64_MAX, 0, false},
        {1, INT64_MAX, false},
        {-1, INT64_MAX, false},
        {0, INT64_MAX, false},
        {INT64_MAX, INT64_MAX, true},
        {INT64_MAX / 2, INT64_MAX / 2, true},
        {INT64_MIN / 2, INT64_MIN / 2, true},
        {INT64_MIN, INT64_MIN, true}
    };

    bool res = true;

    for (int i = 0; i < LEN(tests); i++) {
        if (mult_overflow_int64(tests[i].x, tests[i].y) != tests[i].res) {
            res = false;
            fprintf(stderr, "Failed test %d: add_overflow_int64(%"PRId64", "
                    "%"PRId64"). Expected %d, got %d\n.",
                    i + 1, tests[i].x, tests[i].y, tests[i].res, !tests[i].res);
        }
    }

    return res;
}

int main() {
    if (!mult_overflow_int64_test()) { return 1; }
    return 0;
}
