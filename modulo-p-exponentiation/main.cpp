#include <iostream>

#include <cstdint>
#include <limits>

#include <algorithm>

#include "helper_templ.tpp"


/*
 *  Executes a series of uint64_t(uint64_t) functions on the integers
 *  modulo some choosen integer.
 *
 *  Second prompt is for an entire line of commands, represented as
 *  individual chars.
 *  Check function table below for char -> lambda mapping.
 *
 */
int main()
{
    using std::uint64_t;
    auto printVector = printVectorFactory<uint64_t, 2>;

    uint64_t modulus;
    promptInputAndStore(modulus, "Enter modulus: ");

    // Create array of integers in (mod modulus)
    std::vector<uint64_t> arr;
    arr.resize( static_cast<size_t>(modulus) );
    for (size_t i{0}; i < modulus; ++i) {
        arr[i] = i;
    }
    

    // Setup function table 
    std::vector< std::function<uint64_t(uint64_t)> > function_table;
    function_table.push_back( [](uint64_t i){ return i*i; } );                  // A
    function_table.push_back( [](uint64_t i){ return i*i*i; } );                // B
    function_table.push_back( [](uint64_t i){ return i*i*i*i; } );              // C
    function_table.push_back( [](uint64_t i){ return i*i*i*i*i; } );            // D
    function_table.push_back( [](uint64_t i){ return i*i*i*i*i*i; } );          // E
    function_table.push_back( [](uint64_t i){ return i+1; } );                  // F 
    function_table.push_back( [](uint64_t i){ return i-1; } );                  // G
    function_table.push_back( [modulus](uint64_t i){ return i+modulus-1; } );   // H
    function_table.push_back( [](uint64_t i){ return i; } );                    // I
   
    std::function<uint64_t(uint64_t)> clamp{
        [modulus](uint64_t i){ return i % modulus; }
    };


    // Print initial state of the array
    std::cout << "[I]  |";
    printVector(arr);

    // Apply lambdas specified on std::cin by chars from function
    // table on each element in the array and print
    std::string line;
    std::getline(std::cin, line);

    for (char const c : line)
    {
        // Only evaluate chars in: [a-z] or [A-Z]
        // Equivalent: a == A, ..., z == Z
        int c_upper{ std::toupper(c) };
        if ( !(65 <= c_upper && c_upper <= 90) ) { continue; }

        size_t findex{ static_cast<size_t>(c_upper-65) };
        std::cout
            << '['
            << (char)(65 + findex)
            << "]  |";
        
        // Apply lambda
        std::ranges::transform(
                arr,
                arr.begin(),
                clamp * function_table[ findex ]
        );

        printVector(arr);
    }
}
