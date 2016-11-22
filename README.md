# CXX-Template

<p>Copyright &copy; 2014, 2015, 2016 <a href="http://lesterhedges.net">Lester Hedges</a>
<a href="http://www.gnu.org/licenses/gpl-3.0.html">
<img width="80" src="http://www.gnu.org/graphics/gplv3-127x51.png"></a></p>

[![Build Status](https://travis-ci.org/lohedges/cxx-template.svg?branch=master)](https://travis-ci.org/lohedges/cxx-template)

## About
This repository provides a set of simple templates and helper files for
managing a small C++ project. A comprehensive `Makefile` is used to build a
static library along with its demos, unit tests, and documentation. This may
be of use for anyone looking to build and deploy a codebase on a remote server
or high-performance computing cluster, those wanting to free themselves from
the shackles of an integrated development environment, or perhaps simply wishing
to better understand how to use [GNU Make](http://www.gnu.org/software/make/).

This project was largely inspired by Zed Shaw's [Learn C The Hard Way](http://c.learncodethehardway.org/book/).

## Usage
The `src` directory contains header files and source code for the (illustrative,
but essentially useless) Shapes library which can be compiled using the included
`Makefile`. To get detailed information regarding usage of the `Makefile` and the
available targets simply run make on the command-line with no arguments, i.e.

```bash
make
```
If you would prefer to use [CMake](http://www.cmake.org/), e.g. if you aren't
using make as your generator, or are compiling on Windows, simply copy the
contents of the cmake directory into the root of the project folder then run
cmake, i.e. (assuming that you are currently in the root directory)

```bash
cp -r cmake/* .
cmake .
```

Be warned that if you use make as your cmake generator then the original
Makefile will be overwritten. To recover it simply run `git co Makefile`

## Targets
* help&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-->  print help message
* build&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-->  build library, demos, and tests (default=release)
* devel&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-->  build using development compiler flags (debug)
* release&nbsp;&nbsp;&nbsp;&nbsp;-->  build using release compiler flags (optimized)
* doc&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-->  generate source code documentation with doxygen
* test&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-->  run unit tests
* valgrind&nbsp;&nbsp;&nbsp;-->  run unit tests via valgrind
* clean&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-->  remove object and dependency files
* clobber&nbsp;&nbsp;&nbsp;&nbsp;-->  remove all files generated by make
* install&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;-->  install library, demos, and documentation
* uninstall&nbsp;&nbsp;&nbsp;-->  uninstall library, demos, and documentation

## Features

### Auto-dependencies
Source and object file auto-dependencies are handled using a recipe taken from
[here](http://scottmcpeak.com/autodepend/autodepend.html).

### Unit testing
Taking inspiration from [Learn C The Hard Way](http://c.learncodethehardway.org/book/),
automated testing is handled by a modified version of the MinUnit framework.
See `MinUnit.h` in the `src` directory for details. Also included are Zed's
excellent [debugging macros](http://c.learncodethehardway.org/book/ex20.html).
See `Debug.h` for details.

Unit tests can be compiled and run directly by typing `make test` on the
command-line. To run the test code via [Valgrind](http://valgrind.org/)
simply use `make valgrind` instead.

### Documentation
Comprehensive source code documentation is handled via
[Doxygen](http://www.stack.nl/~dimitri/doxygen/).
To compile the documentation, simply run `make doc`.

### Version control
In a rapidly evolving codebase it is helpful that the library knows the version of
the source code from which it was compiled. This allows any bugs to be traced to
a specific version of the code. As such, an abbreviated version of the git commit
hash is passed as a command-line `#define` directive. When using the library the
user can access version information through the `COMMIT` and `BRANCH` constants.
The included demo codes show examples of how to print version control information.

### Clean ouput
By default make's rather verbose output is entirely suppressed using the
`.SILENT` target. (Simply comment out this line if you are trying to debug
a problem.) Instead, simple cmake-like information is provided using custom
`echo` commands with colorized output achieved via `tput`.

## Dependencies
Make sure that any external libraries are are accessible to your shell
environment. The LIBS variable should be used for any linker flags, e.g.
-lfftw3. Use the LDFLAGS environment variable for any non-standard paths.
This can be set in your shell profile, on the command-line, or passed directly
to make as an option. For example, if using MacPorts on OS X

```bash
export LDFLAGS='-L/opt/local/lib'
```

## Tips
* To set a different installation path run
```bash
make PREFIX=path install
```
* Additional CXXFLAGS can be passed using OPTFLAGS, e.g.
```bash
make OPTFLAGS=-Wall devel
```
* Targets can be chained together, e.g.
```bash
make release doc test
```

## Helper scripts
Two helper scripts are provided in order to help expedite the process of
creating a new C++ project.

### `setup`
This script converts all of the necessary files in the repository ready
for the new library. To set things up for a project called `new`, run

```bash
./setup new
```

This assumes that the clone git repository is left untouched, i.e. all files
refer to the default `shapes` project.

Alternatively, you can convert files from an `old` project to a `new` one as
follows

```bash
./setup new old
```

### `class_template`
Create a new C++ class template, i.e. default header and source files with
constructor and destructor stubs. To create a new class, run

```bash
./class_template ClassName
```

This will generate the files `ClassName.h` and `ClassName.cpp` in the current
working directory. Alternatively, running

```bash
./class_template ClassName path
```

will move the files to the directory specified by `path`.

Note that the template files use tabs. If you prefer to use spaces (as I do)
then you can fix this afterwards in your editor, e.g. in Vim you can run

```bash
:retab
```

## Windows users
Although intended to be used on a [Unix-like](https://en.wikipedia.org/wiki/Unix-like)
operating system, the simple build system works fine on Windows using
[MinGW](http://mingw.org). For modern, 64-bit Windows systems, we recommend using
[MYSYS2](http://msys2.github.io). This has been used to successfully build on
Windows 7 and 10. After installing MYSYS2 (following the instructions on the
[website](http://msys2.github.io)) you will need to install several additional
packages:

```bash
pacman -S gcc git diffutils make
```
