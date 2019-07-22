#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <cstdint>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <string>
#include <sstream>
#include <vector>

#include <doctest.h>
#include <lab14.h>


SCENARIO( "Frequency counts for word lists") {
  GIVEN( "the default lab word list" ) {
    std::vector<std::string> words = {
        "bake", "foo", "Alice", "Bob", "darla", "maps",
        "make", "alice", "Darla", "bat", "seat",
        "set", "FOO", "AlicE", "bob", "bait", "map"
    };

    WHEN( "the counting function does nothing" ) {
      auto actual_counts = mesa::frequency_table(words,
           [] (const std::string s) {return s;} );
      THEN( "the frequency of every word should equal 1" ) {
        for (const auto& word: words) {
          CAPTURE(word);
          REQUIRE(actual_counts[word] == 1);
        }
      }
    }
    WHEN( "counting lowercase words" ) {
      auto actual_counts = mesa::frequency_table(words, mesa::to_lower);
      std::map<std::string, size_t> expected = {
          {"alice", 3}, {"bait",  1}, {"bake", 1}, {"bat",  1},
          {"bob",   2}, {"darla", 2}, {"foo",  2}, {"make", 1},
          {"map",   1}, {"maps",  1}, {"seat", 1}, {"set",  1}
      };
      THEN( "the frequency of words should equal 1 except alice=3, bob,darla, foo = 2" ) {
        for (const auto& word: words) {
          CAPTURE(word);
          REQUIRE(actual_counts[word] == expected[word]);
        }
      }
    }
    WHEN( "counting without vowels" ) {
      std::vector<std::string> words = {
          "bake", "foo", "alice", "bob", "darla", "map",
          "make", "alice", "darla", "bat", "seat",
          "set", "foo", "alice", "bob", "bait", "map"
      };
      auto actual_counts = mesa::frequency_table(words,
           [] (const std::string& s) {
           std::string t = s;
               t.erase(std::remove_if(t.begin(), t.end(), 
                 [](unsigned char x){return x=='a'||x=='e'||x=='i'||x=='o';} ), t.end());
               return t;
           }
      );
      std::map<std::string, size_t> expected = {
          {"lc", 3}, {"bt",  2}, {"bk", 1},
          {"bb",   2}, {"drl", 2}, {"f",  2}, {"mk", 1},
          {"mp",   2}, {"st", 2}
      };
      THEN( "the frequency of words should equal 1 except alice=3, bob,darla, foo = 2" ) {
        for (const auto& word: words) {
          CAPTURE(word);
          REQUIRE(actual_counts[word] == expected[word]);
        }
      }
    }
  }
}

SCENARIO( "Compute the invariants of frequency table") {

  GIVEN( "null data" ) {
    std::vector<std::string> words;
    WHEN( "an empty vector is provided" ) {
      auto actual = mesa::frequency_table(words,
           [] (std::string s) {return s;} );
      THEN( "the frequency table should be empty" ) {
        REQUIRE(actual.empty() == true);
      }
    }
  }
}




