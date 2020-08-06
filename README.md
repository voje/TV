# RGB webcam game controller
Main project in `./Project`.   
See `./Project/README.md` for details on the c++ app.   

This project was built with Opencv v3.1.0.   
We can quickly build and test with a higher version by using docker.   


## Build Docker
Check `Makefile`.   
First, we build the docker container (you can use the commands in `Dockerfile` on your own OS if you want...).   
```bash
make build-docker
```

## Run Docker
After building the container, open `xhost` on your host OS.   
**WARNING**: this is a quick development hack.   
Running the following command will make your system vulnerable.   
Run on trusted networks!
```bash
# Open xserver on host (HIGHLY DANGEROUS, ONLY DO THIS IN A TRUSTED HOME NETWORK).   
xhost +

# When finished, close it with:
xhost -
```

Run the docker container.
```bash
make run-docker
```

Inside the container:
```bash
# Test X forwarding.
xeyes

# Clear old build files.
rm -rf ./*

# Build new app.
cmake ../src
make
./detector
```
This version will only work if you specify input files in `detector.conf`. We can't capture webcam with this Docker setup.   

## Build and run on host
See commands in `Dockerfile`.

## Other dependencies
For the program to generate user input, you will need to install packages xdotool and wmctrl.
`$ sudo apt-get install xdotool wmctrl`

You can adjust the parameters in file `detector.conf`.
