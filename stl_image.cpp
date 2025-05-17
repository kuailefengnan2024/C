// stl_image.cpp
// 学习目标：使用STL（标准模板库）实现简单的图像处理操作
// 适用场景：模拟AIGC图像处理中的常见操作，学习STL容器和算法
// 运行要求：C++11或更高版本，编译器支持STL

#include <iostream> // 输入输出
#include <vector>   // STL容器：动态数组
#include <algorithm> // STL算法
#include <numeric>  // 添加这行，使用accumulate函数
#include <memory>   // 添加这行，使用智能指针
using namespace std;

// 类定义：Image模拟图像，包含像素数据
class Image {
private:
    vector<double> pixels; // 存储像素亮度值（模拟灰度图）
    int width;             // 图像宽度
    int height;            // 图像高度

public:
    // 构造函数：初始化图像
    Image(int w, int h) : width(w), height(h) {
        pixels.resize(w * h, 0.0); // 初始化所有像素为0
        cout << "创建图像：宽=" << w << ", 高=" << h << endl;
    }

    // 析构函数
    ~Image() {
        cout << "销毁图像" << endl;
    }

    // 设置像素亮度
    void setPixel(int x, int y, double brightness) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            pixels[y * width + x] = brightness;
        }
    }

    // 获取像素亮度
    double getPixel(int x, int y) const {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            return pixels[y * width + x];
        }
        return 0.0;
    }

    // 使用STL算法计算平均亮度
    double getAverageBrightness() const {
        // 学习点：accumulate是STL算法，计算所有元素总和
        double sum = accumulate(pixels.begin(), pixels.end(), 0.0);
        return sum / pixels.size();
    }

    // 使用STL算法增强亮度
    void enhanceBrightness(double factor) {
        // 学习点：transform是STL算法，批量修改容器元素
        transform(pixels.begin(), pixels.end(), pixels.begin(),
            [factor](double p) { return p * factor; });
    }
};

int main() {
    // 1. STL容器：vector
    // 学习点：vector是动态数组，自动管理内存
    Image img(3, 3); // 创建3x3图像

    // 2. 设置数据
    // 学习点：模拟图像处理中对像素的操作
    img.setPixel(0, 0, 100.0);
    img.setPixel(1, 1, 150.0);
    img.setPixel(2, 2, 200.0);

    // 3. 数据访问
    cout << "像素(1,1)亮度：" << img.getPixel(1, 1) << endl;

    // 4. STL算法：计算平均亮度
    cout << "平均亮度：" << img.getAverageBrightness() << endl;

    // 5. STL算法：增强亮度
    img.enhanceBrightness(1.2); // 增亮20%
    cout << "增强后平均亮度：" << img.getAverageBrightness() << endl;

    // 6. 智能指针（STL特性）
    // 学习点：unique_ptr自动管理动态内存
    unique_ptr<Image> imgPtr = make_unique<Image>(2, 2);
    imgPtr->setPixel(0, 0, 50.0);
    cout << "智能指针图像平均亮度：" << imgPtr->getAverageBrightness() << endl;

    return 0;
}