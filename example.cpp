#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include <vector>
#include <deque>
#include <stack>

using namespace std;
using namespace boost::unit_test;
namespace tt = boost::test_tools;

void example1()
{
	vector<int> v; // 정수를 저장하는 컨테이너 v 생성

	v.push_back(10); // v에 정수 추가
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	BOOST_CHECK(v[0] == 10);
	BOOST_CHECK(v[1] == 20);
	BOOST_CHECK(v[2] == 30);
	BOOST_CHECK(v[3] == 40);
	BOOST_CHECK(v[4] == 50);
}

void example2()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	int index = 0;
	vector<int>::iterator iter; // 반복자 생성(아직 원소를 가리키지 않음)
	for (iter = v.begin(); iter != v.end(); ++iter){
		BOOST_CHECK(v[index] == *iter);
		index++;
	}
}

void example3(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin(); //시작 원소를 가리키는 반복자
	BOOST_CHECK(iter[0] == v[0]);
	BOOST_CHECK(iter[1] == v[1]);
	BOOST_CHECK(iter[2] == v[2]);
	BOOST_CHECK(iter[3] == v[3]);
	BOOST_CHECK(iter[4] == v[4]);

	iter += 2; // += 연산
	cout << *iter << endl;
	BOOST_CHECK(*iter == v[2]);
	cout << endl;

	vector<int>::iterator iter2 = iter + 2; // + 연산
	cout << *iter2 << endl;
	BOOST_CHECK(*iter2 == v[4]);
}

void example4(){
	deque<int> dq;

	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);
	dq.push_back(50);

	deque<int>::iterator iter = dq.begin(); //시작 원소를 가리키는 반복자
	BOOST_CHECK(iter[0] == dq[0]);
	BOOST_CHECK(iter[1] == dq[1]);
	BOOST_CHECK(iter[2] == dq[2]);
	BOOST_CHECK(iter[3] == dq[3]);
	BOOST_CHECK(iter[4] == dq[4]);
	cout << endl;

	iter += 2; // += 연산
	BOOST_CHECK(*iter == dq[2]);
	cout << endl;

	deque<int>::iterator iter2 = iter + 2; // + 연산
	cout << *iter2 << endl;
	BOOST_CHECK(*iter2 == dq[4]);
}

void example5(){
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);

	sort(v.begin(), v.end()); // 정렬 가능(vector는 임의 접근 반복자)
	//sort(lt.begin(), lt.end()); // 에러!(list는 양방향 반복자)
}

void example6(){
	vector<int> v;
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(30);

	int index = 0;
	vector<int> test_vector1;
	test_vector1.push_back(10);
	test_vector1.push_back(20);
	test_vector1.push_back(30);
	test_vector1.push_back(40);
	test_vector1.push_back(50);
	sort(v.begin(), v.end(), less<int>()); // 오름차순 정렬

	if (test_vector1.size() == v.size())
	{
		for (int i = 0; i < test_vector1.size(); i++)
		{
			BOOST_CHECK(test_vector1[i] == v[i]);
		}
	}
	else
	{
		BOOST_CHECK(test_vector1.size() == v.size());
	}
	/*
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
		BOOST_CHECK(*iter == v[index]);
		index++;
	}
	*/

	cout << endl;
	vector<int> test_vector2;
	test_vector2.push_back(50);
	test_vector2.push_back(40);
	test_vector2.push_back(30);
	test_vector2.push_back(20);
	test_vector2.push_back(10);
	sort(v.begin(), v.end(), greater<int>()); // 내림차순 정렬

	if (test_vector2.size() == v.size())
	{
		for (int i = 0; i < test_vector2.size(); i++)
		{
			BOOST_CHECK(test_vector2[i] == v[i]);
		}
	}
	else
	{
		BOOST_CHECK(test_vector2.size() == v.size());
	}

	cout << endl;
}

void example7(){
	stack<int> st; //stack 컨테이너 생성

	st.push(10); // 데이터 추가(입력)
	st.push(20);
	st.push(30);

	cout << st.top() << endl; // top 데이터 출력
	st.pop(); // top 데이터 삭제
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();

	if (st.empty()) // 스택이 비었는지 확인
		cout << "stack이 데이터 없음" << endl;
}

