#!/bin/bash

problem=hiccup

g++-7 -Wall -lm -static -DEVAL -o "${problem}" -O2 "grader.cpp" "${problem}.cpp"
