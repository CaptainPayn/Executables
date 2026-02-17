#!/bin/bash

NODE_NAMES=$(openstack --os-cloud=openstack esi node list | grep -oE "MOC-[A-Z0-9]+-[A-Z]+[0-9]*[A-Z]*" | sort)

for i in $NODE_NAMES; do
	openstack --os-cloud=openstack baremetal node show $i | grep "provision_state"
done
