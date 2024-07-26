#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
// usually we include header files (hpp)
// just for illustration purposes here
#include "pe-sports-03.cpp"

class XPESports : public PESports {
public:    
    void hello () {
        std::cout << "Hello XPESports\n";
    }
    void guess_hydrophobicity () {
        std::cout << "hydrophob??" << std::endl;
        
    }
    void menu () {
        std::string choice = "";
        std::cout << "You like the new game of hydrophicity? (y)es / (n)o / (c)ancel: " ;
        std::cin >> choice;
        if (choice == "y" || choice == "yes") {
            guess_hydrophobicity();
        } else if (choice == "n" || choice == "no") {
            PESports::menu();
            //this->menu();
        } else {
            std::cout << "Ok, a pitty - Bye!\n";
        }
    }
protected:
    std::vector<std::string> slhp = {"I","V","L","F","C","M","A","W","G","T","S","Y","P","H","N","D","Q","E","K","R"};
    std::vector<std::string> valhb= {"yes","yes","yes","yes","yes","yes","yes","yes","neu","neu","neu","neu","neu","neu","no","no","no","no","no","no"}; 
};
#ifdef XPE
int main(int args, char **argv) { 
    auto pe = XPESports();
    // pe.maxTrials = 3; // not possible
    pe.hello();
    pe.menu();
}
#endif
