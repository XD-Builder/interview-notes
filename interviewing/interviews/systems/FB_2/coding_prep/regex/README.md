# Abstract
* This document introduces regular expression in Python and its usages

## What is regex
1. Def
   1. Regular expressions, REs, or regexes, are essentially a tiny, highly specialize programming language embedded inside Python and made available through the re module. You specify the rules for the set of possible strings that you want to match and ask the question does this string match the pattern or is there a match for the pattern anywhere in this string. It can also be used to modify a string or to split it apart.
   2. It's compiled into a series of bytecodes which are then executed by a matching engine written in C.
      1. It's not all possible string processing tasks can be done using regex. Therefore, some tasks is better fitted to write Python code.
2. Using Regex
   1. p = re.compile("regex", re.IGNORECASE)
      1. returns a pattern object which have methods for various operations such as searching for pattern matches or performing string substitutions.
   2. p.match(" ")
      1. returns None if no match else a match object will be returned.
      2. Only checks if the RE matches at the start of a string
   3. Match Object Functions
      1. m.group() => returns the string matched by the RE
      2. m.start() => returns the starting index of the match
      3. m.end() => returns the ending index of the match
      4. m.span() => returns a tuple containing the (start, end) positions of the match
      5. m.search() => scans through the string, so the match may not start at zero.
      6. m.findall() => returns a list of matching strings
      7. m.split("strings") => returns a list of string split by the matcher
3. When to not use regex
   1. Regexes are a powerful tool for some applications but in some ways their behavior isn't intuitive and at times they don't behave the way you may expect them to.
   2. Why use string methods
      1. If you are matching a fixed string, or a single character class, you're not using any re features such as the IGNORECASE flag, then the full power of regex may not be required. String itself has several methods for performing operations with fixed strings and they are usually much faster because the implementation is a single small C loop that's been optimized for the purpose instead of the large more generalized regular expression engine.