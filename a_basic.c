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
    // *i = 666;  取出内存地址所对应的值并把它修改成 666
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
    printf("&i 的值是:%p\n", &i); //0x7ffeedf5b9a8, 二级地址即指针i的地址
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
//    int *p1 = i;
//    printf("p1 的值是:%p\n", p1); //0x64=100
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
    printf("l的值是：%ld\n", l);
    printf("s的值是：%d\n", s);
    printf("c的值是：%c\n", c); //c%:char
    printf("str的值是：%s\n", str);//%s:string
}


/*********-------------------------*********/
/**
 * 多级指针
 */
void multilevelPointer() {
    // 一级指针 *
    // 二级指针 **
    // 在真实开发过程中，最多只用三级指针  int ***
    int num = 999;
    int *num_p = &num; //取出 num 的内存地址给 num_p（一级指针）
    printf("num_p 的值是：%p\n", num_p); //指针指向的地址，0x7ffeee2bf9dc
    printf("&num_p 的值是：%p\n", &num_p); //指针本身的地址，0x7ffeee2bf9d0
    printf("*num_p 的值是：%d\n", *num_p); //指针指向地址的值，999
    printf("&num 的值是：%p\n", &num); // num变量的地址，0x7ffeee2bf9dc
    printf("\n");

    int **num_pp = &num_p; // 取出num_p的内存地址给 num_pp（二级指针）
    printf("num_pp 的值是：%p\n", num_pp); //指针指向的地址，0x7ffeee2bf9d0
    printf("&num_pp 的值是：%p\n", &num_pp); //指针本身的地址，0x7ffeee2bf9c8
    printf("*num_pp 的值是：%p\n", *num_pp); //指针指向地址的值是地址了，0x7ffeee2bf9dc
    printf("\n");

    int ***num_ppp = &num_pp;  // 取出 num_pp 的内存地址给 num_ppp（三级指针）
    printf("num_ppp 的值是：%p\n", num_ppp); //指针指向的地址，0x7ffeee2bf9c8
    printf("&num_ppp 的值是：%p\n", &num_ppp); //指针本身的地址，0x7ffeee2bf9c0
    printf("*num_ppp 的值是：%p\n", *num_ppp); //指针指向地址的值是地址了，0x7ffeee2bf9d0
    printf("\n");

    int ****num_pppp = &num_ppp;  // 取出 num_ppp 的内存地址给 num_pppp（四级指针）
    printf("num_pppp 的值是：%p\n", num_pppp); //指针指向的地址，0x7ffeee2bf9c0
    printf("&num_pppp 的值是：%p\n", &num_pppp); //指针本身的地址，0x7ffeee2bf9b8
    printf("*num_pppp 的值是：%p\n", *num_pppp); //指针指向地址的值是地址了，0x7ffeee2bf9c8
    printf("\n");

    int *****num_ppppp = &num_pppp;  // 取出 num_pppp 的内存地址给 num_ppppp（五级指针）
    printf("num_ppppp 的值是：%p\n", num_ppppp); //指针指向的地址，0x7ffeee2bf9b8
    printf("&num_ppppp 的值是：%p\n", &num_ppppp); //指针本身的地址，0x7ffeee2bf9b0
    printf("*num_ppppp 的值是：%p\n", *num_ppppp); //指针指向地址的值是地址了，0x7ffeee2bf9c0

    //思考： 三级指针实现三维数组
    // int *** arrPpp;

    //多级指针的意义是什么

}

/**
 * 数组与数组指针
 */
void arrayAndPointer() {
    // 定义数组
//    int [] arr_error = {1, 2, 3, 4}; //错误的写法
    int arr[] = {1, 2, 3, 4};
    // 遍历数组
    // 其他平台不能用 Clion能用， Linux上报错
    for (int i = 0; i < 4; ++i) {
        printf("%d ", arr[i]); // 取值
    }
    int i = 0;
    for (i = 0; i < 4; i++) {
        printf("%d ", arr[i]); // 取值
    }
    printf("\n");

    //数组的内存地址 == 第一个元素的内存地址 &arr[0]  == &arr
    printf("arr  =   %p\n", arr);//0x7ffee192c9c0
    printf("&arr  =   %p\n", &arr); //0x7ffee192c9c0
    printf("&arr[0]  =   %p\n", &arr[0]); //0x7ffee192c9c0
    //既然数组就是一个内存地址,可以通过数组地址取出第一个元素的值
    int *arr_p = arr;
    printf("*arr_p  =   %d\n", *arr_p); // 1
    //指针挪动取出其它位置的值
    arr_p += 1;
    printf("*arr_p  =   %d\n", *arr_p); // 2
    //不会越界
    arr_p += 25;
    printf("%d\n", *arr_p); // 系统值 -473166960

    printf("\n 采用指针遍历数组");
    //采用指针遍历数组
    // 数组是连续的内存空间（没有断层，有规律） int 数组在32位目标机器上每次挪动 4个字节
    int arr2[] = {1, 2, 3, 4};
    int *arr_p2 = arr2;
    int j = 0;
    for (j = 0; j < 4; ++j) {
        printf("位置%d的值是:%d\n", j, *(arr_p2 + j));
        // 04    08   12    16
        printf("位置%d的内存地址是:%p\n", j, (arr_p2 + j));

        //位置0的值是:1
        //位置0的内存地址是:0x7ffee6ba39b0
        //位置1的值是:2
        //位置1的内存地址是:0x7ffee6ba39b4
        //位置2的值是:3
        //位置2的内存地址是:0x7ffee6ba39b8
        //位置3的值是:4
        //位置3的内存地址是:0x7ffee6ba39bc
    }
    printf("\n 循环时给数组赋值");

    int arr3[] = {1, 2, 3, 4, 5};
    printf(" arr3 的内存大小：%lu\n", sizeof(arr3)); //20=5个int

    // 循环赋值操作
    int k = 0;
    for (k = 0; k < 5; ++k) {
        // 1.拿到 元素的内存地址   (arrP + j)
        // 2.取出 元素内存地址所对应的值 * (arrP + j)
        *(arr3 + k) = (k + 10001);
        printf("位置%d的值是:%d\n", k, *(arr3 + k));
    }
    // sizeof arr3 = 16(sizeof arr)  /  4(sizeof(int))
    // 变量 刚刚赋值的数组
    for (int l = 0; l < sizeof arr3 / sizeof(int); ++l) {
        printf("位置%d的值是:%d\n", l, *(arr3 + l));
    }
    //位置0的值是:10001
    //位置1的值是:10002
    //位置2的值是:10003
    //位置3的值是:10004
    //位置4的值是:10005

}

