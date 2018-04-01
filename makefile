#!/bin/bash

PROG = dct
all: $(PROG)

dct: src/dct.cpp src/version.h
	g++ -o bin/dct src/dct.cpp src/version.h -I.

prefix	:= /home/$(USER)/DCT

install:
	mkdir $(prefix)
	mkdir $(prefix)/docs
	cp bin/dct $(prefix)/dct
	cp docs/README $(prefix)/docs/README
	cp docs/LICENSE $(prefix)/docs/LICENSE

clean:
	rm bin/$(PROG)

remove:
	rm -Rf $(prefix)/docs
	rm -Rf $(prefix)/dct
	rm -Rf $(prefix)
	
test:
