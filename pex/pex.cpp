#include "pex.hpp"
namespace pex {
std::regex lpattern = std::regex("^[a-z]+$");
std::regex upattern = std::regex("^[A-Z]+$");

std::string get_home_directory () {
    // get home directory Unix
    const char* homeDir = getenv("HOME");
    // Get home directory on Windows (untested)
    const char* userProfile = getenv("USERPROFILE");
    std::string result = "";
    if (homeDir != nullptr) {
        result = homeDir;
    } else if (userProfile != nullptr) {
        result = userProfile;
    }
    return(result);
}

std::string to_lower (const std::string srcstring) {
    std::string destinationString;
    
    // Allocate the destination space
    destinationString.resize(srcstring.size());
    // Convert the source string to lower case
    // storing the result in destination string
    std::transform(srcstring.begin(),
                   srcstring.end(),
                   destinationString.begin(),
                   ::tolower);
    return(destinationString);
}

std::string to_upper  (const std::string srcstring) {
    std::string destinationString;
    
    // Allocate the destination space
    destinationString.resize(srcstring.size());
    // Convert the source string to lower case
    // storing the result in destination string
    std::transform(srcstring.begin(),
                   srcstring.end(),
                   destinationString.begin(),
                   ::toupper);
    return(destinationString);
}

bool ends_with(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare(fullString.length() - ending.length(), ending.length(), ending));
    }
    return false;
}

bool starts_with(std::string const &fullString, std::string const &starting) {
    if (fullString.length() >= starting.length()) {
        return (0 == fullString.compare(0, starting.length(), starting));
    }
    return false;
}

bool is_lower(const std::string& str) {
    return std::regex_match(str, lpattern);
}

bool is_upper(const std::string& str) {
    return std::regex_match(str, upattern);
}
// should be replaced with std::regex_replace
bool replace(std::string& str, const std::string& from, const std::string& to, bool all) {
     if(from.empty())
        return (false);
    if (all) {
        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
        if (start_pos == 0) {
            return(false);
        } else {
            return(true);
        }
    } else {
        size_t start_pos = str.find(from);
        if(start_pos == std::string::npos)
            return false;
        str.replace(start_pos, from.length(), to);
        return true;
    }
}
std::vector<int> file_grep (const std::string & filename, const std::string & pattern) {
    std::ifstream infile;
    std::vector<int> matches = {};
    std::regex rx = std::regex(pattern);
    int x = 0;
    std::string line;
    infile.open(filename);
    while (std::getline(infile,line)) {
        x++;
        if (std::regex_search(line,rx)) {
            matches.push_back(x);
        }
    }
    infile.close();
    return(matches);
    
}
bool file_has_extension (const std::string &filename, const std::string & extension) {
    std::string ext = to_lower(extension);
    std::string fname = to_lower(filename);
    return fname.length() >= ext.size() && fname.substr(fname.length() - ext.size()) == ext;
}

bool file_is_compressed (const std::string& filename) {
    std::vector<std::string> zipExtensions = {".gz", ".zip",  ".bz2", ".xz", ".7z"};
    for (const auto& ext : zipExtensions) {
        std::string fname = to_lower(filename);
        if (fname.size() >= ext.size() && 
            fname.compare(fname.size() - ext.size(), ext.size(), ext) == 0) {
            return true;
        }
    }
    return false;
}


bool file_exists(const std::string & filename) {
    std::ifstream infile;
    infile.open(filename);
    if (infile) {
        return(true);
    } else {
        return(false);
    }
}

bool file_is_gzipped (const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    char bytes[2];
    file.read(bytes, 2);
    return (file.gcount() == 2 && static_cast<unsigned char>(bytes[0]) == 0x1f && static_cast<unsigned char>(bytes[1]) == 0x8b);
}

// grep like commands

std::vector<int> grep (const std::string & pattern, const std::string & str,
                       const std::regex::flag_type & flag) {
    std::regex rx;
    rx =std::regex(pattern,flag);
    std::vector<int> index_matches; // results saved here 
    for(auto it = 
        std::sregex_iterator(str.begin(), str.end(), rx);
        it != std::sregex_iterator(); ++it)  {   
        index_matches.push_back(it->position());
    }
    return(index_matches);
}



std::vector<int> grep (const std::string & pattern, const std::vector<std::string> & vstring, 
    const std::regex::flag_type & flag) {
    std::regex rx;
    rx =std::regex(pattern,flag);
    std::vector<int> index_matches = {}; // results saved here 
    int i = 0;
    for (auto el : vstring) {
        if (std::regex_search(el,rx)) {
            index_matches.push_back(i);
        }   
        i=i+1;
    }
    return(index_matches);
}


