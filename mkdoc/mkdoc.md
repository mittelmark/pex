## mkdoc command line application

## USAGE

```
mkdoc cmd infile outfile
```

## COMMANDS

The following commands are available:

* _code2md infile outfile_ - extract the Markdown documentation embedded in infile and write this into outfile
* _code2html infile outfile_ - extract the Markdown documentation embedded in infile and write this into converted to HTML into outfile
* _md2html infile outfile_ - convert a given Markdown infile into a HTML outfile

Please note that per default a stylesheet link is added to the HTML output file. The file is named _mkdoc.css_

## CLASS USAGE

The application is as well a class _MkDoc_ which can be used within other applications.
It supports the following methods.

* _Mkdoc mkdoc_  - default constructor, creating the instance _mkdoc_
* _void mkdoc.code2md(std::string infile, std::string outfile)_ - extract the Markdown documentation embedded in infile and write this into outfile
* _void mkdoc.code2html(std::string infile, std::string outfile)_ - extract the Markdown documentation embedded in infile and write this into converted to HTML into outfile
* _void mkdoc.md2html(std::string infile, std::string outfile)_ - convert a given Markdown infile into a HTML outfile

## EXAMPLE

Below an example where mkdoc builds its own documentation:

```
MkDoc mkdoc;
mkdoc.code2html("mkdoc.cpp","mkdoc.html");
```

## COMPILATION AND DOCUMENTATION

Below is a demonstration on how to compile this file mkdoc.cpp and how to 
create a header file of the css file to be embedded within the source code.

```
xxd -i mkdoc.css mkdoci-css.h
g++ -std=c++17 -Iinclude mkdoc.cpp -o mkdoc
./mkdoc code2html mkdoc.cpp mkdoc.html
```

## AUTHORS 

@ PE students 2020 and lecturer Detlef Groth, University of Potsdam

## THIRD PARTY LIBRARIES

The mkdoc application uses standard C++ libraries and the third party header only library _maddy_ from XYZ to convert Markdown code into HTML code.

## LICENSE

The mkdoc.cpp source code is relased using the MIT license.
