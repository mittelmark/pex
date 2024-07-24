---
title: Mkdoc - Documentation creater for any Programming Language
author: Detlef Groth
date: 2024-07-24 21:38
---

## Introduction

This project was a homework  project in Summer  sememster  2020 for the
course  "Programming  Expertise"  - a  bridge  course  for our  Master  course
Bioinformatics   at  the   University   of   Potsdam.   It  uses  the   [Maddy
library](https://github.com/progsource/maddy)    from   Petra   Baranski   for
optionall< converting the Markdown extracted documentation into HTML.

The following files are part of the project:

- [mkdoc.cpp](mkdoc.cpp) - the main application file
- [mkdoci-css.cpp](mkdoci-css.cpp)   -  the  css  code   created   with  the
  [xxd](https://github.com/ckormanyos/xxd)  application.

The compilation of the program is just using:

```
g++ -I. mkdoc.cpp -o mkdoc.cpp
```

## Application purpose

Documentation  of classes,  methods,  functions  and variables can be embedded
directly with in the programming code using Markdown formatting commands after
lines   starting  with  `#'`  which  are  surrounded  by  Multiline   comments
markders.
So in C++ code that should like like this  (example from mkdoc.cpp):

```
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
#' * _code2md infile outfile_ - extract the Markdown documentation embedded in
#'    infile and write this into outfile
#' * _code2html infile outfile_ - extract the Markdown  documentation embedded
#'   in infile and write this into converted to HTML into outfile
#' * _md2html infile outfile_ - convert a given Markdown infile into a HTML outfile
#' 
#'
*/
```

The mkdoc application just extracts the Markdown comments into a Markdown file
and optionally converts them as well to HTML code using the maddy library.

