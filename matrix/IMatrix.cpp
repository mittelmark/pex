#include <iostream>
#include <vector>

// for find

// Task 4 template for sprintf in C++
#include <cstdio>
#include <string>
// Task 4 find and distance
#include <algorithm>

// Task 5
// IO
#include <fstream>
#include <sstream>

// Exception 
#include <exception>
class IMatrix {
    typedef std::vector< std::vector<int> > IntMatrix;
    typedef std::vector<int> row;
    typedef std::vector<int> col;
    typedef std::vector<std::string> names;
    public:
    int n=0;
    IMatrix(bool squared) : squared(squared) { }
    IMatrix(int nrow, int ncol, bool squared=false) : squared(squared) {
        IntMatrix mt(nrow,row(ncol,0));
        this->mt = mt;
    }
    // Operator overloading currently only by index
    int& operator() (int rid, int cid) {
        try {
            if (rid-1 > nrow() || cid-1 > ncol()) {
                throw "invalid matrix indices" ;
            }
            return mt[rid][cid];
        } catch (const char * msg) {
            std::cerr << "Out of Range error: " << msg << '\n';
        }
        // problem must return reference
        return mt[0][0];
    }
    int  operator() (int rid, int cid) const {
        if (rid-1 > nrow() || cid-1 > nrow()) {
            std::cout << "error out of range" << std::endl;
            return(0);
        }
        return mt[rid][cid];
    }
    void asText () ;
    int nrow () const { return(mt[0].size()); }
    int ncol () const { return(mt.size()) ; }
    int get (int rid, int cid) { return mt[rid][cid] ; }

    int get (std::string rsid, std::string csid) {
        auto r = std::find(rnames.begin(), rnames.end(), rsid);
        auto c = std::find(cnames.begin(), cnames.end(), csid);
        int idxr = std::distance(rnames.begin(),r);
        int idxc = std::distance(cnames.begin(),c);        
        if (idxr < rnames.size() && idxc < cnames.size()) {
            return(mt[idxr][idxc]);
        } 
        return(-1);
    }
    void set (int rid, int cid, int value) { 
        mt[rid][cid]=value;
    }

    void set (std::string rsid, std::string csid, int value) { 
        auto r = std::find(rnames.begin(), rnames.end(), rsid);
        auto c = std::find(cnames.begin(), cnames.end(), csid);
        int idxr = std::distance(rnames.begin(),r);
        int idxc = std::distance(cnames.begin(),c);        
        if (idxr < rnames.size() && idxc < cnames.size()) {
            mt[idxr][idxc]=value;
        } else {
            std::cout << "error in set with strings" ;
        }
    }

    row getRow (int rid) { return(mt.at(rid)) ; }
    col getColumn (int cid) {
        std::vector<int> ret;
        for (auto r : mt) {
            ret.push_back(r.at(cid));
        }
        return(ret);
    }
    row getRow (std::string rsid) {
        auto r = std::find(rnames.begin(), rnames.end(), rsid);
        int rid = std::distance(rnames.begin(),r);
        return(mt.at(rid)) ;
    }
    col getColumn (std::string csid) {
        auto c = std::find(cnames.begin(), cnames.end(), csid);
        int cid = std::distance(cnames.begin(),c);

        std::vector<int> ret;
        for (auto r : mt) {
            ret.push_back(r.at(cid));
        }
        return(ret);
    }
    void addRow (row values) { mt.push_back(values); }
    void addRow (std::string rname, row values) { 
        rnames.push_back(rname);
        mt.push_back(values);  
    }
    void addColumn (col values) {
        int i = 0; 
        for (auto &x : mt) {
            x.push_back(values[i]);
            i+=1;
        }
    }
    void addColumn (std::string cname, col values) {
        int i = 0; 
        cnames.push_back(cname);
        for (auto &x : mt) {
            x.push_back(values[i]);
            i+=1;
        }
    }
    // extend Task 3
    void extend (int value) {
        row r(nrow(),value);
        addRow(r);
        col c(ncol(),value);
        addColumn(c); 
    }
    
