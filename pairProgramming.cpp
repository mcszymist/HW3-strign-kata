#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <string>
using std::string;

int add(const string &addable){
    if(addable.size()==0){
        return 0;
    }
    return 1;
}

TEST_CASE( "add null str [add]" ) {
    REQUIRE( add("") == 0 );
    REQUIRE( add("1") == 1);
    REQUIRE( add("1,2") == 3);

}