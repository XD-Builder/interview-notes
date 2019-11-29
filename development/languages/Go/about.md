## Background

1. Language is initially developed at Google in the year 2007 by Robert Griesemer, Rob Pike, Ken Thompson. It's a statically-typed language having syntax similar to that of C.
   1. It provides **garbage collection**, **type safety**, **dynamic-typing capability**, **many advanced built-in types** such as variable length arrays and **key-value maps**.
   2. It also provides a rich standard library.
   3. Launched in November 2009 and is used in some of the Google's production systems.

## Overview

1. How Go projects are organized and built
   1. Programs are constructed using packages, for efficient management of dependencies. It uses traditional compile and link model to generate executable binaries.
2. Features of Go
   1. Support for environment adopting patterns similar to dynamic languages. Ex. type inference x := 0 // a valid declaration of a variable x of type int.
   2. Inbuilt concurrency support: lightweight process (via go routines), channels, select statement.
   3. Go programs are simple, concise, and safe
   4. Support for Interfaces and Type embedding
   5. Production of statically linked native binaries without external dependencies.
3. Excluded Features of Go
   1. Type inheritance
   2. Method or operator overloading
   3. Circular dependencies among packages
   4. Pointer arithmetic
   5. Assertions
   6. Generic programming

## Go Program Structure

1. The bare minimum structure of Go program includes parts:
   1. Package declaration, import packages, functions, variables, statements and expressions and comments.
2. Executing a Go program
   1. go run program.go

## Basic Syntax

1. Line Separator
   1. The line separator is a statement terminator. That is individual statement don't need a special separator like ";" in C. The Go compiler internally places ";" as the statement terminator to indicate the end of one logical entity.
2. Comments
   1. /\* \*/
3. Identifiers
   1. Identifier = letter { letter | unicode_digit }
   2. Go is case sensitive programming language.
4. Keywords
   1. break, default, func, interface, select, case, defer, Go, map, Struct, chan, else, fallthrough, if, range, Type, continue, for, import, return, Var
5. Whitespace in Go
   1. A term used to describe blanks, tabs, newline characters, and comments.
      1. A line containing only whitespace, possibly with a comment, is known as a blank line, and a Go compiler totally ignores it.
      2. Whitespaces separate one part of a statement from another and enables the compiler to identify where one element in a statement, such as int, ends and the next element begins.
