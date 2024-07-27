#include <algorithm>
#include <iostream>
#include <string>
#include <regex>
#include <cctype>
#include "dstring.hpp"

// Detlef's string class
// extended methods using delegation
// build with help of perplexity:
// https://www.perplexity.ai/search/c-how-can-i-check-that-two-vec-iZg_rVIOTrS_w6zGrWA7jQ

namespace pex {
// constructors
dstring::dstring() : str() {
    lpattern = std::regex("^[a-z]+$");
    upattern = std::regex("^[A-Z]+$");
}
dstring::dstring(const std::string& s) : str(s) {
    lpattern = std::regex("^[a-z]+$");
    upattern = std::regex("^[A-Z]+$");
}
dstring::dstring(const char* s) : str(s) {
    lpattern = std::regex("^[a-z]+$");
    upattern = std::regex("^[A-Z]+$");
}
// methods
bool dstring::starts_with(const std::string& prefix) const {
    return str.rfind(prefix, 0) == 0;
}
bool dstring::ends_with(const std::string & ending) {
    if (str.length() >= ending.length()) {
        return (0 == str.compare(str.length() - ending.length(), ending.length(), ending));
    }
    return false;
}
bool dstring::is_lower() {
    return std::regex_search(str, lpattern);
}
bool dstring::is_upper() {
    return std::regex_search(str, upattern);
}
dstring & dstring::to_upper() {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::toupper(c); });
    return *this;
}

dstring & dstring::to_lower() {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return *this;
}
// Forward other string operations to the internal std::string
// delegate all methods to std::string so pstr.get().length();
const std::string& dstring::get() const {
    return str;
}

// operators
// Need to again overload the some operators as delegation
// only works for methods
// Overload the << operator
std::ostream& operator<<(std::ostream& os, const dstring & myStr) {
    return os << myStr.str;
}
// Overload the >> operator
std::istream& operator>>(std::istream& is, dstring & myStr) {
    return std::getline(is, myStr.str);
}

    // Additional useful operators
    dstring& dstring::operator+=(const dstring& rhs) {
        str += rhs.str;
        return *this;
    }

    dstring operator+(dstring lhs, const dstring& rhs) {
        lhs += rhs;
        return lhs;
    }

    // Comparison operators
    bool dstring::operator==(const dstring& rhs) const {
        return str == rhs.str;
    }
    bool dstring::operator==(const std::string & rhs) const {
        return str == rhs;
    }
    // Comparison operators
    bool dstring::operator!=(const dstring & rhs) const {
        return str != rhs.str;
    }
    bool dstring::operator!=(const std::string & rhs) const {
        return str != rhs;
    }

} // end namespace

#ifdef DSTRING
// compile with g++ -DDSTRING dstring.cpp -o dstring
int main (int argc, char * argv[]) {
    pex::dstring hello("hello");
    std::string hellostd("hello");
    std::cout << (hello == hellostd) << std::endl;
    //std::cout << (hellostd == hello) << std::endl;
    pex::dstring HELLO("HELLO");
    std::cout << (hello != hellostd) << std::endl;
    std::cout << (hello != HELLO) << std::endl;    
    std::cout << hello.is_lower() << std::endl;
    std::cout << hello.is_upper() << std::endl;
    std::cout << HELLO.is_lower() << std::endl;
    std::cout << HELLO.is_upper() << std::endl;
    std::cout << HELLO.to_lower() << std::endl;
    std::cout << HELLO << std::endl;
    std::cout << (HELLO == hello) << std::endl;
    std::cout << (HELLO != hello) << std::endl;
    pex::dstring hello2;
    std::cin >> hello2;
    std::cout << hello2 << std::endl;
}
#endif
