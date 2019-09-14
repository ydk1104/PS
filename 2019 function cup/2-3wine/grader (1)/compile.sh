#!/bin/bash

problem=wine

g++-7 -Wall -lm -static -DEVAL -o "${problem}" -O2 "grader.cpp" "bartender.cpp" "taster.cpp"
