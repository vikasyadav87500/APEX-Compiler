#!/bin/bash

YELLOW='\033[1;33m'
GREEN='\e[1;32m'
NOCOLOR='\033[0m'

function run() {
	flex lexer.l && bison -dy parser.y && gcc y.tab.c lex.yy.c -w
	local total_testcases="$1"
	echo "Running: $total_testcases"
	local start=1
	while [ $start -le $total_testcases ]
	do
		printf "\n\n"
		for i in {1..35}
		do
			echo -ne "="
		done
		echo -ne "  ${YELLOW}Running TestCase $start${NOCOLOR}  "
		for i in {1..35}
		do
			echo -ne "="
		done
		printf "\n\n                                      ${GREEN}3 ADDRESS CODE ${NOCOLOR} \n\n"
		local filename="tests/test"$start".apex"
		./a.exe $filename
		((start++))
	done
}

number_of_files=`ls -l ./tests/ | egrep -c '^-'`
run $number_of_files