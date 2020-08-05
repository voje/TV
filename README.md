# RGB webcam game controller
Requirement: docker daemon (tested on Ubuntu 18.04).   

## Build
Check `Makefile`.   
First, we build the docker container (you can use the commands in `Dockerfile` on your own OS if you want...).   
`make build-docker`

## Run program
After building the container, run it:
`make run-docker`
Inside the container:
```bash
cmake ../src
make
./detector
```

For the program to generate user input, you will need to install packages xdotool and wmctrl.
`$ sudo apt-get install xdotool wmctrl`

You can adjust the parameters in file `detector.conf`.
