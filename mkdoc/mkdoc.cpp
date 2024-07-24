#include <iostream>
#include <memory>
#include <string>
#include <regex>
#include <fstream>
#include <filesystem>

#include "maddy/parser.h"
#include "mkdoci-css.h"

/*
#' ## mkdoc command line application
#' 
#' ## USAGE
#' 
#' ```
#' mkdoc cmd infile outfile
#' ```
#' 
#' ## COMMANDS
#' 
#' The following commands are available:
#' 
#' * _code2md infile outfile_ - extract the Markdown documentation embedded in infile and write this into outfile
#' * _code2html infile outfile_ - extract the Markdown documentation embedded in infile and write this into converted to HTML into outfile
#' * _md2html infile outfile_ - convert a given Markdown infile into a HTML outfile
#' 
#' Please note that per default a stylesheet link is added to the HTML output file. The file is named _mkdoc.css_
#' 
#' ## CLASS USAGE
#' 
#' The application is as well a class _MkDoc_ which can be used within other applications.
#' It supports the following methods.
#' 
#' * _Mkdoc mkdoc_  - default constructor, creating the instance _mkdoc_
#' * _void mkdoc.code2md(std::string infile, std::string outfile)_ - extract the Markdown documentation embedded in infile and write this into outfile
#' * _void mkdoc.code2html(std::string infile, std::string outfile)_ - extract the Markdown documentation embedded in infile and write this into converted to HTML into outfile
#' * _void mkdoc.md2html(std::string infile, std::string outfile)_ - convert a given Markdown infile into a HTML outfile
#' 
#' ## EXAMPLE
#' 
#' Below an example where mkdoc builds its own documentation:
#' 
#' ```
#' MkDoc mkdoc;
#' mkdoc.code2html("mkdoc.cpp","mkdoc.html");
#' ```
#' 
#' ## COMPILATION AND DOCUMENTATION
#' 
#' Below is a demonstration on how to compile this file mkdoc.cpp and how to 
#' create a header file of the css file to be embedded within the source code.
#' 
#' ```
#' xxd -i mkdoc.css mkdoci-css.h
#' g++ -std=c++17 -Iinclude mkdoc.cpp -o mkdoc
#' ./mkdoc code2html mkdoc.cpp mkdoc.html
#' ```
#' 
#' ## AUTHORS 
#' 
#' @ PE students 2020 and lecturer Detlef Groth, University of Potsdam
#' 
#' ## THIRD PARTY LIBRARIES
#' 
#' The mkdoc application uses standard C++ libraries and the third party header only library _maddy_ from XYZ to convert Markdown code into HTML code.
#' 
#' ## LICENSE
#' 
#' The mkdoc.cpp source code is relased using the MIT license.
  
*/
using namespace std;

class MkDoc {
public:
    void code2md (string infile, string outfile);
    void md2html(string infile, string outfile);
    void code2html(string infile, string outfile);
    int main(int argc, char**argv);
};
void MkDoc::code2md(string infile, string outfile){
    string line;
    ifstream myfile (infile);
    ofstream myoutfile (outfile);
    regex md("^\\s*#' ");
    if (myfile.is_open() and myoutfile.is_open()) {
        while ( getline (myfile,line) )
        {
            if (regex_search(line, md)) {
                line = regex_replace(line, md, "");
                myoutfile << line << "\n";
            }
        }
        myfile.close();
        myoutfile.close();
    }
    
    else cout << "Unable to open out or input file"; 
}

void MkDoc::md2html(string infile, string outfile) {
    string line;
    ifstream myfile (infile);
    ofstream ofile (outfile);
    stringstream markdownInput;
    regex rx = regex("\\..+");
    if (myfile.is_open()) {
        while ( getline (myfile,line) ) {
            markdownInput << line << endl;
        }
    }
    shared_ptr<maddy::ParserConfig> config = make_shared<maddy::ParserConfig>();
    config->isEmphasizedParserEnabled = true; // default
    config->isHTMLWrappedInParagraph = true; // default
    shared_ptr<maddy::Parser> parser = make_shared<maddy::Parser>(config);
    string htmlOutput = parser->Parse(markdownInput);
    ofile << "<html><head><title>" << regex_replace(infile,rx,"") << " manual</title><link rel='stylesheet' href='mkdoci.css' type='text/css'></head><body>\n" ;
    ofile <<  htmlOutput << endl;
    ofile <<  "\n</body></html>";
    // TODO: check if file exists
    if (!std::filesystem::exists("mkdoci.css")) {
        std::ofstream cssfile ("mkdoci.css");
        for (unsigned int i = 0; i < mkdoc_css_len; i++) {
            cssfile.put(mkdoc_css[i]);
        }
        cssfile.close();
    }

}
    
void MkDoc::code2html(string infile, string outfile){
    string in_between="temp.md";
    code2md(infile,in_between);
    md2html(in_between,outfile);
    /*if( remove( "temp.md" ) != 0 )
        perror( "Error deleting temporary file file" );
    else
       puts( "temporary File successfully deleted" );
     */

}
int MkDoc::main(int argc, char **argv) {
    if (argc != 4) {
        cout << "Usage: mdkoc cmd infile outfile\n";
        cout << "   cmd either code2md, md2html or code2html\n";
        return(0);
    } 
    
    string cmd(argv[1]);
    
    if (cmd == "code2md") {
        code2md(argv[2],argv[3]); 
    } else if (cmd == "md2html") {
        md2html(argv[2],argv[3]); 
    } else if (cmd == "code2html") {
        code2html(argv[2],argv[3]); 
    } else  {
        cout << "Unkown command: " << cmd << endl;
        cout << "   valid commands are: code2md, md2html or code2html\n";
    } 
    return(0);
}    

// TODO move main to extra file or use ifdef ...
int main (int argc, char**argv) {
    MkDoc mkdoc;
    return(mkdoc.main(argc,argv)); 
}

