#include <iostream>  // ���������������
using namespace std; // ʹ�ñ�׼�����ռ�

// ʹ��ָ�뽻�������������ĺ���
void swapFloats(float* ptr1, float* ptr2) {
    float temp = *ptr1;  // ��ʱ�洢ptr1ָ����ָ���ֵ
    *ptr1 = *ptr2;       // ��ptr2ָ����ָ���ֵ����ptr1ָ��ı���
    *ptr2 = temp;        // ����ʱ�洢��ֵ(ԭptr1��ֵ)����ptr2ָ��ı���
}

int main_task2() {
    float num1, num2;  // �������������ͱ���

    // ��ȡ�û�����
    cout << "�������һ��������: ";
    cin >> num1;
    cout << "������ڶ���������: ";
    cin >> num2;

    // ��ʾ����ǰ��ֵ
    cout << "\n����ǰ:" << endl;
    cout << "��һ����: " << num1 << endl;
    cout << "�ڶ�����: " << num2 << endl;

    // ���ý����������������������ĵ�ַ
    swapFloats(&num1, &num2);

    // ��ʾ�������ֵ
    cout << "\n������:" << endl;
    cout << "��һ����: " << num1 << endl;
    cout << "�ڶ�����: " << num2 << endl;

    return 0;  // ������������
}