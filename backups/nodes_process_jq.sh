#!/bin/bash

#NODE_NAMES=$(openstack --os-cloud=openstack esi node list | grep -oE "MOC-[A-Z0-9]+-[A-Z]+[0-9]*[A-Z]*" | sort)
NODE_NAMES=$(openstack --os-cloud=openstack esi node list | grep -oE "MOC-R4PAC[0-9]{2}U[0-9]{2}(-S[0-9]+[A-Z]?)?" | sort)

for i in $NODE_NAMES; do
    echo "=== $i ==="
    
    node_info=$(openstack --os-cloud=openstack baremetal node show "$i" -f json)
    
    echo "$node_info" | jq -r '
        "Resource Class: \(.resource_class // "N/A")",
        "IP Address: \(.driver_info.ipmi_address // .driver_info.redfish_address // "N/A")",
        "Provision State: \(.provision_state // "N/A")",
        "Last Error: \(.last_error // "None")",
        "Target State: \(.target_provision_state // "N/A")"
    '
    echo ""
done
