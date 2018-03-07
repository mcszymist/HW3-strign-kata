#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <string>
using std::string;
using std::stringstream;
#include <vector>
using std::vector;

int add(const string &addable){
    stringstream ss(addable);
    vector<int> addableNums{};
    int storage = 0;
    if(addable.size()==0){
        return 0;
    }
    while(!ss.eof()){
        ss >> storage;
        addableNums.push_back(storage);
    }
    storage = 0;
    for(auto nums : addableNums){
        storage += nums;
    }
    return storage;
}

TEST_CASE( "add null str [null]" ) {
    REQUIRE( add("") == 0 );
}
TEST_CASE( "add single num str [single]" ) {
    REQUIRE( add("1") == 1);
    REQUIRE( add("2") == 2);
}
TEST_CASE( "add double num str [double]" ) {
    REQUIRE( add("1,2") == 3);
}