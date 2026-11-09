// RUN: %clang_cc1 -x c   -std=gnu99   -dM -E -triple x86_64-pc-linux %s | FileCheck -check-prefix=NO %s
// RUN: %clang_cc1 -x c++ -std=c++11   -dM -E -triple x86_64-pc-linux %s | FileCheck -check-prefix=NO %s
// i686 has __int128 in this fork (X86_32TargetInfo::hasInt128Type); 32-bit
// SPARC still has none.
// RUN: %clang_cc1 -x c++ -std=gnu++11 -dM -E -triple sparc-pc-linux  %s | FileCheck -check-prefix=NO %s
// RUN: %clang_cc1 -x c++ -std=gnu++11 -dM -E -triple i686-pc-linux   %s | FileCheck -check-prefix=YES %s
// RUN: %clang_cc1 -x c++ -std=gnu++11 -dM -E -triple x86_64-pc-linux %s | FileCheck -check-prefix=YES %s
// RUN: %clang_cc1 -x c++ -std=gnu++1y -dM -E -triple x86_64-pc-linux %s | FileCheck -check-prefix=YES %s
// PR23156

// NO-NOT: __GLIBCXX_TYPE_INT_N_0
// NO-NOT: __GLIBCXX_BITSIZE_INT_N_0
// YES-DAG: __GLIBCXX_TYPE_INT_N_0
// YES-DAG: __GLIBCXX_BITSIZE_INT_N_0
