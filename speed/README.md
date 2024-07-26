---
title: Spped tips and tricks for C++ code
author: Detlef Groth
date: 2024-07-26 06:25
---

## Introduction

Here a few tips and tricks to speed up regular expression code.

## Regular Expressions

Regular  expressions in C++ can be very slow. To speed up the final program it
is  often  helpful  to use  the  optimizer  flags  like  `g++ -O3` for the Gnu
compiler or using  simple  string  functions  like. Even better to replace not
neccessary  regular  expressions like with the string.find  command so instead
for instance using  `std::regex_search(line,  std::regex('^id:  '))` you could
speed up the code with `line.find('id: ') == 0`. 


The example [speed-regex.cpp](speed-regex.cpp) compares the speed using these two approaches.

```
[micky speed]$ g++ speed-regex.cpp 
[micky speed]$ ./a.out 
Usage: ./a.out FILENAME
[micky speed]$ time ./a.out go.obo ## 30 MB Gene Ontology Obo file
lines: 607352 ms:132
find ids: 47276 ms:182
regex ids: 47276 ms:9861

real    0m10,184s
user    0m9,993s
sys     0m0,068s
[micky speed]$ g++ -O3 speed-regex.cpp 
[micky speed]$ time a.out go.obo
lines: 607352 ms:113
find ids: 47276 ms:127
regex ids: 47276 ms:788

real    0m1,036s
user    0m0,984s
sys     0m0,039s
```

So using the compiler `-O3` flag alone  speeds up the  program from around 10 to just
0.7 seconds for the 30MB input file and using `line.find('id: ') == 0` makes it even
more five times faster.


## Memoization


The concept of memoization  extends  extensive  function calls with a check if
that  function was already  called with the same set of  arguments. If this is
the case, the previously  computed result is returned  instead of re-computing
it again. If you need more details, here is a 
[tutorial                                                                   on
geeksforgeeks](https://www.geeksforgeeks.org/what-is-memoization-a-complete-tutorial/).

But now here an example for calculating the Fibonacci number giving in the PEX lecture.


```cpp
#include <iostream>
#include <chrono>
#include <map>
int fibr (int x) {
    // static variable remembers variable values from previous calls
    static std::map<int,int> myfib;
    if (x < 3) {
        if (x == 0) {
            return(0;
        }
        return(1) ;
    }
    if (myfib.count(x)==0) {
        myfib[x]=fibr(x-2)+(fibr(x-1));
    }
    return(myfib[x]);
}
int main () {
    auto start = std::chrono::system_clock::now();
    for (int x = 1; x < 30; x++) {
        std::cout << "Fibonacci  of " << x
            << "=" << fib(x) << std::endl;
    }
    auto diff = std::chrono::system_clock::now() - start ;
    std::cout << "Elapsed(ms)=" << diff.count()/1000 << std::endl;
    return(0);
}
```

Here a comparison of a normal recursive  Fibonacci number  implementation with
the memoized version using the file [speed-memoize.cpp](speed-memoize.cpp):
.
```
[micky speed]$ g++ -O3 speed-memoize.cpp 
[micky speed]$ ./a.out 
Usage: ./a.out number
[micky speed]$ time ./a.out 45
Result for fib(45) = 1134903170
Elapsed time (ms) recursive (1134903170): 1581
Elapsed time (ms) memoized  (1134903170): 0
Elapsed time (ms) constexpr (1134903170): 1477

real    0m3,066s
user    0m3,013s
sys     0m0,023s
```

Using constexpr does not have a positive impact.

A long  discussion  about  general  memoization  approaches  can be  found  on
[Stackexchange](https://stackoverflow.com/questions/17805969/writing-universal-memoization-function-in-c11).

However just adding a std::map and a count check does seems for me much easier
than these more generic approaches.

