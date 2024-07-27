#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "include/doctest.h"
#include "pex.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

TEST_CASE("testing the string functions") {
    CHECK(pex::to_lower("Hello") == "hello");
    CHECK(pex::to_lower("HELLO") == "hello");    
    CHECK(pex::to_upper("HeLlO") == "HELLO");        
    CHECK(pex::to_upper("hello") == "HELLO");        
    CHECK(pex::starts_with("dummy","dum") == true); 
    CHECK(pex::starts_with("dummy","dummy") == true);
    CHECK(pex::ends_with("dummy", "mmy") == true);    
    CHECK(pex::ends_with("dummy","dummy") == true);        
    CHECK(pex::ends_with("dummy","ummx") == false); 
    CHECK(pex::is_lower("dummy123") == false);
    CHECK(pex::is_lower("dummy") == true);    
    CHECK(pex::is_upper("DUMMY") == true);    
    CHECK(pex::is_upper("DUmMY") == false);    
}
TEST_CASE("testing the file functions") {
    CHECK(pex::file_is_compressed("dummy.gz") == true);
    CHECK(pex::file_is_compressed("dummy.obo.GZ") == true);
    CHECK(pex::file_is_compressed("dummy.obo") == false);
    CHECK(pex::file_is_compressed("dummy.obo.gza") == false);
    CHECK(pex::file_has_extension("dummy.obo.gz",".gz") == true);    
    CHECK(pex::file_has_extension("dummy.obo.gz","gz") == true);
    // checks by opening the file
    CHECK(pex::file_exists("dummy.obo") == true);
    CHECK(pex::file_is_gzipped("dummy.obo") == false);
    CHECK(pex::file_is_gzipped("dummy.obo.gz") == true);
}

TEST_CASE("grep functions") {
    std::vector<int> expected = {0, 5};
    std::vector<int> result = pex::grep("he[lL]","helloheLLo");
    CHECK( result == expected );
    expected = {0,2};
    result = pex::grep("he[lL]",{"helloheLLo","world","heLLo"});
    CHECK( result == expected ); 
    CHECK(pex::grepl("he[lL]","hello") == true);
    CHECK(pex::grepl("he[lL]","hexlo") == false);
}

TEST_CASE("all and any functions") {
    std::vector<bool> b1 = {true, true, false};
    std::vector<bool> b2 = {true, true, true};
    CHECK(pex::all(b1) == false);
    CHECK(pex::any(b1) == true);
    CHECK(pex::all(b2) == true);
    CHECK(pex::any(b2) == true);
}
