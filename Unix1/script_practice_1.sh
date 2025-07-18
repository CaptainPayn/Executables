#!/bin/bash

#print out to screen asking for input
echo -n "Enter file name. To end type q: "
read NAME
#loop keeps asking while a q is not entered
while test "$NAME" != "q" ; do

	#creates file using NAME variable
	touch $NAME
	#asks for input again
	echo -n "Enter file name. To end type q: " ; read NAME

done
