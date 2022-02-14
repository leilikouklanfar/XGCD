#include "fast_remainder.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>
#include "../Time HOAC/rng.h"
long get_nanos();
uint32_t time_fast_mod(uint32_t num);
uint32_t time_mod_operator(uint32_t num);
//https://stackoverflow.com/questions/361363/how-to-measure-time-in-milliseconds-using-ansi-c/36095407#36095407


int main(void) {
    long time_mod3_operator = 0UL;
    //long time_mod5_operator = 0UL;
    long time_fast3_rem = 0UL;
    long stop_time;
    long start_time;
    uint32_t rnum_ui31;
    uint32_t isDiv;

    for(int i=0; i<100; i++){
       printf("\nROUND #%d\n",i);
       rnum_ui31 = get_ui31_rn();
       printf("For ui31bit: %" PRIu32 "\n",rnum_ui31);

       start_time = get_nanos();
       // Use operator
       isDiv = time_mod_operator(rnum_ui31);
       stop_time =  get_nanos();
       time_mod3_operator += stop_time - start_time;
       printf("Operator: %ld\n", time_mod3_operator);

       start_time = get_nanos();
       isDiv = time_fast_mod(rnum_ui31);
       stop_time =  get_nanos();
       time_fast3_rem += stop_time - start_time;
       printf("FastRem: %ld\n", time_fast3_rem);

    }
    return 0;
}

uint32_t time_mod_operator(uint32_t num){
	return num % 3;
}

uint32_t time_fast_mod(uint32_t num){
    uint64_t lowbits = 6148914691236517206 * num;
    return ((__uint128_t)lowbits * d3) >> 64;
}
long get_nanos() {
    struct timespec ts;
    timespec_get(&ts, TIME_UTC);
    return (long)ts.tv_sec * 1000000000L + ts.tv_nsec;
}

