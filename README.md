![Alt text](image.png)
<br />

## few sorting algorithms - a short analysis
<br />

- each of these .cpp files can be compiled with the command:<br />
g++ -o outfile anyfile.cpp -std=c++17.<br />

- genData.cpp generates 10000 integers to the file data.txt, of course you can change<br />
the number of generated numbers if you want.<br />

I used the compiler version: g++ (Ubuntu 11.4.0-2ubuntu1~18.04) 11.4.0<br />
On my Kubuntu 18.04 (kernel version 5.4.0-152-generic) I ran these programs like this:<br />

time ./selection <br />
and i received: <br />
start sorting...<br />
finish sorting...<br />
real    0m0,371s<br />
user    0m0,367s<br />
sys     0m0,004s<br />

time ./insertion <br />
start sorting... <br />
finish sorting... <br />
real    0m0,279s <br />
user    0m0,275s <br />
sys     0m0,000s <br />

time ./merge<br />
start sorting...<br />
finish sorting...<br />
real    0m0,015s<br />
user    0m0,015s<br />
sys     0m0,000s<br />

time ./quick<br />
start sorting...<br />
finish sorting...<br />
real    0m0,009s<br />
user    0m0,009s<br />
sys     0m0,000s<br />

### It can be seen that, as usual, the quick sort algorithm is the fastest$`~~`$😺
<br />
