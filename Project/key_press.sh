#!bin/bash

#modify key bindings in this script
# xdotool key / keydown / keyup
# wmctrl -R <window_name>

simulate=false
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
	*)
		echo "error: Undefined command."
		;;
esac