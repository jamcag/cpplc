#include "catch2/catch_test_macros.hpp"

#include <map>
#include <string_view>

bool can_construct(const std::string_view& ransom_note, const std::string_view& magazine) {
    std::map<char, int> counts;
    for (int i = 0; i < magazine.size(); ++i) {
        if (!counts.contains(magazine.at(i))) {
            counts[magazine.at(i)] = 0;
        }
        counts[magazine.at(i)]++;
    }

    for (int i = 0; i < ransom_note.size(); ++i) {
        if (!counts.contains(ransom_note.at(i))) {
            return false;
        }
        counts[ransom_note.at(i)]--;
    }
    for (const auto[c, count] : counts) {
        if (count < 0) {
            return false;
        }
    }
    return true;
}

TEST_CASE("Given Examples") {
    REQUIRE_FALSE(can_construct("a", "b"));
    REQUIRE_FALSE(can_construct("aa", "ab"));
    REQUIRE(can_construct("aa", "aab"));
}