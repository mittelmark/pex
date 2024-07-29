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
    argparse::ArgumentParser program("argparse");
    int x;      // decimal points    double y;   // float to be rounded 
    double number ;
    bool verbose = false;
    bool version = false;
    // positional argument no leading dash
    program.add_argument("number")
          .help("display the square of this given number")
          .metavar("NUMBER")
          .scan<'f',float>().store_into(number);
    // option with parameter -leading dash
    program.add_argument("--round").help("round a number").metavar("POINTS")
                .choices(0,1,2,3,4,5,6,7,8,9).store_into(x); 
    // flag
    program.add_argument("-v", "--verbose")
                .help("set verbose on")
                .default_value(false)
                .implicit_value(true)
                .store_into(verbose);
    program.add_argument("-v", "--version")
          .help("show version information")
          .default_value(false)
          .implicit_value(true)
          .action([&](const auto &){ std::cout << "0.0.1\n"; exit(0); });
    try {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << std::regex_replace(USAGE,std::regex("APPNAME"),argv[0]) 
              << std::endl;
        exit(0);
    }
    if (verbose) { std::cout << "verbose is on\n"; }
    std::cout << "square of: " << number << " is " <<
          std::fixed << std::setprecision(x) <<
          number*number <<  std::endl;
    return 0;
}
