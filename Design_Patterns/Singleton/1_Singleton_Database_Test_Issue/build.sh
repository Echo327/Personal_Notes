#!/usr/bin/bash

# Flags
CLEAN=false
BUILD=false
TEST=false

# Display help message
show_help() {
    echo "Usage: $0 [options]"
    echo
    echo "Options:"
    echo "  clean   - Deletes build folder"
    echo "  build   - cmake build into the build folder"
    echo "  test    - Run all tests"
    echo "  all     - Performs clean, build, and test in that order"
    echo "  --help  - Display this help message"
}

# Check if no options were provided
if [ $# -eq 0 ]; then
    echo "Need to provide at least 1 option"
    echo "Possible options are: clean, build, test, all, or --help"
    echo "all = clean build test"
    exit 1
fi

# Check for 'clean', 'build', 'test', or 'all' options
for opt in "$@"; do
    case "$opt" in
        clean)
            CLEAN=true
            ;;
        build)
            BUILD=true
            ;;
        test)
            TEST=true
            ;;
        all)
            CLEAN=true
            BUILD=true
            TEST=true
            ;;
        --help)
            show_help
            exit 0
            ;;
        *)
            echo "Unknown option: $opt"
            ;;
    esac
done

if [ "$CLEAN" == true ]; then
    # Check and delete if the 'build' directory exists
    if [ -d "build" ]; then
        echo "Directory 'build' exists. Deleting it..."
        rm -rf ./build
    else
        echo "Directory 'build' does not exist."
    fi
fi

if [ "$BUILD" == true ]; then
    # Create a build directory and move into it
    if [ -d "build" ]; then
        echo "Build folder already exists"
        exit 1
    else
        echo "Creating build directory"
        mkdir build
        cd build
    fi

    # Run cmake to configure the project
    echo "Configuring project"
    cmake ..

    # Build the project
    echo "Building project"
    if [[ "$(uname)" == "Linux" || "$(uname)" == *MINGW* ]]; then
        make
    else
        cmake --build .
    fi
fi

if [ "$TEST" == true ]; then
    # Ensure we're in the 'build' directory before running tests
    if [ -d "build" ]; then
      cd build
    fi
    # Run the tests
    echo "Running Tests"
    ctest
fi