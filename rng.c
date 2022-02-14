#include "rng.h"

const int nbit = 64;
const int base = 10;


/**
INVOKING BY:

  int nbits = 32;
  char* rn1 = get_nbit_rn(nbits);
  char* rn1 = get_nbit_rn(nbits);
  int x = atoi(rnum);
  int y = atoi(rnum);
    
  free(rn1);
  free(rn2);

OR:

  int x = get_16bit_rn();
  int y = get_16bit_rn();
    

 */
//int main(){
  //mpz_rand_num mpz_rnum; 
  //init_mpz_rand_num(&mpz_rnum);
  //seed(&mpz_rnum);
  //char* rnum =get_rn(16);
  //int num_i = atoi(rnum);
  
  //printf("rnum:%s \n", rnum);
  //printf("num_i:%d \n", num_i);
  //free(rnum);
  //return 0;
//}

// MAKE SURE TO FREE MEMORY
// free(char* name)
int get_i16_rn(){
  mpz_rand_num mpz_rnum; 
  init_mpz_rand_num(&mpz_rnum);
  seed(&mpz_rnum);
  char* temp = gen_rand_nbits_num(&mpz_rnum, 16);
  int res = atoi(temp);
  clean_up(&mpz_rnum);
  free(temp);
  return res;
}

//https://stackoverflow.com/questions/34206446/how-to-convert-string-into-unsigned-int-c
uint32_t get_ui16_rn(){
  mpz_rand_num mpz_rnum; 
  init_mpz_rand_num(&mpz_rnum);
  seed(&mpz_rnum);
  char* temp = gen_rand_nbits_num(&mpz_rnum, 16);
  uint32_t res = strtoul(temp, NULL, 10);
  clean_up(&mpz_rnum);
  free(temp);
  return res;
}

//https://stackoverflow.com/questions/34206446/how-to-convert-string-into-unsigned-int-c
uint32_t get_ui31_rn(){
  mpz_rand_num mpz_rnum; 
  init_mpz_rand_num(&mpz_rnum);
  seed(&mpz_rnum);
  char* temp = gen_rand_nbits_num(&mpz_rnum, 31);
  uint32_t res = strtoul(temp, NULL, 10);
  clean_up(&mpz_rnum);
  free(temp);
  return res;
}


// MAKE SURE TO FREE MEMORY
// free(char* name)
/*
uint32 get_16bit_rn(){
  mpz_rand_num mpz_rnum; 
  init_mpz_rand_num(&mpz_rnum);
  seed(&mpz_rnum);
  char* temp = gen_rand_nbits_num(&mpz_rnum, 16);
  int res = atoi(temp);
  clean_up(&mpz_rnum);
  free(temp);
  return res;
}
*/

// MAKE SURE TO FREE MEMORY
// free(char* name)
char* get_nbit_rn(int entropy){
  mpz_rand_num mpz_rnum; 
  init_mpz_rand_num(&mpz_rnum);
  seed(&mpz_rnum);
  char* temp = gen_rand_nbits_num(&mpz_rnum, entropy);
  clean_up(&mpz_rnum);
  return temp;
}

// Create, initialize, and seed a new random number generator.
void seed(mpz_rand_num* rand_num){
  printf("SEED\n");
  uint32_t time = current_nanos();
  gmp_randseed_ui(rand_num->state, time);
}

// Create, initialize, and set the value of rop to 0.
void init_mpz_rand_num(mpz_rand_num* rand_num){
  printf("INIT\n");
  mpz_init(rand_num->mpz_num);
  gmp_randinit_mt(rand_num->state);
  seed(rand_num);
}

// Generate a random integer in the range [0, (2^nbits)-1].
void gen_rand_num_leq_nbits(mpz_rand_num* rand_num, int nbits){
  printf("GEN\n");
  seed(rand_num);
  mpz_urandomb(rand_num->mpz_num, rand_num->state, nbits);
  gmp_printf ("%s is an mpz %Zd\n", "here", rand_num->mpz_num);
}

// Generate a random integer in the range [(2^nbits-1), (2^nbits)-1].
//
// char * mpz_get_str (char *str, int base, const mpz_t op)
// Convert op to a string of digits in base base.
// https://gmplib.org/manual/Converting-Integers
//
// MUST FREE MEMORY!!!
// char* num = gen_rand_nbits_num(..);
// printf("%s \n", num);
// free(num);
//
char* gen_rand_nbits_num(mpz_rand_num* rand_num, int nbits){
  seed(rand_num);
  mpz_rrandomb(rand_num->mpz_num, rand_num->state, nbits);
  gmp_printf ("%s is an mpz %Zd\n", "here", rand_num->mpz_num);
  char *string = malloc(64);
  return mpz_get_str(NULL,base,rand_num->mpz_num);
}

// Free all memory occupied by state and rop.
void clean_up(mpz_rand_num* rand_num){  
  gmp_randclear(rand_num->state);
  mpz_clear(rand_num->mpz_num);
}

// gives the time from system on in as an unsigned long int
uint32_t current_nanos() {
  struct timespec res;
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &res);
  return (res.tv_sec * 100000UL) + res.tv_nsec;
}

int getSize (char * s) {
    char * t;    
    for (t = s; *t != '\0'; t++){
      printf("t%s\n",t);
    }
    return t - s;
}


