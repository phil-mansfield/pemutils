#include <stdio.h>
#include <limits.h>
#include <inttypes.h>
#include <stdint.h>

#include "overflow.h"

#define LEN(xs) ((int)(sizeof(xs) / sizeof(xs[0])))

bool add_overflow_int64_test() {
    struct {int64_t x, y; bool res;} tests[15] = {
        {1, 2, false},
        {-3, -42, false},
        {0, 0, false},
        {-5, 10, false},
        {10, -5, false},
        {INT64_MIN, -1, true},
        {INT64_MIN, 0, false},
        {-1, INT64_MIN, true},
        {0, INT64_MIN, false},
        {INT64_MAX, 1, true},
        {INT64_MAX, 0, false},
        {1, INT64_MAX, true},
        {0, INT64_MAX, false},
        {INT64_MAX, INT64_MAX, true},
        {INT64_MIN, INT64_MIN, true}
    };

    bool res = true;

    for (int i = 0; i < LEN(tests); i++) {
        if (add_overflow_int64(tests[i].x, tests[i].y) != tests[i].res) {
            res = false;
            fprintf(stderr, "Failed test %d: add_overflow_int64(%"PRId64", "
                    "%"PRId64"). Expected %d, got %d\n.",
                    i + 1, tests[i].x, tests[i].y, tests[i].res, !tests[i].res);
        }
    }

    return res;
}

bool add_overflow_ushrt_test() {
    struct {unsigned short x, y; bool res;} tests[7] = {
        {1, 2, false},
        {0, 0, false},
        {USHRT_MAX, 1, true},
        {USHRT_MAX, 0, false},
        {1, USHRT_MAX, true},
        {0, USHRT_MAX, false},
        {USHRT_MAX, USHRT_MAX, true}
    };

    bool res = true;

    for (int i = 0; i < LEN(tests); i++) {
        if (add_overflow_ushrt(tests[i].x, tests[i].y) != tests[i].res) {
            res = false;
            fprintf(stderr, "Failed test %d: add_overflow_ushrt(%u, "
                    "%u). Expected %d, got %d\n.",
                    i + 1, tests[i].x, tests[i].y, tests[i].res, !tests[i].res);
        }
    }

    return res;
}

int main() {
    if (!add_overflow_int64_test()) { return 1; }
    if (!add_overflow_ushrt_test()) { return 1; }
    return 0;
}
