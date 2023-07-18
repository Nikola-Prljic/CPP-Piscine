#!/bin/sh
make
./RPN "5 1 -" > out
./RPN "1 2 -" >> out
./RPN "2 1 -" >> out
./RPN "5 1 - 3 +" >> out
./RPN "5 1 *" >> out
./RPN "5 2 - 3 + 4 - 3 *" >> out
echo "->out:"
cat out
echo "->in:"
cat in
echo ----
diff out in
echo $?
rm out