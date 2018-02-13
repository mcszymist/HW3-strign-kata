#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <string>
using std::string;

int add(const string &addable){

}

TEST_CASE( "add null str [add]" ) {
    REQUIRE( add("") == 0 );

}