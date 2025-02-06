#include "fixture.hpp"

#include <cstdio>

kustest::Fixture::Fixture() noexcept
{
}

kustest::Fixture::~Fixture()
{
    std::fflush(stdout);
    std::fflush(stderr);
}
