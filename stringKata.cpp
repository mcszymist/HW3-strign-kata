#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <string>
using std::string;
using std::stringstream;
using std::to_string;
#include <vector>
using std::vector;
#include <iostream>
using std::cout;

const string removeNonNums(const string &curroptString){
    string curroption = curroptString;
    for(int i = 0;i<curroption.size();i++){
        if(!(curroption[i] >= '0' && curroption[i] <= '9' || curroption[i]=='-')){
            curroption[i] = ' ';
        }
    }
    return curroption;
}

int add(const string &addable){
    stringstream ss(removeNonNums(addable));
    vector<int> addableNums{},negativeNums{};
    int storage = 0;
    while(ss >> storage){
        addableNums.push_back(storage);
    }
    storage = 0;
    for(auto nums : addableNums){
        if(nums < 0){
            negativeNums.push_back(nums);
        }
        storage += nums;
    }
    if(negativeNums.size()!=0){
        string errorCode("negatives not allowed: ");
        for(auto nums : negativeNums){
            errorCode += to_string(nums) + ",";
        }
        errorCode.pop_back();
        throw(errorCode);
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
}
TEST_CASE( "add different chars num str [delimiters]" ) {
    REQUIRE( add("1\n2,3")==6);
}
TEST_CASE ( "negative numbers not allowed [negative]"){
    REQUIRE_THROWS_WITH( add("1,2,3,-4"), "negatives not allowed: -4" );
}
TEST_CASE( "numbers over 1000 not supported [notSupported]"){
    REQUIRE( add("1,2000,3")== 4);

}