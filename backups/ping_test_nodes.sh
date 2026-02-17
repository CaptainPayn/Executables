#!/bin/bash

NODE_NAMES=$(openstack --os-cloud=openstack esi node list | grep -oE "MOC-R4PAC[0-9]{2}U[0-9]{2}(-S[0-9]+[A-Z]?)?" | sort)

for i in $NODE_NAMES; do
	echo "=== $i ==="
	node_info=$(openstack --os-cloud=openstack baremetal node show "$i" -f json)
	ip_address=$(echo "$node_info" | jq -r '.driver_info.ipmi_address // .driver_info.redfish_address // "N/A"')
	echo -n "Trying to ping ($ip_address)"
	if ping -c 1 -W 2 "$ip_address" > /dev/null 2>&1; then
		echo "SUCCESS"
	else
		echo "FAILED"
fi
done
