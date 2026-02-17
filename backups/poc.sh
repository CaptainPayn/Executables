#!/bin/bash

alias openstack-baremetal="openstack --os-cloud=openstack baremetal node"
read -p "Enter node name: " NODE_NAME
read -p "Enter command to run: " COMMAND
case "$COMMAND" in
	"manage") openstack-baremetal node manage "$NODE_NAME";;
	"show") openstack-baremetal node show "$NODE_NAME";;
	"inspect") openstack-baremetal node inspect "$NODE_NAME";;
	*) echo "Invalid option --usage <manage|show|inspect> <NODE-LABEL>"
esac
