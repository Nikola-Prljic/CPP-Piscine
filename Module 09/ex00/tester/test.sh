#!/bin/sh
num=0
cd ..
make
mv btc tester
make clean
cd tester
> out
ft_test()
{
    ./btc "$1" $2 $3 >> out 2>&1
    valgrind ./btc $1 > valgrind_test.txt 2>&1
    grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
    val_error=$?
    grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
    val_blocks=$?
    num=$(($num + $val_error + $val_blocks))
}

ft_test input.txt

if [ $num -eq 0 ]
    then echo valgrind: ok
else
    echo valgrind: ko
fi

diff out expOut.txt

if [ $? -eq 0 ]
    then echo "tests:    ok"
    rm out valgrind_test.txt
    rm btc
else
    echo ko
fi