///usr/bin/g++ filename.cpp -o filename && exec ./filename
/*
 * cpp-app.cpp
 * 
 * Copyright 2024 kiosk-user <kiosk-user@node-001-1>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
void box (std::string choice = "t", int size = 9) {
    std::string border = " +---------------------+";
    std::map<std::string, std::string> mymap;
    mymap["t"] = "TODO";
    mymap["p"] = "PROGRESS";
    mymap["d"] = "DONE";
    if (mymap.count(choice) == 0) {
        if (choice == "all" || choice == "a") {
            std::cout << "       \033[31mo\033[0m TODO                      \033[33mo\033[0m PROGRESS                   \033[32mo\033[0m DONE\n";
            std::cout << border << "   " << border << "   " << border << "\n";
            for (int i = 0; i < size; i++)	{
                std::cout << " | " << i+1 << "                   " << "|    "; // TODO
                std::cout << "| " << i+1 << "                   " << "|    "; // PROGRESS
                std::cout << "| " << i+1 << "                   " << "|\n"; // DONE
            }
            std::cout << border << "   " << border << "   " << border << "\n";
        } else {
            std::cout << "invalid choice '" << choice << "'\n";
        }
    } else {
        std::cout << "        " << mymap[choice] << "\n";
        std::cout << border << "\n";
        for (int i = 0; i < size; i++)	{
            std::cout << " | " << i+1 << "                   " << "|\n";
            
        }
        
        std::cout << border << "\n";
    }
    
}
void menu () {	
    std::string choice = "";
    int size = 9;
    while (true) {
        std::cout << "\n\033[32mPlease select \033[0m " ;
        std::cout << "\033[32mq\033[0m(uit), " ;
        std::cout << "\033[32mt\033[0m(odo), " ;
        std::cout << "\033[32mp\033[0m(progress), " ;
        std::cout << "\033[32md\033[0m(one), " ;
        std::cout << "\033[32ma\033[0m(ll), " ;
        std::cout << "\033[32ms\033[0m(et size): " ;
        
        std::cin >> choice;
        if (choice == "q")	{
			break;
		} else if (choice == "s") {
			std::cout << " \033[32mEnter board size:\033[0m ";
			std::cin >> size;
		} else {
			box(choice,size);
		}
	}	
	
}
int main(int argc, char **argv) {
	
	menu();
	
	return 0;
}

