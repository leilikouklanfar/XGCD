#include "fast_remainder.h"


// fastmod computes (n mod d) given precomputed c
uint32_t fastmod3(uint32_t n) {
  printf("n: %"PRIu32"\n",n);
  printf("c3:%"PRIu64 "\n",c3);
  uint64_t lowbits = c3 * n;
  return ((__uint128_t)lowbits * d3) >> 64;
}
