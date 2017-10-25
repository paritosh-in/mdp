make clean > /dev/null 2>&1
make CFLAGS=-DN=100 > /dev/null 2>&1

./Application > test/actual/broadcast.txt
