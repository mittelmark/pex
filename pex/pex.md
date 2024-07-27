---
title: Long Title
author: Detlef Groth
date: 2024-07-27 11:31
abstract: >
    Some abstract ...
    on several lines ...
include-before: |
    <style>
    body { max-width: 1000px; font-family: Candara, sans-serif; }
    pre  { font-family: Consolas; monospaced; }
    table { min-width: 400px; border-spacing: 5px;  border-collapse: collapse; }
    </style>
    <center>some links on top</center>
---

## NAME

__pex__ -  namespace  with  C++  utility  functions  for  the  course  Programming
Expertise.

## SYNOPSIS

```cpp


```

## Functions

### File and Directory related functions

__std::string get_home_directory ()__

> get the users home directory as a string

__bool file_exists(const std::string & filename)__

> check if  the   given   filename  exists as a file, simple   replacement   for   the
`¥filesystem::exists` function

__bool  file_has_extension  (const std::string & filename, const std::string &
extension)__

> check if the file has the given file extension

__bool file_is_compressed (const std::string & filename)__

check if the given filename has an extension belonging to a compressed such as
zip, gz, 7z, z etc

__bool file_is_gzipped (const std::string & filename)__

> check if the given filename belongs to a file which is gzip compressed

__std::vector<int>  file_grep (const std::string & filename, const std::string
& pattern)__

> search the file with the given  string  pattern and return the line  numbers
matching that patterns

### String related functions

__bool ends_with(std::string const &fullString, std::string const &ending)__

>  check if the given strings ends with the given ending string

__bool is_lower(const std::string& str)__

> check if the given string only consists out of lower case letters

__bool is_upper(const std::string& str)__

> check if the given string only consists out of upper case letters

__bool replace(std::string& str, const std::string& from, const std::string& to, bool all = false)__

> replace in the given string all or one `from` string to `to` string arguments

__bool starts_with(std::string const &fullString, std::string const &starting)__

> check if the given strings start with the given starting string

__std::string to_lower (const std::string srcstring)__

> convert all uppercase characters in the given string to lowercase letters

__std::string to_upper  (const std::string srcstring)__

> convert all lowercase characters in the given string to uppercase letters

### Regular expressions

__std::vector<int> grep (const std::string & pattern, const std::string & str,
                       const      std::regex::flag_type      &      flag     =
                       std::regex::extended)__

> search  the given  string  with a pattern  and return the  positions  in the
string where this pattern is found
                       
__std::vector<int> grep (const std::string & pattern, const std::vector<std::string> & vstring, 
                       const std::regex::flag_type & flag = std::regex::extended)__

> search the given string  vector for a pattern and retutn the vector  indices
which match the pattern
   
__bool grepl (const std::string & pattern, const std::string & str,  
            const std::regex::flag_type & flag = std::regex::extended)__

> check if a string contains the pattern

__std::vector<bool> grepl (const std::string & pattern, const std::vector<std::string> & vstring,  
                         const      std::regex::flag_type     &     flag     =
                         std::regex::extended)__

> check the given  string  vector  for a pattern  and return true or false for
each element

__std::string gsub (const std::string & pattern, 
                  const std::string & replace, 
                  const std::string & str,
                  const std::regex::flag_type & flag = std::regex::extended)__

> do replacement  for the given string using the given pattern
 
__std::vector<std::string> gsub (const std::string & pattern, 
                               const std::string & replace, 
                               const std::vector<std::string> & vstring,
                               const std::regex::flag_type & flag = std::regex::extended)__

> do  replacements  for all string of the given vector using the given pattern
and return the modified strings as vector

### Boolean vector checks

__bool all (const std::vector<bool> & vec)__

> check if all element in the given vector contains true values

__bool any (const std::vector<bool> & vec)__

> check if the given vector has any true value


## Constants


- __const std::string RED = "\033[31m"__ - terminal red
- __const std::string GREEN = "\033[32m"__ - terminal green
- __const std::string YELLOW = "\033[33m"__ - terminal yellow
- __const std::string BLUE = "\033[34m"__ - terminal blue
- __const std::string MAGENTA = "\033[35m"__ - terminal magenta
- __const std::string CYAN = "\033[36m"__ - terminal cyan
- __const std::string LRED = "\033[91m"__ - terminal light red
- __const std::string LGREEN = "\033[92m"__ - terminal light green
- __const std::string LYELLOW = "\033[93m"__ - terminal light yellow
- __const std::string LBLUE = "\033[94m"__ - terminal light b√lue
- __const std::string LMAGENTA = "\033[95m"__ - terminal light magenta
- __const std::string LCYAN = "\033[96m"__ - terminal light cyan
- __const std::string RESET = "\033[0m"__ - terminal defaults




