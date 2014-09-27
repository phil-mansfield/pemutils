#ifndef PEMUTILS_DEBUG_H_

#include <assert.h>
#include <stdio.h>

#ifdef DEBUG
#define debug_assert()
#define debug_printf(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else /*!DEBUG*/
#define debug_assert()
#define debug_printf(fmt, ...)
#endif /* DEBUG */

#define print_location() printf("%s:%s:%d", __FILE__, __PRETTY_FUNCTION__, __LINE__)
#define println_location() printf("%s:%s:%d\n", __FILE__, __PRETTY_FUNCTION__, __LINE__)

#define check_mem(ptr)

#endif /* PEMUTILS_DEBUG_H_ */
