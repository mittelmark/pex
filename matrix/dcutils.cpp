// -!- C++ -!- //////////////////////////////////////////////////////////////
//  Author        : Detlef Groth
//  Created       : Mon Jun 14 16:09:26 2021
//  Last Modified : <240725.0810>
//
//  Description	  : Basic implementation of Matrix like class
//
//  Notes         : Demonstrate 
//                  - class usage
//                  - public and protected members
//                  - namespaces
//                  - working with templates
//                  - std::vector data structures
//                  - operator overloading
//
//  History        : 2021 exercise PEX, 2024 documentation fixes
//	
/////////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2021-2024 Detlef Groth, University of Potsdam, Germany
//  License:      MIT
// 

#include <iostream>
#include <vector>
#include <map>
#include <regex>

namespace dcutils {
template <class T>
class Minimat {
public:
    void addRow(std::vector<T> row);
    void addColumn(std::vector<T> column);
    std::vector<T> getRow(int n);
    std::vector<T> getColumn(int n);
    int nrow();
    int ncol();
    int operator()(int x,  int y)  { 
        if (x > rows-1 || y > cols-1) {
            throw std::out_of_range("Error: out of range access!");
        }
        return(data.at(y).at(x));
    }

protected:
    std::vector< std::vector<T> > data;
    int rows = 0;
    int cols = 0;
};

template <class T>
void Minimat<T>::addRow (std::vector<T> row) {
    if (rows==0 & cols == 0) {
        for (int i = 0; i < row.size();i++) {
            data.push_back(std::vector<T>{row[i]});
        }
        rows+=1;
        cols=row.size();
    } else if (cols == row.size()) {
        for (int i = 0; i < row.size(); i++) {
            data.at(i).push_back(row.at(i));
        }
        rows+=1;
    } else {
        throw std::invalid_argument("incompatible dimension" );
    }
    return;
}

template <class T>
void Minimat<T>::addColumn (std::vector<T> column) {
    if (rows==0 & ncol == 0) {
        data.push_back(column);
        cols=column.size();
    } else if (rows == column.size()) {
        data.push_back(column);
        cols=cols+1;
    } else {
        throw std::invalid_argument("incompatible dimension" );
    }
    return;
}

template <class T>
std::vector<T> Minimat<T>::getRow(int n) {
    if (n > rows-1) {
        throw std::invalid_argument("row out of range" );
    }
    std::vector<T> res;
    for (auto el: data) {
        res.push_back(el.at(n)) ;
    }
    return(res);          
}

template <class T>
std::vector<T> Minimat<T>::getColumn(int n) {
    if (n > cols-1) {
         throw std::invalid_argument("column out of range" );
    }

    return(data.at(n));
}

template <class T>
int Minimat<T>::nrow() {
    return(rows);
}

template <class T>
int Minimat<T>::ncol() {
    return(cols);
}

// TODO: Medimat
// - rownames
// - colnames
// - transpose
// - access A1 C2
// - Chessboard-Example
// - autonames (LETTERS) 
// - check for limits nrow, ncol

} // END OF NSP

int main (int argc, char ** argv) {
    // just testing code which should be placed in a test c++ file
    // for instance using the doctest library
    auto mmat = dcutils::Minimat<int>();
    mmat.addRow(std::vector<int>{0,1,2,3,4});
    mmat.addRow(std::vector<int>{5,6,7,8,9});
    std::cout << "0,0: " << mmat(0,0) << std::endl;
    std::cout << "0,3: " << mmat(0,3) << std::endl;    
    std::cout << "nrow: " << mmat.nrow() << std::endl;
    std::cout << "ncol: " << mmat.ncol() << std::endl;
    auto mmatf = dcutils::Minimat<float>();
    mmatf.addRow({1.1,1.2,1.3});
    mmatf.addRow({1.4,1.5,1.6});    
    std::cout << "ncol: " << mmatf.ncol() << std::endl;
    for (auto el : mmatf.getColumn(1)) {
        std::cout << "el: " << el << std::endl;
    }
    return(0);
    /* std::cout << "0,6: " << mmatf(0,6) << std::endl;   */
}


          
 

