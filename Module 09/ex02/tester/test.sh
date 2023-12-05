#!/bin/bash
num=0
testcount=1
test_ammount=5000
int_is_sorted=8000
cd ..
make
mv PmergeMe tester
make clean
cd tester
> out
echo "-----------------"
ft_test()
{
    ./PmergeMe $1 > out 2>&1
    #valgrind ./PmergeMe $1 > valgrind_test.txt 2>&1
    #grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
    #val_error=$?
    #grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
    #val_blocks=$?
    #num=$(($num + $val_error + $val_blocks))

    grep -q "vector is sorted" out
    int_is_sorted=$?
    grep -q "deque is sorted" out
    int_is_sorted=$(($int_is_sorted + $?))
    if [ $int_is_sorted -ne 0 ]
        then echo "| Test $testcount : ko   |"
        cat out > "$testcount"_failed.txt
    else
        echo "| Test $testcount : ok   |"
    fi
    testcount=$((1+testcount))
}

#ft_test "53 2"
#ft_test "53 86 54 89 15 33 39 4 71 3"
#ft_test "42 1 3 2 43 331 -1"
#ft_test "222 60 240 411 121 73 277 11 92 438 264 440 69 297 284 374 174 31 481 17 155 407 217 441 34 415 393 247 83 28 294 88 117 148 76 285 237 214 183 205 176 273 307 468 330 194 209 304 232 223 71 424 242 388 462 143 168 486 36 418 473 170 270 91 444 320 198 359 162 252 175 108 497 124 341 309 487 189 436 338 296 145 245 340 414 286 490 112 256 218"
#ft_test "42 1 3"
#ft_test "1 2"
#ft_test "42 1 22 1223 231 -2 31 222 "
#ft_test "213 123 1321314 12412 12321 22 25 2 1 44 21 39 23 34 12 128 3123"
#ft_test "1 2 4 3 -1"


#diff out in

#if [ $? -eq 0 ]
#then echo "tests:    ok"
#rm out valgrind_test.txt
#rm PmergeMe
#else
#    echo ko
#fi

MAXCOUNT=$((1 + $RANDOM % 3000))
count=1

ft_make_array()
{
    array_length=$(shuf -i 10-10 -n 1)
    number=($(shuf -i 0-11 -n $array_length))
}

x=1
while [ $x -le $test_ammount ]
do
    ft_make_array
    ft_test "${number[*]}"
    x=$(( $x + 1 ))
done

if [ $num -eq 0 ]
    then echo "| valgrind: ok  |"
else
    echo "| valgrind: ko  |"
fi

#rm out PmergeMe

echo "-----------------"

#rm out valgrind_test.txt PmergeMe