void example8(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//일반 반복자 iterator를 역방향 반복자 reverse_iterator로 변환
	reverse_iterator< vector<int>::iterator > riter(v.end());
	reverse_iterator< vector<int>::iterator > end_riter(v.begin());

	for (; riter != end_riter; ++riter)
		cout << *riter << " ";
	cout << endl;
}

void example9(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	// STL 모든 컨테이너는 반복자 어댑터 reverse_iterator를 typedef 타입으로 정의하며
	// rbegin(), rend()로 컨테이너의 역방향 반복자를 반환함.
	vector<int>::reverse_iterator riter(v.rbegin());
	for (; riter != v.rend(); ++riter)
		cout << *riter << " ";
	cout << endl;
}

void example10(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator normal_iter = v.begin() + 3; //40 원소를 가리키는 정방향 반복자
	vector<int>::reverse_iterator reverse_iter(normal_iter);// normal_iter의 역방향 반복자


	cout << "정방향 반복자의 값: " << *normal_iter << endl;
	cout << "역방향 반복자의 값: " << *reverse_iter << endl;
	cout << endl;

	for (vector<int>::iterator iter = v.begin(); iter != normal_iter; ++iter)
		cout << *iter << " "; //정방향 출력
	cout << endl;

	for (vector<int>::reverse_iterator riter = reverse_iter; riter != v.rend(); ++riter)
		cout << *riter << " "; //역방향 출력
	cout << endl;
}

void example11(){
	cout << less<int>()(10, 20) << endl; //임시 less 객체로 비교
	cout << less<int>()(20, 20) << endl;
	cout << less<int>()(20, 10) << endl;
	cout << "==============" << endl;
	cout << not2(less<int>())(10, 20) << endl;// 임시 객체 less에 not2 어댑터 적용
	cout << not2(less<int>())(20, 20) << endl;
	cout << not2(less<int>())(20, 10) << endl;
	cout << endl;

	less<int> l;
	cout << l(10, 20) << endl; // less 객체 l로 비교    
	cout << l(20, 20) << endl;
	cout << l(20, 10) << endl;
	cout << "==============" << endl;
	cout << not2(l)(10, 20) << endl; // less 객체 l에 not2 어댑터 적용
	cout << not2(l)(20, 20) << endl;
	cout << not2(l)(20, 10) << endl;
}

void example12(){
	vector< int, allocator<int> > v;
	v.push_back(10);
	cout << *v.begin() << endl;

	//set<typename T, typename Pred = less< T >, typename Alloc = allocator<T> >
	// set<int> 와 같음
	set< int, less<int>, allocator<int> > s;
	s.insert(10);
	cout << *s.begin() << endl;
}

void example13(){
	list<int> lt;

	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(30);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);
	lt.push_back(10);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.unique();
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
}

bool Predicate(int first, int second)
{
	return second - first <= 0;
}

void example14(){
	list<int> lt;

	lt.push_back(10);
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(30);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);
	lt.push_back(10);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.unique(Predicate);
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	BOOST_CHECK(lt.size() == 5);
	cout << endl;
}

void example15(){
	list<int> lt;

	lt.push_back(20);
	lt.push_back(10);
	lt.push_back(50);
	lt.push_back(30);
	lt.push_back(40);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(); // 오름차순( less, < 연산) 정렬
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
}

struct Greater
{
	bool operator () (int left, int right) const
	{
		return left > right;
	}
};

void example16(){
	list<int> lt;

	lt.push_back(20);
	lt.push_back(10);
	lt.push_back(50);
	lt.push_back(30);
	lt.push_back(40);

	list<int>::iterator iter;
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(greater<int>()); // 조건자 greater를 사용하여 내림차순 정렬
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(less<int>()); // 조건자 less를 사용하여 다시 오름차순 정렬
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(Greater()); // 사용자 정의 조건자를 사용하여 내림차순 정렬
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
}

