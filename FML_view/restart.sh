#!/bin/bash
#. ../tux.env
	buildserver -o $1 -f $1.c -s FVs;
	tmshutdown -s $1;
	make install;
	tmboot -s $1;


