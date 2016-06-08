#!bin/bash

#modify key bindings in this script

case "$1" in
	"RUN_ON")
		echo "start running"
		;;
	"RUN_OFF")
		echo "stop running"
		;;
	*)
		echo "error: Undefined command."
		;;
esac