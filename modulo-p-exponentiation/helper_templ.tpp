#include <iomanip>

/*
 * printVectorFactory<>()
 *
 * Used to generate vector<T> print function with a
 * predefined print width.
 */
template<typename T, std::size_t W>
void printVectorFactory(std::vector<T> const& arr)
{
    if ( arr.empty() ) return;

    std::cout << std::setw(W) << *arr.cbegin();
    for (auto it{ ++arr.cbegin() }; it < arr.cend(); ++it) {
        std::cout << ' ' << std::setw(W) << *it;
    }
    std::cout << std::endl;
}


// Function composition operator
template<typename T3, typename T2, typename T1>
std::function<T3(T1)> operator*
    (std::function<T3(T2)> const& f,
     std::function<T2(T1)> const& g)
{
    return [&f,&g](T1&& t) {
        return f( g( std::forward<T1&&>(t)) );
    };
}


/*
 * Stores user provided value in the dest argument
 */
template<typename T>
void promptInputAndStore(T& dest, std::string const& prompt)
{
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> dest) {
            break;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

