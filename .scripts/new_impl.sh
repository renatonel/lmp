#!/bin/bash

# Script to create new C implementation file.
# Usage:
#   new_impl.sh impl_name location
#
# example:
#   new_impl.sh math src
#
# Note that the header name does not contain a file extension (.c)
#
# Author:
#   CWRN 2023

NAME=$1
LOCATION=$2

if [ -z $LOCATION ]; then
    LOCATION='.';
fi

IMPL_CONTENT=$(cat << END
/** ${NAME}.c
 *  Implementation for ${NAME}.h
 **/

#include <${NAME}.h>

int ${NAME}() {
    return 0;
}

END
)

mkdir -p "$LOCATION"
echo "${IMPL_CONTENT}" > ${LOCATION}/${NAME}.c

