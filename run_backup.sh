#!/bin/bash

set -e
BACKUP_DIR=/mnt/storage/backups
FILE_COUNT=$(ls -l | wc -l)

tar -vczf "$BACKUP_DIR/home.$(date -I).tar.gz" --exclude='.mozilla' --exclude='.cache' --exclude='.vscode' /home/"$USER"

if [[ $FILE_COUNT -gt 4 ]]; then
	find "$BACKUP_DIR" -name "home.*.tar.gz" -mtime +7 -delete
fi
