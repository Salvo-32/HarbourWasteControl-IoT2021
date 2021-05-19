#!/bin/bash

if [[ $# -lt 1 ]]
then
	echo "$0 INPUTFILE"
	exit 1
fi

INPUTFILE=$1

DEVICE_ID=1
while IFS=, read -r altitude latitude
do
	./gen_firmware.sh $altitude $latitude $DEVICE_ID
	let "DEVICE_ID += 1"
done < $INPUTFILE
