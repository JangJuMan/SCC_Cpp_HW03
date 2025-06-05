#pragma once
#include <algorithm>

template<typename T>
class SimpleVector {
private:
	T* data;
	int currentSize;
	int currentCapacity;

protected:
	void resize(int newCapacity) {
		if (newCapacity <= currentCapacity) {	// 기존 capacity보다 작은 경우 아무것도 하지 않음
			return;
		}
		std::cout << "[Resize] " << currentCapacity << " to " << newCapacity << "\n";

		T* newData = new T[newCapacity];		// 새 동적 배열 할당
		for (int i = 0; i < currentSize; i++) {	// 기존 데이터를 새 배열에 복사
			newData[i] = data[i];
		}
		delete[] data;							// 기존 배열을 삭제
		data = newData;							// 새 배열을 data에 연결
		currentCapacity = newCapacity;			// capacity 증가
	}

public:
	SimpleVector()								// 기본생성자
		: data(new T[10]), 
		currentSize(0), 
		currentCapacity(10) {
		std::cout << "[Base Constructor] SimpleVector() \n"; 
	}
	SimpleVector(int capacity)					// 파라미터 생성자
		: data(new T[capacity]),
		currentSize(0),
		currentCapacity(capacity) {		
		std::cout << "[Parameter Constructor] SimpleVector(" << capacity << ")\n"; 
	}

	SimpleVector(const SimpleVector& other)		// 복사 생성자
		: data(new T[other.currentCapacity]),	// 새 동적배열 할당
		currentSize(other.currentSize), 
		currentCapacity(other.currentCapacity){
		std::cout << "[Copy Constructor] SimpleVector()\n";
		for (int i = 0; i < currentSize; i++) {	// 복사할 other의 data를 새 동적 배열에 복사
			data[i] = other.data[i];
		}
	}

	// 대입 연산자
	SimpleVector& operator=(const SimpleVector& other) {
		if (this == &other) {		// 자기 자신 대입 방지
			return *this;
		}
		std::cout << "[Copy Assignement]SimpleVector()\n";

		// 기존 메모리 해제
		delete[] data;

		// 새 메모리 할당 및 복사
		currentSize = other.currentSize;
		currentCapacity = other.currentCapacity;
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++) {
			data[i] = other.data[i];
		}
		return *this;
	}

	~SimpleVector() {					// 소멸자, 생성한 동적 배열을 삭제
		std::cout << "[Destructor] ~SimpleVector()\n";
		delete[] data;
	}

	T& operator[](int index) const {	// square bracket 접근이 가능하도록
		return data[index];
	}

	void push_back(const T& value) {
		if (currentSize == currentCapacity) {	// 용량이 꽉 찼다면
			resize(currentCapacity + 5);		// 용량 + 5 증가
		}
		data[currentSize++] = value;			// 마지막 element에 value 추가
	}
	void pop_back() {				
		if (currentSize > 0) {			// vector에 element가 들어있는 경우에만
			currentSize--;				// vector size--
		}
	}
	int size() const{					// const로 멤버변수 수정 불가하도록
		return currentSize;
	}
	int capacity() const{				// const로 멤버변수 수정 불가하도록
		return currentCapacity;
	}
	void sortData() {	// data 오름차순 정렬
		std::sort(data, data + currentSize);	// std::greater<T>(), std::less<T>()
	}
};