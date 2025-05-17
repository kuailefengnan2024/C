// pointer_oop.cpp
// 学习目标：掌握指针、内存管理和面向对象编程（OOP）
// 适用场景：掌握C++内存管理和控制，为图像处理中的对象定义建模
// 运行要求：与basic_syntax.cpp相同，确保编译器支持C++11或更高版本

#include <iostream> // 输入输出
using namespace std;

// 类定义：Pixel表示图像中的一个像素点（OOP示例）
class Pixel {
private: // 封装：私有成员只能通过公有方法访问
    int red;   // RGB颜色值
    int green;
    int blue;

public: // 公有接口
    // 构造函数：初始化对象
    // 学习点：构造函数在对象创建时自动调用
    Pixel(int r = 0, int g = 0, int b = 0) : red(r), green(g), blue(b) {
        cout << "像素创建：R=" << r << ", G=" << g << ", B=" << b << endl;
    }

    // 析构函数：释放资源
    // 学习点：析构函数在对象销毁时自动调用
    ~Pixel() {
        cout << "像素销毁：R=" << red << ", G=" << green << ", B=" << blue << endl;
    }

    // 成员函数：获取亮度
    double getBrightness() const { // const表示不修改对象
        return 0.299 * red + 0.587 * green + 0.114 * blue;
    }

    // 成员函数：设置颜色（演示参数引用传递）
    void setColor(int& r, int& g, int& b) {
        red = r;
        green = g;
        blue = b;
    }
};

// 函数：动态创建并返回像素指针
Pixel* createPixel(int r, int g, int b) {
    // 学习点：new分配内存，返回指针
    return new Pixel(r, g, b);
}

int main() {
    // 1. 指针基础
    // 学习点：指针存储内存地址，&取地址，*解引用
    int value = 100;
    int* ptr = &value; // ptr指向value的地址
    cout << "值：" << value << ", 地址：" << ptr << ", 指针解引用：" << *ptr << endl;

    // 2. 动态内存分配
    // 学习点：new分配内存，delete释放内存，避免内存泄漏
    Pixel* pixelPtr = createPixel(255, 128, 64);
    cout << "动态对象亮度：" << pixelPtr->getBrightness() << endl;
    delete pixelPtr; // 释放内存
    pixelPtr = nullptr; // 避免野指针

    // 3. 对象与类
    // 学习点：创建Pixel对象展示封装和方法调用
    Pixel pixel(200, 150, 100); // 栈上分配
    cout << "栈对象亮度：" << pixel.getBrightness() << endl;

    // 4. 引用与指针传参
    // 学习点：演示引用传递和指针参数
    int r = 50, g = 75, b = 25;
    pixel.setColor(r, g, b);
    cout << "更新后亮度：" << pixel.getBrightness() << endl;

    return 0;
}