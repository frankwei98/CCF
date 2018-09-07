echo "目前编译试题  -" $1
cd $1

g++ main.cpp -o main.bin
./main.bin