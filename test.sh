echo "Running tests..."
echo

#chmod +x gendeck.o

#output=$(./main.o 15 36 18 44 222 0 -1 -33 44 120 31 -12 -2)
#output=$(echo $input | ./main.o)
#"input" entre aspas toma uma única string. Sem aspas considera varias strings separadas por espaço"
input1=$1
input2=$2
input3=$3
input4=$4

# 2o atributo do gendeck "p" imprime as cartas.
# "d" imprime os dados ou a posição das cartas no monte

#expected_output=$(./gendeck.o "$input2" "p")
expected_output=$(cat "$input4")
#input3=$(./gendeck.o "$input2" "d")
input_string=$(cat "$input3")

output=$(./main.o "$input1" "$input2" "$input_string")

#echo deckprint2.txt
#hexdump -C deckprint2.txt
echo
echo
echo
#echo ./main.o "$input1" "$input2" "$input3"
#./main.o "$input1" "$input2" "$input3" | hexdump -C

if [ $? -eq 0 ] ; then
  echo "Pass: Program exited zero"
else
  echo "Fail: Program did not exit zero"
  exit 1
fi

if [ "$output" == "$expected_output" ] ; then
  echo "Pass: Output is correct"
else
  echo "Expected '$expected_output' but got: '$output'"
  exit 1
fi

echo
echo "All tests passed."

exit 0
