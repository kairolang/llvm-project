// __SIZEOF_INT128__ (and, for GNU C++, __GLIBCXX_TYPE_INT_N_0) on the 32-bit
// targets this fork gives __int128; still absent where it does not.

// RUN: %clang_cc1 -E -dM -triple=i686-linux-gnu < /dev/null | FileCheck %s
// RUN: %clang_cc1 -E -dM -triple=armv7-linux-gnueabihf < /dev/null | FileCheck %s
// RUN: %clang_cc1 -E -dM -triple=armv6-linux-gnueabihf < /dev/null | FileCheck %s
// RUN: %clang_cc1 -E -dM -triple=riscv32-linux-gnu < /dev/null | FileCheck %s
// RUN: %clang_cc1 -E -dM -triple=powerpc-linux-musl < /dev/null | FileCheck %s
// RUN: %clang_cc1 -E -dM -triple=mips-linux-gnu < /dev/null | FileCheck %s
// RUN: %clang_cc1 -E -dM -triple=mipsel-linux-musl < /dev/null | FileCheck %s
// RUN: %clang_cc1 -x c++ -std=gnu++17 -E -dM -triple=i686-linux-gnu < /dev/null \
// RUN:   | FileCheck %s --check-prefixes=CHECK,GXX
// RUN: %clang_cc1 -E -dM -triple=sparc-linux-gnu < /dev/null \
// RUN:   | FileCheck %s --check-prefix=NONE
// RUN: %clang_cc1 -E -dM -triple=powerpc-ibm-aix < /dev/null \
// RUN:   | FileCheck %s --check-prefix=NONE

// GXX: #define __GLIBCXX_TYPE_INT_N_0 __int128
// CHECK: #define __SIZEOF_INT128__ 16
// NONE-NOT: __SIZEOF_INT128__
