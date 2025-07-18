#!/bin/bash

DATE=$(date +"%Y-%m-%d")

cat << "EOF"
   _____   ____ ______________________    ________________    _____________  __.  _________
  /  _  \ |    |   \__    ___/\_____  \   \__    ___/  _  \  /   _____/    |/ _| /   _____/
 /  /_\  \|    |   / |    |    /   |   \    |    | /  /_\  \ \_____  \|      <   \_____  \ 
/    |    \    |  /  |    |   /    |    \   |    |/    |    \/        \    |  \  /        \
\____|__  /______/   |____|   \_______  /   |____|\____|__  /_______  /____|__ \/_______  /
        \/                            \/                  \/        \/        \/        \/ 
EOF

read -p "Would you like to add a task?(Y or N) " CHOICE


if [[ "$CHOICE" = "Y" ]]; then
    read -p "Enter your task: " TASK
    echo $TASK >> ${DATE}_tasks.txt && echo "Task added"
elif [[ "$CHOICE" = "N" ]]; then
    echo "Goodbye"
    exit 0
else
    echo "Wrong choice"
fi
