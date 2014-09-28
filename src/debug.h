#ifndef PEMUTILS_DEBUG_H_

#include <assert.h>
#include <stdio.h>

#ifdef DEBUG
#define debug_assert(expr) assert(expr)
#define debug_printf(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else /*!DEBUG*/
#define debug_assert(expr)
#define debug_printf(fmt, ...)
#endif /* DEBUG */

#define fprint_location(loc) fprintf(loc, "%s: %s: line %d: ", __FILE__, __PRETTY_FUNCTION__, __LINE__)
#define println_location() printf("%s: %s: line %d\n", __FILE__, __PRETTY_FUNCTION__, __LINE__)

#define check(expr, fmt, ...) (if (expr) {fprint_location(stderr); fprintf(stderr, fmt, ##__VA_ARGS__);  exit(1);})

#define check_mem(ptr) check(ptr, "Allocator failed :3")
#define impossible(fmt, ...) check(0, fmt, ##__VA_ARGS__)

#endif /* PEMUTILS_DEBUG_H_ */
