#include <utility>
#include <regex>
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
          .help("display the square of this given number");
    // options with values:
    program.add_argument("-r","--round")
          .help("the rounding digits");
    // flags with no values:
    program.add_argument("-v", "--verbose")
          .help("set verbose on")
          .default_value(false)
          .implicit_value(true);
    try {
        program.parse_args(argc, argv);
    }
    catch (const std::runtime_error& err) {
        std::cout << err.what() << std::endl;
        std::cout << program;
        exit(0);
    }
    auto number = program.get<std::string>("number");
    auto x = 0.0;
    if (std::regex_search(number,isnumber)) {
        x = std::stof(number);
    } else {
        std::cout << "Error: '" << number << "' is not a number!\n" ;
        return(1);
    }
    auto round = program.get<std::string>("--round");
    auto r = 2;
    if (std::regex_search(round,isnatural)) {
        r = std::stoi(round);
    } else {
        std::cout << "Error: '" << number << "' is not a natural number!\n" ;
        return(1);
    }
    std::cout << r << std::endl;

    auto verbose = program.get<bool>("--verbose"); 
    if (verbose) { std::cout << "verbose is on\n"; }
    std::cout << "square of: " << x << " is " <<
          std::fixed << std::setprecision(r) <<
          x*x <<  std::endl;
    return 0;
}
