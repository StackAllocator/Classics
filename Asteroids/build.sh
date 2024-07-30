#!/bin/sh

set -xe

g++ ./src/main.c \
	./src/player.c \
	./src/screen.c \
	-o main -lm -lraylib
