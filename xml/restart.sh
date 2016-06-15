#!/bin/bash
#. ../tux.env
	buildserver -s XML -o $1 -f $1.cpp -f -ltxml
	tmshutdown -s $1;
	make install;
	tmboot -s $1;


