#include <stdio.h> // C99 标准库

// <> 寻找系统的资源
// “” 寻找我们自己写的资源
// .h .hpp(声明文件 头文件)
// .c  .cpp （实现文件）


//由于C语言不支持函数重载，所以声明的函数，不需要写参数
//生命函数
void changeByValue();

//生命函数
void changeByPoint();

/**
 * 函数的使用
 * 函数：修改一个数（指针操作）
 * C语言不允许函数重载，Java可以，C++可以
 * 函数不能写在 main的下面，会报错, 可以先声明，然后再main函数下面实现
 */
void cFunction() {
    int i = 100;
    // int * i;  定义指针
    // *i = 888;  取出内存地址所对应的值修改成 666
    printf("i 的值是:%d\n", i); //100
    printf("&i 的值是:%p\n", &i); //0x7ffeebef79fc
    changeByValue(i);
    printf("i 的值是:%d\n", i); //100
    changeByPoint(&i);
    printf("i 的值是:%d\n", i); //666
}

void changeByPoint(int *i) {
    printf("i 的值是:%p\n", i); //0x7ffeebef79fc，地址一样
    printf("*i 的值是:%d\n", *i); //100
    *i = 666;
}

void changeByValue(int i) {
    printf("&i 的值是:%p\n", &i); //0x7ffeebef79dc,地址不一样
    i = 666;
}


/**
 * 指针操作
 *  1. 通过指针地址取出值
 *  2. 通过指针变量取出值
 *  3. 通过 指针（地址）修改值
 */
void cPoint() {

    // 通过指针地址取出值
    int a = 100;
    double b = 200;
    printf("a 的值是:%d\n", a);
    printf("b 的值是:%lf\n", b);
    // * == 取出 变量 a 地址所对应的值 == 100
    // 既然任何变量都是地址，可以使用 * 获取值
    printf("a 通过地址取出的值是：%d\n", *(&a));
    printf("b 通过地址取出的值是：%f\n", *(&b));

    // 通过指针变量取出值
    /*
       int* a_p , double* b_p
      内存地址变量，内存地址别名，指针，指针变量，指针别名，.... 一大段的专业术语 ...
      理解：  大道至简 （化繁为简）
      内存地址 == 指针, 指针 == 内存地址
        int *，  double *      (int类型的指针)
      指针别名，指针变量 == 就是一个变量而已，只不过 是指针的 变量 而已
        a_p，  b_p
    */
    int *a_p = &a;
    double *b_p = &b;
    printf("a 通过指针变量取出的值是：%p\n", a_p); //0x7ffee33c19fc
    printf("a 通过指针变量取出的值是：%p\n", &a); //0x7ffee33c19fc
    printf("a 通过指针变量取出的值是：%d\n", *a_p); //100
    printf("b 通过指针变量取出的值是：%f\n", *b_p); //200.000000


    //通过  指针（地址） 修改值
    int i = 100;
    // p:我只接收地址，你给我一个100，不规范
    int *p1 = (int *) i;
    printf("p1 的值是:%p\n", p1); //0x64=100
//    printf("*p1 的值是:%d\n", *p1); //地址无效，取出出数据，报错

    int *p = &i;
    i = 200;
    printf("i的值是:%d\n", i); //200
    printf("&i的值是:%p\n", &i); //0x7ffee64039dc
    //变量i地址指向了300
    *p = 300;
    printf("&i的值是:%p\n", &i); //0x7ffee64039dc
    printf("p 的值是:%p\n", p); //0x7ffee91f79dc
    printf("*p 的值是:%d\n", *p); //300
    printf("i的值是:%d\n", i); //300

}

/**
 * 地址概念:
 *
 * Java 万物皆对象
 * C C++(对象) 万物皆指针
 * Linux 万物皆文件
 */
void cAddress() {
    // 指针 == 地址
    // %p == 地址输出的占位符号
    // & == 取出变量地址
    int a = 100;
    printf("数字a的地址是：%p\n", &a); //数字a的地址是：0x7ffeeae4f9fc
}

/**
 * 基本类型占用的字节数 sizeof获取字节数
 */
void basicDataTypeSizeOf() {
    printf("int 数据类型所占的字符数：%lu\n", sizeof(int)); //4字节
    printf("short 数据类型所占的字符数：%lu\n", sizeof(short)); //2字节
    printf("double 数据类型所占的字符数：%lu\n", sizeof(double)); //8字节
    printf("char 数据类型所占的字符数：%lu\n", sizeof(char)); //1字节
}

/**
 * 基本数据类型
 */
void basicDataType() {
    int i = 100;
    double d = 200;
    float f = 300;
    long l = 400;
    short s = 500;
    char c = 'c';
    //字符串
    char *str = "jay";
    //占位打印
    printf("i的值是：%d\n", i); //%d:整形
    printf("d的值是：%lf\n", d); //%lf=long float
    printf("f的值是：%f\n", f); //f%:float
    printf("l的值是：%d\n", l);
    printf("s的值是：%d\n", s);
    printf("c的值是：%c\n", c); //c%:char
    printf("str的值是：%s\n", str);//%s:string
}


int main() {
    printf("Hello, C! \n");
    printf("\n\n===== 基本数据类型 ===== \n");
    basicDataType();
    printf("\n\n===== 基本类型占用的字节数 sizeof获取字节数 ===== \n");
    basicDataTypeSizeOf();
    printf("\n\n===== 地址概念 ===== \n");
    cAddress();
    printf("\n\n===== 指针操作 ===== \n");
    cPoint();
    printf("\n\n===== 函数的使用 ===== \n");
    cFunction();
    return 0;
}


