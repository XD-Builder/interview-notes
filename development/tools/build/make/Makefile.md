# Abstract
- This document tries enable a newbie to quickly get up to speed reading and writing Makefile. Full reference can be found  [here](https://www.gnu.org/software/make/manual/html_node/)

## Directives
* include filenames…
    * The arg filenames must be non-empty and space-separated if more than one arg.

## Functions
* $(firstword names…)
    * Returns the first name in space separated names
* $(foreach var,list,text)
    * First the first two args var and list and expanded but not text arg. Then for each word of the expanded value of list, the variable named by the expanded value of var is set to that word. Then the text is expanded and can reference that variable variable name set by var.
* $(wildcard pattern…)
    * A space-separated list of names of existing files that match one of this given file name patterns will be returned.
