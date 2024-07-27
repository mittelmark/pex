#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <regex>
#include <cctype>

namespace pex {
class dstring {
private:
    std::string str = "";
    std::regex lpattern;
    std::regex upattern;

public:
    // constructors
    dstring(); 
    dstring(const std::string& s);
    dstring(const char* s);
    // methods
    bool starts_with(const std::string& prefix) const ;
    bool ends_with(const std::string & ending);
    bool is_lower();
    bool is_upper();
    dstring & to_upper();
    dstring & to_lower();
    // delegate all methods to std::string
    const std::string& get() const;
    // operators
    // Need to again overload the some operators as delegation
    // only works for methods
    // Overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const dstring & myStr);
    // Overload the >> operator
    friend std::istream& operator>>(std::istream& is, dstring & myStr);
    // Additional useful operators
    dstring& operator+=(const dstring& rhs);
    friend dstring operator+(dstring lhs, const dstring& rhs);
    // Comparison operators
    bool operator==(const dstring& rhs) const ;
    bool operator==(const std::string& rhs) const ;    
    bool operator!=(const dstring& rhs) const;
    bool operator!=(const std::string & rhs) const;
};
} // end namespace
