#!/bin/bash

#MUST BE RAN WITH SUDO|AS ROOT
cat dellist.txt | while read user
do
        echo "Deleting: ${user}"
        userdel -r -f "${user}"
done
echo "ls /home"
ls /home
