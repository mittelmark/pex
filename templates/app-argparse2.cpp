#include <iostream>
#include <regex>
#include <stdexcept>
#include <utility>
#include "include/argparse.hpp"

static const char USAGE[] =
R"(Usage: APPNAME [-h,--help -V,--verbose -v,--version -s,--say-hello] --round n number
)";

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << std::regex_replace(USAGE,std::regex("APPNAME"),argv[0]) 
              << std::endl;
        return(0);
    }
    argparse::ArgumentParser program("argparse","0.0.1");
    int x = 2;      // decimal points    double y;   // float to be rounded 
    double number = 0.0;
    bool hello = false;
    bool verbose = false;
    // positional argument no leading dash
    program.add_argument("number")
          .help("display the square of this given number")
          .metavar("NUMBER")
          .scan<'f',float>().store_into(number);
    // option with parameter -leading dash
    program.add_argument("-r","--round").help("round a number").metavar("POINTS")
                .choices(0,1,2,3,4,5,6,7,8,9).store_into(x); 
    // flag
    program.add_argument("-V", "--verbose")
                .help("set verbose on").flag().store_into(verbose);
    // action example
    program.add_argument("-s", "--say-hello")
          .help("Say Hello World!")
          .flag()
          .store_into(hello)
          .action([&](const auto &){ std::cout << "Hello World!\n"; exit(0); });
    
    try {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << std::regex_replace(USAGE,std::regex("APPNAME"),argv[0]) 
              << std::endl;
        exit(0);
    }
    if (program["--verbose"] == true) { std::cout << "verbose is on\n"; }
    std::cout << "square of: " << number << " is " <<
          std::fixed << std::setprecision(x) <<
          number*number <<  std::endl;
    return 0;
}
