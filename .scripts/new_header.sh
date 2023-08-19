#!/bin/bash

# Script to create new C header file.
# Usage:
#   new_header.sh header_name location
#
# example:
#   new_header.sh math src/headers
#
# Note that the header name does not contain a file extension (.h)
#
# Author:
#   CWRN 2023

NAME=$1
LOCATION=$2

if [ -z $LOCATION ]; then
    LOCATION='.';
fi

HEADER_CONTENT=$(cat << END
/** ${NAME}.h
 * 
 **/

#ifndef __${NAME^^}_H__
#define __${NAME^^}_H__

int ${NAME}();

#endif // __${NAME^^}_H__
END
)

mkdir -p "$LOCATION"
echo "${HEADER_CONTENT}" > ${LOCATION}/${NAME}.h

