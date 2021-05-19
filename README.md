# Make-24

Using brutal force to make 24 in C.

## Basic information

* Maintainer: Libao Jin & Lingxiao Jia
* Email: [jinlibao@outlook.com](mailto:jinlibao@outlook.com?subject=[GitHub]%20Make-24)
* Create date: 06/28/2017
* Update date: 05/19/2021
* Current version: [v3.1](https://github.com/jinlibao/Make-24/tree/v3.1)

## Demo

We've provided a Makefile to make the compiling process much easier. Go to `src`, then run

```bash
cd src
make run
```

or

```bash
cd src && mkdir build && cd build
cmake ..
make
./game24   < ../../data/game24.in > ../../data/game24.res
./game24_2 < ../../data/game24.in > ../../data/game24_2.res

# interface 1: read numbers from command line
./make_24 1 number_1 number_2 number_3 number_4

# interface 2: read numbers from keyboard (default)
./make_24
./make_24 2
# enter "0 0 0 0" to exit

# interface 3: read data from/write data into files
./make_24 3 < ../../data/game24.in > ../../data/game24_3.res
```
