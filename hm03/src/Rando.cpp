#include <algorithm>
#include <array>
#include <functional>
#include <limits>
#include "Rando.hpp"

Rando::Rando()
{
    // Proper seeding of mt19937 taken from:
    // https://kristerw.blogspot.com/2017/05/seeding-stdmt19937-random-number-engine.html
    std::random_device rd;
    std::array<unsigned int, std::mt19937::state_size> seed_data;
    std::generate_n(seed_data.data(), seed_data.size(), std::ref(rd));
    std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
    engine = std::mt19937(seq);
}

// These functions are required for uniform_int_distribution to work
unsigned int Rando::operator()()
{
    return engine();
}

typename Rando::result_type Rando::min()
{
    return std::numeric_limits<unsigned int>::min();
}

typename Rando::result_type Rando::max()
{
    return std::numeric_limits<unsigned int>::max();
}
