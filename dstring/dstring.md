---
title: pex::dstring manual pageLong Title
author: Detlef Groth
date: 2024-07-27 08:42
---

## NAME

pex::dstring - string class with additional methods based on std::string.

## DESCRIPTION

This  class is  created to  illustrate  the  concepts  of  inheritance using delegation,  method
implementation  and operator  overloading  in C++. Original  functions  of the
std::string calls can be called with the get method. This approach is 

## Constructors

__pex::dstring()__

> Initialize a dstring with an empty string.

__pex::dstring(const std::string& s)__

> Initialize a dstring with the given string 's'.

__pex::dstring(char *s)__

> Initialize a dstring with the given character array 's'.

## Methods

In addition to all methods of the
[std::string](https://en.cppreference.com/w/cpp/string/basic_string) the
following methods are provided:

__bool pex::dstring::ends_with(const std::string & ending)__

> Check if the string ends with the given ending.

__std::string get()__

> Returns the internal  standard string object, useful to call orignal methods
  for std::string

__bool pex::dstring::is_lower()__

> Check if the string only has lower case characters.

__bool pex::dstring::is_upper()__

> Check if the string only has upper case characters.

__bool pex::dstring::starts_with(const std::string& prefix)__

> Check if the string starts with the given prefix.

__pex::dstring pex::dstring::to_lower()__

> Converts the string to lower case characters.

__pex::dstring pex::dstring::to_upper()__

> Converts the string to upper case characters.

## Operators

One  disadvantage  of the used  approach is that you have to redo all operator
overloadings,  for  instance  to  compare  a dstring  object  with a  standard
std::string  object  which  is  awkward.  Then  as well  only  right-hand-side
comparisons  work  like  pex::dstring  ==  std::string  but  not  the  reverse
std::sting == pex::dstring.  Alternativly  you could use the get method to use
the internal std::string for this purpose.

Anyway, the  following  operators  has been  overloaded  to mimic the operators of the
std::string class:

`>>`, ``<<``, `+=`, `+`, `==` and `!=`.

## Example

```{.cmd eval=TRUE file=hello.cxx}
///usr/bin/g++ -o "${0%.cpp}" dstring.cpp "$0" && exec "${0%.cpp}"
// compile with g++ dstring.cpp test.cpp -o test
#include <iostream> 
#include <filesystem>
#include "dstring.hpp"

int main(int argc, char** argv) {
  pex::dstring hello = "Hello";
  std::string world = "World";
  std::cout << "hello starts with hel? " << hello.starts_with("hel") << std::endl;
  std::cout << "hello == world?        " << (hello == world) << std::endl;
  std::cout << "hello != world?        " << (hello != world) << std::endl;
  return(0);
} 
```

## AUTHOR

Detlef Groth, University of Potsdam, Germany

## LICENSE


MIT-License:


Copyright (c) 2024 Detlef Groth, University of Potsdam, Germany

Permission is hereby  granted, free of charge, to any person  obtaining a copy
of this software and associated  documentation files (the "Software"), to deal
in the Software without  restriction,  including without limitation the rights
to use, copy, modify,  merge,  publish,  distribute,  sublicense,  and/or sell
copies  of the  Software,  and to  permit  persons  to whom  the  Software  is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE  SOFTWARE IS PROVIDED  "AS IS", WITHOUT  WARRANTY OF ANY KIND,  EXPRESS OR
IMPLIED,  INCLUDING  BUT NOT  LIMITED TO THE  WARRANTIES  OF  MERCHANTABILITY,
FITNESS FOR A PARTICULAR  PURPOSE AND  NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS  OR  COPYRIGHT  HOLDERS  BE LIABLE  FOR ANY  CLAIM,  DAMAGES  OR OTHER
LIABILITY,  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.



