#include <catch2/catch_test_macros.hpp>

std::array<int, 3> numbers = { 1, 2, 3 };

namespace {
    struct Person {
        std::string name;
    };
}

TEST_CASE("A std::array can be iterated", "[array]") {
    int sum = 0;
    for (auto i : numbers) {
        sum += i;
    }
    REQUIRE(sum == 6);
}

TEST_CASE("A std::array has a size", "[array]") {
    REQUIRE(numbers.size() == 3);
}

TEST_CASE("A std::array is empty ONLY if the 2nd param is 0", "[array]") {
    constexpr std::array<int, 0> new_array{ };
    REQUIRE(new_array.empty());
}

TEST_CASE("A std::array can use hold custom types", "[array]") {
    const auto p0 = Person{ "Mike1" };
    const auto p1 = Person{ "Mike2" };
    const auto p2 = Person{ "Mike3" };
    std::array<Person, 3> people = { p0, p1, p2};

    REQUIRE(people.at(0).name == p0.name);
    REQUIRE(people.at(1).name == p1.name);
    REQUIRE(people.at(2).name == p2.name);
}