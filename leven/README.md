---
title: Implementing a function for the Edit distance between two strings
author: Detlef Groth
date: 2024-07-25 07:26
---

## Introduction

This was an exercise in Summer  semester 2022,  implementing  the  Levenshtein
distance  which  is the  edit  distance  between  two  strings  using  dynamic
programming.

## Files

- [levenshtein.cpp](levenshtein.cpp) - with functions main and levenshtein:
    - basic parsing of command line options using argc and argv variables
    - working with regular  expression  from command line argument  checks and
    text extraction
    - implementing a dynamic programming algorithm

## Example

Here an example run with output:

```
[micky leven]$ g++ levenshtein.cpp -o leven
[micky leven]$ ./leven
Usage: ./leven string1 string2 ?gapcost?
   ex: ./leven drei three 1
[micky leven]$ ./leven drei three 2
edit_dist of 'drei' and 'three' is: 4
[micky leven]$ ./leven drei three 1
edit_dist of 'drei' and 'three' is: 3
```


