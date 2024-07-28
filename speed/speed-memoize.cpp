#include <iostream>
#include <chrono>
#include <map>
#include <regex>
// normal recursive version
int fibr (int x) {
    if (x == 0) {
        return(0);
    } else if (x < 3) {
        return(1) ;
    }
    return(fibr(x-2)+(fibr(x-1)));
}

// constexpr keyword does not help
// can only have on return statement
// and as the number is taken from the argument list of argv
// the compiler does not know how many to compute beforehand
constexpr int fibc (int x) {
    int val = 0;
    if (x == 0) {
        val = 0;
    } else if (x < 3) {
        val = 1 ;
    } else {
        val = fibc(x-2)+(fibc(x-1));
    }
    return(val);
}
// version using memoization with a 
// static map variable
int fibm (int x) {
    static std::map<int,int> myfib;
    if (x == 0) {
        return(0);
    } else if (x < 3) {
        return(1) ;
    }
    if (myfib.count(x)==0) {
        myfib[x]=fibm(x-2)+(fibm(x-1));
    }
    return(myfib[x]);
}
int main (int argc, char * argv[]) {
    if (argc == 1) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return(0);
    }
    if (!std::regex_search(argv[1],std::regex("^[0-9]+$"))) {
        std::cout << "Error: '" << argv[1] << "' is not a number!" << std::endl;
        return(0);
    }
    int n = std::stoi(argv[1]);
    int r = fibm(n);
    std::cout << "Result for fib(" << n <<") = " << r << std::endl;
    auto start = std::chrono::system_clock::now();
    r = fibr(n);
    r = fibr(n);    
    auto diff = std::chrono::system_clock::now() - start ;
    std::cout << "Elapsed time (ms) recursive (" <<r<<"): " << diff.count()/1000000 << std::endl;
    start = std::chrono::system_clock::now();
    r = fibm(n);
    r = fibm(n);    
    diff = std::chrono::system_clock::now() - start ;
    std::cout << "Elapsed time (ms) memoized  (" <<r<<"): " << diff.count()/1000000 << std::endl;
    start = std::chrono::system_clock::now();
    r = fibc(n);
    r = fibc(n);    
    diff = std::chrono::system_clock::now() - start ;
    std::cout << "Elapsed time (ms) constexpr (" <<r<<"): " << diff.count()/1000000 << std::endl;
    return(0);
}
