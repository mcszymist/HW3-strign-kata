#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <string>
using std::string;
using std::stringstream;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;
const string removeNonNums(const string &curroptString){
    string curroption = curroptString;
    for(int i = 0;i<curroption.size();i++){
        if(!(curroption[i] >= '0' && curroption[i] <= '9')){
            curroption[i] = ' ';
        }
    }
    return curroption;
}

int add(const string &addable){
    stringstream ss;
    ss.str(removeNonNums(addable));
    cout << ss.str();
    vector<int> addableNums{};
    int storage = 0;
    while(ss >> storage){
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
TEST_CASE( "add triple num str [triple]" ) {
    REQUIRE( add("1,2,3") == 6);
}
TEST_CASE( "add mass num str [massLength]" ) {

    REQUIRE( add("1,1,1,1,1,1,1,1,1,1") == 10);
    REQUIRE( add("3456788")==3456788);
}
TEST_CASE( "add different chars num str [delimiters]" ) {
    REQUIRE( add("1\n2,3")==6);
}