// a C++ grepl which works like the R grepl
bool grepl (const std::string & pattern, const std::string & str,  
            const std::regex::flag_type & flag) {
    return(std::regex_search(str,std::regex(pattern, flag)));
}

std::vector<bool> grepl (const std::string & pattern, const std::vector<std::string> & vstring,  
                         const std::regex::flag_type & flag) {
    std::vector<bool> res = {};
    std::regex rx(pattern, flag);
    for (auto el : vstring) {
        res.push_back(std::regex_search(el,rx));
    }
    return(res);
        
}

// a R like gsub
std::string gsub (const std::string & pattern, 
                  const std::string & replace, 
                  const std::string & str,
                  const std::regex::flag_type & flag) {
    std::regex rx;
    rx =std::regex(pattern,flag);
    std::string result = std::regex_replace(str,rx,replace);
    return(result);
}



std::vector<std::string> gsub (const std::string & pattern, 
                               const std::string & replace,
                               const std::vector<std::string> & vstring, 
                               const std::regex::flag_type & flag) {
    std::regex rx;
    rx =std::regex(pattern,flag);
    std::vector<std::string> results = {}; // results saved here 
    for (auto el : vstring) {
        std::string result = {};
        result = std::regex_replace(el,rx,replace);
        results.push_back(result);
    }   
    return(results);
}



// implementation of any and all for vectors
bool any (const std::vector<bool> & vec) {
    bool ret = false;
    for (auto el: vec) {
        if (el) {
            ret = true;
            break;
        }
    }
    return(ret);
}

bool all (const std::vector<bool> & vec) {
    bool ret = true;
    for (auto el: vec) {
        if (!el) {
            ret = false;
            break;
        }
    }
    return(ret);
}


};
#ifdef PEXI
// to run this compile with:
// g++ -DPEXI pex.cpp -o pexi
int main() {
    std::cout << pex::LYELLOW << "file functions checks\n" << pex::RESET;
    std::cout << "PEX Home: " << pex::get_home_directory()
        << std::endl;
    std::cout << pex::file_has_extension("hello.obo",".obo") << std::endl;
    std::cout << pex::file_has_extension("hello.Obo",".obo") << std::endl;
    std::cout << pex::file_has_extension("hello.Obo.gz",".obo") << std::endl;    
    std::cout << "file.obo.gz is compressed? " << pex::file_is_compressed("file.obo.gz") << std::endl;    
    std::cout << "file.Obo    is compressed? " << pex::file_is_compressed("file.Obo") << std::endl;        
    std::cout << pex::LYELLOW << "string functions checks\n" << pex::RESET;
    std::cout << pex::to_lower("Hello World!") << std::endl;
    std::cout << pex::to_upper("Hello World!") << std::endl;    
    std::cout << "hello ends with lo? " << pex::ends_with("hello", "lo") << std::endl;            
    std::cout << "hello starts with hel? " << pex::starts_with("hello", "hel") << std::endl;            
    std::cout << pex::LYELLOW << "grep checks\n" << pex::RESET;
    for (auto i : pex::grep("he[lL]","helloheLLo")) {
        std::cout << i << std::endl;
    }
    for (auto i : pex::grep("he[lL]",{"helloheLLo","world","heLLo"})) {
        std::cout << i << std::endl;
    }
    std::cout << pex::grepl("he[lL]","hello") << std::endl;
    std::cout << pex::grepl("he[lL]","hexlo") << std::endl;
    std::vector<bool> b1 = {true, true, false};
    std::vector<bool> b2 = {true, true, true};
    std::cout << pex::LYELLOW << "all and any checks\n" << pex::RESET;
    std::cout << pex::all(b1) << std::endl;
    std::cout << pex::any(b1) << std::endl;
    std::cout << pex::all(b2) << std::endl;
    std::cout << pex::any(b2) << std::endl;
    std::vector<int> matches = pex::file_grep("pex.cpp","^std::");
    std::cout << pex::LYELLOW << "file_grep checks\n" << pex::RESET;
    for (auto m : matches) {
        std::cout << m << std::endl;
    }
    std::cout << pex::LYELLOW << "gsub checks\n" << pex::RESET;
    std::cout << pex::gsub("he(ll)l*o","he$1o","hello helllo helllllllox") << std::endl;
    for (auto s : pex::gsub("hel[lL]o", "hello",{"hello","helLo","world"})) {
        std::cout << s << std::endl;
    }
    return(0);
}
#endif

#ifdef SEB
int main () {
    std::cout << " I'm (not) Sebastian!\n";
    return(0);
}
#endif



