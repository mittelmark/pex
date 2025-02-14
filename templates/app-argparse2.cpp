#include <iostream>
#include <stdexcept>
#include <utility>
#include "include/argparse.hpp"

int main(int argc, char *argv[]) {
    //                               appname  version
    argparse::ArgumentParser program(argv[0],"0.0.1");
    int r = 2;             // decimal points 
    double number = 0.0;   // float to be rounded 
    bool verbose = false;  // verbose example
    // positional argument: no leading dash
    program.add_argument("number")
          .help("display the square of this given number")
          .metavar("NUMBER")
          .scan<'f',float>().store_into(number);
    // option with parameter: leading dash(es)
    program.add_argument("-r","--round").help("round a number").metavar("POINTS")
                .choices(0,1,2,3,4,5,6,7,8,9).store_into(r); 
    // flag
    program.add_argument("-V", "--verbose")
                .help("set verbose on").flag().store_into(verbose);
    // action example for flag
    program.add_argument("-s", "--say-hello")
          .help("Say Hello World!")
          .flag()
          .action([&](const auto &){ std::cout << "Hello World!\n"; exit(0); });
    
    try {
        program.parse_args(argc, argv);
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program.usage() << std::endl;
        std::exit(1);
    }
    if (verbose) { std::cout << "verbose is on\n"; }
    std::cout << "square of: " << number << " is " <<
          std::fixed << std::setprecision(r) <<
          number*number <<  std::endl;
    return 0;
}
