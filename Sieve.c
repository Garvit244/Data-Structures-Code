#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
#define                 bool    _Bool
 
static unsigned long    prime_limit = 1000000;
 
unsigned long sqrtld(unsigned long N) {
    int                 b = 1;
    unsigned long       res,s;
    while(1<<b<N) b+= 1;
    res = 1<<(b/2 + 1);
    for(;;) {
        s = (N/res + res)/2;
        if(s>=res) return res;
        res = s;
    }
}
 
unsigned long * make_primes(unsigned long limit) {
    unsigned long      *primes;
    unsigned long       i,j;
    unsigned long       s = sqrtld(prime_limit);
    unsigned long       n = 0;
    bool *sieve = malloc((prime_limit + 1) * sizeof(bool));
    sieve[0] = 0;
    sieve[1] = 0;
    for(i=2; i<=prime_limit; i++) sieve[i] = 1;
    j = 4;
    while(j<=prime_limit) {
        sieve[j] = 0;
        j += 2;
    }
    for(i=3; i<=s; i+=2) {
        if(sieve[i] == 1) {
            j = i * 3;
            while(j<=prime_limit) {
                sieve[j] = 0;
                j += 2 * i;
            }
        }
    }
    for(i=2;i<=prime_limit;i++) if(sieve[i]==1) n += 1;
    primes = malloc((n + 1) * sizeof(unsigned long));
    primes[0] = n;
    j = 1;
    for(i=2;i<=prime_limit;i++) if(sieve[i]==1) {
        primes[j] = i;
        j++;
    }
    free(sieve);
    return primes;
}
 
 
int main(void) {
 
    unsigned long * primes = make_primes(prime_limit);
 
    printf("There are %ld primes <= %ld\n",primes[0],prime_limit);
 
 
    free(primes);
    return 0;
}
