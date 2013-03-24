#!/bin/sh -x

case `uname -s` in
    Darwin)
        DYLD_FORCE_FLAT_NAMESPACE=yes
        DYLD_INSERT_LIBRARIES=write-wrapper.so
        export DYLD_FORCE_FLAT_NAMESPACE
        export DYLD_INSERT_LIBRARIES
        ;;
    Linux)
        LD_PRELOAD=write-wrapper.so
        export LD_PRELOAD
        ;;
    *)
        echo "Unsupported/unknown OS"
        exit 1
esac
./test foo bar