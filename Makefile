CC = g++
CFLAGS = -g -Wall -std=c++17
SOURCES = cpp/implementation/*.cpp

all: build

build:
	pip install -e gigaframe_util

clean:
	rm -rf build dist .DS_Store *.egg-info *.so *.pyc gigaframe_util/build gigaframe_util/dist gigaframe_util/__pycache__ gigaframe_util/*.{egg-info,pyc,so}
