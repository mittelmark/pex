/*
 * main-app.cxx
 * 
 * Copyright 2022 Detlef Groth <dgroth@amundsen>
 * 
 * License MIT
 * 
 */
#include <iostream>
#include <regex>
#include <string>

int min (int a, int b) {
    return((a) < (b) ? (a) : (b));
}
int levenshtein_distance(std::string src, std::string dst, int gapcost = 1) {
    int src_len = src.length();
    int dst_len = dst.length();
    if (src == dst) {
        return 0;
    } else if (src.length() == 0) {
        return  dst.length()*gapcost;
    } else if (dst.length() == 0) {
        return  src.length()*gapcost;
    }
    
    int d[src_len + 1][dst_len + 1];
    for (size_t i = 0; i < src_len + 1; i++) d[i][0] = i*gapcost;
    for (size_t j = 0; j < dst_len + 1; j++) d[0][j] = j*gapcost;
    
    for (size_t i = 1; i < src_len + 1; i++) {
        for (size_t j = 1; j < dst_len + 1; j++) {
            //                 vertical/horizontal  (ins, del)             diagonal  operation (subst)
            d[i][j] = min(min(d[i-1][j]+ gapcost, d[i][j-1]+ gapcost) , d[i-1][j-1] + (src[i-1] == dst[j-1] ? 0 : 1));
        }   
    }   
    return d[src_len][dst_len];
}

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " string1 string2 ?gapcost?" << std::endl;
        std::cout << "   ex: " << argv[0] << " drei three 1" << std::endl;
        return(0);
    }
    int gapcost = 1;
    std::regex isnumber("[1-9]");
    if (argc == 4 && std::regex_match(argv[3],isnumber)) {
        gapcost = std::stoi(argv[3]);
    } else if (argc == 4) {
        std::cout << "Error: gapcost is not a positive integer like 1, 2, 3 or so!" << std::endl;
        return(0);
    }
    
    int dist = levenshtein_distance(argv[1],argv[2], gapcost);
    std::cout << "edit_dist of '" << argv[1] << "' and '" << argv[2] << "' is: " << dist << std::endl;
    return(0);
}
