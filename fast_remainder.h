/**
 * @file mpz_xgcd.h
 * Random mzp number creator
 */
#pragma once
#ifndef FAST_REMAINDER_H
#define FAST_REMAINDER_H


#include <inttypes.h>
#include <stdio.h>

//MAKE THESE INLINE INSTEAD OF STATIC LATER


static const uint32_t d3 = 3;// your divisor > 0
// c = ceil( (1<<64) / d ) ; we take L = N
static const uint64_t c3 = UINT64_C(0xFFFFFFFFFFFFFFFF) / d3 + 1;


static const uint32_t d5 = 5;// your divisor > 0
// c = ceil( (1<<64) / d ) ; we take L = N
static const uint64_t c5 = UINT64_C(0xFFFFFFFFFFFFFFFF) / d5 + 1;

static const uint32_t d7 = 7;// your divisor > 0
// c = ceil( (1<<64) / d ) ; we take L = N
static const uint64_t c7 = UINT64_C(0xFFFFFFFFFFFFFFFF) / d7 + 1;

static const uint32_t d11 = 11;// your divisor > 0
// c = ceil( (1<<64) / d ) ; we take L = N
static const uint64_t c11 = UINT64_C(0xFFFFFFFFFFFFFFFF) / d11 + 1;

uint32_t fastmod3(uint32_t n);

#endif 

