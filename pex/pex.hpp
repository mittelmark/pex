#pragma once
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

namespace pex {
// terminal colors
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string LRED = "\033[91m";
const std::string LGREEN = "\033[92m";
const std::string LYELLOW = "\033[93m";
const std::string LBLUE = "\033[94m";
const std::string LMAGENTA = "\033[95m";
const std::string LCYAN = "\033[96m";
const std::string RESET = "\033[0m";
// file and file system functions
std::string get_home_directory ();
bool file_exists(const std::string & filename);
bool file_has_extension (const std::string & filename, const std::string & extension);
bool file_is_compressed (const std::string & filename);
bool file_is_gzipped (const std::string & filename);
std::vector<int> file_grep (const std::string & filename, const std::string & pattern);
// string functions
std::string to_lower (const std::string srcstring);
std::string to_upper  (const std::string srcstring);
bool ends_with(std::string const &fullString, std::string const &ending);
bool starts_with(std::string const &fullString, std::string const &starting);
bool is_lower(const std::string& str);
bool is_upper(const std::string& str);
bool replace(std::string& str, const std::string& from, const std::string& to, bool all = false);
// grep functions
std::vector<int> grep (const std::string & pattern, const std::string & str,
                       const std::regex::flag_type & flag = std::regex::extended);

std::vector<int> grep (const std::string & pattern, const std::vector<std::string> & vstring, 
                       const std::regex::flag_type & flag = std::regex::extended);
   
bool grepl (const std::string & pattern, const std::string & str,  
            const std::regex::flag_type & flag = std::regex::basic);
std::vector<bool> grepl (const std::string & pattern, const std::vector<std::string> & vstring,  
                         const std::regex::flag_type & flag = std::regex::extended);
std::string gsub (const std::string & pattern, 
                  const std::string & replace, 
                  const std::string & str,
                  const std::regex::flag_type & flag = std::regex::extended);

std::vector<std::string> gsub (const std::string & pattern, 
                               const std::string & replace, 
                               const std::vector<std::string> & vstring,
                               const std::regex::flag_type & flag = std::regex::extended);

// check boolean vectors
bool any (const std::vector<bool> & vec);
bool all (const std::vector<bool> & vec);
}