void example17(){
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	lt2.push_back(25);
	lt2.push_back(35);
	lt2.push_back(60);


	list<int>::iterator iter;
	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl << "===============" << endl;

	lt1.merge(lt2); // lt2를 lt1으로 합병 정렬합니다. 정렬 기준은 less

	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
}

void example18(){
	list<int> lt1;
	list<int> lt2;

	lt1.push_back(50);
	lt1.push_back(40);
	lt1.push_back(30);
	lt1.push_back(20);
	lt1.push_back(10);

	//lt2.push_back(25); //lt1과 lt2의 정렬 방식이 다르므로 오류
	//lt2.push_back(35);
	//lt2.push_back(60);

	// lt1과 lt2는 정렬 방식이 같다.
	// greater 조건자( > 연산 ) 정렬 기준을 사용함
	lt2.push_back(60);
	lt2.push_back(35);
	lt2.push_back(25);


	list<int>::iterator iter;
	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl << "===============" << endl;

	// lt2를 lt1으로 합병 정렬합니다. 
	// 두 list의 정렬 기준이 > 연산인 greater라는 것을 predicate로 지정합니다.
	lt1.merge(lt2, greater<int>());

	cout << "lt1: ";
	for (iter = lt1.begin(); iter != lt1.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "lt2: ";
	for (iter = lt2.begin(); iter != lt2.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
}

void example19(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	cout << v.size() << endl;
	cout << v.capacity() << endl;
	cout << v.max_size() << endl;
}

void example20(){
	vector<int> v1(5); //0으로 초기화된 size가 5인 컨테이너
	v1.push_back(10); //10 추가
	v1.push_back(20); //20 추가
	v1.push_back(30); //30 추가
	v1.push_back(40); //40 추가
	v1.push_back(50); //50 추가

	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5); //0으로 초기화된 size가 5인 컨테이너
	v2[0] = 10; // 0에서 10로 수정
	v2[1] = 20; // 0에서 20로 수정
	v2[2] = 30; // 0에서 30로 수정
	v2[3] = 40; // 0에서 40로 수정
	v2[4] = 50; // 0에서 50로 수정

	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

void example21(){
	vector<int> v1(5); //기본값 0으로 초기화된 size가 5인 컨테이너
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5, 0); //지정값 0으로 초기화된 size가 5인 컨테이너    
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	vector<int> v3(5, 10); //지정값 10으로 초기화된 size가 5인 컨테이너    
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
}

void example22(){
	vector<int> v(5); //기본값 0으로 초기화된 size가 5인 컨테이너

	v[0] = 10;
	v[1] = 20;
	v[2] = 30;
	v[3] = 40;
	v[4] = 50;
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	v.resize(10); //기본값 0으로 초기화된 size가 10인 컨테이너로 확장
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	v.resize(5); //size가 5인 컨테이너로 축소 capacity는 변화 없음.
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
}

void example23(){
	vector<int> v(5);

	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	vector<int>().swap(v);// 기본 생성자로 만든 vector컨테이너와 v 컨테어너를 swap한다.
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
}

void example24(){
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	vector<int> v2;
	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);

	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << ", " << v2[i] << endl;
	cout << endl;

	v1.swap(v2); // v1과 v2를 swap합니다.
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << ", " << v2[i] << endl;
	cout << endl;
}

void example25(){
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	cout << v[0] << ", " << v.front() << endl; // 첫 번째 원소
	cout << v[4] << ", " << v.back() << endl; // 마지막 원소
}

