/*
 * Author: Detlef Groth, University of Potsdam, Germany
 * License: MIT 
 * PEX exercise 2022 Lecture 1
 * 
 * Topics:
 *     - input and output operators
 *     - function definition
 *     - interactive menu
 *     - reusing functions
 *     - random number creation
 */


#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

int addition (int n=10, bool multi=false) {
    srand( (unsigned)time( NULL ) );
    int success = 0;
    int x,y, answer = 0;
    for (int i = 0; i < n; i++) {
        if (multi) {
            x = rand() % 20 + 1; // range 1 to 20
            y = rand() % 20 + 1; // range 1 to 20
            std::cout << "What is " << x << " * " << y << "? write -1 to quit!";
        } else {
            x = rand() % 190 + 10; // range 10 to 200
            y = rand() % 190 + 10; // range 10 to 200
            std::cout << "What is " << x << " + " << y << "? write -1 to quit! ";
        }
        std::cin >> answer ;
        if (answer == -1) {
            break;
        }
        if (multi) {
            if (answer == x*y) {
                std::cout << "\033[32mCorrect!\033[0m\n";
                success++;
            } else {
                std::cout << "\033[31mFailed!\033[0m\n";
            }		
        } else {
            if (answer == x+y) {
                std::cout << "\033[32mCorrect!\033[0m\n";
                success++;
            } else {
                std::cout << "\033[31mFailed!\033[0m\n";
            }		
        }	 
    }
    std::cout << "You had " << success << " out of " << n << " answers correct!\n";
    return(success);
}
int multiplication (int n = 10) {
    return(addition(n,true));
}
void menu () {
    std::string choice="m";
    while (true) {
        std::cout << "What do you want?\n (a)ddition, (m)ultiplication? Enter (q) to quit! ";
        std::cin >> choice;
        if (choice == "q") {
            break;
        } else if (choice == "a") {
            addition(5);
        } else if (choice == "m") {
            multiplication(5);
        }
    }
    std::cout << "Goodbye!\n";
}
int main(int argc, char **argv) {
    menu();
    return 0;
}

