// RUN: %clang_cc1 -triple mips-none-linux-gnu -emit-llvm -w -o - %s | FileCheck --check-prefix=NEW %s

// RUN: %clang_cc1 -triple mips64-none-linux-gnu -emit-llvm -w -target-abi n32 -o - %s | FileCheck --check-prefix=NEW %s
// RUN: %clang_cc1 -triple mips64-none-linux-gnu -emit-llvm -w -o - %s | FileCheck --check-prefix=NEW %s

// O32 has __int128 too in this fork (MipsTargetInfo::hasInt128Type), the
// same as N32/N64, so all three share NEW.

int check_int128(void) {
  return sizeof(__int128);
// NEW: ret i32 16
}
