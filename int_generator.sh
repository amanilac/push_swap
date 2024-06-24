#!/bin/bash

integers=()

while [ ${#integers[@]} -lt 100 ]; do

	random_int=$((($RANDOM * 32768 + $RANDOM) % 4294967296 - 2147483648))

	if [[ ! " ${integers[@]} " =~ " $random_int " ]]; then
		integers+=($random_int)
	fi
done

ARG=${integers[@]}

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap $ARG
