#include <iostream>
#include <vector>
#include <string>
// sheeps-01.cpp - compile with: "g++ -o sheeps sheeps-01.cpp"

void board (int rows = 8, int cols = 8 ) {
    std::vector<std::string> LETTERS = {"A","B","C","D","E","F","G","H","I","J" };
    for (int i = 0; i < rows*2+1; i++) {
        if (i % 2  == 1) {
            std::cout << " " << rows-(i-1)/2 << " |";
            for (int j = 0; j < cols; j++) {
                if (i % 4 == 3 && j % 2 == 0) {
                    std::cout << " - |";
                } else if (i % 4 == 1 && j % 2 == 1) {
                    std::cout << "\33[31;1m - \33[0;m|";
                } else {
                    std::cout << "   |";
                }
            }
            std::cout << "\n";
        } else {
            std::cout << "   +";
            for (int j = 0; j < cols; j++) {
                std::cout << "---+";
            }
            std::cout << "\n";
        }
    }
    std::cout << "    ";
    for (int j = 0; j < cols; j++) {
        std::cout << " " << LETTERS[j] << "  ";
    }
    std::cout << "\n";
}
int main(int argc, char ** argv ) {
    board(10,10);
    return 0;
}
