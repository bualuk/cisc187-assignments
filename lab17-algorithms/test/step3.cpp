#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#define DOCTEST_CONFIG_NO_POSIX_SIGNALS

#include <iterator>
#include <sstream>
#include <string>

#include <doctest.h>
#include <lab17.h>



SCENARIO( "expunge letters") {
  WHEN( "attempting to remove 'a'" ) {
    std::string words = "The rain in Spain falls mainly on the plain.\n";
    std::stringstream actual;
    std::string expected = "The rin in Spin flls minly on the plin.\n";
    mesa::expunge_letter(words.begin(), words.end(), 
                         std::ostream_iterator<char>(actual), 'a');

    THEN( "all the 'a' chars should be removed" ) {
      REQUIRE (expected == actual.str());
    }
  /*
    actual.clear();
    auto expected_pos = std::remove_copy_if(words.begin(), words.end(),
                             std::ostream_iterator<char>(actual), [](char x) {return 'a' == x;});
    AND_THEN( "the distance between the expected and actual iterators should be 0" ) {
      REQUIRE (std::distance(expected_pos, last) == 0);
    }
  */
  }
  WHEN( "attempting to remove 'e'" ) {
    std::string words = "Let's eat Grandma! Yes, commas save lives.";
    std::stringstream actual;
    std::string expected =  "Lt's at Grandma! Ys, commas sav livs.";
    mesa::expunge_letter(words.begin(), words.end(), 
                         std::ostream_iterator<char>(actual), 'e');
    THEN( "all the 'e' chars should be removed" ) {
      REQUIRE (expected == actual.str());
    }
  }
  WHEN( "attempting to remove 's'" ) {
    std::string words = "she sells sea shells by the sea shore";
    std::stringstream actual;
    std::string expected = "he ell ea hell by the ea hore";
    mesa::expunge_letter(words.begin(), words.end(), 
                         std::ostream_iterator<char>(actual), 's');
    THEN( "all the 's' chars should be removed" ) {
      REQUIRE (expected == actual.str());
    }
  }
}

