---
title: Implementing of R like grep, any and all functions
author: Detlef Groth
date: 2024-07-25 08:18
---

## Introduction

This was an exercise in Summer  semester  2021,  implementing  the R functions
grep, grepl, any and all in C++.
The testing code in main  illustrates  the  requirement  for better
testing   facilities   for  instance   using  a  unit  testing   library  like
[doctest](https://github.com/doctest/doctest).

## Files

- [grep.cpp](grep.cpp) - with methods `pex::grep`,  `pex::grepl`,  `pex::any`
  and `pex::all` exercising:
    - function overloading
    - default function arguments
    - using data structure std::vector
    - using namespaces
    - motivating the use of testing frameworks
    
    


