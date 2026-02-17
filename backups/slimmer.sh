#!/bin/bash
#author: philip yurovskiyh

#MUST BE RAN WITH SUDO|AS ROOT
#Check if running as root; exit if not
if [[ $EUID -ne 0 ]]; then
   echo "This script must be run as root" 
   exit 1
fi

#loop control variable
COUNT=0

#setting up table
printf "+--------------------------------------------------------------------------+\n"
printf "| %-13s | %-10s | %-3s | %-3s | %-3s | %-25s |\n" "LAST" "FIRST" "JOB" "OLD" "NEW" "MESSAGE"
printf "+--------------------------------------------------------------------------+\n"
   
#starting the while loop to read file
while read DATA; do
	#creating initial variables
	USER_ID=$(echo $DATA | cut -d'|' -f1)
	LAST_NAME=$(echo $DATA | cut -d'|' -f2)
	FIRST_NAME=$(echo $DATA | cut -d'|' -f3)
	JOB=$(echo $DATA | cut -d'|' -f4)
	OLD_NICE=$(echo $DATA | cut -d'|' -f5)
	PREFERRED_PASSWORD=$(echo $DATA | cut -d'|' -f6)
	FULL_NAME="${FIRST_NAME} ${LAST_NAME}"

	#if/elif/else statments
	if [[ ${JOB} == "P" ]] ; then
		NEW_NICE=3
	elif [[ ${JOB} == "S" ]]; then
		NEW_NICE=6
	else
		NEW_NICE=7
	fi

	#if not test to see if file exists and is a directory
	if [[ ! -d "/home/${USER_ID}" ]]; then
		ENCRYPTED_PASSWORD=$(echo "${PREFERRED_PASSWORD}" | openssl passwd -1 -stdin)
		useradd -m -c "${FULL_NAME}" -p "${ENCRYPTED_PASSWORD}" "${USER_ID}" > /dev/null
		MESSAGE="${USER_ID} created"
	else
		MESSAGE="${USER_ID} already set up"
	fi
	
	#making backup directory and supressing errors
	mkdir /home/${USER_ID}/${LAST_NAME}_backup 2> /dev/null
	chown "${USER_ID}" /home/"${USER_ID}"/"${LAST_NAME}_backup" 2> /dev/null


	#outputting data in a table w/ formatting
	printf "| %-13s | %-10s | %-3s | %-3s | %-3s | %-25s |\n" "${LAST_NAME}" "${FIRST_NAME}" "${JOB}" "${OLD_NICE}" "${NEW_NICE}" "${MESSAGE}"

	#counter adding each time it code loops
     	let COUNT=$COUNT+1

	#directing the actual file
    	done <  test3_data.txt

printf "+--------------------------------------------------------------------------+\n"
