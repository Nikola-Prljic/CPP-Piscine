#!/bin/sh
make
./RPN "5 1 -" > out
./RPN "1 2 -" >> out
./RPN "2 1 -" >> out
./RPN "1 2 * 2 / 2 * 2 4 - +" >> out
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" >> out
./RPN "" 2>> out
./RPN "a" 2>> out
./RPN "7 2 *c" 2>> out
./RPN "7 2 *c" 2>> out
./RPN "7 2 * c" 2>> out
./RPN "7c2 *" 2>> out
./RPN "7c2" 2>> out
./RPN "      " 2>> out
./RPN "  2 *" 2>> out
./RPN "******" 2>> out
./RPN "2 2 #" 2>> out
./RPN "2 2.*" 2>> out
./RPN "2 2 * * *" 2>> out
./RPN "2 2 2 * *" >> out
./RPN "2 2 2 2 2 2 + + + + +ä" 2>> out
echo "->out:"
cat out
echo "->expected:"
cat in
echo ----
diff out in
if [ $? -eq 0 ]
    then echo ok
else
    echo ko
rm out
fi