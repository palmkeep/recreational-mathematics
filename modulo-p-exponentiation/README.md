# Integer operations modulo P
The program is used to evaluate an arbitrary series of functions on the integers modulo some value M.

You can specify a series of these functions to perform on all integers in the range by enterering a string of chars.
Each char corresponding to the position of the wanted function in the table.

Be careful, no overflow-checks are performed.

## Squaring modulo 1+2\*\*e
Some interesting patterns:

    mod(5),     cmdline(aa a)
    
    mod(17),    cmdline(aaaa a)
    
    mod(257),   cmdline(aaaa aaaa a)
    
Additional square-op to show stability.

\*Appears as though\* if 1+2\*\*e is prime, then for all n which are not congruent with 0 mod 1+2\*\*e, iterating:

    n_{i+1} = (n_i)**2 (mod 1+2**e)
    
will always result in:

    n_e congruent with 1 (mod 1+2**e)


## Cubing modulo 2+3\*\*e
Similar-ish result for cubes:

    mod(2+3**2), cmdline(bbbb)
    
    mod(2+3**3), cmdline(bbbb bb)
    
    mod(2+3**4), cmdline(bbbb bbbb)
    
    Won't work with: [5,7]
    
    mod(2+3**8), cmdline( 16 b's )
    
    mod(2+3**10), cmdline( 20 b's )
    
Where after e\*2 iterations all the integers are back in their original equivalence classes.

