/*
 * boosttest.cpp
 *
 *  Created on: 2017. 7. 16.
 *      Author: Tmax
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool Pred(int left, int right) {
	return 3 < right - left;
}

void example1() {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	if (binary_search(v.begin(), v.end(), 20))
		cout << "20 원소가 존재합니다." << endl;
	else
		cout << "20 원소가 존재하지 않습니다." << endl;
}

void example2() {
	vector<int> v;

	v.push_back(40);
	v.push_back(46);
	v.push_back(12);
	v.push_back(80);
	v.push_back(10);
	v.push_back(47);
	v.push_back(30);
	v.push_back(55);
	v.push_back(90);
	v.push_back(53);

	cout << "[v 원본]: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	sort(v.begin(), v.end(), Pred);
	cout << "[v: 정렬]: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	if (binary_search(v.begin(), v.end(), 32, Pred))
		cout << "32 원소가 존재합니다." << endl;
	else
		cout << "32 원소가 존재하지 않습니다." << endl;

	if (binary_search(v.begin(), v.end(), 35, Pred))
		cout << "35 원소가 존재합니다." << endl;
	else
		cout << "35 원소가 존재하지 않습니다." << endl;
}

void example3() {
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(20);

	cout << "[v 원본]: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	//기본 정렬 기준 less 사용
	sort(v.begin(), v.end());
	cout << "[v: less 정렬]: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	//비교 조건자 less 지정(일반 버전 binary_search() 가능)
	cout << "비교 less 찾기: " << binary_search(v.begin(), v.end(), 20, less<int>())
			<< endl;

	//정렬 기준 greater 지정
	sort(v.begin(), v.end(), greater<int>());
	cout << "[v: greater 정렬]: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	//조건자 정렬 기준 greater 지정
	cout << "비교 greater 찾기: "
			<< binary_search(v.begin(), v.end(), 20, greater<int>()) << endl;
}

void example4() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(40);

	vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);
	v3.push_back(60);

	if (includes(v1.begin(), v1.end(), v2.begin(), v2.end()))
		cout << "v2는 v1의 부분 집합" << endl;
	else
		cout << "v2는 v1의 부분 집합 아님" << endl;

	if (includes(v1.begin(), v1.end(), v3.begin(), v3.end()))
		cout << "v3는 v1의 부분 집합" << endl;
	else
		cout << "v3는 v1의 부분 집합 아님" << endl;

	//정렬 기준을 greater<int> 설정
	sort(v1.begin(), v1.end(), greater<int>());
	sort(v2.begin(), v2.end(), greater<int>());
	//비교 기준을 greater<int> 설정
	if (includes(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>()))
		cout << "greater정렬 순차열: v2는 v1의 부분 집합" << endl;
}

void example5() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter_lower, iter_upper;

	iter_lower = lower_bound(v.begin(), v.end(), 30);
	iter_upper = upper_bound(v.begin(), v.end(), 30);

	cout << "30 원소의 순차열 [iter_lower, iter_upper): ";
	for (vector<int>::iterator iter = iter_lower; iter != iter_upper; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example6() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//vector<int>::iterator iter_lower, iter_upper;
	pair<vector<int>::iterator, vector<int>::iterator> iter_pair;

	iter_pair = equal_range(v.begin(), v.end(), 30);

	cout << "30 원소의 순차열 [iter_pair.first, iter_pair.second): ";
	for (vector<int>::iterator iter = iter_pair.first; iter != iter_pair.second;
			++iter)
		cout << *iter << " ";
	cout << endl;
}

void example7() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(60);

	vector<int> v3(10); //size: 10인 vector 생성

	cout << "v1: ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2: ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
	cout << "v3: ";
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;

	vector<int>::iterator iter_end;
	//v1의 순차열과 v2의 순차열을 합병하여 [v3.begin(), iter_end)의 순차열에 저장한다.
	iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	cout << "v1: ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2: ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
	cout << "v3: ";
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
}

void example8() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	v.push_back(20);
	v.push_back(30);
	v.push_back(60);

	cout << "v의 두 구간으로 정렬된 하나의 순차열" << endl;
	cout << "[v.begin(), v.begin()+5) + [v.begin()+5, v.end())" << endl;
	cout << "v: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// 두 구간으로 정렬된 하나의 순차열을 한 구간으로 정렬한다.
	inplace_merge(v.begin(), v.begin() + 5, v.end());

	cout << "v: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example9() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(60);

	vector<int> v3(10); //size: 10인 vector 생성
	vector<int>::iterator iter_end;

	iter_end = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(),
			v3.begin());
	cout << "[v3.begin(), iter_end): ";
	for (vector<int>::iterator iter = v3.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "v3: ";
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
}

void example10() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(60);

	vector<int> v3(10); //size: 10인 vector 생성
	vector<int>::iterator iter_end;

	iter_end = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
			v3.begin());
	cout << "교집합[v3.begin(), iter_end): ";
	for (vector<int>::iterator iter = v3.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;

	iter_end = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(),
			v3.begin());
	cout << "차집합[v3.begin(), iter_end): ";
	for (vector<int>::iterator iter = v3.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;

	iter_end = set_symmetric_difference(v1.begin(), v1.end(), v2.begin(),
			v2.end(), v3.begin());
	cout << "대칭차집합[v3.begin(), iter_end): ";
	for (vector<int>::iterator iter = v3.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example11() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	cout << accumulate(v.begin(), v.end(), 0) << endl;
	cout << accumulate(v.begin(), v.end(), 100) << endl;
}

template<typename T>
struct Plus {
	T operator()(const T& left, const T& right) {
		return left + right;
	}
};

void example12() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << "v: ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// 사용자 합 연산 0+1+2+3+4+5
	//cout << accumulate(v.begin(), v.end(), 0, Plus<int>()) << endl;
	// plus 합 연산 0+1+2+3+4+5
	cout << accumulate(v.begin(), v.end(), 0, plus<int>()) << endl;
	// multiplies 곱 연산 1*1*2*3*4*5
	cout << accumulate(v.begin(), v.end(), 1, multiplies<int>()) << endl;
}

void example13() {
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);

	// 0 + 1*2 + 2*2 + 3*2 + 4*2 + 5*2
	cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0) << endl;
	// 100 + 1*2 + 2*2 + 3*2 + 4*2 + 5*2
	cout << inner_product(v1.begin(), v1.end(), v2.begin(), 100) << endl;
}


void example14() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);
	v2.push_back(2);

	// 0 + 10-2 + 20-2 + 30-2 + 40-2 + 50-2 사용자 함수 사용
	//cout << inner_product(v1.begin(), v1.end(), v2.begin(), 0, Plus, Minus) << endl;
	// 0 + 10-2 + 20-2 + 30-2 + 40-2 + 50-2 STL 함수자 사용
	cout
			<< inner_product(v1.begin(), v1.end(), v2.begin(), 0, plus<int>(),
					minus<int>()) << endl;
}

void example15() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << "v1: ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5); //size: 5인 vector 생성
	vector<int>::iterator iter_end;
	iter_end = adjacent_difference(v1.begin(), v1.end(), v2.begin());

	cout << "v2: ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

void example16() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << "v1: ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5); //size: 5인 vector 생성
	vector<int>::iterator iter_end;
	iter_end = adjacent_difference(v1.begin(), v1.end(), v2.begin(), plus<int>());
	//iter_end = adjacent_difference(v1.begin(), v1.end(), v2.begin(), Plus);

	cout << "v2: ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

void example17() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << "v1: ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5); //size: 5인 vector 생성
	vector<int>::iterator iter_end;
	iter_end = partial_sum(v1.begin(), v1.end(), v2.begin());

	cout << "v2: ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

int Multi(int left, int right) {
	return left * right;
}

void example18() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << "v1: ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5); //size: 5인 vector 생성
	vector<int>::iterator iter_end;
	//iter_end = partial_sum(v1.begin(), v1.end(), v2.begin(), multiplies<int>());
	iter_end = partial_sum(v1.begin(), v1.end(), v2.begin(), Multi);

	cout << "v2: ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

void example19() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter;
	//구간 [v.begin(), v.end())에서 현재 원소와 다음 원소가 같아지는 첫 번째 반복자를 반환
	iter = adjacent_find(v.begin(), v.end());

	if (iter != v.end()) //같은 원소가 없다면 구간의 끝 반복자 반환
		cout << *iter << endl;

	for (; iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

//이항 조건자
bool Pred_1(int a, int b) {
	return abs(b - a) > 10;
}

void example20() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	v.push_back(90);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter;
	iter = adjacent_find(v.begin(), v.end(), Pred_1);

	if (iter != v.end())
		cout << *iter << endl;

	for (; iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example21() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// 구간 [v.begin(), v.end())에서 30 원소의 개수를 반환
	int n = count(v.begin(), v.end(), 30);
	cout << "30의 개수: " << n << endl;
}

bool Pred_2(int n) {
	return 25 < n;
}

void example22() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// 구간 [v.begin(), v.end())에서 25 보다 큰 원소의 개수를 반환
	int n = count_if(v.begin(), v.end(), Pred_2);
	cout << "25보다 큰 원소의 개수 :" << n << endl;
}

void example23() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	//구간 [v1.being(), v1.end)와 구간 [v2.begin(), v2.begin()+3)을 비교 합니다.
	if (equal(v1.begin(), v1.end(), v2.begin()))
		cout << "두 순차열은 같습니다." << endl;
}

void example24() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(21);
	v1.push_back(30);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(33);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	//구간 [v1.being(), v1.end)와 구간 [v2.begin(), v2.begin()+3)을 비교 합니다.
	if (equal(v1.begin(), v1.end(), v2.begin(), Pred))
		cout << "두 순차열은 같습니다." << endl;
}

bool Pred_3(int n) {
	return 35 < n;
}

void example25() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// 구간 [v.begin(), v.end())에서 25 보다 큰 원소의 개수를 반환
	vector<int>::iterator iter;
	iter = find(v.begin(), v.end(), 20);
	if (iter != v.end())
		cout << *iter << "을 찾다!" << endl;

	iter = find_if(v.begin(), v.end(), Pred);
	if (iter != v.end())
		cout << "순차열에서 35보다 큰 첫 번째 원소: " << *iter << endl;
}

void example26() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);

	vector<int>::iterator iter;
	iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (iter != v1.end()) {
		// 일치하는 마지막 순차열의 첫 원소의 반복자 iter
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
		;
	}
}

bool Pred_4(int left, int right) {
	return left <= right;
}

void example27() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(15);
	v1.push_back(20);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(10);
	v1.push_back(11);
	v1.push_back(12);
	v1.push_back(80);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(15);
	v2.push_back(25);

	vector<int>::iterator iter;
	iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred);
	if (iter != v1.end()) {
		// 일치하는 마지막 순차열의 첫 원소의 반복자 iter
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
		;
	}
}

void example28() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(40);
	v2.push_back(80);
	v2.push_back(20);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	vector<int>::iterator iter;
	iter = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (iter != v1.end())
		cout << "iter : " << *iter << endl;
}

bool Pred_5(int left, int right) {
	return left > right;
}

void example29() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(40);
	v2.push_back(80);
	v2.push_back(20);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	vector<int>::iterator iter;
	iter = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred_5);
	if (iter != v1.end())
		cout << "iter : " << *iter << endl;
}

void Print(int n) {
	cout << n << " ";
}

void example30() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for_each(v.begin(), v.begin() + 2, Print);
	cout << endl;
	for_each(v.begin(), v.begin() + 4, Print);
	cout << endl;
	//[v.begin(), v.end()) 구간의 원소 출력
	for_each(v.begin(), v.end(), Print);
	cout << endl;
}

class PrintFunctor {
	char fmt;
public:
	explicit PrintFunctor(char c = ' ') :
			fmt(c) {
	}
	void operator ()(int n) const {
		cout << n << fmt;
	}
};

void example31() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for_each(v.begin(), v.end(), PrintFunctor()); // 원소의 구분을 ' '로
	cout << endl;
	for_each(v.begin(), v.end(), PrintFunctor(',')); // 원소의 구분을 ','로
	cout << endl;
	for_each(v.begin(), v.end(), PrintFunctor('\n')); // 원소의 구분을 '\n'로
	cout << endl;
}

void example32() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(50);

	vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);
	v3.push_back(30);

	if (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()))
		cout << "v1 < v2" << endl;
	else
		cout << "v1 >= v2" << endl;

	if (lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end()))
		cout << "v1 < v3" << endl;
	else
		cout << "v1 >= v3" << endl;
}

template<typename T>
struct Less {
	bool operator()(const T& left, const T& right) const {
		return left < right;
	}
};

void example33() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(25);
	v2.push_back(30);

	if (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(),
			less<int>()))
		cout << "기준 less v1과 v2의 비교: true" << endl;
	else
		cout << "기준 less v1과 v2의 비교: false" << endl;

	if (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(),
			greater<int>()))
		cout << "기준 greater v1과 v2의 비교: true" << endl;
	else
		cout << "기준 greater v1과 v2의 비교: false" << endl;

	if (lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(),
			Less<int>()))
		cout << "사용자 기준 Less v1과 v2의 비교: true" << endl;
	else
		cout << "사용자 기준 Less v1과 v2의 비교: false" << endl;
}

class Point {
	int x, y;
public:
	explicit Point(int _x = 0, int _y = 0) :
			x(_x), y(_y) {
	}
	int GetX() const {
		return x;
	}
	int GetY() const {
		return y;
	}
	void Print() const {
		cout << '(' << x << ',' << y << ')' << endl;
	}
};
bool XCompare(const Point& left, const Point& right) {
	return left.GetX() < right.GetX();
}
bool YCompare(const Point& left, const Point& right) {
	return left.GetY() < right.GetY();
}

void example34() {
	int a = 10, b = 20;
	int r;

	r = max(a, b);
	cout << "max: " << r << endl;
	r = min(a, b);
	cout << "min: " << r << endl;

	Point pt1(5, 8), pt2(3, 9);
	Point pt3;

	pt3 = max(pt1, pt2, XCompare);
	cout << "x max: ";
	pt3.Print();
	pt3 = max(pt1, pt2, YCompare);
	cout << "y max: ";
	pt3.Print();
}

void example35() {
	vector<int> v;

	v.push_back(30);
	v.push_back(10);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	vector<int>::iterator iter;
	iter = max_element(v.begin(), v.end());
	cout << *iter << endl;

	iter = min_element(v.begin(), v.end());
	cout << *iter << endl;
}

class Point1 {
	int x, y;
public:
	explicit Point1(int _x = 0, int _y = 0) :
			x(_x), y(_y) {
	}
	int GetX() const {
		return x;
	}
	int GetY() const {
		return y;
	}
	void Print() const {
		cout << '(' << x << ',' << y << ')' << endl;
	}
};
bool Compare(const Point& left, const Point& right) {
	if (left.GetX() < right.GetX())
		return true;
	else if (left.GetX() > right.GetX())
		return false;
	else
		return left.GetY() < right.GetY();
}

void example36() {
	vector<Point> v;

	v.push_back(Point(3, 2));
	v.push_back(Point(2, 5));
	v.push_back(Point(1, 5));
	v.push_back(Point(3, 3));
	v.push_back(Point(3, 2));

	vector<Point>::iterator iter;
	iter = max_element(v.begin(), v.end(), Compare);
	cout << "max: ";
	iter->Print(); //반복자가 가리키는 객체의 멤버는 -> 연산자로 접근
	cout << "max: ";
	(*iter).Print(); //위와 같음
}

void example37() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	v2.push_back(80);
	v2.push_back(90);

	pair<vector<int>::iterator, vector<int>::iterator> iter_pair;
	iter_pair = mismatch(v1.begin(), v1.end(), v2.begin());

	cout << "v1: " << *iter_pair.first << ", " << "v2: " << *iter_pair.second
			<< endl;
}

bool Pred4(int left, int right) {
	return abs(right - left) <= 5;
}

void example38() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(11);
	v2.push_back(25);
	v2.push_back(33);
	v2.push_back(46);
	v2.push_back(50);

	pair<vector<int>::iterator, vector<int>::iterator> iter_pair;
	iter_pair = mismatch(v1.begin(), v1.end(), v2.begin(), Pred4);

	cout << "v1: " << *iter_pair.first << ", " << "v2: " << *iter_pair.second
			<< endl;
}

void example39() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(70);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(30);
	v2.push_back(40);
	v2.push_back(50);

	vector<int>::iterator iter;
	iter = search(v1.begin(), v1.end(), v2.begin(), v2.end());
	if (iter != v1.end()) {
		// 일치하는 첫 번째 순차열의 첫 원소의 반복자 iter
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
		;
	}
}

void example40() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter;
	iter = search_n(v.begin(), v.end(), 3, 30);
	if (iter != v.end()) {
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
		;
	}
}

bool Pred5(int left, int right) {
	return abs(right - left) <= 5;
}

void example41() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(32);
	v.push_back(28);
	v.push_back(33);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter;
	iter = search_n(v.begin(), v.end(), 3, 30, Pred);
	if (iter != v.end()) {
		cout << "iter : " << *iter << endl;
		cout << "iter-1 : " << *(iter - 1) << endl;
		cout << "iter+1 : " << *(iter + 1) << endl;
		;
	}
}

void example42() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2(5); //size 5인 vector 생성

	vector<int>::iterator iter;
	// 구간 [v1.begin(), v1.end())의 모든 원소를 [v2.begin(), iter)의 순차열로 복사.
	iter = copy(v1.begin(), v1.end(), v2.begin());
	cout << "v2 마지막 원소: " << *(iter - 1) << endl;

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

void example43() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2(10); //size 10인 vector 생성

	vector<int>::iterator iter;
	// 구간 [v1.begin(), v1.end())의 모든 원소를
	// [iter, v2.end())의 순차열로 마지막 원소부터 복사.
	iter = copy_backward(v1.begin(), v1.end(), v2.end());
	cout << "v2 첫 원소: " << *iter << endl;

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

void example44() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	// 구간 [v.begin(), v.end())의 모든 원소를 0으로 채운다.
	fill(v.begin(), v.end(), 0);
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// 구간 [v.begin(), v.begin()+3)의 모든 원소를 55로 채운다.
	fill_n(v.begin(), 3, 55);
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void Func(int& r) {
	r += 5;
}

void example45() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	for_each(v.begin(), v.end(), Func);
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

class Accumulation {
	int total;
public:
	explicit Accumulation(int init = 0) :
			total(init) {
	}
	void operator()(int& r) {
		total += r;
		r = total;
	}
};

void example46() {
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	//[v.begin(), v.end()) 모든 원소를 초기값 0부터 시작하여 *p += *(p-1)를 적용합니다.
	for_each(v.begin(), v.end(), Accumulation(0));
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

class Integer {
	int data;
public:
	explicit Integer(int d = 0) :
			data(d) {
	}
	int operator()() {
		return data++;
	}
};

void example47() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// [v.begin(), v.end())의 원소를 1~5로 채운다.
	generate(v.begin(), v.end(), Integer(1));
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// [v.begin(), v.end())의 원소를 100~104로 채운다.
	generate(v.begin(), v.end(), Integer(100));
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// [v.begin(), v.begin()+3)의 원소를 1~3로 채운다.
	generate_n(v.begin(), 3, Integer(1));
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example48() {
	int a = 10, b = 20;

	vector<int> v;
	v.push_back(10);
	v.push_back(20);

	cout << "a= " << a << ", " << "b= " << b << endl;
	swap(a, b);
	cout << "a= " << a << ", " << "b= " << b << endl;

	vector<int>::iterator p = v.begin();
	vector<int>::iterator q = v.begin() + 1;

	cout << "v[0]= " << v[0] << ", " << "v[1]= " << v[1] << endl;
	iter_swap(p, q);
	cout << "v[0]= " << v[0] << ", " << "v[1]= " << v[1] << endl;
}

void example49() {

	vector<int> v1;
	v1.push_back(10);
	v1.push_back(30);
	v1.push_back(50);
	v1.push_back(60);
	v1.push_back(80);

	vector<int> v2;
	v2.push_back(20);
	v2.push_back(40);
	v2.push_back(70);

	vector<int> v3(10); //size 10인 vector 생성
	vector<int>::iterator iter_end;
	iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
	cout << "v3 : ";
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
	cout << "v3(합병 순차열): " << *v3.begin() << '~' << *(iter_end - 1) << endl;
}

template<typename T>
struct Greater {
	bool operator()(const T& left, const T& right) const {
		return left > right;
	}
};

void example50() {
	vector<int> v1;
	v1.push_back(80);
	v1.push_back(60);
	v1.push_back(50);
	v1.push_back(30);
	v1.push_back(10);

	vector<int> v2;
	v2.push_back(70);
	v2.push_back(40);
	v2.push_back(20);

	vector<int> v3(10); //size 10인 vector 생성
	vector<int>::iterator iter_end;
	iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), greater<int>() );
	//iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin(), Greater<int>());

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
	cout << "v3 : ";
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
	cout << "v3(합병 순차열): " << *v3.begin() << '~' << *(iter_end - 1) << endl;
}

void example51() {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(30);
	v.push_back(30);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	replace(v.begin(), v.end(), 30, 0);
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

bool Pred6(int n) {
	return 30 <= n && n <= 50;
}

void example52() {
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);
	v.push_back(70);
	v.push_back(80);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	replace_if(v.begin(), v.end(), Pred, 0);
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

bool Pred7(int n) {
	return n <= 30;
}

void example53() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(30);
	v1.push_back(50);

	vector<int> v2(6); //size: 6인 vector 생성
	vector<int> v3(6); //size: 6인 vector 생성

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
	cout << "v3 : ";
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;

	vector<int>::iterator iter_end;
	// 30인 원소를 모두 0으로 변환하여 [v2.begin(), iter_end) 순차열에 저장한다.
	iter_end = replace_copy(v1.begin(), v1.end(), v2.begin(), 30, 0);
	// 30이하인 원소를 모두 0으로 변환하여 [v3.begin(), iter_end) 순차열에 저장한다.
	iter_end = replace_copy_if(v1.begin(), v1.end(), v3.begin(), Pred, 0);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
	cout << "v3 : ";
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
}

void example54() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(11);
	v2.push_back(22);
	v2.push_back(33);
	v2.push_back(44);
	v2.push_back(55);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	swap_ranges(v1.begin(), v1.end(), v2.begin());

	cout << endl << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

int Func2(int n) {
	return n + 5;
}
void example55() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	transform(v.begin(), v.end(), v.begin(), Func2);
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

int Func3(int n) {
	return n + 5;
}

void example56() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2(10); //size: 10 vector 생성

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int>::iterator iter_end;
	iter_end = transform(v1.begin(), v1.end(), v2.begin(), Func);
	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
	cout << "[v2.begin(), iter_end) 순차열: " << *v2.begin() << " ... "
			<< *(iter_end - 1) << endl;
}

void example57() {

	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	vector<int> v3(5); //size: 5인 vector 생성

	vector<int>::iterator iter_end;
	iter_end = transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
	//iter_end = transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), Plus);
	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		//cout << v2[i] << " ";
	cout << endl;
	cout << "v3 : ";
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
	cout << "[v3.begin(), iter_end) 순차열: ";
	for (vector<int>::iterator iter = v3.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example58() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter_end;
	iter_end = remove(v.begin(), v.end(), 30);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	cout << "remove 후 [v.begin(), iter_end) 순차열: ";
	for (vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example59() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter_end;
	iter_end = remove(v.begin(), v.end(), 30);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// 구간 [iter_end, v.end())의 원소를 실제 제거(삭제)합니다.
	v.erase(iter_end, v.end());
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

bool Pred8(int n) {
	return 30 <= n && n <= 40;
}

void example60() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter_end;
	iter_end = remove_if(v.begin(), v.end(), Pred8);

	cout << "[v.begin(), iter_end) : ";
	for (vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example61() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2(5);
	vector<int>::iterator iter_end;
	iter_end = remove_copy(v1.begin(), v1.end(), v2.begin(), 30);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;
	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	cout << "[v2.begin(), iter_end) : ";
	for (vector<int>::iterator iter = v2.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example62() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter_end;
	iter_end = unique(v.begin(), v.end());

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "[v.begin(), iter_end) : ";
	for (vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example63() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(30);
	v.push_back(40);
	v.push_back(40);
	v.push_back(30);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter_end;
	iter_end = unique(v.begin(), v.end());

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "[v.begin(), iter_end) : ";
	for (vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

bool Pred7(int left, int right) {
	return abs(right - left) < 10;
}

void example64() {
	vector<int> v;
	v.push_back(10);
	v.push_back(11);
	v.push_back(30);
	v.push_back(32);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter_end;
	iter_end = unique(v.begin(), v.end(), Pred);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "[v.begin(), iter_end) : ";
	for (vector<int>::iterator iter = v.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example65() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
	cout << next_permutation(v.begin(), v.end()) << endl;
	;
	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
	cout << next_permutation(v.begin(), v.end()) << endl;
	;
	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
	cout << next_permutation(v.begin(), v.end()) << endl;
	;
	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
	cout << next_permutation(v.begin(), v.end()) << endl;
	;
	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
	cout << next_permutation(v.begin(), v.end()) << endl;
	;
	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
	// 마지막 순열이므로 next_permutation()은 false 반환
	cout << next_permutation(v.begin(), v.end()) << endl;
	;
	cout << "v : " << v[0] << " " << v[1] << " " << v[2] << endl;
}

bool Pred10(int n) {
	return n < 40;
}

void example66() {
	vector<int> v;
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(60);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator iter_sep;
	// 40 원소를 기준으로 미만과 이상을 분류한다.
	iter_sep = partition(v.begin(), v.end(), Pred10);

	cout << "40미만의 순차열: ";
	for (vector<int>::iterator iter = v.begin(); iter != iter_sep; ++iter)
		cout << *iter << " ";
	cout << endl;
	cout << "40이상의 순차열: ";
	for (vector<int>::iterator iter = iter_sep; iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example67() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	// [v.begin(), v.end()) 순차열 뒤집기.
	reverse(v.begin(), v.end());
	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example68() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5); //size : 5 인 vector 생성 (덮어쓰기이므로)

	vector<int>::iterator iter_end;
	iter_end = reverse_copy(v1.begin(), v1.end(), v2.begin());

	cout << "v2 : ";
	for (vector<int>::iterator iter = v2.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example69() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	vector<int>::iterator middle = v.begin() + 2;
	// 모든 원소를 왼쪽으로 2만큼씩 회전한다.
	rotate(v.begin(), middle, v.end());

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example70() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5);
	vector<int>::iterator middle = v1.begin() + 2;
	vector<int>::iterator iter_end;
	// 모든 원소를 왼쪽으로 2만큼씩 회전하여 [v2.begin(), iter_end) 순차열에 복사한다.
	iter_end = rotate_copy(v1.begin(), middle, v1.end(), v2.begin());

	cout << "v2 : ";
	for (vector<int>::iterator iter = v2.begin(); iter != iter_end; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example71() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	make_heap(v.begin(), v.end());
	cout << "v[힙 생성] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example72() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	make_heap(v.begin(), v.end());
	cout << "v[힙 생성] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.push_back(35);
	cout << "v 순차열에 35 추가 : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	push_heap(v.begin(), v.end());
	cout << "v[힙 추가] 연산 수행 :";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example73() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	make_heap(v.begin(), v.end());
	cout << "v[힙 생성] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	pop_heap(v.begin(), v.end());
	cout << "v[힙 삭제] 연산 수행 :";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example74() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	v.push_back(60);

	make_heap(v.begin(), v.end());
	cout << "v[힙 생성] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	sort_heap(v.begin(), v.end());
	cout << "v[힙 정렬] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example75() {
	vector<int> v;
	v.push_back(40);
	v.push_back(10);
	v.push_back(50);
	v.push_back(30);
	v.push_back(20);
	v.push_back(60);

	//부모 노드가 모든 자식 노드보다 작은 힙을 생성한다.
	make_heap(v.begin(), v.end(), greater<int>());
	cout << "v[힙 생성] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.push_back(35);
	push_heap(v.begin(), v.end(), greater<int>());
	cout << "v[힙 추가] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	sort_heap(v.begin(), v.end(), greater<int>());
	cout << "v[힙 정렬] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example76() {
	vector<int> v;

	for (int i = 0; i < 100; ++i)
		v.push_back(rand() % 1000);

	nth_element(v.begin(), v.begin() + 20, v.end());

	cout << "v[상위 20개] : ";
	for (vector<int>::size_type i = 0; i < 20; ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "v[하위 80개] : ";
	for (vector<int>::size_type i = 20; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example77() {
	vector<int> v;

	for (int i = 0; i < 100; ++i)
		v.push_back(rand() % 1000);

	cout << "v[정렬 전] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	sort(v.begin(), v.end());
	cout << "v[정렬 less] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	//sort(v.begin(), v.end(), Greater);
	sort(v.begin(), v.end(), greater<int>() );
	cout << "v[정렬 greater] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example78() {
	vector<int> v;

	v.push_back(30);
	v.push_back(50);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(10);
	v.push_back(40);

	cout << "v[정렬 전] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	stable_sort(v.begin(), v.end());
	cout << "v[정렬 less] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	//stable_sort(v.begin(), v.end(), Greater);
	sort(v.begin(), v.end(), greater<int>() );
	cout << "v[정렬 greater] : ";
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example79() {
	vector<int> v;

	for (int i = 0; i < 100; ++i)
		v.push_back(rand() % 1000);

	partial_sort(v.begin(), v.begin() + 20, v.end());

	cout << "v[상위 정렬 20개] : ";
	for (vector<int>::size_type i = 0; i < 20; ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "v[하위 80개] : ";
	for (vector<int>::size_type i = 20; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example80() {
	vector<int> v1;

	for (int i = 0; i < 100; ++i)
		v1.push_back(rand() % 1000);

	cout << "[v1 정렬 전] :  ";
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(20); //size : 20의 vector 생성

	partial_sort_copy(v1.begin(), v1.end(), v2.begin(), v2.end());
	cout << "[v2 less]:  ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	partial_sort_copy(v1.begin(), v1.end(), v2.begin(), v2.end(),
			greater<int>());
	cout << "[v2 greater] :  ";
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

struct LessFunctor // 1. 함수 객체 조건자
{
	bool operator()(int left, int right) const {
		return left < right;
	}
};

bool LessFun(int left, int right) // 2. 함수 조건자
		{
	return left < right;
}

void example81() {

	bool (*LessPtr)(int, int) = LessFun; // 3. 함수 포인터 조건자

	LessFunctor lessFunctor;

	//모두 bool 형식을 반환
	//1. 함수 객체로 10과 20을 비교
	cout << lessFunctor(10, 20) << endl;

	//2. 함수로 10과 20을 비교
	cout << LessFun(10, 20) << endl;

	//3. 함수 포인터로 10과 20을 비교
	cout << LessPtr(10, 20) << endl;
}

template<typename T>
struct Plus1 {
	T operator( )(const T& left, const T& right) const {
		return left + right;
	}
};

void example82() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);

	vector<int> v3(3); //size: 3인 vector 생성

	//STL 조건자 plus<int> 사용
	//transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
	//사용자 정의 조건자 Plus<int> 사용
	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), Plus1<int>());

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	cout << "v2 : ";
	for (vector<int>::size_type i = 0; i < v2.size(); i++)
		cout << v2[i] << " ";
	cout << endl;

	cout << "v3 : ";
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;
}

void example83() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	vector<int> v3(3); //size: 3인 vector 생성
	//STL 조건자 plus<int> 사용
	transform(v1.begin(), v1.end(), v3.begin(),
			binder1st<plus<int> >(plus<int>(), 100));
	//사용자 정의 조건자 Plus<int> 사용
	//transform(v1.begin(), v1.end(), v3.begin(), binder1st< Plus<int> > (Plus<int>(), 100) );

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	cout << "v3 : ";
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;
}

template<typename T>
struct Plus3 {
	typedef T first_argument_type;
	typedef T second_argument_type;
	typedef T result_type;

	T operator( )(const T& left, const T& right) const {
		return left + right;
	}
};

void example84() {

	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	vector<int> v3(3); //size: 3인 vector 생성
	//STL 조건자 plus<int> 사용
	//transform(v1.begin(), v1.end(), v3.begin(), binder1st< plus<int> > (plus<int>(), 100));
	//사용자 정의 조건자 Plus<int> 사용
	transform(v1.begin(), v1.end(), v3.begin(),
			binder1st<Plus3<int> >(Plus3<int>(), 100));

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	cout << "v3 : ";
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;
}

template<typename T>
struct Plus4: public binary_function<T, T, T> {
	T operator( )(const T& left, const T& right) const {
		return left + right;
	}
};

void example85() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	vector<int> v3(3); //size: 3인 vector 생성
	//STL 조건자 plus<int> 사용
	//transform(v1.begin(), v1.end(), v3.begin(), binder1st< plus<int> > (plus<int>(), 100));
	//사용자 정의 조건자 Plus<int> 사용
	transform(v1.begin(), v1.end(), v3.begin(),
			binder1st<Plus4<int> >(Plus4<int>(), 100));

	cout << "v1 : ";
	for (vector<int>::size_type i = 0; i < v1.size(); i++)
		cout << v1[i] << " ";
	cout << endl;

	cout << "v3 : ";
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;
}

void example86() {
	plus<int> oPlus;
	//1. oPlus 객체로 10, 20 더하기. 암묵적 호출
	cout << oPlus(10, 20) << endl;
	//2. oPlus 객체로 10, 20 더하기. 명시적 호출
	cout << oPlus.operator()(10, 20) << endl;

	//3. 임시 객체로 10, 20 더하기. 암묵적 호출(일반적인 사용)
	cout << plus<int>()(10, 20) << endl;
	//4. 임시 객체로 10, 20 더하기. 명시적 호출
	cout << plus<int>().operator()(10, 20) << endl;
}

void example87() {
	Plus4<int> oPlus;
	cout << oPlus(10, 20) << endl;
	cout << oPlus.operator()(10, 20) << endl;

	//cout << Plus<int>()(10, 20) << endl;
	// cout << Plus<int>().operator()(10, 20) << endl;
}

void example88() {
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);

	vector<int> v3(5); //size: 5인 vector 생성

	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
	cout << "v3(v1+v2) : ";
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;

	transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), multiplies<int>());
	cout << "v3(v1*v2) : ";
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;

	transform(v1.begin(), v1.end(), v3.begin(), negate<int>());
	cout << "v3(-v1) : ";
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;

	adjacent_difference(v1.begin(), v1.end(), v3.begin(), minus<int>());
	cout << "v3(v1 인접 원소와의 차) : ";
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;

	partial_sum(v1.begin(), v1.end(), v3.begin(), multiplies<int>());
	cout << "v3(v1 원소의 곱 누적) : ";
	for (vector<int>::size_type i = 0; i < v3.size(); i++)
		cout << v3[i] << " ";
	cout << endl;

	cout << "v1 모든 원소의 곱: "
			<< accumulate(v1.begin(), v1.end(), 1, multiplies<int>()) << endl;
}

void example89() {
	less<int> oLess;
	//1. oLess 객체로 10, 20을 비교 true. 암묵적 호출
	cout << oLess(10, 20) << endl;
	//2. oLess 객체로 10, 20을 비교 true.  명시적 호출
	cout << oLess.operator()(10, 20) << endl;

	//3. 임시 객체로 10, 20을 비교 true. 암묵적 호출(일반적인 사용)
	cout << less<int>()(10, 20) << endl;
	//4. 임시 객체로 10, 20을 비교 true. 명시적 호출
	cout << less<int>().operator()(10, 20) << endl;
}

template<typename T>
struct Less1: public binary_function<T, T, bool> //어댑터 적용이 가능하도록.
{
	bool operator( )(const T& left, const T& right) const {
		return left < right;
	}
};
void example90() {
	Less1<int> oLess;
	cout << oLess(10, 20) << endl;
	cout << oLess.operator()(10, 20) << endl;

	cout << Less<int>()(10, 20) << endl;
	cout << Less<int>().operator()(10, 20) << endl;
}

void example91() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	cout << "20 보다 작은 원소의 개수: "
			<< count_if(v.begin(), v.end(),
					bind2nd<less<int> >(less<int>(), 20)) << endl;
	cout << "20 보다 작거나 같은 원소의 개수: "
			<< count_if(v.begin(), v.end(),
					bind2nd<less_equal<int> >(less_equal<int>(), 20)) << endl;
	cout << "20 보다 큰 원소의 개수: "
			<< count_if(v.begin(), v.end(),
					bind2nd<greater<int> >(greater<int>(), 20)) << endl;
	cout << "20 보다 크거나 같은 원소의 개수: "
			<< count_if(v.begin(), v.end(),
					bind2nd<greater_equal<int> >(greater_equal<int>(), 20))
			<< endl;
	cout << "20과 같은 원소의 개수: "
			<< count_if(v.begin(), v.end(),
					bind2nd<equal_to<int> >(equal_to<int>(), 20)) << endl;
	cout << "20과 다른 원소의 개수: "
			<< count_if(v.begin(), v.end(),
					bind2nd<not_equal_to<int> >(not_equal_to<int>(), 20))
			<< endl;
}

template<typename T>
struct Logical_and: public binary_function<T, T, bool> //어댑터 적용이 가능하도록.
{
	bool operator( )(const T& left, const T& right) const {
		return left && right;
	}
};

void example92() {
	int n = 30;
	logical_and<bool> oAnd;
	//1. oAnd 객체로 10 < n < 50 인가? true. 암묵적 호출
	cout << oAnd(greater<int>()(n, 10), less<int>()(n, 50)) << endl;
	//2. oAnd 객체로 10 < n < 50 인가? true.  명시적 호출
	cout << oAnd.operator()(greater<int>()(n, 10), less<int>()(n, 50)) << endl;

	//3. 임시 객체로 10 < n < 50 인가? true. 암묵적 호출(일반적인 사용)
	cout << logical_and<bool>()(greater<int>()(n, 10), less<int>()(n, 50))
			<< endl;
	//4. 임시 객체로 10 < n < 50 인가? true. 명시적 호출
	cout
			<< logical_and<bool>().operator()(greater<int>()(n, 10),
					less<int>()(n, 50)) << endl;
}

void example93() {
	//less의 첫 인자를 10으로 고정한 단항 조건자 binder 생성.
	binder1st<less<int> > binder = bind1st(less<int>(), 10);

	// binder는 첫 번째 인자를 10으로 고정한 less.
	cout << binder(5) << ':' << less<int>()(10, 5) << endl; // 두 문장이 동일합니다.
	cout << binder(10) << ':' << less<int>()(10, 10) << endl; // 두 문장이 동일합니다.
	cout << binder(20) << ':' << less<int>()(10, 20) << endl; // 두 문장이 동일합니다.
	cout << "=====위와 같음=====" << endl;
	// 임시 객체 사용
	cout << bind1st(less<int>(), 10)(5) << ':' << less<int>()(10, 5) << endl;
	cout << bind1st(less<int>(), 10)(10) << ':' << less<int>()(10, 10) << endl;
	cout << bind1st(less<int>(), 10)(20) << ':' << less<int>()(10, 20) << endl;
}

void example94() {
	binder2nd<less<int> > binder = bind2nd(less<int>(), 10);

	// binder는 두 번째 인자를 10으로 고정한 less.
	cout << binder(5) << ':' << less<int>()(5, 10) << endl; // 두 문장이 동일합니다.
	cout << binder(10) << ':' << less<int>()(10, 10) << endl; // 두 문장이 동일합니다.
	cout << binder(20) << ':' << less<int>()(20, 10) << endl; // 두 문장이 동일합니다.
	cout << "=====위와 같음=====" << endl;
	// 임시 객체 사용.
	cout << bind2nd(less<int>(), 10)(5) << ':' << less<int>()(5, 10) << endl;
	cout << bind2nd(less<int>(), 10)(10) << ':' << less<int>()(10, 10) << endl;
	cout << bind2nd(less<int>(), 10)(20) << ':' << less<int>()(20, 10) << endl;
}

void example95() {
	less<int> oLess;
	binary_negate<less<int> > negate = not2(less<int>());

	cout << negate(5, 10) << ':' << not2(oLess)(5, 10) << ':'
			<< not2(less<int>())(5, 10) << endl; //모두 같다.
	cout << negate(10, 10) << ':' << not2(oLess)(10, 10) << ':'
			<< not2(less<int>())(10, 10) << endl; //모두 같다.
	cout << negate(20, 10) << ':' << not2(oLess)(20, 10) << ':'
			<< not2(less<int>())(20, 10) << endl; //모두 같다.
}

void example96() {
	binder2nd<less<int> > binder = bind2nd(less<int>(), 10);
	unary_negate<binder2nd<less<int> > > negate = not1(binder);

	cout << negate(5) << ':' << not1(binder)(5) << ':'
			<< not1(bind2nd(less<int>(), 10))(5) << endl; //모두 같다.
	cout << negate(10) << ':' << not1(binder)(10) << ':'
			<< not1(bind2nd(less<int>(), 10))(10) << endl; //모두 같다.
	cout << negate(20) << ':' << not1(binder)(20) << ':'
			<< not1(bind2nd(less<int>(), 10))(20) << endl; //모두 같다.
}

bool Pred9(int n) {
	return 30 <= n && n <= 40;
}

void example97() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	cout << "30이상 40이하의 원소 개수: " << count_if(v.begin(), v.end(), Pred9) << endl;
	//다음은 에러입니다. not1은 어댑터로 함수 객체에 argument_type, result_type가 정의되어 있어야 함!
	cout << "30이상 40이하가 아닌 원소 개수: " << count_if(v.begin(), v.end(), not1(Pred9))
			<< endl;
}

void example98() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	cout << "30이상 40이하의 원소 개수: " << count_if(v.begin(), v.end(), Pred9) << endl;
	//가능~!
	cout << "30이상 40이하가 아닌 원소 개수: "
			<< count_if(v.begin(), v.end(), not1(ptr_fun(Pred9))) << endl;
}

template<typename RType, typename AType>
class Ptr_fun_class: public unary_function<AType, RType> {
	RType (*pf)(AType);
public:
	Ptr_fun_class(RType (*_pf)(AType)) :
			pf(_pf) {
	}
	RType operator()(AType n) const {
		return pf(n);
	}
};
// 일반 함수를 함수 객체로 변환하는 ptr_fun() 함수
template<typename RType, typename AType>
Ptr_fun_class<RType, AType> Ptr_fun(RType (*pf)(AType)) {
	return Ptr_fun_class<RType, AType>(pf);
}

void example99() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	cout << "v : ";
	for (vector<int>::size_type i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;

	cout << "30이상 40이하의 원소 개수: " << count_if(v.begin(), v.end(), Pred) << endl;
	//가능~!
	//cout<<"30이상 40이하가 아닌 원소 개수: " << count_if(v.begin(), v.end(), not1( Ptr_fun(Pred) ) ) << endl;
}

class Point3 {
	int x;
	int y;
public:
	explicit Point3(int _x = 0, int _y = 0) :
			x(_x), y(_y) {
	}
	void Print() const {
		cout << x << ',' << y << endl;
	}
	int GetX() const {
		return x;
	}
	int GetY() const {
		return y;
	}
};

void example100() {
	vector<Point> v;
	v.push_back(Point(1, 1));
	v.push_back(Point(2, 2));
	v.push_back(Point(3, 3));
	v.push_back(Point(4, 4));
	v.push_back(Point(5, 5));

	// 호출 불가능
	//for_each(v.begin(), v.end(), &Point::Print );
	// 호출 가능
	for_each(v.begin(), v.end(), mem_fun_ref(&Point::Print));
}

template<typename RType, typename CType>
class Mem_fun_ref_class: public unary_function<CType, RType> {
	RType (CType::*pf)() const;
public:
	Mem_fun_ref_class(RType (CType::*_pf)() const) :
			pf(_pf) {
	}
	RType operator()(const CType& o) const {
		return (o.*pf)();
	}
};
// 어댑터 함수 : 멤버 함수를 주소를 저장하는 함수 객체를 반환
template<typename RType, typename CType>
Mem_fun_ref_class<RType, CType> Mem_fun_ref(RType (CType::*pf)() const) {
	return Mem_fun_ref_class<RType, CType>(pf);
}

void example101() {
	vector<Point> v;
	v.push_back(Point(1, 1));
	v.push_back(Point(2, 2));
	v.push_back(Point(3, 3));
	v.push_back(Point(4, 4));
	v.push_back(Point(5, 5));

	for_each(v.begin(), v.end(), Mem_fun_ref(&Point::Print));
}

template<typename RType, typename CType>
class Mem_fun_class: public unary_function<CType, RType> {
	RType (CType::*pf)() const;
public:
	Mem_fun_class(RType (CType::*_pf)() const) :
			pf(_pf) {
	}
	RType operator()(const CType* p) const {
		return (p->*pf)();
	}
};
// 어댑터 함수 : 멤버 함수를 주소를 저장하는 함수 객체를 반환
template<typename RType, typename CType>
Mem_fun_class<RType, CType> Mem_fun(RType (CType::*pf)() const) {
	return Mem_fun_class<RType, CType>(pf);
}

void example102() {
	vector<Point*> v;
	v.push_back(new Point(1, 1));
	v.push_back(new Point(2, 2));
	v.push_back(new Point(3, 3));
	v.push_back(new Point(4, 4));
	v.push_back(new Point(5, 5));

	//STL 버전
	for_each(v.begin(), v.end(), mem_fun(&Point::Print));
	//사용자 버전
	for_each(v.begin(), v.end(), Mem_fun(&Point::Print));
}

int main() {
	cout << "aaa" << endl;
}

