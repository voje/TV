## Build
```
mkdir build
rm ./build/* -rf
cd ./build
cmake ../src
make
```

## Run
```
cd ./build

# Edit parameters in ../detector.conf
./detector
```

## detector.conf parameters
Capturing from webcam:
```
input_file 0
```

Using a file (debugging):
```
input_file 
```
