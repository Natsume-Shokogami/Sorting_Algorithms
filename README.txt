# Sorting_Algorithms
#This includes all files (except the .exe file) in my codes of lab_03 in Data Structures & Algorithms class.
#There're still some issues in my codes, you can change them and commit your changes here.
#-All citations about the algorithms are in the comments between the functions.
#-There may still some bugs in my codes, fix if you found them
#-The comparison count in the functions can be overflowed due to large initial data sizes (up to 500 000 elements), please change "int &count_cmp" to long long instead (The reason I didn't change that because I dont know the limit of long long in different compilers).
#If you use g++ to compile on Windows, you can use this command -Wl,--stack,stack-size with stack-size is the maximum stack size you want your program to have (g++ 8 MB default stack size, VS 1 MB if I am not wrong).
For example, g++ -Wl,--stack,67108864 -o sorting.exe ./sort.cpp ./data.cpp will generate a execution file with 64 MB stack size maximum.
