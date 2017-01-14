#!/bin/bash
tail -n +2 param.h > temp2
echo '#define SCHFLAG      "'$1'"'| cat - temp2 >temp3 && mv temp3 param.h
rm temp2
make
