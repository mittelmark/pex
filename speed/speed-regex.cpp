#include <iostream>
#include <regex>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <tuple>
#include <filesystem>
#include <chrono>

void countLines (std::string filename) {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::ifstream fin = std::ifstream(filename);
    std::string line = "";
    int x = 0;

    while (getline(fin,line)) {
        x=x+1;
    }
    fin.close();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << "lines: " << x << " ms:" << ms_int.count() << std::endl;
}
void countIds (std::string filename) {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::ifstream fin = std::ifstream(filename);
    std::string line = "";
    int x = 0;

    while (getline(fin,line)) {
        if (line.find("id:")==0){
            x=x+1;
        }
    }
    fin.close();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << "find ids: " << x << " ms:" << ms_int.count() << std::endl;
}
void countIdsRegex (std::string filename) {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::ifstream fin = std::ifstream(filename);
    std::string line = "";
    int x = 0;
    std::regex rx("^id: ");

    while (getline(fin,line)) {
        if (std::regex_search(line,rx)){
            x=x+1;
        }
    }
    fin.close();
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    std::cout << "regex ids: " << x << " ms:" << ms_int.count() << std::endl;
}

void usage (char *argv[]) {
    std::cout << "Usage: " << argv[0] << " FILENAME" << std::endl;
}
void help (char *argv[]) {
    std::cout << "Appname, Author, Affiliation, Copyright\n";
    usage(argv);
}
int main (int argc,  char *argv[]) {
    namespace fs = std::filesystem;
    if (argc != 2) {
        usage(argv);
    } else if (strcmp(argv[1],"--help") == 0 || strcmp(argv[1],"-h") == 0) {
        help(argv);
    } else if (!fs::exists(argv[1])) {
        std::cout << "Error: File '" << argv[1] << "' does not exists!" << std::endl;
    } else {
        countLines(argv[1]);
        countIds(argv[1]);
        countIdsRegex(argv[1]);
    }
    return(0);
}

// $ g++ test-regex.cpp
// $ ./a.out /home/groth/workspace/delfgroth/docs/lehre/data/gene_ontology_edit.obo.2020-12-01
// fine!
// lines:     567782  ms:27
// find ids:  47345   ms:57
// regex ids: 47345   ms:8600
// $ g++ -O3 test-regex.cpp
// ./a.out /home/groth/workspace/delfgroth/docs/lehre/data/gene_ontology_edit.obo.2020-12-01
// fine!
// lines:     567782   ms:24
// find ids:  47345    ms:50
// regex ids: 47345    ms:661

// https://stackoverflow.com/questions/70583395/why-is-stdregex-notoriously-much-slower-than-other-regular-expression-librarie

