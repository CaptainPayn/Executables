#!/bin/bash

NODE_NAMES=$(openstack --os-cloud=openstack esi node list | grep "inspect failed" | grep -oE "MOC-[A-Z0-9]+-[A-Z]+[0-9]*[A-Z]*")
read -p "Enter output filename: " FILENAME

for i in $NODE_NAMES; do
	echo $i >> $FILENAME
	openstack --os-cloud=openstack baremetal node show $i | grep -E "last_error" >> $FILENAME

done
