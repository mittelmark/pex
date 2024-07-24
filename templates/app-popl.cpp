#include <iostream>
#include <iomanip>
#include <regex>
#include "include/popl.hpp"

static const char USAGE[] =
R"(Usage: APPNAME [-h,--help -v,--verbose] --round n number
)";


int main (int argc, const char * argv[]) {
    if (argc == 1) {
        std::cout << std::regex_replace(USAGE,std::regex("APPNAME"),argv[0]) 
              << std::endl;
        return(0);
    }
    std::regex isnumber("^[+-]?([0-9]*[.])?[0-9]+$");
    std::regex isnatural("^[0-9]+$");    
    popl::OptionParser app(
                           "poplex application\nUsage: poplex [options] number\nOptions");
    // flags:
    auto help   = app.add<popl::Switch>("h", "help",
                                        "produce help message");
    auto verbose   = app.add<popl::Switch>("v", "verbose",
                                           "set verbose on");
    // options with values:
    auto round = app.add<popl::Value<int>>("r", "round", 
                                           "natural number for rounding digits",2);
    try {
        app.parse(argc, argv);
    }       
    catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << std::regex_replace(USAGE,std::regex("APPNAME"),argv[0]) 
              << std::endl;
        exit(0);
    }
    
    // print auto-generated help message
    if (help->is_set()) {
        std::cout << app << "\n";
        return(0);
    } else if (verbose->is_set()) {
        std::cout << "verbose is on\n";
    }
    // unknown options check
    // (undefined ones, like "-u" or "--undefined")
    for (const auto& unknown_option: app.unknown_options()) {
        std::cout << "Error: unknown option: " << unknown_option << "\n";
        return(0);
    }
    // positionals:
    float number = 0;
    for (const auto& arg: app.non_option_args()) {
        if (std::regex_search(arg,isnumber)) {
            number = std::stof(arg);
            std::cout << "square of: " <<  number << " is " <<
                  std::fixed <<
                  std::setprecision(round->value()) <<
                  number*number <<  std::endl;
        } else {
            std::cout << "Error: " << arg << " is not a number!\n";
        }
    }
    if (number == 0) {
        std::cout << app.help();
       }
    return(0);
}
