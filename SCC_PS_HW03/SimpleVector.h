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
		if (newCapacity <= currentCapacity) {	// ���� capacity���� ���� ��� �ƹ��͵� ���� ����
			return;
		}
		std::cout << "[Resize] " << currentCapacity << " to " << newCapacity << "\n";

		T* newData = new T[newCapacity];		// �� ���� �迭 �Ҵ�
		for (int i = 0; i < currentSize; i++) {	// ���� �����͸� �� �迭�� ����
			newData[i] = data[i];
		}
		delete[] data;							// ���� �迭�� ����
		data = newData;							// �� �迭�� data�� ����
		currentCapacity = newCapacity;			// capacity ����
	}

public:
	SimpleVector()								// �⺻������
		: data(new T[10]), 
		currentSize(0), 
		currentCapacity(10) {
		std::cout << "[Base Constructor] SimpleVector() \n"; 
	}
	SimpleVector(int capacity)					// �Ķ���� ������
		: data(new T[capacity]),
		currentSize(0),
		currentCapacity(capacity) {		
		std::cout << "[Parameter Constructor] SimpleVector(" << capacity << ")\n"; 
	}

	SimpleVector(const SimpleVector& other)		// ���� ������
		: data(new T[other.currentCapacity]),	// �� �����迭 �Ҵ�
		currentSize(other.currentSize), 
		currentCapacity(other.currentCapacity){
		std::cout << "[Copy Constructor] SimpleVector()\n";
		for (int i = 0; i < currentSize; i++) {	// ������ other�� data�� �� ���� �迭�� ����
			data[i] = other.data[i];
		}
	}

	// ���� ������
	SimpleVector& operator=(const SimpleVector& other) {
		if (this == &other) {		// �ڱ� �ڽ� ���� ����
			return *this;
		}
		std::cout << "[Copy Assignement]SimpleVector()\n";

		// ���� �޸� ����
		delete[] data;

		// �� �޸� �Ҵ� �� ����
		currentSize = other.currentSize;
		currentCapacity = other.currentCapacity;
		data = new T[currentCapacity];
		for (int i = 0; i < currentSize; i++) {
			data[i] = other.data[i];
		}
		return *this;
	}

	~SimpleVector() {					// �Ҹ���, ������ ���� �迭�� ����
		std::cout << "[Destructor] ~SimpleVector()\n";
		delete[] data;
	}

	T& operator[](int index) const {	// square bracket ������ �����ϵ���
		return data[index];
	}

	void push_back(const T& value) {
		if (currentSize == currentCapacity) {	// �뷮�� �� á�ٸ�
			resize(currentCapacity + 5);		// �뷮 + 5 ����
		}
		data[currentSize++] = value;			// ������ element�� value �߰�
	}
	void pop_back() {				
		if (currentSize > 0) {			// vector�� element�� ����ִ� ��쿡��
			currentSize--;				// vector size--
		}
	}
	int size() const{					// const�� ������� ���� �Ұ��ϵ���
		return currentSize;
	}
	int capacity() const{				// const�� ������� ���� �Ұ��ϵ���
		return currentCapacity;
	}
	void sortData() {	// data �������� ����
		std::sort(data, data + currentSize);	// std::greater<T>(), std::less<T>()
	}
};