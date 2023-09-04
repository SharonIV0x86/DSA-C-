.DEFAULT_GOAL := run

mainFile: main.cpp
    g++ main.cpp -o mainFile

run: mainFile
    ./mainFile

clean:
    rm -f mainFile