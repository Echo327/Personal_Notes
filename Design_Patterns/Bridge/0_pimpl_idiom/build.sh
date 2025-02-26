#!/bin/bash

BUILD_DIR="build"

# Check for "clean" argument
if [ "$1" == "clean" ]; then
    echo "Cleaning build directory..."
    rm -rf $BUILD_DIR
    echo "Clean complete!"
    exit 0
fi

# Create and navigate to the build directory
mkdir -p $BUILD_DIR
cd $BUILD_DIR

# Run CMake to generate build files
cmake ..

# Compile the project
cmake --build .

# Run the executable if build succeeds
if [ $? -eq 0 ]; then
    echo "Build successful! Running the program..."
    ./MyProject  # Change to MyProject.exe for Windows if needed
else
    echo "Build failed!"
fi
