#!/bin/bash

#put parameter into variable
SOURCE_DIR="$1"

#error handling if no parameter is passed
if [[ -z "$SOURCE_DIR" ]]; then
    echo "You must enter directory as parameter</path/to/directory>"
    exit 1
fi

#error handling if the directory doesnt exist
if [[ ! -d "$SOURCE_DIR" ]]; then
    echo "Directory to backup doesnt exist"
    exit 1
fi

#take date and format to be used as name
DATE=$(date +"%Y-%m-%d")

#make name for backup directory using the DATE variable
BACKUP_DIR=$SOURCE_DIR/backup_"$DATE"

#make directory with backup name variable
mkdir -p "$BACKUP_DIR"

#using rsync to copy everything except for the backup directory
rsync -av --exclude="$(basename "$BACKUP_DIR")" "$SOURCE_DIR"/ "$BACKUP_DIR"/ && echo "Created backup of ${SOURCE_DIR} in the source directory"

#list existing backups sorted by timestamp
BACKUPS=($(ls -t "${SOURCE_DIR}/backup_"* 2>/dev/null))  
    #check if there are more than 3 backups
    if [ "${#BACKUPS[@]}" -gt 3 ]; then
        #get backups beyond the last 3
        BACKUPS_REMOVE="${BACKUPS[@]:3}"
        #remove the oldest backups
        rm -rf "${BACKUPS_REMOVE[@]}"
    fi
