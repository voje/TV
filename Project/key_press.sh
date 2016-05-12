#!bin/bash
if [[ $2 == "down" ]]; then
    xdotool keydown $1
elif [[ $2 == "up" ]]; then
    xdotool keyup $1
fi
