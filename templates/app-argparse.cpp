#include <iostream>
#include <regex>
#include <stdexcept>
#include <utility>
#include "include/argparse.hpp"

static const char USAGE[] =
R"(Usage: APPNAME [-h,--help -v,--verbose] --round n number
)";

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << std::regex_replace(USAGE,std::regex("APPNAME"),argv[0]) 
              << std::endl;
        return(0);
    }
    std::regex isnumber("^[+-]?([0-9]*[.])?[0-9]+$");
    std::regex isnatural("^[0-9]+$");    
    argparse::ArgumentParser program("argparse");
    // positional arguments:
    program.add_argument("number")
          .help("display the square of this given number")
          .default_value(2);
    // options with values:
    program.add_argument("-r","--round")
          .help("the rounding digits")
          .default_value(2);
    // flags with no values:
    program.add_argument("-v", "--verbose")
          .help("set verbose on")
          .default_value(false)
          .implicit_value(true);
    // defaults:
    std::string number = "";
    float n = 0.0;
    std::string round = "";
    int r = 2;
    bool verbose = false;
    try {
        program.parse_args(argc, argv);
        verbose = program.get<bool>("--verbose"); 
        number = program.get<std::string>("number");
        round = program.get<std::string>("--round");
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << std::regex_replace(USAGE,std::regex("APPNAME"),argv[0]) 
              << std::endl;
        exit(0);
    }
    if (std::regex_search(number,isnumber)) {
        n = std::stof(number);
    } else {
        std::cout << "Error: '" << number << "' is not a number!\n" ;
        return(1);
    }
    if (std::regex_search(round,isnatural)) {
        r = std::stoi(round);
    } else {
        std::cout << "Error: '" << number << "' is not a natural number!\n" ;
        return(1);
       }

    if (verbose) { std::cout << "verbose is on\n"; }
    std::cout << "square of: " << n << " is " <<
          std::fixed << std::setprecision(r) <<
          n*n <<  std::endl;
    return 0;
}
