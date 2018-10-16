#ifndef THIS___RANDO_HPP
#define THIS___RANDO_HPP

#include <random>

/*
 * This class serves as a wrapper around the mt19937 PRNG. It ensures proper 
 * seeding without the need to carry extra lines of code and plop them into 
 * every program.
 * 
 * Rando class tested to at least work with uniform_int_distribution<unsigned int>
 */
class Rando {
public:
    Rando();
    unsigned int operator()();

    using result_type = unsigned int;   // aliases are preferred over typedefs as of C++11
    result_type min();
    result_type max();
private:
    std::mt19937 engine;
};

#endif