#!/bin/bash

NODE_NAMES=$(openstack --os-cloud=openstack esi node list | grep "inspect failed" | grep -oE "MOC-[A-Z0-9]+-[A-Z]+[0-9]*[A-Z]*")
for i in $NODE_NAMES; do
	echo $i >> ipmi_call_failed.txt
	openstack --os-cloud=openstack baremetal node show $i | grep -E "IMPI call failed" >> ipmi_call_failed.txt

done
