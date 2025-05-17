// stl_image.cpp
// ��ѧĿ�꣺ʹ��STL����׼ģ��⣩ʵ�ּ򵥵�ͼ�����ز���
// ���ó�����ģ��AIGCͼ�����е������������ѧϰSTL�������㷨
// ����Ҫ��C++11����߰汾��������֧��STL

#include <iostream> // �������
#include <vector>   // STL��������̬����
#include <algorithm> // STL�㷨
using namespace std;

// �ඨ�壺Imageģ��ͼ�񣬰�����������
class Image {
private:
    vector<double> pixels; // �洢��������ֵ��ģ��Ҷ�ͼ��
    int width;             // ͼ����
    int height;            // ͼ��߶�

public:
    // ���캯������ʼ��ͼ��
    Image(int w, int h) : width(w), height(h) {
        pixels.resize(w * h, 0.0); // ��ʼ����������Ϊ0
        cout << "����ͼ�񣺿�=" << w << ", ��=" << h << endl;
    }

    // ��������
    ~Image() {
        cout << "����ͼ��" << endl;
    }

    // ������������
    void setPixel(int x, int y, double brightness) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            pixels[y * width + x] = brightness;
        }
    }

    // ��ȡ��������
    double getPixel(int x, int y) const {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            return pixels[y * width + x];
        }
        return 0.0;
    }

    // ʹ��STL�㷨����ƽ������
    double getAverageBrightness() const {
        // ��ѧ��accumulate��STL�㷨����������Ԫ���ܺ�
        double sum = accumulate(pixels.begin(), pixels.end(), 0.0);
        return sum / pixels.size();
    }

    // ʹ��STL�㷨��ǿ����
    void enhanceBrightness(double factor) {
        // ��ѧ��transform��STL�㷨�������޸�����Ԫ��
        transform(pixels.begin(), pixels.end(), pixels.begin(),
            [factor](double p) { return p * factor; });
    }
};

int main() {
    // 1. STL������vector
    // ��ѧ��vector�Ƕ�̬���飬�Զ������ڴ�
    Image img(3, 3); // ����3x3ͼ��

    // 2. ��������
    // ��ѧ��ģ��ͼ����������������
    img.setPixel(0, 0, 100.0);
    img.setPixel(1, 1, 150.0);
    img.setPixel(2, 2, 200.0);

    // 3. ��������
    cout << "����(1,1)���ȣ�" << img.getPixel(1, 1) << endl;

    // 4. STL�㷨������ƽ������
    cout << "ƽ�����ȣ�" << img.getAverageBrightness() << endl;

    // 5. STL�㷨����ǿ����
    img.enhanceBrightness(1.2); // ��������20%
    cout << "��ǿ��ƽ�����ȣ�" << img.getAverageBrightness() << endl;

    // 6. ����ָ�루STL���ԣ�
    // ��ѧ��unique_ptr�Զ�����̬�ڴ�
    unique_ptr<Image> imgPtr = make_unique<Image>(2, 2);
    imgPtr->setPixel(0, 0, 50.0);
    cout << "����ָ��ͼ��ƽ�����ȣ�" << imgPtr->getAverageBrightness() << endl;

    return 0;
}