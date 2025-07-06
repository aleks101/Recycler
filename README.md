HOW TO BUILD:
  -in the Recycler folder, make a build64 or build32 folder, depending on which configuration you want:
    mkdir build64 // mkdir build32
  -move into the created folder
  -run the cmake script to build the library:
    cmake .. -G "" -A x64 -D ARCHITECTURE=x64
  -to compile the code run:
    cmake --build .
