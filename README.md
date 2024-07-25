# pex

C++ Code for exerices, homeworks and C++ hints and links for the lecture  "Programming  Expertise" at the University
of Potsdam for the Master course Bioinformatics in the second semester.

## Projects

- [Pexban](pexban) - 4 weeks project of a Kanban board application (SS2024)
- Sheepboard - 4 weeks project to play the game sheeps and wolf (SS2023) 
- [Blossum](blossum)  - exercise  for parsing  inline  tabular data and using
  operator overloading (SS2022)
- [Calc](calc) - exercise for writing a terminal tool to exercise addition and multiplication (SS2022)
- [Grep](grep) - exercise for using std::vector to implement R like grep functions (SS2022)
- [Leven](leven) - exercise for implementing the Levenshtein edit distance (SS2022)
- [GoUtils](goutils) - exercise start of a parser for Gene Ontology obo files (SS2021)
- [Minimat](matrix) - exercise for implementing a matrix class using templates (SS2021)
- [Mkdoc](mkdoc) - 2 weeks project for a API documentation tool using Markdown (SS2020)

## Code

- pex namespace with utility functions
- pex::dstring class - extension of std::string

## Templates

- [app-argv.cpp](https://github.com/mittelmark/pex/blob/main/templates/app-argv.cpp) - template for new applications using pureargc/argv parsing
- [app-argparse.cpp](https://github.com/mittelmark/pex/blob/main/templates/app-argparse.cpp) - template for new applications using the [argparse](https://github.com/p-ranav/argparse) library
- [app-popl.cpp](https://github.com/mittelmark/pex/blob/main/templates/app-popl.cpp) - template for new applications using the [popl](https://github.com/badaix/popl) library

You can use these templates with the following editors like this:

- Nano
    - use the insert file feature
- Geany (Linux)
    - copy the files into a folder ~/.config/geany/templates/files
    - the menu entry "File -> New (from template)" should then show these files as new starting files
- Jasspa MicroEmacs - https://githhub.com/mittelmark/microemacs
    - use the insert-file command, press Esc, then x then enter insert-file in
      the command line and write down the file name supported by using the TAB
      key for filename competion
    - or use the insert-template menu:
        - create folder ~/.jasspa/cpp 
        - copy the files into this folder but change the extension from cpp to etf
          (Micro__E__macs __t__emplate __f__ile)    
        - if you then create a new Cpp-file and thereafter execute the command "Esc x  insert-template"  and then press
          the TAB key you should see the  templates  where the  selected one will be
          inserted at the current cursor position
    
## Snippets

Here are  editor  snippets  which  allow  you more  easily  to embed  C++ code
snippets:

-  for MicroEmacs
  [cpp.eaf](https://github.com/mittelmark/pex/blob/main/snippets/cpp.eaf) - just
   copy this file into the MicroEmacs user folder, usually ~/.jasspa, then use
   the command  "Esc x  abbrev-list"  in the editor to see the  abbreviations,
   clicking on them inserts the text snippets
- [geany.conf](https://github.com/mittelmark/pex/blob/main/snippets/geany.conf) for Geany - just add the lines of this file to your snippets.conf file
    
## Links

### Documentation

- https://en.cppreference.com/w/
- https://devdocs.io/

## Interfacing C++ with R and Python

- [Rcpp](https://cran.r-project.org/web/packages/Rcpp/index.html)
- [Python bindings overview](https://realpython.com/python-bindings-overview)
- [SWIG - interace generator for Octave, Python, R, Tcl etc](https://swig.org/)

### Source code tools

- [cppcheck](http://cppcheck.net/) - C++ code checker/linter - install with: `sudo dnf|apt install cppcheck`
- [astyle](https://astyle.sourceforge.net/) - C++ source code formatter - install: with `sudo dnf|apt install astyle`
- 
### CLI-Libraries

- [argparse](https://github.com/p-ranav/argparse) - Python argparse alike
- [CLI11](https://github.com/CLIUtils/CLI11) - most feature complete but slower compilation
- [popl](https://github.com/badaix/popl) - small and easy to use

### Unit-Testing

- [doctest](https://github.com/doctest/doctest) - single file header testing
- [utest](https://github.com/sheredom/utest.h) - single file header testing

### GUI-libraries

- [FLTK](http://www.fltk.org/) - small GUI library
- [webview](https://github.com/webview/webview) - use HTML, CSS and JavaScript to build C++ applications

### File related libraries

- [glob](https://github.com/p-ranav/glob) - glob style file matching
- [gzstream](https://www.cs.unc.edu/Research/compgeom/gzstream/) - reading compressed files as streams
- [ghc/filesystem](https://github.com/gulrak/filesystem) - filesystem (C++17) backport

### Reflection

- [visit_struct](https://github.com/cbeck88/visit_struct) - loop over members
  of a structure
- [reglexpr](https://en.cppreference.com/w/cpp/keyword/reflexpr) - C++ proposal

### Backports of new C++ features to older compilers

- [fmt](https://github.com/fmtlib/fmt) - std::format (C++20) alternative and more
- [ghc/filesystem](https://github.com/gulrak/filesystem) - filesystem (C++17) backport
- [optional-lite](https://github.com/martinmoene/optional-lite) - optional (C++17) backport
- [nanoranges](https://github.com/tcbrindle/NanoRange) - ranges (C++20) support for C++17
- [span-lite](https://github.com/martinmoene/span-lite) - span (C++20) backport
- [Martin Moene Backports](https://github.com/martinmoene?tab=repositories&q=lite&type=&language=&sort=)
  
### Other

- [nlohmann/json](https://github.com/nlohmann/json) - using Json like STL containers
- [maddy](https://github.com/progsource/maddy) - Markdown conversion to HTML
 
### Videos about new C++ features C++ Weekly

- [C++98](https://www.youtube.com/watch?v=78Y_LRZPVRg)
- [C++11](https://www.youtube.com/watch?v=D5n6xMUKU3A)
- [C++14](https://www.youtube.com/watch?v=mXxNvaEdNHI)
- [C++17](https://www.youtube.com/watch?v=QpFjOlzg1r4)
- [C++20](https://www.youtube.com/watch?v=N1gOSgZy7h4)
- [C++23](https://www.youtube.com/watch?v=N2HG___9QFI)
- [90 features in 20 minutes](https://www.youtube.com/watch?v=VpqwCDSfgz0)

