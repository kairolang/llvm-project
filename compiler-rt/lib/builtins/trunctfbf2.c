//===--------- lib/trunctfbf2.c - quad -> bfloat conversion -------*- C -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#define QUAD_PRECISION
#include "fp_lib.h"

// Any target with TF mode: nothing below is x86-specific, and the backends
// of i686, RISC-V and others emit __trunctfbf2 for an f128 -> bf16 cast.
// The file is only built where __bf16 exists (BF16_SOURCES).
#if defined(CRT_HAS_TF_MODE)
#define SRC_QUAD
#define DST_BFLOAT
#include "fp_trunc_impl.inc"

COMPILER_RT_ABI dst_t __trunctfbf2(src_t a) { return __truncXfYf2__(a); }

#endif
