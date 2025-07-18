#!/bin/bash

#display name of script
echo "$0"

#checking if no parameter was passed
if [ "$#" -eq 0 ]
then
	echo "You must provide one parameter"

#checking if more than 1 parameter was passed
elif [ "$#" -gt 1 ]
then
	echo "You must provide only one parameter"

else
	#testing if directory exists using test and exit status
	test -d "$1"
	if [ "$?" -eq 0 ]
	then
		echo "Already exists"
	else
		#if you get here that means it passed all checks and
		#will have a directory made
		mkdir "$1" ; echo "$1 directory created."
	fi
fi

