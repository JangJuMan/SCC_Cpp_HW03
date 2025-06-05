#include <iostream>
#include "SimpleVector.h"

int main() {
    // 기본 생성자 호출
    SimpleVector<int> vec1;
    std::cout << "\tvec1 초기 크기: " << vec1.size() << ", 용량: " << vec1.capacity() << "\n";

    // 용량 지정 생성자 호출
    SimpleVector<int> vec2(5);
    std::cout << "\tvec2 초기 크기: " << vec2.size() << ", 용량: " << vec2.capacity() << "\n";

    // push_back 테스트
    for (int i = 0; i < 8; ++i) {
        vec2.push_back(i * 10);
        std::cout << "\tpush_back: " << i * 10 << " -> size: " << vec2.size() << ", capacity: " << vec2.capacity() << "\n";
    }

    // sort 테스트
    vec2.sortData();
    std::cout << "\t정렬 후:\n";
    for (int i = 0; i < vec2.size(); ++i) {
        std::cout << "\tvec2[" << i << "] = " << vec2[i] << "\n";  // [] 연산자가 없으므로 오류 발생 예정
    }

    // 복사 생성자 테스트
    SimpleVector<int> vec3 = vec2;  // 복사 생성자 호출됨
    std::cout << "\tvec3 복사 완료. 크기: " << vec3.size() << ", 용량: " << vec3.capacity() << "\n";
    for (int i = 0; i < vec3.size(); ++i) {
        std::cout << "\tvec3[" << i << "] = " << vec3[i] << "\n";
    }

    // 복사 대입 연산자 테스트
    SimpleVector<int> vec4(3);
    vec4.push_back(1);
    vec4.push_back(2);

    std::cout << "\t 대입 연산자 호출 전 vec4.size() : " << vec4.size() << "\n";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << "\tvec4[" << i << "] = " << vec4[i] << "\n";
    }

    vec4 = vec3;
    std::cout << "\t 대입 연산자 호출 후 vec4.size() : " << vec4.size() << "\n";
    for (int i = 0; i < vec4.size(); i++) {
        std::cout << "\tvec4[" << i << "] = " << vec4[i] << "\n";
    }


    return 0;
}
