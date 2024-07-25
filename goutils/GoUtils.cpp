#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <regex>

class GoUtils {
public:
    std::string getEntry(std::string filename,std::string id) {
        // homework implementation:
        // set results as empty string
        // open file
        // loop over lines
        //    check for lines starting with "id: "+id
        //    if found set flag true 
        //       collect lines until next empty line in results
        //       break on empty lines
        // close file
        // return results
        return("Info: Method getEntry is not yet implemented!");
    }
    std::string getName(std::string filename,std::string id) {
        std::ifstream infile; 
        std::string line = "";
        std::string name = "";
        infile.open(filename); 
        std::regex rx ("^id: "+id);
        bool flag = false;
        // homework: speed upcode
        // compile with g++ -O3 option
        // replace std::regex_search with string.lfind == 0
        // use time command from the terminal before and after
        // these changes
        // use a GO id which comes very late in the GO file
        while (std::getline(infile, line)) {
            if (std::regex_search(line,rx)) {
                flag = true;
            }
            if (flag && std::regex_search(line, std::regex("^name:"))) {
                name = std::regex_replace(line,std::regex("^name: "),"");
                break;
            }
        }
                
        return(name);
    }
    bool isObsolete(std::string filename, std::string id) {
        // homework implementation:
        // check if a GO-id has been deprecated
        // can be seen if the entry has a 'is_obsolete: true' entry
        // call getEntry
        // inspect the result, check if it has this line
        std::cout << "Info: Method 'isObsolete' is not yet implemented!" << std::endl;
        return(true);
    }
    
};

void usage (std::string appname) {
    std::cout << "Usage: " << appname << " cmd obofile GO-id"
          "\nwhere cmd-name is either getEntry, getName, isObsolete\n" ;
}

int main (int argc, char ** argv) {
    namespace fs = std::filesystem;
    if (argc != 4) {
        usage(argv[0]);
    } else {
        auto go=GoUtils();
        std::string appname  = argv[0];
        std::string cmdname  = argv[1];
        std::string filename = argv[2];
        std::string goid     = argv[3];   
        std::regex isgo      = std::regex("GO:[0-9]{7}");
        // checks
        if (!fs::exists(filename)) {
            std::cout << "Error: File " << filename << " does not exists!\n" ;
            usage(appname);
        } else if (!std::regex_match(goid,isgo)) {
            std::cout << "GO id: '" << goid << 
                  "' is not a valid id, it must have GO: prefix and 7 digits!\n" ;
            usage(appname);
        } 
        // call functions
        else if (cmdname == "getEntry") {
            std::cout << go.getEntry(filename,goid) << std::endl;
        } else if (cmdname == "getName") {
            std::cout << go.getName(filename,goid) << std::endl;
        } else if (cmdname == "isObsolete") {
            std::cout << go.isObsolete(filename,goid) << std::endl;
        } else {
            std::cout << "Error: Unknown command '" << cmdname << 
                  "'! Valid commands are getEntry, getName and isObsolete!" << std::endl;
            usage(appname);
        }
    }
    return(0);
}
