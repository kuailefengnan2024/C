// basic_syntax.cpp
// ��ѧĿ�꣺չʾC++�����﷨������������������������ƽṹ�ͺ���
// ���ó�������ѧ��ѧϰC++������������ṹ�ͻ����߼�
// ����Ҫ�����ú�C++����������g++�����Ƽ�ʹ��VS Code��Visual Studio

#include <iostream> // ��׼���������
using namespace std; // ʹ�ñ�׼�����ռ䣬����ÿ��дstd::

// ������������������ֵ��ƽ�����ȣ�ģ��AIGCͼ�����е����ȼ��㣩
double calculateBrightness(int r, int g, int b);

// ���������������
int main() {
    // 1. ��������������
    // ��ѧ�������Ǵ洢���ݵ�������C++��ǿ�������ԣ�������������
    int red = 255;    // ��ɫͨ����0-255��ģ��ͼ�����أ�
    int green = 128;  // ��ɫͨ��
    int blue = 64;    // ��ɫͨ��
    double brightness; // �洢����ֵ����������

    // 2. �����������
    // ��ѧ��cin�������룬cout���������<<��>>����������
    cout << "������RGB����ֵ (�� �� ������Χ0-255)��";
    cin >> red >> green >> blue;

    // 3. ���ƽṹ - �������
    // ��ѧ��if-else�����ж������Ƿ�Ϸ���RGBֵ����0-255֮�䣩
    if (red < 0 || red > 255 || green < 0 || green > 255 || blue < 0 || blue > 255) {
        cout << "����RGBֵ������0-255֮�䣡" << endl;
        return 1; // ����1��ʾ�����쳣�˳�
    }

    // 4. ��������
    // ��ѧ��������װ�����ô��룬calculateBrightness��������
    brightness = calculateBrightness(red, green, blue);

    // 5. ���ƽṹ - ѭ��
    // ��ѧ��forѭ��ģ���������չʾѭ����ʹ��
    cout << "����ֵ��" << brightness << endl;
    for (int i = 0; i < 3; i++) {
        cout << "��" << i + 1 << "��ȷ�����ȣ�" << brightness << endl;
    }

    return 0; // ���������˳�
}

// �������壺����RGB���ص����ȣ����ڼ�Ȩƽ����ģ��ͼ����
double calculateBrightness(int r, int g, int b) {
    // ��ѧ���������ղ��������ؼ�����
    // ���ȹ�ʽ��Y = 0.299R + 0.587G + 0.114B���������۸�֪��
    double result = 0.299 * r + 0.587 * g + 0.114 * b;
    return result;
}