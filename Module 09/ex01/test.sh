#!/bin/sh
num=0
make

ft_test()
{
    ./RPN "$1" $2 $3 >> out 2>&1
    valgrind ./RPN $1 > valgrind_test.txt 2>&1
    grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
    val_error=$?
    grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
    val_blocks=$?
    num=$(($num + $val_error + $val_blocks))
}

ft_test "5 1 -"
ft_test "1 2 -"
ft_test "2 1 -"
ft_test "1 2 * 2 / 2 * 2 4 - +"
ft_test "8 9 * 9 - 9 - 9 - 4 - 1 +"
ft_test ""
ft_test "a"
ft_test "7 2 *c"
ft_test "*7 2 *c"
ft_test "7 2 * c"
ft_test "7c2 *"
ft_test "7c2"
ft_test "      "
ft_test "  2 *"
ft_test "******"
ft_test "2 2 #"
ft_test "2 2.*"
ft_test "2 2 * * *"
ft_test "2 2 2 * *"
ft_test "2 2 2 2 2 2 + + + + +ä"
ft_test 3 2 *
ft_test a s
ft_test "9 9 * 2 2 2 * * *"
ft_test "9 9 * 2 2 2 * **"
ft_test "2 2 1 2 3 + + * /"
ft_test "1 2 3 + -"
ft_test "1 2 3 - -"
ft_test "5 2 3 1 2 4 9 8 * - + - * + -"
ft_test "1 9 -"
ft_test "9 3 3 + - 3 /"
ft_test "5 3 5 * + 2 / 2 3 4 + - * 2 * 3 * 2 1 3 4 * + - *"
ft_test "5 3 5 * + 2 / 2 3 4 + - *"
ft_test "5 3 5 * + 2 /"
ft_test ""
ft_test ""
ft_test ""

if [ $num -eq 0 ]
    then echo valgrind: ok
else
    echo valgrind: ko
fi

diff out in

if [ $? -eq 0 ]
    then echo "tests:    ok"
    rm out valgrind_test.txt
else
    echo ko
fi