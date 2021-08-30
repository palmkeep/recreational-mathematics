#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>


void print_b64(const uint64_t n)
{
    char binary_str[65]; binary_str[64] = '\0';
    for (int i=63; 0 <= i; --i) {
        binary_str[63-i] = (char)(48 + ((n>>i)&1));
    }
    printf("0b%s", binary_str);
}


/*
 * Constructs the number c so:
 *      n * c = (2**i) - 1,
 * with i being the smallest possible integer where the equality holds.
 *
 * Algorithm works by calculating the repeating part of the fraction: 1/n.
 * The finite repeating sequence, without leading zeroes, is the complementary number c.
 *
 */
int calc_n(uint64_t n)
{
    if (n%2 == 0) {
        puts("Error: n cannot be 0 or divisible by 2");
        return -1;
    } else if (n > ((uint64_t)(-1)>>1)) {
        puts("Error: n is to large");
        return -1;
    } else if (n == 1) {
        puts("Error: trivial, 1*1 == 2-1");
        return -1;
    }


    puts("Calculating c in: n * c == (2**i) - 1");

    uint64_t c = 1;
    uint64_t digits = 0;
    while (c < n) {
        c <<= 1;
    }
    c -= n;
    fputs("c = 0b1", stdout);
    ++digits;

    while (c != 1) {
        c <<= 1;
        while (c < n) {
            c <<= 1;
            fputs("0", stdout);
            ++digits;
        }
        c -= n;
        fputs("1", stdout);
        ++digits;
    }
    fputs("\n", stdout);
    fputs("n = ", stdout); print_b64(n); fputs("\n", stdout);

    uint64_t nDigits = 1;
    while (n >> nDigits) {
        ++nDigits;
    }

    printf("%lu binary digits in c\n", digits);
    printf("%lu binary digits in n\n", nDigits);

    return 0;
}



int main(int argc, char** argv)
{
    if (argc < 2) {
        puts("Usage: ./all-bin-ones <N>, N%2 == 1");
        return -1;
    }

    uint64_t N;
    sscanf(argv[1], "%lu", &N);
    int retCode = calc_n(N);

    return retCode;
}



