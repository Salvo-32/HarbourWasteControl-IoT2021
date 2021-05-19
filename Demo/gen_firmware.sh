#!/bin/bash

BOARD=b-l072z-lrwan1

if [[ $# -lt 3 ]]
then
	echo "$0 LATITUDE ALTITUDE DEVICE_ID"
	exit 1
fi	

export LATITUDE=$1
export ALTITUDE=$2
export DEVICE_ID=$3


if [[ $RIOTBASE == '' ]]
then
	echo "must export variable RIOTBASE: 'export RIOTBASE=/path/to/riot'"
	exit 1
fi

if [[ $SOURCE_DIR == '' ]]
then
	SOURCE_DIR='.'
fi

if [[ $OUTPUT_DIR == '' ]]
then
	mkdir output
	OUTPUT_DIR='./output'
fi

make -C $SOURCE_DIE clean all
make -C $SOURCE_DIR all
cp $SOURCE_DIR"/bin/"$BOARD"/demo.elf" $OUTPUT_DIR/"device"$DEVICE_ID.elf

