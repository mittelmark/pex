# pex

C++ Code and hints for the lecture "Programming expertise" at the University of Potsdam

## Projects

- Pexban
- Mkdoc
- Sheepboard

## Code

- pex namespace with utility functions
- pex::dstring class - extension of std::string

## Templates

- [app-argv.cpp](https://github.com/mittelmark/pex/blob/main/templates/app-argv.cpp) - template for new applications using pureargc/argv parsing
- [app-argparse.cpp](https://github.com/mittelmark/pex/blob/main/templates/app-argparse.cpp) - template for new applications using the [argparse](https://github.com/p-ranav/argparse) library
- [app-popl.cpp](https://github.com/mittelmark/pex/blob/main/templates/app-popl.cpp) - template for new applications using the [popl](https://github.com/badaix/popl) library

You can use these templates with the following editors like this:

- Nano
    - just use the insert file feature
- Geany (Linux)
    - copy the files into a folder ~/.config/geany/templates/files
    - the menu entry "File -> New (from template=" should then show these files as new starting files
- Jasspa MicroEmacs - https://githhub.com/mittelmark/microemacs
    - create folder ~/.jasspa/cpp
    - copy the files into this folder but change the extension from cpp to etf
    (MicroEmacs template file)    
    - if you then create a new Cpp-file and thereafter execute the command "Esc x  insert-template"  and then press
    the TAB key you should see the  templates  where the  selected one will be
    inserted at the current cursor position
    -alternatively  you can simply use the  insert-file  command of MicroEmacs
    after pressing "Esc x" (first escape, then x) and then select the file to insert
    
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

