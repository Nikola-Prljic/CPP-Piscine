#!/bin/sh
num=0

make
./RPN "5 1 -" > out 2>&1
valgrind ./RPN "5 1 -" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "1 2 -" >> out 2>&1
valgrind ./RPN "1 2 -" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "2 1 -" >> out 2>&1
valgrind ./RPN "2 1 -" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "1 2 * 2 / 2 * 2 4 - +" >> out 2>&1
valgrind ./RPN "1 2 * 2 / 2 * 2 4 - +" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" >> out 2>&1
valgrind ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "" >> out 2>&1
valgrind ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "a" >> out 2>&1
valgrind ./RPN "" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "7 2 *c" >> out 2>&1
valgrind ./RPN "7 2 *c" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "*7 2 *c" >> out 2>&1
valgrind ./RPN "*7 2 *c" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "7 2 * c" >> out 2>&1
valgrind ./RPN "7 2 * c" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "7c2 *" >> out 2>&1
valgrind ./RPN "7c2 *" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "7c2" >> out 2>&1
valgrind ./RPN "7c2" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "      " >> out 2>&1
valgrind ./RPN "      " > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "  2 *" >> out 2>&1
valgrind ./RPN "  2 *" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "******" >> out 2>&1
valgrind ./RPN "******" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "2 2 #" >> out 2>&1
valgrind ./RPN "2 2 #" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "2 2.*" >> out 2>&1
valgrind ./RPN "2 2.*" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "2 2 * * *" >> out 2>&1
valgrind ./RPN "2 2 * * *" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "2 2 2 * *" >> out 2>&1
valgrind ./RPN "2 2 2 * *" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "2 2 2 2 2 2 + + + + +ä" >> out 2>&1
valgrind ./RPN "2 2 2 2 2 2 + + + + +ä" > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN >> out 2>&1
valgrind ./RPN > valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

./RPN "1 2 *" a >> out 2>&1
valgrind ./RPN "1 2 *" a> valgrind_test.txt 2>&1
grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
val_error=$?
grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
val_blocks=$?
num=$(($num + $val_error + $val_blocks))

if [ $num -eq 0 ]
    then echo valgrind: ok
else
    echo valgrind: ko
fi

#echo "->out:"
#cat out
#echo "->expected:"
#cat in
#echo ----

diff out in

if [ $? -eq 0 ]
    then echo "tests:    ok"
    rm out valgrind_test.txt
else
    echo ko
fi