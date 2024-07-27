#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
typedef std::vector< std::vector<int>> Matrix;
enum { White, Black, Sheep, Wolf };
class SheepBoard {
public:
    void display (int rows = 8, int cols = 8 ) {
        int x = 0;
        int y = 0;
        std::string piece = "";
        for (int i = 0; i < rows; i++) {
            std::cout << "   +";
            for (int j = 0; j < cols; j++) {
                std::cout << "---+";
            }
            std::cout << "\n";
            if (i < 10) {
                std::cout << " " << rows-i << " |" ;
            } else {
                std::cout << "" << rows-i << " |" ;
            }
            
            for (int j = 0; j < cols; j++) {
                piece = PIECES[board[i][j]];
                std::cout << piece << "|";
            }
            std::cout << "\n";
        }
        std::cout << "   +";
        for (int j = 0; j < cols; j++) {
            std::cout << "---+";
        }
        std::cout << "\n";
        std::cout << "   ";
        for (int j = 0; j < cols; j++) {
            std::cout << "  " << LETTERS[j] << " " ;
	}
        std::cout << "\n";
        // do your looping and display
    }
    void move (std::string mv) {
        std::string from = "";
        std::string to   = "";
        moves.push_back(mv);
        std::cout << "moving " << mv << std::endl;
        std::size_t found = mv.find("-");
        from = mv.substr(0,found);
        to   = mv.substr(found+1,mv.size());
        int x1, y1, x2, y2 = 0;
        x1 = getColumn(from.substr(0,1));
        x2 = getColumn(to.substr(0,1));
        y1 = 8-std::atoi(from.substr(1,from.length()-1).c_str());
        y2 = 8-std::atoi(to.substr(1,to.length()-1).c_str());
        int current = board[y2][x2];
        board[y2][x2] = board[y1][x1];
        board[y1][x1] = current; 
        //std::cout << from << " i is: " <<  PIECES[board[y1][x1]]<< "\n";
        // do the rest
        display(8,8);
        usleep(1000*1000);
    }
    void menu () {
        std::cout << "menu running " << std::endl;
    }
private:
    int getColumn(std::string col) {
        // return the index from the LETTERS variable
        // belonging to the letter in col
        for (int i = 0; i < LETTERS.size();i++) {
            if (LETTERS[i] == col) {
                return(i);
            } 
        }
        return(1);
    }
    // some suggestions
    Matrix board = {
        {White, Wolf,  White, Black, White, Black, White, Black, White, Black, White, Black},
        {Black, White, Black, White, Black, White, Black, White, Black, White, Black, White},
        {White, Black, White, Black, White, Black, White, Black, White, Black, White, Black},        
        {Black, White, Black, White, Black, White, Black, White, Black, White, Black, White},
        {White, Black, White, Black, White, Black, White, Black, White, Black, White, Black},        
        {Black, White, Black, White, Black, White, Black, White, Black, White, Black, White},
        {White, Black, White, Black, White, Black, White, Black, White, Black, White, Black},        
        {Sheep, White, Sheep, White, Sheep, White, Sheep, White, Sheep, White, Sheep, White}};
    std::vector<std::string> moves = {};    
    std::vector<std::string> LETTERS = {"A","B","C","D","E","F","G","H","I","J", "K", "L" };
    std::vector<std::string> PIECES  = {"   ", "\33[31;1m - \33[0;m", "\033[33;1m \u26C0 \033[0m", "\033[32;1m \u26C0 \033[0m"};
    
};
int main(int argc, char ** argv ) {
    // my sample run
    SheepBoard board;
    board.display(8,8);
    usleep(1000*1000);
    board.menu(); // should do not yet do anything
    board.move("B8-C7");
    board.move("A1-B2");
    board.move("C7-D6");    
    board.move("C1-D2");
    board.move("D6-E5");
    board.move("E1-F2");
    board.move("E5-D4");    
    board.move("G1-H2");
    board.move("D4-E3");    
    return 0;
}

// compiling:
// g++ sheeps-02.cpp
// recording animated gif
// byzanz-record --duration=10 --x=10 --y=40 --width=400 \
//  height=400 out.gif & ./a.out
