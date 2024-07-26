#include <iostream>
#include <string>
#include <array>

// Prototypes
std::string a2aaa (std::string a) ;
std::string aaa2a (std::string aaa);
float a2mw (std::string a);
void menu();

float a2mw(std::string a) {
    std::cout << "I am a2mw Wait a week!" << std::endl;
    return(1.0);
}
void menu () {
    std::cout << "I am your menu!" << std::endl;
    //while (true) { 
    //  ask for a letter code 
    // if triple call aaa2a
    // if single call a2aaa
    //  translate it 
    //  if q break 
    //}
    std::cout << a2aaa("A") << std::endl;
    aaa2a("Ala");
}
std::string a2aaa (std::string a) {
    std::array<std::string,2> tl = {"Ala","Leu"};
    std::array<std::string,2> sl = {"A",  "L" };
    
    for (int i; i < sl.size(); i++) {
        if (sl[i] == a) {
            a = tl[i];
            break;
        }
    }
    //std::cout << "I am a2aaa" << std::endl;
    return(a);
}

std::string aaa2a (std::string aaa) {
    std::array<std::string,2> tl = {"Ala","Leu"};
    std::array<std::string,2> sl = {"A","L" };

    std::cout << "I am aaa2a" << std::endl;
    return(aaa);
}

int main (int args, char **argv) {
    menu();
}
