/**
 * implementation of some test to check the accuracy of the alorithm
 */
#ifndef __TESTS_H__
#define __TESTS_H__

#include <stdio.h>
#include <gmp.h>

/**
 * do nothing if debug is not enabled
 */
#ifndef DEBUG

#define check_mulltiplier(mpz_primorial,    \
                          cc1_muls,         \
                          cc2_muls,         \
                          sieve_size,       \
                          layers,           \
                          primes,           \
                          min_prime,        \
                          max_prime)

#define check_candidates(mpz_primorial,     \
                         all,               \
                         cc1,               \
                         twn,               \
                         chain_length,      \
                         extension,         \
                         sieve_words,       \
                         test_params)

#define check_ratio(stats)

#define check_sieve(cc1,                     \
                    cc2,                     \
                    twn,                     \
                    ext_cc1,                 \
                    ext_cc2,                 \
                    ext_twn,                 \
                    cc1_muls,                \
                    cc2_muls,                \
                    chain_length,            \
                    sieve_words,             \
                    extensions,              \
                    layers,                  \
                    primes,                  \
                    min_prime,               \
                    max_prime,               \
                    mpz_primorial,           \
                    sieve_size,              \
                    use_first_half)

#define check_primes(primes, two_inverses, len)

#define check_share(share, orig_difficulty, type)
   
#else

#ifndef CHECK_MULLTIPLIER
#define check_mulltiplier(mpz_primorial,    \
                          cc1_muls,         \
                          cc2_muls,         \
                          sieve_size,       \
                          layers,           \
                          primes,           \
                          min_prime,        \
                          max_prime)
#else

/**
 * this checks that the calculated multiplier:
 */
char check_mulltiplier(const mpz_t mpz_primorial,
                       const uint32_t *const cc1_muls, 
                       const uint32_t *const cc2_muls,
                       const uint32_t sieve_size,
                       const uint32_t layers,
                       const uint32_t *const primes,
                       const uint32_t min_prime,
                       const uint32_t max_prime);
#endif

#ifndef CHECK_CANDIDATES
#define check_candidates(mpz_primorial,     \
                         all,               \
                         cc1,               \
                         twn,               \
                         chain_length,      \
                         extension,         \
                         sieve_words,       \
                         test_params)
#else

/**
 * test if an candidate array was soeved correctly
 */
char check_candidates(const mpz_t mpz_primorial,
                      const sieve_t *const all,
                      const sieve_t *const cc1,
                      const sieve_t *const twn,
                      const uint32_t chain_length,
                      const uint32_t extension,
                      const uint32_t sieve_words,
                      TestParams *const test_params);
#endif

#ifndef CHECK_RATIO
#define check_ratio(stats)
#else
/**
 * tests that the ratio of cc1, cc2 and twn candidates are not to different
 */
char check_ratio(const SieveStats *const stats);
#endif

#ifndef CHECK_SIEVE
#define check_sieve(cc1,                     \
                    cc2,                     \
                    twn,                     \
                    ext_cc1,                 \
                    ext_cc2,                 \
                    ext_twn,                 \
                    cc1_muls,                \
                    cc2_muls,                \
                    chain_length,            \
                    sieve_words,             \
                    extensions,              \
                    layers,                  \
                    primes,                  \
                    min_prime,               \
                    max_prime,               \
                    mpz_primorial,           \
                    sieve_size,              \
                    use_first_half)
#else
/**
 * easy sieveing without cache optimation and stuff to check
 * the high performace version
 */
char check_sieve(const sieve_t *const cc1,
                 const sieve_t *const cc2,
                 const sieve_t *const twn,
                 const sieve_t *const ext_cc1,
                 const sieve_t *const ext_cc2,
                 const sieve_t *const ext_twn,
                 const uint32_t *const cc1_muls,
                 const uint32_t *const cc2_muls,
                 const uint32_t chain_length,
                 const uint32_t sieve_words,
                 const uint32_t extensions,
                 const uint32_t layers,
                 const uint32_t *const primes,
                 const uint32_t min_prime,
                 const uint32_t max_prime,
                 const mpz_t    mpz_primorial,
                 const uint32_t sieve_size,
                 const uint32_t use_first_half);
#endif

#ifndef CHECK_PRIMES
#define check_primes(primes, two_inverses, len)
#else
char check_primes(const uint32_t *const primes, 
                  const uint32_t *const two_inverse, 
                  const uint32_t len);
#endif

#ifndef CHACK_SHARE
#define check_share(share, orig_difficulty, type)
#else

/**
 * chacks if a BlockHeader to submit is valid
 */
char check_share(BlockHeader *share, uint32_t orig_difficulty, char type);
#endif

#endif /* DEBUG */

#endif /* __TESTS_H__ */