/**
 * 指针类型
 */
void pointerType() {
    int num = 12;
    int *num_p = &num;
    int *p_value = &num_p;
    long *p_value_l = &num_p;
    // 优化处理，报错：检测无法通过的
    double *num_p_d = num_p;
    printf("%lu\n", sizeof(int)); //4
    printf("%lu\n", sizeof(p_value)); //4
    printf("p_value:%p\n", p_value); //-342091312
    printf("p_value_l:%p\n", p_value_l); //140732896000464
    printf("&num_p:%p\n", &num_p); //-342091312
    printf("%lu\n", sizeof(double)); //8
    printf("%lu\n", sizeof(long)); //8
    printf("%lu\n", sizeof num_p); //8
    printf("%lu\n", sizeof num_p_d); // 8

    // 指针占用的内存大小是？
    // 答：int double long  的指针大小永远都是：4个字节（32），8字节（64）
    // 指针类型有何用？。  既然都是 4或8 个字节，为什么还要分指针类型
    // 答：取值的时候，怎么取，类型是为了计算偏移量，这就是类型规定的好处

    // int * p; // 类型是为了计算偏移量

}

int add(int num1, int num2) {
    printf("num1 + num2 = %d\n", (num1 + num2));
    return (num1 + num2);
}

void subtraction(int num1, int num2) {
    printf("num1 - num2 = %d\n", (num1 - num2));
}

/**
 *  操作 回调到  add  subtraction
 * @param method  void(*method)(int,int)  声明好函数指针,(*method) 函数名, (int,int) 两个参数
 * @param num1
 * @param num2
 */
void operate(void(*method)(int, int), int num1, int num2) {
    method(num1, num2);
    printf("operate 函数的 method 指针：%p\n", method);// add :0x10fc077e0,   subtraction:0x10fc07810
}

/**
 * 函数指针.高阶函数
 */
void funPointer() {
    operate((void (*)(int, int)) add, 10, 10);
    operate(subtraction, 100, 10);
    // 原理是什么？
    printf("main函数的 add 指针是多少：%p\n", add);//0x10fc077e0
    printf("main函数的 subtraction 指针是多少：%p\n", subtraction);//0x10fc07810
    // &add和add是一样的值吗
    printf("%p, %p\n", add, &add); // 0x10fc077e0, 0x10fc077e0

    //函数指针
    int (*add_p)(int, int) = add; //返回值
    printf("add_p: %p, %p\n", add_p, &add_p);
    printf("add_p(1,3): %d\n", add_p(1, 3));

    void (*operate_p)(void (*add_p)(int, int), int, int) =operate; //二层高阶函数
    printf("operate_p: %p, %p\n", operate_p, &operate_p); //0x102a23750, 0x7ffeed1df9d0
    printf("*operate_p: %p\n", *operate_p); //0x102a23750 todo
    operate_p(add_p(1, 3), 3, 4);


}


int main() {
    printf("Hello, C! \n");
//    printf("\n\n===== 基本数据类型 ===== \n");
//    basicDataType();
//    printf("\n\n===== 基本类型占用的字节数 sizeof获取字节数 ===== \n");
//    basicDataTypeSizeOf();
//    printf("\n\n===== 地址概念 ===== \n");
//    cAddress();
//    printf("\n\n===== 指针操作 ===== \n");
//    cPoint();
//    printf("\n\n===== 函数的使用 ===== \n");
//    cFunction();

//    printf("\n\n===== 多级指针 ===== \n");
//    multilevelPointer();
//    printf("\n\n===== 数组与指针 ===== \n");
//    arrayAndPointer();
//    printf("\n\n===== 指针类型 ===== \n");
//    pointerType();

    printf("\n\n===== 函数指针 ===== \n");
    funPointer();

    return 0; //返回0是为了
}



