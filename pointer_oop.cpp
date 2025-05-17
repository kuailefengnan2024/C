// pointer_oop.cpp
// ��ѧĿ�꣺����ָ�롢�ڴ������������̣�OOP��
// ���ó��������C++�ڴ����������ƣ�Ϊͼ�����е����ض���ģ
// ����Ҫ����basic_syntax.cpp��ͬ��ȷ��������֧��C++11����߰汾

#include <iostream> // �������
using namespace std;

// �ඨ�壺Pixel��ʾͼ���е�һ�����ص㣨OOPʾ����
class Pixel {
private: // ��װ��˽�г�Աֻ��ͨ�����з�������
    int red;   // RGB��ɫֵ
    int green;
    int blue;

public: // ���нӿ�
    // ���캯������ʼ������
    // ��ѧ�����캯���ڶ��󴴽�ʱ�Զ�����
    Pixel(int r = 0, int g = 0, int b = 0) : red(r), green(g), blue(b) {
        cout << "�������أ�R=" << r << ", G=" << g << ", B=" << b << endl;
    }

    // ����������������Դ
    // ��ѧ�����������ڶ�������ʱ�Զ�����
    ~Pixel() {
        cout << "�������أ�R=" << red << ", G=" << green << ", B=" << blue << endl;
    }

    // ��Ա��������ȡ����
    double getBrightness() const { // const��ʾ���޸Ķ���
        return 0.299 * red + 0.587 * green + 0.114 * blue;
    }

    // ��Ա������������ɫ����������ʹ�����ã�
    void setColor(int& r, int& g, int& b) {
        red = r;
        green = g;
        blue = b;
    }
};

// ��������̬�������ز�����ָ��
Pixel* createPixel(int r, int g, int b) {
    // ��ѧ��new������ڴ棬����ָ��
    return new Pixel(r, g, b);
}

int main() {
    // 1. ָ�����
    // ��ѧ��ָ��洢�ڴ��ַ��&ȡ��ַ��*������
    int value = 100;
    int* ptr = &value; // ptrָ��value�ĵ�ַ
    cout << "ֵ��" << value << ", ��ַ��" << ptr << ", ָ������ã�" << *ptr << endl;

    // 2. ��̬�ڴ����
    // ��ѧ��new�����ڴ棬delete�ͷ��ڴ棬�����ڴ�й©
    Pixel* pixelPtr = createPixel(255, 128, 64);
    cout << "��̬�������ȣ�" << pixelPtr->getBrightness() << endl;
    delete pixelPtr; // �ͷ��ڴ�
    pixelPtr = nullptr; // ����Ұָ��

    // 3. ���������
    // ��ѧ������Pixel����չʾ��װ�ͷ�������
    Pixel pixel(200, 150, 100); // ջ�Ϸ���
    cout << "ջ���������ȣ�" << pixel.getBrightness() << endl;

    // 4. ������ָ����
    // ��ѧ�������Ǳ�������ָ�����
    int r = 50, g = 75, b = 25;
    pixel.setColor(r, g, b);
    cout << "���º��������ȣ�" << pixel.getBrightness() << endl;

    return 0;
}