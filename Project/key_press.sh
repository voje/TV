#!bin/bash

#modify key bindings in this script
# xdotool key / keydown / keyup
# wmctrl -R <window_name>

simulate=false  	#set true if you want the output to go to terminal (testing purposes)
target_window_name="warcraft"

if $simulate; then
	target_window_name="kristjan"	#going for terminal
fi
wmctrl -R "$target_window_name"

case "$1" in
	"RUN_ON")
		echo "start running"
		xdotool keydown w
		;;
	"RUN_OFF")
		echo "stop running"
		xdotool keyup w
		;;
	"TURN_LEFT_ON")
		echo "start turning left"
		xdotool keydown a
		;;
	"TURN_LEFT_OFF")
		echo "stop turning left"
		xdotool keyup a
		;;
	"TURN_RIGHT_ON")
		echo "start turning right"
		xdotool keydown d
		;;
	"TURN_RIGHT_OFF")
		echo "stop turning right"
		xdotool keyup d
		;;
	"HEAL")
		echo "heal"
		xdotool key 4
		;;
	"TAB")
		echo "tab"
		xdotool key Tab
		;;
	"SHOOT")
		echo "shoot"
		xdotool key 1
		;;
	"SHIELD")
		echo "shield"
		xdotool key c
		;;
	"LOOT")
		echo "loot"
		xdotool keydown Shift
		xdotool click 3
		sleep 0.5s
		xdotool keyup Shift 
		;;
	*)
		echo "error: Undefined command."
		;;
esac
