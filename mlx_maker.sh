#!/bin/bash
if ! [ -d MLX42 ]
then
    git clone https://github.com/codam-coding-college/MLX42.git
fi
cd MLX42
cmake -B build
cmake --build build -j4
cd ..