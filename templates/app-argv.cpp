#include <iostream>
#include <iomanip>
#include <regex>
#include <map>
static const char HELP[] =
R"(Example application, Max Musterman, University of Potsdam, 2024
    Usage:
      APPNAME (-h | --help)
      APPNAME (-v | --verbose)
      APPNAME --round 2 number

    Options:
      -h, --help        Show this screen.
      -r, --round   n   Rounding digits [default: 2]

    Arguments:
      number            Number which will be squared and rounded 
)";

static const char USAGE[] =
R"(Usage: APPNAME [-h,--help -v,--verbose] --round n number
)";

void usage (std::string appname, bool help = false) {
    if (help) {
        std::cout << std::regex_replace(HELP,std::regex("APPNAME"),appname) << std::endl;;
    } else {
        std::cout << std::regex_replace(USAGE,std::regex("APPNAME"),appname);
    }
}
int main(int argc, char *argv[]) {
    std::string appname = argv[0];
    std::regex isnumber("^[+-]?([0-9]*[.])?[0-9]+$");
    std::regex isoption("^-{1,2}[a-zA-Z0-9]+");    
    float square   = 0 ; // positional parameter
    bool square_set = false; // must be given
    int round = 2;       // option, default: 2    
    bool help = false;   // flag
    bool verbose = false;
    if (argc == 1) {
        usage(appname);
    } else if (argc == 2 && 
        std::regex_match(argv[1],isnumber)) {
        square = std::stof(argv[1]);
        square_set = true;
    } else {
        for (int i = 1; i < argc; i++) {
            std::string carg(argv[i]);
            if ("-h" == carg || "--help" == carg) { 
                help=true; // help flag
            } else if ("-v" == carg || "--verbose" == carg) { 
                verbose=true; // help flag
            } else if (carg == "--round" || carg == "-r") { 
                // option check (TODO --round=value
                if (argc > i && std::regex_match(argv[i+1],isnumber)) {
                    round = std::stoi(argv[i+1]);
                    i = i + 1;
                }
            } else if (std::regex_search(carg,isoption)) {
                std::cout << "Error: option '" << carg << "' not implemented!'" << std::endl;
                usage(argv[0]);
            } else if (std::regex_match(carg,isnumber)) { // positional
                square = std::stof(carg);
                square_set = true;
            } else {
                std::cout << "Error: '" << carg << "' is not a number!" << std::endl;
                usage(argv[0]);
            }
        }
    }
    if (help) {
        usage(appname,true);
    } else if (square_set) {
        if (verbose) { std::cout << "Let's be verbose!\n"; } 
        std::cout << "square of: " << square << " is " <<
              std::fixed << std::setprecision(round) <<
              square*square <<  std::endl;
    }
    return 0;
}
