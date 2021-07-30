#!/bin/bash
g++ -std=c++11 -o prog4 *.cpp

valgrind --leak-check=full ./prog4 < ./rapunzel.txt > valgrind-out.txt 2>&1
NOLEAKMSG="in use at exit: 0 bytes in 0 blocks"
grep "$NOLEAKMSG" valgrind-out.txt