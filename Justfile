

default:
    @just --list 

watch:
    find . -name '*.c' -o -name '*.h' | entr -c cmake --build build

