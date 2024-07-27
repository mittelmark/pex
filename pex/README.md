---
title: Namespace pex with utility functions for the course Programming Expertise
author: Detlef Groth
date: 2024-07-27 11:28
---

## Introduction

The files [pex.cpp](pex.cpp) and [pex.hpp](pex.hpp)  provide utility functions
for the C++  part of the  course  Programming  Expertise.  The  functions  are
organized in a namespace pex and belong to four categories:

- file related functions like get_home_directory, file_exists, file_grep
- string related functions like is_lower, starts_with
- regular  expression  based search and  replacements  which mimic R functions
  like grep, grepl and gsub for std::string scalars and vectors
- logical vector checks any and all which as well mimic R functions.

Further there are as well  constantss to allow colored  terminal  outputs like
`pex::YELLOW`, `pex::RED` or `pex::RESET`.

## Files

- [pex.cpp](pex.cpp) - implementation and main function for testing 
- [pex.hpp](pex.hpp) - header file
- [pex.md](pex.md)   - API documentation
- [pex-test.cpp](pex-test.cpp)  - doctest based test file

To run the main  function in pex.cpp you have to define the compiler  variable
PEXI like this:

```
g++ -DPEXI pex.cpp -o pexi
./pexi
```


