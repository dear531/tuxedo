#!/bin/bash
#. ../tux.env
	buildserver -s ASYNC -o $1 -f $1.c
	tmshutdown -s $1;
	make install;
	tmboot -s $1;


