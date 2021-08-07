#!/bin/bash

if [[ $# -lt 1 ]]
then
        echo "$0 INPUTFILE"
        exit 1
fi

if [[ $SOURCE_DIR == '' ]]
then
        SOURCE_DIR='./'
fi

INPUTFILE=$1

DEVICE_ID=1
while IFS=, read -r node_id
do
	echo "flashing node $node_id with firmware device$DEVICE_ID.elf"
	iotlab-node --flash $SOURCE_DIR"output/device"$DEVICE_ID".elf" -l saclay,st-lrwan1,$node_id                    
	let "DEVICE_ID += 1"
done < $INPUTFILE

