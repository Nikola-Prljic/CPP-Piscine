#!/bin/bash
num=0
testcount=1
cd ..
make
mv PmergeMe tester
make clean
cd tester
> out
> sorted
echo "-----------------"
ft_test()
{
    ./PmergeMe $1 > out 2>&1
    valgrind ./PmergeMe $1 > valgrind_test.txt 2>&1
    grep -q "ERROR SUMMARY: 0 errors" valgrind_test.txt
    val_error=$?
    grep -q "All heap blocks were freed -- no leaks are possible" valgrind_test.txt
    val_blocks=$?
    num=$(($num + $val_error + $val_blocks))

    array=($1)
    printf "%s\n" "${array[@]}" | sort -n > sorted

    diff out sorted
    if [ $? -eq 0 ]
        then echo "| Test $testcount : ok   |"
    else
        echo "| Test $testcount : ko   |"
    fi
    testcount=$((1+testcount))
    rm sorted
}

ft_test "53 86 54 89 15 33 39 4 71 3"
ft_test "42 1 3 2 42 331 -1"
ft_test "222 60 240 411 121 73 277 11 92 438 264 440 69 297 284 374 174 31 481 17 155 407 217 441 34 415 393 247 83 28 294 88 117 415 148 76 285 237 294 214 183 205 92 176 273 28 307 468 330 194 209 304 155 232 223 71 424 242 388 462 143 168 486 36 418 473 170 270 91 473 270 444 320 304 198 359 162 252 175 108 497 124 341 309 487 189 436 338 148 296 145 245 340 414 286 490 69 112 256 218"

if [ $num -eq 0 ]
    then echo "| valgrind: ok  |"
else
    echo "| valgrind: ko  |"
fi
echo "-----------------"
rm out valgrind_test.txt PmergeMe

#diff out in

#if [ $? -eq 0 ]
#then echo "tests:    ok"
#rm out valgrind_test.txt
#rm PmergeMe
#else
#    echo ko
#fi
