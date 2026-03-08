#include<stdio.h>
#include<stdlib.h>

int main() {
    {
        char *func(int); //返回字符串指针的函数
    }
    {
        char (*func)(int);//func是指向一个返回字符的函数的指针
    }
    {
        char (*func[3])(int);//func是有三个函数指针的数组
    }
    {
        typedef int arr5[5];//arr5是有五个int的数组的类型
        typedef arr5* p_arr5;//p_arr5是指向有五个元素的数组的指针类型
        typedef p_arr5 arr10[10];//arr10是有十个指针的数组的类型，每个指针指向一个有五个int的数组
    }
    return 0;
}