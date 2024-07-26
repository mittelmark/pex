#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

class PESports {

public:    
    float a2mw(std::string a) {
      std::cout << "I am a2mw Wait a week!" << std::endl;
      return (1.0);
    }
    void menu() {
        std::string ch="";
        std::cout << "I am your menu!" << std::endl;
        while (true) {
            std::cout << "Enter your choice:\na2aaa (a) aaa2a (b) options (o) quit (q):\n" << std::endl;
            std::cin >> ch;
            std::cout << ch;
            if (ch == "q") {
                break;
            } else if (ch == "o") {
                options();
            }
        }
        //  ask for a letter code
        // if triple call aaa2a
        // if single call a2aaa
        //  translate it
        //  if q break
        //}
        std::cout << a2aaa("A") << std::endl;
        aaa2a("Ala");
    }
    std::string a2aaa(std::string a) {
        for (int i; i < sl.size(); i++) {
            if (sl.at(i) == a) {
                a = tl.at(i);
                break;
            }
        }
        return (a);
    }
    
    std::string aaa2a(std::string aaa) {
        std::cout << "I am aaa2a" << std::endl;
        return (aaa);
    }
    int play_size () {
        std::vector<std::string> asl = {"A", "G", "S", "N", "D", "C", "P", "T",
            "Q", "E", "H", "V",
            "R", "I", "L", "K", "M", "F", "W", "Y"};
        
        std::vector<std::string> asize = {"s","s","s""s","s","s","s","s",
            "m","m","m","m","l","l","l","l","l","l","l","l"};
        int x = 0;
        srand(time(NULL));
        int idx = 0; ;
        int score = 0;
        while (x++ < maxTrials) {
            idx=rand() % 20-1;
            // ask a question
        }
        return(score);
    }
    void options () {
        std::cout << "How many trials (integer): " << std::endl;
        std::cin >> maxTrials;
        std::cout << "How many seconds (integer): " << std::endl;
        std::cin >> maxTime ;
        return;
    }
protected:
    int maxTrials = 10;
    int maxTime = 5; 
    std::vector<std::string> tl = {"Ala","Arg","Asn","Asp","Cys","Gln","Glu","Gly","His","Ile","Leu","Lys","Met","Phe","Pro","Ser","Thr","Trp","Tyr","Val"};
    std::vector<std::string> sl = {"A","R","N","D","C","Q","E","G","H","I","L","K","M","F","P","S","T","W","Y","V"};
};

int main(int args, char **argv) { 
    auto pe = PESports();
    // pe.maxTrials = 3; // not possible
    pe.menu();
}
