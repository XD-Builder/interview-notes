# Abstract

- This document explores different useful/practical aspects of Vim and how it can be applied to boost your productivity

## Packages

### Vundle

1. What is?
   1. Short for Vim Bundle, a Vim plugin manager. It keeps track of and configures your plugins right in vimrc.
   2. It allows install and update configured plugins, search by name all available Vim scripts, clean unused plugins up
   3. It automatically manages runtime path of your installed scripts and regenerates help tags after installing and updating
2. How to Configure?
   1. Download Vundle to ~/.vim/bundle/Vundle.vim
   2. On top of .vimrc
      1. set nocompatible " be iMproved, required
      2. filetype off " required
      3. set rtp+=~/.vim/bundle/Vundle.vim
      4. call vundle#begin() " To begin Vundle Plugin
      5. Plugin 'VundleVim/Vundle.vim' " Let Vundle manage Vundle
      6. " ... Other plugins
      7. call vundle#end() " required, Vundle plugin load
      8. filetype plugin indent on " required, enables filetype detection by content or extension, plugin to filetype application and indent rules for a number of filetype
3. How to use?
   1. Normal Mode
      1. PluginList, PluginInstall, PluginSearch foo, PluginClean

### Commentary

1. What is?
   1. Comment stuff out with `gcc` for entire line, and `gc` + motion to comment out along motion
   2. Also allows range comment with :x,yCommentary and global invocation :g/ToComment/Commentary

### Vim-dispatch

1. What is?
   1. Kicks off builds and test suites using one of several asynchronous adapters such including tmux, iTerm, Windows, and a headless mode and when the job completes, errors will be loaded and parsed automatically.
2. Use 1 - Compiler Switching
   1. The core of Vim's compiler system is `:make` and a command similar to `:grep` that runs a build tool and parses the resulting errors
   2. The default build tool is `make` and you can change it by running `:compiler`
   3. `:Dispatch` command looks for a compiler for an executable and sets it up automatically.
   4. Default Dispatch
      1. With no arguments, `:Dispatch` looks for a `b:dispatch` variable.
      2. autocmd FileType java let b:dispatch = 'javac %'
         1. This sets filetype java to be dispatched via javac <filename>
3. Use 2 - Spawning interactive processes
   1. You want to kick off a process without any output capturing or error parsing.
   2. Run `:Start lein repl`, and unlike make a new window will start and in focus

### Vim-repeat

1. What is?
   1. '.' command only works on the last native command inside that map. Vim-repeat supports repeating of plugins such as surround.
   2. Support to repeat other plugins is generally as simple as:
      1. silent! call repeat#set("\<Plug>MyWonderfulMap", v:count)

### Vim-surround

1. Features
   1. Change Surround - `cs"'`
      1. "Hello world!" => 'Hello world!'
   2. Remove the delimiters entirely - `ds"`
      1. "Hello world!" => Hello world!
   3. Add delimiter to a text - `ysiw]`
      1. "Hello world!" => [Hello] world!
   4. Wrap entire line in parentheses - `yssb` or `yss)`
      1. { Hello } world! => ({ Hello } world!)

### Auto Pairs

1. What is?
   1. Insert/delete brackets, parens, quotes in pair
2. Features
   1. Insert/delete in pair, insert new indented line after Return
      1. [ => [], food[<BS>] => foo, {|}(<CR> at |) = > {<br> | <br>}
   2. Insert spaces before closing characters for enclosed parens, [], (), {}
   3. Skip when inside a word and when previous character is \
   4. Other features such as Fly mode, fast wrap

### Tagbar

1. What is?
   1. A Vim plugin that provides an easy way to browse the tags of the current file and get an overview of its structure.
   2. It creates a sidebar that displays the ctags-generated tags of the current file, ordred by their scope. It means that for example methods in C++ are displayed under the class they are defined in.
2. What it is not?
   1. It's not a general purpose tool for managing tags files because it only creates the tags it needs on the fly in memory without creating any files
   2. tags file management is provided by other plugins such as "easytags"

### Syntastic

1. What is?
   1. A syntax checking plugin which runs files through external syntax checkers and displays any resulting errors to the user.
2. Features
   1. Errors are loaded into the location list for the corresponding window
   2. When the cursor is on a line containing an error, the error message is echoed in the command window
   3. Signs are placed beside lines with errors
   4. There is a configurable statusline flag you can include in your statusline config
   5. Hover the mouse over a line containing an error and the error message is displayed as a balloon
   6. Highlighting errors with syntax highlighting.

### Vim-gitgutter

1. What is?
   1. A plugin which shows a git diff in the 'gutter'. It shows which lines have been added, modified or removed.
2. Features
   1. Shows signs for added, modified and removed lines
   2. Runs the diff asynchronously where possible
   3. Ensures signs are always up to date.
   4. Quick jumping between blocks of changed lines ("hunks)
   5. Stage/undo/preview individual hunks
   6. Provides a hunk text object.
   7. Diffs against index (default) or any commit
   8. Handles line endings correctly, even with repos that do CRLF conversion
   9. Optional line highlighting
   10. Fully customizable (signs, column, line highlights, mapping)
   11. Can be toggled on/off
   12. Preserves signs from other plugins
   13. Easy to integrate diff stats into status line; built-in integration with vim-airline

### ctrlp

1. What is?
   1. A full path fuzzy file, buffer, mru, tag, ... finder for Vim
2. Feature
   1. Written in pure Vimscript for MacVim, gVim and Vim 7.0+
   2. Full support for Vim's regexp as search patterns.
   3. Built-in Most Recently Used (MRU) files monitoring
   4. Built-in project's root finder
   5. Open multiple files at once
   6. Create new files and directories
   7. Extensible

### ack

1. What is?
   1. Run you favorite search tool from Vim, with an enhanced results list
   2. It's designed as a frontend for the programmer's search tool ack.
2. Use
   1. :Ack [options] {pattern} [{directories}]
      1. It searches recursively in {directories} which defaults to the current directory for the {pattern}
      2. Files containing the search term will be listed in the quickfix window, along with the line number of the occurrence, once for each occurrence. <Enter> on a line will open the file and place the cursor on the matching line.

### nerdtree

1. What is?
   1. A file system explorer which allows users to visually browse complex directory hierarchies, quickly open files for reading or editing, and perform basic file system operations

### Miscellaneous

1. vim-polyglot
   1. A solid language pack for vim
