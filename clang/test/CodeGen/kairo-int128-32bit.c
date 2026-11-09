// Kairo's fork gives __int128 to the 32-bit targets Kairo ships (i386, ARM,
// RV32, 32-bit PowerPC, MIPS o32) without -fforce-enable-int128, with the
// layout that flag gives: size 16, align 16, passed as an i128 in IR. MIPS
// marks it signext/zeroext as it does every integer argument.

// RUN: %clang_cc1 -triple i686-linux-gnu -emit-llvm -o - %s \
// RUN:   | FileCheck %s --check-prefixes=CHECK,PLAIN
// RUN: %clang_cc1 -triple armv7-linux-gnueabihf -emit-llvm -o - %s \
// RUN:   | FileCheck %s --check-prefixes=CHECK,PLAIN
// RUN: %clang_cc1 -triple thumbv7em-none-eabi -emit-llvm -o - %s \
// RUN:   | FileCheck %s --check-prefixes=CHECK,PLAIN
// RUN: %clang_cc1 -triple riscv32-linux-gnu -emit-llvm -o - %s \
// RUN:   | FileCheck %s --check-prefixes=CHECK,PLAIN
// RUN: %clang_cc1 -triple powerpc-linux-gnu -emit-llvm -o - %s \
// RUN:   | FileCheck %s --check-prefixes=CHECK,PLAIN
// RUN: %clang_cc1 -triple mips-linux-gnu -emit-llvm -o - %s \
// RUN:   | FileCheck %s --check-prefixes=CHECK,MIPS
// RUN: %clang_cc1 -triple mipsel-linux-gnu -emit-llvm -o - %s \
// RUN:   | FileCheck %s --check-prefixes=CHECK,MIPS

// CHECK: @size = {{.*}}global i32 16
int size = sizeof(__int128);
// CHECK: @align = {{.*}}global i32 16
int align = _Alignof(__int128);

// PLAIN-LABEL: define{{.*}} i128 @add(i128 noundef %a, i128 noundef %b)
// MIPS-LABEL: define{{.*}} i128 @add(i128 noundef signext %a, i128 noundef signext %b)
// CHECK: add nsw i128
__int128 add(__int128 a, __int128 b) { return a + b; }

unsigned __int128 ext(unsigned __int128);

// PLAIN-LABEL: define{{.*}} i128 @call(i128 noundef %x)
// PLAIN: call i128 @ext(i128 noundef
// MIPS-LABEL: define{{.*}} i128 @call(i128 noundef zeroext %x)
// MIPS: call i128 @ext(i128 noundef zeroext
unsigned __int128 call(unsigned __int128 x) { return ext(x); }
