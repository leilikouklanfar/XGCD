/**
 * @file mpz_xgcd.h
 * Random mzp number creator
 */
#pragma once
#ifndef RNG_H
#define RNG_H

#include <gmp.h>
#include <time.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  gmp_randstate_t state;
  // Creates a new multiple precision integer.
  mpz_t mpz_num;
} mpz_rand_num;


int get_i16_rn();
uint32_t get_ui16_rn();
uint32_t get_ui31_rn();
char* get_nbit_rn(int entropy);

void seed(mpz_rand_num* rand_num);
void init_mpz_rand_num(mpz_rand_num* rand_num);
void gen_rand_num_leq_nbits(mpz_rand_num* rand_num, int nbits);
char* gen_rand_nbits_num(mpz_rand_num* rand_num, int nbits);
void clean_up(mpz_rand_num* rand_num);
uint32_t current_nanos();
int getSize (char * s);



#endif 

