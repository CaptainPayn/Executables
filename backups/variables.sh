#!/bin/bash

NAME="Jack"
AGE=32
COURSE="UNIX-2"

echo "Hello, my name is $NAME \
and I am $AGE years old and \
I am taking $COURSE"

CURRENT_USER=$(whoami)
echo "Current user: $CURRENT_USER"

COUNT=10
echo $COUNT
COUNT=$((COUNT+5))
echo $COUNT

