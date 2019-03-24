# Labyrinth-GSoC-2019
This program solve the Labyrinth problem proposed by JdeRobot for GSoC 2019.It finds the largest pathway moving only between holes. The descriptions of the problem can be found at:
https://jderobot.org/store/jmplaza/uploads/gsoc/gsoc2019-c++_test.pdf

## How to use
```
git clone ...
cd ...
mkdir build
cd build
cmake ..
make
./Labyrinth_GSoC2019 <the path to the input labyrinth>
```
The program will output the result as a txt file named 'Result.txt'.

## Example:
Input:
```
##.##.#
#..##.#
#.#####
#..####
##..###
###.###
```

Output:
```
10
##0##.#
#21##.#
#3#####
#45####
##67###
###8###
###9###
```

## Author
Shunkai Li, a master student of Peking University, China.
