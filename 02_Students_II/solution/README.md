# How to build my proj

## Use CMake

```shell
cd {solutionPATH}
mkdir build
cd build
cmake ..
make
```

## Use Compiler(Clang or g++)

```shell
cd {solutionPATH}
g++ main.cpp -o Assignment2
```

# How to use my program

```shell
./Assignment2 {{DataFilePATH}}
```

For example:
(Use cmake so `Assignment` is in `{solutionPATH}/build`)
```shell
./Assignment2 ../Data.txt
```