#!/bin/bash
	tmshutdown -s forwarda;
	tmshutdown -s forwardb;
	buildserver -f forwarda.c -o forwarda -s FORWARD_A;
	buildserver -f forwardb.c -o forwardb -s FORWARD_B;
	make install;
	tmboot -s forwarda;
	tmboot -s forwardb;

