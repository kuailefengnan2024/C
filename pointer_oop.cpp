// pointer_oop.cpp
// 教学目标：讲解指针、内存管理、面向对象编程（OOP）
// 适用场景：理解C++内存操作和类机制，为图像处理中的像素对象建模
// 环境要求：与basic_syntax.cpp相同，确保编译器支持C++11或更高版本

#include <iostream> // 输入输出
using namespace std;

// 类定义：Pixel表示图像中的一个像素点（OOP示例）
class Pixel {
private: // 封装：私有成员只能通过公有方法访问
    int red;   // RGB颜色值
    int green;
    int blue;

public: // 公有接口
    // 构造函数：初始化像素
    // 教学：构造函数在对象创建时自动调用
    Pixel(int r = 0, int g = 0, int b = 0) : red(r), green(g), blue(b) {
        cout << "创建像素：R=" << r << ", G=" << g << ", B=" << b << endl;
    }

    // 析构函数：清理资源
    // 教学：析构函数在对象销毁时自动调用
    ~Pixel() {
        cout << "销毁像素：R=" << red << ", G=" << green << ", B=" << blue << endl;
    }

    // 成员函数：获取亮度
    double getBrightness() const { // const表示不修改对象
        return 0.299 * red + 0.587 * green + 0.114 * blue;
    }

    // 成员函数：设置颜色（参数传递使用引用）
    void setColor(int& r, int& g, int& b) {
        red = r;
        green = g;
        blue = b;
    }
};

// 函数：动态分配像素并返回指针
Pixel* createPixel(int r, int g, int b) {
    // 教学：new分配堆内存，返回指针
    return new Pixel(r, g, b);
}

int main() {
    // 1. 指针基础
    // 教学：指针存储内存地址，&取地址，*解引用
    int value = 100;
    int* ptr = &value; // ptr指向value的地址
    cout << "值：" << value << ", 地址：" << ptr << ", 指针解引用：" << *ptr << endl;

    // 2. 动态内存管理
    // 教学：new分配内存，delete释放内存，避免内存泄漏
    Pixel* pixelPtr = createPixel(255, 128, 64);
    cout << "动态像素亮度：" << pixelPtr->getBrightness() << endl;
    delete pixelPtr; // 释放内存
    pixelPtr = nullptr; // 避免野指针

    // 3. 面向对象编程
    // 教学：创建Pixel对象，展示封装和方法调用
    Pixel pixel(200, 150, 100); // 栈上分配
    cout << "栈上像素亮度：" << pixel.getBrightness() << endl;

    // 4. 引用与指针结合
    // 教学：引用是别名，简化指针操作
    int r = 50, g = 75, b = 25;
    pixel.setColor(r, g, b);
    cout << "更新后像素亮度：" << pixel.getBrightness() << endl;

    return 0;
}