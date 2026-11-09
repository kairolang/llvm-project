// __int128 is accepted on the 32-bit targets this fork gives it, and the
// __int128_t / __uint128_t typedefs exist.

// RUN: %clang_cc1 -fsyntax-only -verify -triple i686-linux-gnu %s
// RUN: %clang_cc1 -fsyntax-only -verify -triple i686-w64-windows-gnu %s
// RUN: %clang_cc1 -fsyntax-only -verify -triple armv7-linux-gnueabihf %s
// RUN: %clang_cc1 -fsyntax-only -verify -triple thumbv7em-none-eabi %s
// RUN: %clang_cc1 -fsyntax-only -verify -triple riscv32-linux-gnu %s
// RUN: %clang_cc1 -fsyntax-only -verify -triple powerpc-linux-gnu %s
// RUN: %clang_cc1 -fsyntax-only -verify -triple mips-linux-gnu %s
// expected-no-diagnostics

__int128 a = (__int128)-1;
unsigned __int128 b = (unsigned __int128)-1;
__int128_t c;
__uint128_t d;

_Static_assert(sizeof(__int128) == 16, "");
_Static_assert(_Alignof(__int128) == 16, "");
_Static_assert(__SIZEOF_INT128__ == 16, "");
_Static_assert((unsigned __int128)-1 > (unsigned long long)-1, "");
_Static_assert(((__int128)1 << 100) / ((__int128)1 << 99) == 2, "");

__int128 mul(__int128 x, __int128 y) { return x * y; }
