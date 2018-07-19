# Compute-24

Using brutal force to compute 24 in C.

## Basic information

* Maintainer: Libao Jin & Lingxiao Jia
* Email: [jinlibao@outlook.com](mailto:jinlibao@outlook.com?subject=[GitHub]%20Compute-24)
* Create date: 06/28/2017
* Update date: 07/19/2018
* Current version: [v2.0](https://github.com/jinlibao/Compute-24/tree/v2.0)

## Demo

We've provided makefile to make the compiling process much easier.

1. Go to `src`, then run

    ```bash
    cd src
    make
    ```

    or

    ```bash
    cd src
    make compute_24
    ```

2. After running `make`, the executable binary file would be located under `exec`.
3. Run the executable file as follows:

    ```bash
    # interface 1: read numbers from command line
    ../exec/compute_24 1 number_1 number_2 number_3 number_4

    # interface 2: read numbers from keyboard (default)
    ../exec/compute_24
    ../exec/compute_24 2

    # interface 3: read data from/write data into files
    ../exec/compute_24 3 < ../data/input.txt > ../data/output.txt

    ```
4. To exit the program when using interface 1: enter four consecutive 0's.

    ```
    ../exec/compute_24
    1 2 3 4
    1 2 3 4: ((1 * 2) * 3) * 4
    0 0 0 0
    0 0 0 0: Impossible to make up 24.
    ```
