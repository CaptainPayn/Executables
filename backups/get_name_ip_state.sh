#!/bin/bash

# sort nodes
NODE_NAMES=$(openstack --os-cloud=openstack esi node list | grep -oE "MOC-[A-Z0-9]+-[A-Z]+[0-9]*[A-Z]*" | sort)

for i in $NODE_NAMES; do
	
	# echo name
	echo $i

	# grep out resource class
	openstack --os-cloud=openstack baremetal node show $i | grep "resource_class" | tr -s ' '
	
	# grep out the ip
	openstack --os-cloud=openstack baremetal node show $i | grep "driver_info" | grep -oE '([0-9]{1,3}\.){3}[0-9]{1,3}'

	# grep out provision state
	openstack --os-cloud=openstack baremetal node show $i | grep " provision_state" | tr -s ' '
	
	# grep out last error
	openstack --os-cloud=openstack baremetal node show $i | grep "last_error" | tr -s ' '
	
	# grep out target state
	openstack --os-cloud=openstack baremetal node show $i | grep "target_provision_state" | tr -s ' '
	
done
