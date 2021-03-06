# Copyright (c) 2014 Phil Mansfield
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

import sys

###############################################
# Functions that are glorifies format strings #
###############################################

###################
# Function bodies #
###################

license = """/* Copyright (c) 2014 Phil Mansfield
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE. */

"""

C_TEXT = license + """#include "overflow.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <signal.h>
#include <wchar.h>

/* This file is autogenerated by pemutils/scripts/overflow_gen.py
 * All edits will be deleted. */

%s"""

def c_text(funcs):
    return C_TEXT % ("\n\n".join(funcs))

H_TEXT = license + """#ifndef PEMUTIL_OVERFLOW_H_
#define PEMUTIL_OVERFLOW_H_

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <signal.h>
#include <wchar.h>

/* This file is autogenerated by pemutils/scripts/overflow_gen.py
 * All edits will be deleted. */

%s

#endif /* PEMUTIL_OVERFLOW_H_ */"""

def h_text(funcs):
    return H_TEXT % ("\n".join(funcs))

############
# Addition #
############

ADD_SIGNED_BODY = """    if ((x <= 0 && y >= 0) || (x >= 0 && y <= 0)) {
        return false;
    } else if (x > 0) {
        return x > %s - y;
    } else {
        return x < %s - y;
    }"""

def add_signed_body(min_name, max_name):
    return ADD_SIGNED_BODY % (max_name, min_name)

ADD_UNSIGNED_BODY = "    return x > %s - y;"

def add_unsigned_body(min_name, max_name):
    return ADD_UNSIGNED_BODY % max_name

ADD_FUNCTION_WRAPPER = """bool add_overflow_%s(%s x, %s y) {
%s
}"""

def add_function_wrapper(var_name, type_name, body):
    return ADD_FUNCTION_WRAPPER % (var_name, type_name, type_name, body)

ADD_FUNCTION_HEADER = "bool add_overflow_%s(%s x, %s y);"

def add_function_header(var_name, type_name):
    return ADD_FUNCTION_HEADER % (var_name, type_name, type_name)

##################
# Multiplication #
#################

MULT_SIGNED_BODY = """    if (x == 0 || y == 0) {
        return false;
    } else if (x > 0 && y > 0) {
        return %s / x < y;
    } else if (x < 0 && y < 0) {
        return %s / x > y;
    } else if (x < 0 && y > 0) {
        return %s / y > x;
    } else { // x > 0 && y < 0
        return %s / x > y;
    }"""

def mult_signed_body(min_name, max_name):
    return MULT_SIGNED_BODY % (max_name, max_name, min_name, min_name)

MULT_UNSIGNED_BODY = "    return x != 0 && (x * y) / x != y;"

def mult_unsigned_body(min_name, max_name):
    return MULT_UNSIGNED_BODY

MULT_FUNCTION_WRAPPER = """bool mult_overflow_%s(%s x, %s y) {
%s
}"""

def mult_function_wrapper(var_name, type_name, body):
    return MULT_FUNCTION_WRAPPER % (var_name, type_name, type_name, body)

MULT_FUNCTION_HEADER = "bool mult_overflow_%s(%s x, %s y);"

def mult_function_header(var_name, type_name):
    return MULT_FUNCTION_HEADER % (var_name, type_name, type_name)


##################################
# Dealing with unspecified signs #
##################################

UNSPECIFIED_BODY ="""#if (%s != 0)
%s
#else
%s
#endif
"""

def unspecified_body(min_name, signed_body, unsigned_body):
    return UNSPECIFIED_BODY % (min_name, signed_body, unsigned_body)

##########################
# body name manipulation #
##########################

def fixed_width_names(n):
    names = [(True, "int%d" % n), (False, "uint%d" % n),
             (True, "int_fast%d" % n), (False, "uint_fast%d" % n),
             (True, "int_least%d" % n), (False, "uint_least%d" % n)]
    return [(b, var_name, "%s_t" % var_name) for (b, var_name) in names]

# Non-pattern-based type names. Tuples are (is_signed, var_name, type_name),
# where var_name is an undercase version of the string used type's limits.
names = [(True, "schar", "signed char"),
         (False, "uchar", "unsigned char"),
         (True, "shrt", "short"), (False, "ushrt", "unsigned short"),
         (True, "int", "int"), (False, "uint", "unsigned int"),
         (True, "long", "long"), (False, "ulong", "unsigned long"),
         (True, "llong", "long long"), (False, "ullong", "unsigned long long"),
         (False, "size", "size_t"),
         (True, "intmax", "intmax_t"), (False, "uintmax", "uintmax_t"),
         (True, "intptr", "intptr_t"), (False, "uintptr", "uintptr_t"),
         (None, "wchar", "wchar_t"), (None, "sig_atomic", "sig_atomic_t"),
         (None, "wint", "wint_t"), (None, "char", "char")
]

for n in [8, 16, 32, 64]: names += fixed_width_names(n)

def min_max_names(var_name):
    return "%s_MIN" % var_name.upper(), "%s_MAX" % var_name.upper()

def main():
    if len(sys.argv) != 3:
        print ("%s requires two arguments: target .h file and target .c file" %
               sys.argv[0])
        exit(1)

    target_h, target_c = sys.argv[1], sys.argv[2]

    with open(target_h, "w+") as fp:
        funcs = []
        for (_, var_name, type_name) in names:
            funcs.append(add_function_header(var_name, type_name))

        funcs.append("")

        for (_, var_name, type_name) in names:
            funcs.append(mult_function_header(var_name, type_name))

        fp.write(h_text(funcs))

    with open(target_c, "w+") as fp:
        funcs = []
        for (is_signed, var_name, type_name) in names:
            min_name, max_name = min_max_names(var_name)
            signed_body = add_signed_body(min_name, max_name)
            unsigned_body = add_unsigned_body(min_name, max_name)
            if is_signed is None:
                body = unspecified_body(min_name, signed_body, unsigned_body)
            elif is_signed:
                body = signed_body
            else:
                body = unsigned_body
            funcs.append(add_function_wrapper(var_name, type_name, body))

        for (is_signed, var_name, type_name) in names:
            min_name, max_name = min_max_names(var_name)
            signed_body = mult_signed_body(min_name, max_name)
            unsigned_body = mult_unsigned_body(min_name, max_name)
            if is_signed is None:
                body = unspecified_body(min_name, signed_body, unsigned_body)
            elif is_signed:
                body = signed_body
            else:
                body = unsigned_body
            funcs.append(mult_function_wrapper(var_name, type_name, body))

        fp.write(c_text(funcs))

main()
