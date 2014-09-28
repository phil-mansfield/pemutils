pemutils
========

Utility functions for C programs.

Contents
--------

The following headers are found in `pemutils/src`:

* `debug.h` - Useful macros for debugging and failing gracefuly on errors.
              Certain macros assume the use of `c99` or later.
* `overflow.h` - Functions which check for integer overflow on all integer
                 types and all fixed-width integer types defined in
                 `stdint.h`.

The following files are bundled into `pemutils.a`:

* `overflow.c` - Functions which check for integer overflow on all integer
                 types and all fixed-width integer types defined in
                 `stdint.h`.

To Use
------

Call `make` in the root `pemutils/` directory to build `libpemutils.a` in
`pemutils/build/`. You may also want to run [make tests] to ensure everything
is working fine.

When compiling, add the flag `-I path/to/pemutils/src/` while creating object
files, and the flags `-L path/to/pemutils/build` and `-lpemutils` while linking.