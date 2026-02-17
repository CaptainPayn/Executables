#!/bin/bash

#MUST BE RAN WITH SUDO|AS ROOT
#Check if running as root; exit if not
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root" 
   exit 1
fi

cat dellist.txt | while read user
do
        echo "Deleting: ${user}"
        userdel -r -f "${user}"
done
echo "ls /home"
ls /home
