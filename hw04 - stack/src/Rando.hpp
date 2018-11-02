#ifndef THIS___RANDO_HPP
#define THIS___RANDO_HPP

#include <algorithm>
#include <array>
#include <functional>
#include <limits>
#include <random>
#include <type_traits>

/*
 * This class serves as a wrapper around the mt19937 PRNG. It ensures proper 
 * seeding without the need to carry extra lines of code and plop them into 
 * every program.
 * 
 * Rando class has been modified to be a template of >only< unsigned integer types
 */
template <typename T>
class Rando {

    // Rando is now a template class, and this static_assert guarantees 
    // a Rando object can only be instantiated if it is of any unsigned type
    static_assert(std::is_unsigned<T>::value, "Not an unsigned type");

public:
    Rando();
    T operator()();

    using result_type = T;   // aliases are preferred over typedefs as of C++11
    result_type min();
    result_type max();
private:
    std::mt19937 engine;
};


// RANDO FUNCTIONS
template < typename T>
Rando<T>::Rando()
{
    // Proper seeding of mt19937 taken from:
    // https://kristerw.blogspot.com/2017/05/seeding-stdmt19937-random-number-engine.html
    std::random_device rd;
    std::array<T, std::mt19937::state_size> seed_data;
    std::generate_n(seed_data.data(), seed_data.size(), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    engine = std::mt19937(seq);
}

// These functions are required for uniform_int_distribution to work
template <typename T>
T Rando<T>::operator()()
{
    return engine();
}

template <typename T>
typename Rando<T>::result_type Rando<T>::min()
{
    return std::numeric_limits<unsigned int>::min();
}

template <typename T>
typename Rando<T>::result_type Rando<T>::max()
{
    return std::numeric_limits<unsigned int>::max();
}


#endif