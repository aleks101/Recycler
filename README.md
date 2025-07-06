# **Build**

  In the Recycler folder, make a build64 or build32 folder, depending on which configuration you want:
  
    mkdir build64
    
  Move into the created folder

    cd build64
  
  To specify which generator you want to use, you must pass the generator name as the -G option. 
  Generators cmake supports: https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html#manual:cmake-generators(7)
  
  Run the cmake script to build the library
  
    cmake .. -G "Visual Studio 17 2022" -A x64 -D ARCHITECTURE=x64
# **Compile**

  To compile the code run the following code from the created build folder:
  
    cmake --build .
