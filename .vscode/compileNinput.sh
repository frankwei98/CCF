echo "目前编译试题  -" $1
cd $1

g++ $2.cpp -o $2.bin
cat ./$2.input << ./$2