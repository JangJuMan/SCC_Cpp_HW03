#include <iostream>
#include "SimpleVector.h"

int main() {
    // �⺻ ������ ȣ��
    SimpleVector<int> vec1;
    std::cout << "\tvec1 �ʱ� ũ��: " << vec1.size() << ", �뷮: " << vec1.capacity() << "\n";

    // �뷮 ���� ������ ȣ��
    SimpleVector<int> vec2(5);
    std::cout << "\tvec2 �ʱ� ũ��: " << vec2.size() << ", �뷮: " << vec2.capacity() << "\n";

    // push_back �׽�Ʈ
    for (int i = 0; i < 8; ++i) {
        vec2.push_back(i * 10);
        std::cout << "\tpush_back: " << i * 10 << " -> size: " << vec2.size() << ", capacity: " << vec2.capacity() << "\n";
    }

    // sort �׽�Ʈ
    vec2.sortData();
    std::cout << "\t���� ��:\n";
    for (int i = 0; i < vec2.size(); ++i) {
        std::cout << "\tvec2[" << i << "] = " << vec2[i] << "\n";  // [] �����ڰ� �����Ƿ� ���� �߻� ����
    }

    // ���� ������ �׽�Ʈ
    SimpleVector<int> vec3 = vec2;  // ���� ������ ȣ���
    std::cout << "\tvec3 ���� �Ϸ�. ũ��: " << vec3.size() << ", �뷮: " << vec3.capacity() << "\n";
    for (int i = 0; i < vec3.size(); ++i) {
        std::cout << "\tvec3[" << i << "] = " << vec3[i] << "\n";
    }

    // ���� ���� ������ �׽�Ʈ
    SimpleVector<int> vec4(3);
    vec4.push_back(1);
    vec4.push_back(2);

    std::cout << "\t ���� ������ ȣ�� �� vec4.size() : " << vec4.size() << "\n";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << "\tvec4[" << i << "] = " << vec4[i] << "\n";
    }

    vec4 = vec3;
    std::cout << "\t ���� ������ ȣ�� �� vec4.size() : " << vec4.size() << "\n";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << "\tvec4[" << i << "] = " << vec4[i] << "\n";
    }


    return 0;
}
