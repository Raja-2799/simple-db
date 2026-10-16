#!/bin/bash

set -e

build() {
    echo "=============================="
    echo "Building SimpleDB"
    echo "=============================="

    cmake -S . -B build
    cmake --build build -j
}

test() {
    echo "=============================="
    echo "Running tests"
    echo "=============================="

    ctest --test-dir build --output-on-failure
}

server() {
    echo "=============================="
    echo "Starting SimpleDB server"
    echo "=============================="

    ./build/simpledb
}

case "$1" in
    build)
        build
        ;;

    test)
        test
        ;;

    server)
        server
        ;;

    "")
        build
        test
        server
        ;;

    *)
        echo "Unknown command: $1"
        echo ""
        echo "Usage:"
        echo "  ./run.sh build"
        echo "  ./run.sh test"
        echo "  ./run.sh server"
        echo "  ./run.sh"
        exit 1
        ;;
esac