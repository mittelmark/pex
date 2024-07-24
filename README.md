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
- app-popl - template for new applications using the [popl](https://github.com/badaix/popl) library

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
 
