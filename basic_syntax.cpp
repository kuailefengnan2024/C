// basic_syntax.cpp
// 学习目标：展示C++基本语法，包括变量、输入输出、控制结构和函数
// 适用场景：帮助学习C++编程基础结构和基本逻辑
// 运行要求：需配置好C++环境，用g++编译，推荐使用VS Code或Visual Studio

#include <iostream> // 标准输入输出库
using namespace std; // 使用标准命名空间，避免每次写std::

// 函数声明：计算像素值的平均亮度（模拟AIGC图像处理中的亮度计算）
double calculateBrightness(int r, int g, int b);

// 主函数：程序入口
int main() {
    // 1. 变量定义与初始化
    // 学习点：变量是存储数据的容器，C++的强类型特性，整型和浮点型
    int red = 255;    // 红色通道（0-255，模拟图像像素）
    int green = 128;  // 绿色通道
    int blue = 64;    // 蓝色通道
    double brightness; // 存储亮度值的浮点数

    // 2. 输入输出操作
    // 学习点：cin处理输入，cout处理输出，<<和>>操作符重载
    cout << "请输入RGB三个值 (红 绿 蓝，范围0-255)：";
    cin >> red >> green >> blue;

    // 3. 控制结构 - 条件语句
    // 学习点：if-else语句判断输入是否合法（RGB值必须0-255之间）
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        cout << "错误：RGB值必须在0-255之间！" << endl;
        return 1; // 返回1表示程序异常退出
    }

    // 4. 函数调用
    // 学习点：函数封装复用代码，calculateBrightness函数调用
    brightness = calculateBrightness(red, green, blue);

    // 5. 控制结构 - 循环
    // 学习点：for循环模拟数据输出，展示循环的使用
    cout << "亮度值：" << brightness << endl;
    for (int i = 0; i < 3; i++) {
        cout << "第" << i + 1 << "次确认亮度：" << brightness << endl;
    }

    return 0; // 程序正常退出
}

// 函数定义：计算RGB像素的亮度，基于加权平均，模拟图像处理中
double calculateBrightness(int r, int g, int b) {
    // 学习点：函数实现，参数传递与返回值
    // 亮度公式：Y = 0.299R + 0.587G + 0.114B（常见视觉感知公式）
    double result = 0.299 * r + 0.587 * g + 0.114 * b;
    return result;
}