void example26(){
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.front() = 100; // 첫 번째 원소를 100으로
	v.back() = 500; // 마지막 원소를 500으로
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example27(){
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v[0] = 100; //범위 점검 없는 0 index 원소의 참조
	v[4] = 500; //범위 점검 없는 4 index 원소의 참조
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.at(0) = 1000; //범위 점검 있는 0 index 원소의 참조
	v.at(4) = 5000; //범위 점검 있는 4 index 원소의 참조
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v.at(i) << " ";
	cout << endl;
}

void example28(){
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	try
	{
		cout << v.at(0) << endl;
		cout << v.at(3) << endl;
		cout << v.at(6) << endl; //throw out_of_range 예외
	}
	catch (out_of_range &e)
	{
		cout << e.what() << endl;
	}
}

void example29(){
	vector<int> v(5, 1); // 초기값 1의 5개의 원소를 갖는 컨테이너 생성

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.assign(5, 2); // 5개의 원소값을 2로 할당
	cout << v.size() << ',' << v.capacity() << endl;
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example30(){
	vector<int> v(5, 1); // 초기값 1의 5개의 원소를 갖는 컨테이너 생성

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.assign(5, 2); // 5개의 원소값을 2로 할당
	cout << v.size() << ',' << v.capacity() << endl;
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example31(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example32(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin();
	vector<int>::const_iterator citer = v.begin();

	cout << *iter << endl; //가리키는 원소의 참조
	cout << *citer << endl; //가리키는 원소의 상수 참조

	cout << *++iter << endl; //다음 원소로 이동한 원소의 참조
	cout << *++citer << endl; //다음 원소로 이동한 원소의 상수 참조

	*iter = 100;  // 일반 반복자는 가리키는 원소를 변경할 수 있음.
	//*citer = 100; // 상수 반복자는 가리키는 원소를 변경할 수 없음.
}

void example33(){
	vector<int> v;
	int arr[5] = { 10, 20, 30, 40, 50 };

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin();
	int* p = arr;
	cout << *iter << ", " << *p << endl; // iter는 p처럼 동작함.

	vector<int>::const_iterator citer = v.begin();
	const int* cp = arr;
	cout << *citer << ", " << *cp << endl; // citer는 cp처럼 동작함.

	const vector<int>::iterator iter_const = v.begin();
	int* const p_const = arr;
	cout << *iter_const << ", " << *p_const << endl; //iter_const는 p_const처럼 동작함.

	const vector<int>::const_iterator citer_const = v.begin();
	const int* const cp_const = arr;
	cout << *citer_const << ", " << *cp_const << endl; //citer_const는 cp_const처럼 동작함.
}

void example34(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter; //정방향 반복자
	vector<int>::reverse_iterator riter; //역방향 반복자

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	for (riter = v.rbegin(); riter != v.rend(); ++riter)
		cout << *riter << " ";
	cout << endl;
}

void example35(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin() + 2;
	vector<int>::iterator iter2;

	// iter가 가리키는 위치에 정수 100을 삽입.
	// iter2는 삽입한 정수를 가리키는 반복자.
	iter2 = v.insert(iter, 100);

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
	cout << "iter2: " << *iter2 << endl;
}

void example36(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter = v.begin() + 2;

	// iter가 가리키는 위치에 정수 100을 3개 삽입.   
	v.insert(iter, 3, 100);

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	/////////////////////////////////////////////////////
	vector<int> v2;
	v2.push_back(100);
	v2.push_back(200);
	v2.push_back(300);

	iter = v2.begin() + 1;
	// iter가 가리키는 위치에 [v.begin(), v.end()) 구간의 원소를 삽입.   
	v2.insert(iter, v.begin(), v.end());

	for (iter = v2.begin(); iter != v2.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

}

void example37(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter;
	vector<int>::iterator iter2;
	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	iter = v.begin() + 2;
	// iter가 가리키는 위치의 원소를 제거합니다. iter2는 다음 원소 40
	iter2 = v.erase(iter);

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	// [v.begin()+1, v.end()) 구간의 원소를 제거합니다.   
	iter2 = v.erase(v.begin() + 1, v.end()); // iter2는 다음 원소 v.end()

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example38(){
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int> v2(v.begin(), v.end()); // 순차열 [v.begin(), v.end())로 v2를 초기화.

	vector<int>::iterator iter;
	for (iter = v2.begin(); iter != v2.end(); ++iter)
		cout << *iter << " "; // v2 출력
	cout << endl;

	vector<int> v3;
	v3.assign(v.begin(), v.end());  // v3에 순차열 [v.begin(), v.end())을 할당.
	for (iter = v3.begin(); iter != v3.end(); ++iter)
		cout << *iter << " "; // v3 출력
	cout << endl;
}

void example39(){
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(50);

	if (v1 == v2)
		cout << "v1 == v2" << endl;

	if (v1 != v2)
		cout << "v1 != v2" << endl;

	if (v1 < v2)
		cout << "v1 < v2" << endl;
}

void example40(){
	deque<int> dq;

	for (int i = 0; i < 10; i++)
		dq.push_back((i + 1) * 10);

	deque<int>::iterator iter;
	deque<int>::iterator iter2;
	for (iter = dq.begin(); iter != dq.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;


	iter = dq.begin() + 2;
	iter2 = dq.insert(iter, 500);
	cout << *iter2 << endl;

	for (iter = dq.begin(); iter != dq.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;
}

void example41(){
	list<int> lt;

	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);
	lt.push_back(50);

	list<int>::iterator iter = lt.begin();
	list<int>::iterator iter2;
	++iter;
	++iter;

	iter2 = lt.erase(iter); //iter(30)의 원소를 제거합니다.

	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "iter2 : " << *iter2 << endl;

	iter = iter2;
	iter2 = lt.insert(iter, 300); //iter2(40)이 가리키는 위치에 300을 삽입합니다.
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "iter2 : " << *iter2 << endl;
}

void example42(){
	map<int, int> m;

	m.insert(pair<int, int>(5, 100)); // 임시 pair 객체 생성 후 저장
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 70));
	m.insert(pair<int, int>(7, 100));

	pair<int, int> pr(9, 50);
	m.insert(pr); // pr 객체 생성 후 저장

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << (*iter).first << ',' << (*iter).second << ")" << " ";
	cout << endl;

	// 반복자는 -> 연산자가 연산자 오버로딩되어 있으므로 
	//포인터처럼 멤버를 -> 연산자로 접근할 수 있습니다. 
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;
}

void example43(){
	map<int, int> m;
	pair<map<int, int>::iterator, bool> pr; // insert() 결과 pair 객체

	m.insert(pair<int, int>(5, 100));
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 70));
	m.insert(pair<int, int>(7, 100));

	pr = m.insert(pair<int, int>(9, 50)); // 성공!
	if (true == pr.second)
		cout << "key: " << pr.first->first << ", value: " << pr.first->second << " 저장 완료!" << endl;
	else
		cout << "key 9가 이미 m에 있습니다." << endl;

	pr = m.insert(pair<int, int>(9, 50)); // 실패!
	if (true == pr.second)
		cout << "key: " << pr.first->first << ", value: " << pr.first->second << "저장 완료!" << endl;
	else
		cout << "key: 9가 이미 m에 있습니다." << endl;
}

void example44(){
	map<int, int> m;

	m[5] = 100; //key 5, value 100의 원소를 m에 삽입한다.
	m[3] = 100;
	m[8] = 30;
	m[4] = 40;
	m[1] = 70;
	m[7] = 100;
	m[9] = 50;

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;

	m[5] = 200; //key 5의 value를 200으로 갱신한다.

	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;
}

void example45(){
	map<int, string, greater<int> > m;

	m[5] = "five"; // 원소 추가
	m[3] = "three";
	m[8] = "eight";
	m[4] = "four";
	m[1] = "one";
	m[7] = "seven";
	m[9] = "nine";

	map<int, string, greater<int> >::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;


	cout << m[9] << " "; //key와 매핑된 value를 출력합니다.
	cout << m[8] << " ";
	cout << m[7] << " ";
	cout << m[5] << " ";
	cout << m[4] << " ";
	cout << m[3] << " ";
	cout << m[1] << endl;
}

void example46(){
	map<int, int> m;

	m[5] = 100;
	m[3] = 100;
	m[8] = 30;
	m[4] = 40;
	m[1] = 70;
	m[7] = 100;
	m[9] = 50;

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;

	iter = m.find(5);
	if (iter != m.end())
		cout << "key 5에 매핑된 value: " << iter->second << endl;

	map<int, int>::iterator lower_iter;
	map<int, int>::iterator upper_iter;
	lower_iter = m.lower_bound(5);
	upper_iter = m.upper_bound(5);

	cout << "구간 [lower_iter, upper_iter)의 순차열: ";
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;

	pair<map<int, int>::iterator, map<int, int>::iterator> iter_pair;
	iter_pair = m.equal_range(5);

	cout << "구간 [iter_pair.first, iter_pair.second)의 순차열: ";
	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;
}

void example47(){
	multimap<int, int> mm;

	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(3, 100));
	mm.insert(pair<int, int>(8, 30));
	mm.insert(pair<int, int>(3, 40));
	mm.insert(pair<int, int>(1, 70));
	mm.insert(pair<int, int>(7, 100));
	mm.insert(pair<int, int>(8, 50));

	multimap<int, int>::iterator iter;
	for (iter = mm.begin(); iter != mm.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;

	cout << "key 3의 원소의 개수는 " << mm.count(3) << endl;

	iter = mm.find(3);
	if (iter != mm.end())
		cout << "첫 번째 key 3에 매핑된 value: " << iter->second << endl;
}

void example48(){
	multimap<int, int> mm;

	mm.insert(pair<int, int>(5, 100));
	mm.insert(pair<int, int>(3, 100));
	mm.insert(pair<int, int>(8, 30));
	mm.insert(pair<int, int>(3, 40));
	mm.insert(pair<int, int>(1, 70));
	mm.insert(pair<int, int>(7, 100));
	mm.insert(pair<int, int>(8, 50));

	multimap<int, int>::iterator lower_iter;
	multimap<int, int>::iterator upper_iter;
	lower_iter = mm.lower_bound(3);
	upper_iter = mm.upper_bound(3);

	cout << "구간 [lower_iter, upper_iter)의 순차열: ";
	multimap<int, int>::iterator iter;
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;

	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> iter_pair;
	iter_pair = mm.equal_range(3);

	cout << "구간 [iter_pair.first, iter_pair.second)의 순차열: ";
	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;
}

void example49(){
	set<int> s; // 정수 원소를 저장하는 기본 정렬 기준이 less인 빈 컨테이너 생성

	s.insert(50); //랜덤으로 원소(key)를 삽입한다.
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter; // 기본 정렬 기준이 less인 set의 양방향 반복자
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " "; // inorder 2진 트리 탐색 순서로 출력된다.
	cout << endl;

	s.insert(50); //중복된 원소(key)를 삽입한다. 실패!!
	s.insert(50);

	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " "; // 결과는 같다.
	cout << endl;
}

void example50(){
	set<int> s;

	pair<set<int>::iterator, bool> pr;

	pr = s.insert(50); // 50 원소의 첫 번째 삽입
	s.insert(40);
	s.insert(80);

	if (true == pr.second)
		cout << *pr.first << " 삽입 성공!" << endl;
	else
		cout << *pr.first << "가 이미 있습니다. 삽입 실패!" << endl;

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	pr = s.insert(50); // 50 원소의 두 번째 삽입. 실패!!

	if (true == pr.second)
		cout << *pr.first << " 삽입 성공!" << endl;
	else
		cout << *pr.first << "가 이미 있습니다. 삽입 실패!" << endl;

	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example51(){
	set<int, less<int> > s_less; // set<int> s와 같습니다.
	set<int, greater<int> > s_greater; // 정렬 기준으로 greater<int> 조건자를 사용.

	s_less.insert(50);
	s_less.insert(80);
	s_less.insert(40);

	s_greater.insert(50);
	s_greater.insert(80);
	s_greater.insert(40);

	set<int, less<int> >::key_compare l_cmp = s_less.key_comp();
	cout << l_cmp(10, 20) << endl; // 10 < 20 연산!!

	set<int, greater<int> >::key_compare g_cmp = s_greater.key_comp();
	cout << g_cmp(10, 20) << endl; // 10 > 20 연산!!

	cout << "key_compare type: " << typeid(s_less.key_comp()).name() << endl;
	cout << "key_compare type: " << typeid(s_greater.key_comp()).name() << endl;
	cout << "value_compare type: " << typeid(s_less.value_comp()).name() << endl;
	cout << "value_compare type: " << typeid(s_greater.value_comp()).name() << endl;
}

void example52(){
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "원소 50의 개수: " << s.count(50) << endl;
	cout << "원소 100의 개수: " << s.count(100) << endl;
}

void example53(){
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	iter = s.find(30); // 30의 반복자를 반환
	if (iter != s.end())
		cout << *iter << "가 s에 있다!" << endl;
	else
		cout << "20이 s에 없다!" << endl;
}

void example54(){

	set<int, less<int> > s; // 정렬 기준 less

	// 30과 50의 비교
	cout << (!s.key_comp()(30, 50) && !s.key_comp()(50, 30)) << endl; //다르다
	// 30과 30의 비교
	cout << (!s.key_comp()(30, 30) && !s.key_comp()(30, 30)) << endl; //같다(equivalence)
}

void example55(){
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	set<int>::iterator iter_lower;
	set<int>::iterator iter_upper;

	iter_lower = s.lower_bound(30);
	iter_upper = s.upper_bound(30);
	cout << *iter_lower << endl;
	cout << *iter_upper << endl;

	iter_lower = s.lower_bound(55);
	iter_upper = s.upper_bound(55);
	if (iter_lower != iter_upper)
		cout << "55가 s에 있음!" << endl;
	else
		cout << "55가 s에 없음!" << endl;
}

void example56(){
	set<int> s;

	s.insert(50);
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	pair<set<int>::iterator, set<int>::iterator> iter_pair; //반복자 쌍의 pair 객체

	iter_pair = s.equal_range(30);
	cout << *iter_pair.first << endl;
	cout << *iter_pair.second << endl;

	iter_pair = s.equal_range(55);
	if (iter_pair.first != iter_pair.second)
		cout << "55가 s에 있음!" << endl;
	else
		cout << "55가 s에 없음!" << endl;
}

void example57(){
	multiset<int> ms;
	multiset<int>::iterator iter;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 중복
	ms.insert(30); // 30 중복
	ms.insert(70);
	iter = ms.insert(10);

	cout << "iter의 원소: " << *iter << endl;

	for (iter = ms.begin(); iter != ms.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example58(){
	multiset<int> ms;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 중복
	ms.insert(30); // 30 중복
	ms.insert(70);
	ms.insert(10);

	multiset<int>::iterator iter;
	for (iter = ms.begin(); iter != ms.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "30 원소의 개수: " << ms.count(30) << endl; // 30 원소의 개수

	iter = ms.find(30); // 30 첫 번째 원소의 반복자
	cout << "iter: " << *iter << endl;

	multiset<int>::iterator lower_iter;
	multiset<int>::iterator upper_iter;

	lower_iter = ms.lower_bound(30); // 30 순차열의 시작 반복자
	upper_iter = ms.upper_bound(30); // 30 순차열의 끝 표시 반복자
	cout << "lower_iter: " << *lower_iter << ",  " << "upper_iter: " << *upper_iter << endl;

	cout << "구간 [lower_iter, upper_iter)의 순차열: ";
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example59(){
	multiset<int> ms;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 중복
	ms.insert(30); // 30 중복
	ms.insert(70);
	ms.insert(10);

	multiset<int>::iterator iter;
	for (iter = ms.begin(); iter != ms.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//multiset의 반복자 쌍(pair) 객체 생성
	pair<multiset<int>::iterator, multiset<int>::iterator> iter_pair;
	iter_pair = ms.equal_range(30);

	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << *iter << " "; //[iter_pair.first, iter_pair.second) 구간의 순차열
	cout << endl;
}

test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
	framework::master_test_suite().
		add(BOOST_TEST_CASE(&example1));
	framework::master_test_suite().
		add(BOOST_TEST_CASE(&example2));
	framework::master_test_suite().
		add(BOOST_TEST_CASE(&example3));
	framework::master_test_suite().
		add(BOOST_TEST_CASE(&example4));
	framework::master_test_suite().
		add(BOOST_TEST_CASE(&example6));
	return 0;
}