    bool isSquared () { return(this->squared) ; }
    names autonames (int n, std::string prefix = "R") {
        names nms(0);
        std::string fmt;
        std::string name;
        if (n < 10) {
            fmt=prefix+"%i";
        } else if (n < 100) {
            fmt=prefix+"%02i";
        } else if (n < 1000) {
            fmt=prefix+"%03i";
        }
        const char * fstring = fmt.c_str();
        char buffer[20];
        for (int i = 1; i <= n; i++) {
            sprintf(buffer,fstring,i);
            name=buffer;
            nms.push_back(name);
        }
        return(nms);
    }
    names colnames () {
        return(this->cnames);
    }
    names rownames () {
        return(this->rnames);
    }
    void rownames (names rnames) {
        if(nrow() != rnames.size()) {
            std::cout << "error in rownames" ;
        } else {
            this->rnames.clear();
            this->rnames=rnames;
        }
    }
    void rownames(int idx, std::string value) {
        this->rnames[idx]=value;
    }
    void colnames (names cnames) {
        if(ncol() != cnames.size()) {
            std::cout << "error in colnames, ncol=" << cnames.size();
        } else {
            this->cnames.clear();
            this->cnames=cnames;
        }
    }
    void colnames(int idx, std::string value) {
        this->cnames[idx]=value;
    }
    void writeTabfile (std::string filename) {
        names cnms, rnms ;
        if (cnames.size()==0) {
            cnms=autonames(ncol(),"C");
        } else {
            cnms=cnames;
        }
        if (rnames.size()==0) {
            rnms=autonames(nrow(),"R");
        } else {
            rnms=rnames;
        }
        std::ofstream outfile;
        outfile.open(filename, std::ios::out | std::ios::trunc );
        outfile << "RowNames" ;
        for (auto c : cnms) {
            outfile << "\t" << c ;
        }
        outfile << "\n" ;
        int x = 0;
        for (auto r : mt) {
            outfile << rnms[x++] ;
            for (auto c : r) {
                outfile << "\t" << c ;
            }
            outfile << "\n" ;
        }
        outfile.close();
    }
    void readTabfile (std::string filename) {
        names rnms ;
        names cnms ;
        std::string rname, cname, line;
        row r;
        int rownumber = 0;
        std::string scell;
        int icell;
        // open a file in read mode.
        std::ifstream infile; 
        infile.open(filename); 
        IntMatrix tmt;
        while (std::getline(infile, line)) {
            rownumber += 1;
            std::istringstream iss(line);
            if (rownumber == 1) { 
                iss >> scell ; // skip rownames entry
                while (iss >> scell) {
                    cnms.push_back(scell);
                }
            } else { 
                iss >> scell ; 
                r.clear();
                rnms.push_back(scell);
                while ((iss >> icell)) { 
                    r.push_back(icell);
                }
                tmt.push_back(r);
            }
        }
        infile.close();
        //return;
        this->rnames=rnms;
        this->cnames=cnms;
        this->mt=tmt;
        std::cout << "done" << std::endl;
    }
    private:
        std::vector<std::string> cnames = {};
        std::vector<std::string> rnames = {};
       const bool squared = false ;
       IntMatrix mt ;
};
void IMatrix::asText () {
    int i = 0;
    if (cnames.size()>0) {
        for (auto c : colnames()) {
            std::cout << "\t" << c;
        }
        std::cout << std::endl;
    }
    names rn=rownames();
    for(auto r : mt) {
        if (rn.size()>0) {
            std::cout << rn[i] ;
        }
        i+=1;
        for(auto x : r) {
            std::cout << "\t" << x;
        }
        std::cout << std::endl;
    }
}
int main () {
    using namespace std;
    cout << "Hello World!" << endl;
    // TODO: those are all only tests ...
    IMatrix mt(true);
    IMatrix mt2(3,3,false);
    mt2.set(0,0,5);
    mt2.set(1,0,4);
    mt2.asText();
    std::vector<int> newrow = {7,8,9};
    mt2.addRow(newrow);
    std::vector<int> newcol = {7,8,9,10};
    mt2.addColumn(newcol);
    cout << "ncol: " << mt2.ncol() << "first element: " << mt2.get(0,0) << endl;
    for (auto x : mt2.getRow(0)) {
        cout << " " << x ;
    }
    cout << endl;
    for (auto x : mt2.getColumn(0)) {
        cout << " " << x ;
    }
    mt2.extend(6);
    cout << endl;
    mt2.asText();
    mt2.colnames(mt2.autonames(mt2.ncol(),"C"));
    mt2.rownames(mt2.autonames(mt2.nrow(),"R"));    
    mt2.asText();
    mt2.rownames(0,"R1a");
    mt2.colnames(0,"C1a");
    mt2.asText();
    mt2.set("R5","C1a",15);
    mt2.asText();
    cout << mt2.get("R2","C4") << endl;
    for (auto x : mt2.getColumn("C4")) {
        cout << "\t" << x ;
    }
    cout << endl;
    for (auto x : mt2.getRow("R1a")) {
        cout << "\t" << x ;
    }
    cout << endl;
    mt2.writeTabfile("mt2.tab");
    newrow = {7,8,9,10,11};
    mt2.addRow("R6",newrow);
    newcol = {7,8,9,10,11,12};
    mt2.addColumn("C6",newcol);
    cout << "in memory tabdata" << endl;
    mt2.asText();
    
    mt2.readTabfile("mt2.tab");    
    cout << "in file tabdata" << endl;
    mt2.asText();
    // test operator overloading
    cout << mt2(0,0) << endl;
    mt2(0,0) = 0;
    cout << mt2(0,0) << endl;
    mt2.asText();
    // Exception ?
    mt2(7,5) = 100;
    cout << "new val: " << mt2(7,5) << endl;
    cout << "end" << endl;
    
    return 0; 
}


