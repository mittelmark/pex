/*
 * grep.cpp  implementation of R's grep function as well of any and all
 *
 * Copyright 2022-2024 Detlef Groth, University of Potsdam, Germany
 *
 * License: MIT
 *
 */
#include <iostream>
#include <regex>
#include <string>
#include <vector>


namespace pex {

// a C++ grep which works like the R grep
std::vector<int> grep (std::string pattern, std::string str,
                       const std::regex::flag_type & flag = std::regex::extended) {
    std::regex rx;
    rx =std::regex(pattern,flag);
    std::vector<int> index_matches; // results saved here
    for(auto it =
        std::sregex_iterator(str.begin(), str.end(), rx);
        it != std::sregex_iterator(); ++it) {
        index_matches.push_back(it->position());
    }
    return(index_matches);
}
bool grepl (std::string pattern, std::string str,  
            const std::regex::flag_type & flag = std::regex::extended) {
    //Task 1A
    std::regex rx;
    rx = std::regex(pattern,flag);
    std::cout << "match?\n";
    bool out=std::regex_search(str,rx);
    return(out);
}
std::vector<bool> grepl (std::string pattern, std::vector<std::string> strs,  
                         const std::regex::flag_type & flag = std::regex::extended) {
    std::vector<bool> res ;
    std::regex rx;
    rx = std::regex(pattern,flag);	
    for (auto el : strs) {
        if(std::regex_search(el,rx)) {
            res.push_back(true);
        } else {
            res.push_back(false);
        }
    }
    //Task 1B
    return(res);
}
bool any (std::vector<bool> elements) {
    //Task 1C
    for (auto el : elements) {
        if (el) {
            return(true);
        }
    }
    return(false);
}
bool all (std::vector<bool> elements) {
    //Task 1D
    for (auto el : elements) {
        if (!el) {
            return(false);
        }
    }
    return(true);
}
std::vector<int> grep (std::string pattern,
                       std::vector<std::string> vstring,
                       const std::regex::flag_type & flag = std::regex::extended) {
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

} // end of NSP

int main (int argc, char ** argv) {
    std::vector<int> res = pex::grep("[Hh][ea]",
                                     "Hello and hallo world!");
    for (auto r : res)
        std::cout << r << std::endl;
    for (auto i :
         pex::grep("H[ea]", {"Hello","World!",
                   "Hallo","Welt!","by","hallo"
               })) {
        std::cout << i << std::endl;
    }
    for (auto i : pex::grep("H[ea]", {"Hello","World!",
                            "Hallo","Welt!","by","hallo"
                        },
                            std::regex::icase)) {
        std::cout << i << std::endl;
    }
    std::cout << pex::grepl("H.*x","Hallo this is Mister X") << std::endl;
    std::cout << pex::grepl("H.+x","Hallo this is Mister x") << std::endl;
    for (auto match : pex::grepl("H.*x",std::vector<std::string>({"Hallo","Hallo this is x and more"}))) {
        std::cout << "match is " << match << "\n";
    }
    std::cout << pex::all(std::vector<bool>({true,true,true})) << std::endl;
    std::cout << pex::all(std::vector<bool>({true,true,false})) << std::endl;
    std::cout << pex::any(std::vector<bool>({true,true,false})) << std::endl;
}
