---
title: Implementing a dstring class inheriting from std::string
author: Detlef Groth
date: 2024-07-27 08:48
---

## Introduction

This was illustrative  project to show how we can use delegation to inheriting
from the std::string  class. Althought the approach seems powerful at first it
starts to become slightly tedious as we have to overwrite all string operators
or provide a get_string  method to return the internal string object to use it
for operators or functions which require a true std::string object. 

The main idea is to have an internal  std:string object, adding new methods to
the new class and for working  with the internal  std::string  object call the
get function like this:

```cpp
pex::string hello = "Hello";
// calling added pex::dstring method
std::cout << hello.starts_with("hel") << std::endl;
// calling std::string method
std::cout << hello.get().length() << std::endl;;
```

## Files

- [dstring.cpp](dstring.cpp)  - implementation
- [dstring.hpp](dstring.hpp)  - header file
- [dstring.md](dstring.md)     - manual page
- [test.cpp](test.cpp)        - simple test application
