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
	vector<int> v; // ������ �����ϴ� �����̳� v ����

	v.push_back(10); // v�� ���� �߰�
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
	vector<int>::iterator iter; // �ݺ��� ����(���� ���Ҹ� ����Ű�� ����)
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

	vector<int>::iterator iter = v.begin(); //���� ���Ҹ� ����Ű�� �ݺ���
	BOOST_CHECK(iter[0] == v[0]);
	BOOST_CHECK(iter[1] == v[1]);
	BOOST_CHECK(iter[2] == v[2]);
	BOOST_CHECK(iter[3] == v[3]);
	BOOST_CHECK(iter[4] == v[4]);

	iter += 2; // += ����
	cout << *iter << endl;
	BOOST_CHECK(*iter == v[2]);
	cout << endl;

	vector<int>::iterator iter2 = iter + 2; // + ����
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

	deque<int>::iterator iter = dq.begin(); //���� ���Ҹ� ����Ű�� �ݺ���
	BOOST_CHECK(iter[0] == dq[0]);
	BOOST_CHECK(iter[1] == dq[1]);
	BOOST_CHECK(iter[2] == dq[2]);
	BOOST_CHECK(iter[3] == dq[3]);
	BOOST_CHECK(iter[4] == dq[4]);
	cout << endl;

	iter += 2; // += ����
	BOOST_CHECK(*iter == dq[2]);
	cout << endl;

	deque<int>::iterator iter2 = iter + 2; // + ����
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

	sort(v.begin(), v.end()); // ���� ����(vector�� ���� ���� �ݺ���)
	//sort(lt.begin(), lt.end()); // ����!(list�� ����� �ݺ���)
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
	sort(v.begin(), v.end(), less<int>()); // �������� ����

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
	sort(v.begin(), v.end(), greater<int>()); // �������� ����

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
	stack<int> st; //stack �����̳� ����

	st.push(10); // ������ �߰�(�Է�)
	st.push(20);
	st.push(30);

	cout << st.top() << endl; // top ������ ���
	st.pop(); // top ������ ����
	cout << st.top() << endl;
	st.pop();
	cout << st.top() << endl;
	st.pop();

	if (st.empty()) // ������ ������� Ȯ��
		cout << "stack�� ������ ����" << endl;
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

	//�Ϲ� �ݺ��� iterator�� ������ �ݺ��� reverse_iterator�� ��ȯ
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

	// STL ��� �����̳ʴ� �ݺ��� ����� reverse_iterator�� typedef Ÿ������ �����ϸ�
	// rbegin(), rend()�� �����̳��� ������ �ݺ��ڸ� ��ȯ��.
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

	vector<int>::iterator normal_iter = v.begin() + 3; //40 ���Ҹ� ����Ű�� ������ �ݺ���
	vector<int>::reverse_iterator reverse_iter(normal_iter);// normal_iter�� ������ �ݺ���


	cout << "������ �ݺ����� ��: " << *normal_iter << endl;
	cout << "������ �ݺ����� ��: " << *reverse_iter << endl;
	cout << endl;

	for (vector<int>::iterator iter = v.begin(); iter != normal_iter; ++iter)
		cout << *iter << " "; //������ ���
	cout << endl;

	for (vector<int>::reverse_iterator riter = reverse_iter; riter != v.rend(); ++riter)
		cout << *riter << " "; //������ ���
	cout << endl;
}

void example11(){
	cout << less<int>()(10, 20) << endl; //�ӽ� less ��ü�� ��
	cout << less<int>()(20, 20) << endl;
	cout << less<int>()(20, 10) << endl;
	cout << "==============" << endl;
	cout << not2(less<int>())(10, 20) << endl;// �ӽ� ��ü less�� not2 ����� ����
	cout << not2(less<int>())(20, 20) << endl;
	cout << not2(less<int>())(20, 10) << endl;
	cout << endl;

	less<int> l;
	cout << l(10, 20) << endl; // less ��ü l�� ��    
	cout << l(20, 20) << endl;
	cout << l(20, 10) << endl;
	cout << "==============" << endl;
	cout << not2(l)(10, 20) << endl; // less ��ü l�� not2 ����� ����
	cout << not2(l)(20, 20) << endl;
	cout << not2(l)(20, 10) << endl;
}

void example12(){
	vector< int, allocator<int> > v;
	v.push_back(10);
	cout << *v.begin() << endl;

	//set<typename T, typename Pred = less< T >, typename Alloc = allocator<T> >
	// set<int> �� ����
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

	lt.sort(); // ��������( less, < ����) ����
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

	lt.sort(greater<int>()); // ������ greater�� ����Ͽ� �������� ����
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(less<int>()); // ������ less�� ����Ͽ� �ٽ� �������� ����
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	lt.sort(Greater()); // ����� ���� �����ڸ� ����Ͽ� �������� ����
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

	lt1.merge(lt2); // lt2�� lt1���� �պ� �����մϴ�. ���� ������ less

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

	//lt2.push_back(25); //lt1�� lt2�� ���� ����� �ٸ��Ƿ� ����
	//lt2.push_back(35);
	//lt2.push_back(60);

	// lt1�� lt2�� ���� ����� ����.
	// greater ������( > ���� ) ���� ������ �����
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

	// lt2�� lt1���� �պ� �����մϴ�. 
	// �� list�� ���� ������ > ������ greater��� ���� predicate�� �����մϴ�.
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
	vector<int> v1(5); //0���� �ʱ�ȭ�� size�� 5�� �����̳�
	v1.push_back(10); //10 �߰�
	v1.push_back(20); //20 �߰�
	v1.push_back(30); //30 �߰�
	v1.push_back(40); //40 �߰�
	v1.push_back(50); //50 �߰�

	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5); //0���� �ʱ�ȭ�� size�� 5�� �����̳�
	v2[0] = 10; // 0���� 10�� ����
	v2[1] = 20; // 0���� 20�� ����
	v2[2] = 30; // 0���� 30�� ����
	v2[3] = 40; // 0���� 40�� ����
	v2[4] = 50; // 0���� 50�� ����

	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;
}

void example21(){
	vector<int> v1(5); //�⺻�� 0���� �ʱ�ȭ�� size�� 5�� �����̳�
	for (vector<int>::size_type i = 0; i < v1.size(); ++i)
		cout << v1[i] << " ";
	cout << endl;

	vector<int> v2(5, 0); //������ 0���� �ʱ�ȭ�� size�� 5�� �����̳�    
	for (vector<int>::size_type i = 0; i < v2.size(); ++i)
		cout << v2[i] << " ";
	cout << endl;

	vector<int> v3(5, 10); //������ 10���� �ʱ�ȭ�� size�� 5�� �����̳�    
	for (vector<int>::size_type i = 0; i < v3.size(); ++i)
		cout << v3[i] << " ";
	cout << endl;
}

void example22(){
	vector<int> v(5); //�⺻�� 0���� �ʱ�ȭ�� size�� 5�� �����̳�

	v[0] = 10;
	v[1] = 20;
	v[2] = 30;
	v[3] = 40;
	v[4] = 50;
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	v.resize(10); //�⺻�� 0���� �ʱ�ȭ�� size�� 10�� �����̳ʷ� Ȯ��
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	v.resize(5); //size�� 5�� �����̳ʷ� ��� capacity�� ��ȭ ����.
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;
}

void example23(){
	vector<int> v(5);

	cout << "size: " << v.size() << "  capacity: " << v.capacity() << endl;

	vector<int>().swap(v);// �⺻ �����ڷ� ���� vector�����̳ʿ� v ���׾�ʸ� swap�Ѵ�.
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

	v1.swap(v2); // v1�� v2�� swap�մϴ�.
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

	cout << v[0] << ", " << v.front() << endl; // ù ��° ����
	cout << v[4] << ", " << v.back() << endl; // ������ ����
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

	v.front() = 100; // ù ��° ���Ҹ� 100����
	v.back() = 500; // ������ ���Ҹ� 500����
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

	v[0] = 100; //���� ���� ���� 0 index ������ ����
	v[4] = 500; //���� ���� ���� 4 index ������ ����
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.at(0) = 1000; //���� ���� �ִ� 0 index ������ ����
	v.at(4) = 5000; //���� ���� �ִ� 4 index ������ ����
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
		cout << v.at(6) << endl; //throw out_of_range ����
	}
	catch (out_of_range &e)
	{
		cout << e.what() << endl;
	}
}

void example29(){
	vector<int> v(5, 1); // �ʱⰪ 1�� 5���� ���Ҹ� ���� �����̳� ����

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.assign(5, 2); // 5���� ���Ұ��� 2�� �Ҵ�
	cout << v.size() << ',' << v.capacity() << endl;
	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}

void example30(){
	vector<int> v(5, 1); // �ʱⰪ 1�� 5���� ���Ҹ� ���� �����̳� ����

	for (vector<int>::size_type i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;

	v.assign(5, 2); // 5���� ���Ұ��� 2�� �Ҵ�
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

	cout << *iter << endl; //����Ű�� ������ ����
	cout << *citer << endl; //����Ű�� ������ ��� ����

	cout << *++iter << endl; //���� ���ҷ� �̵��� ������ ����
	cout << *++citer << endl; //���� ���ҷ� �̵��� ������ ��� ����

	*iter = 100;  // �Ϲ� �ݺ��ڴ� ����Ű�� ���Ҹ� ������ �� ����.
	//*citer = 100; // ��� �ݺ��ڴ� ����Ű�� ���Ҹ� ������ �� ����.
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
	cout << *iter << ", " << *p << endl; // iter�� pó�� ������.

	vector<int>::const_iterator citer = v.begin();
	const int* cp = arr;
	cout << *citer << ", " << *cp << endl; // citer�� cpó�� ������.

	const vector<int>::iterator iter_const = v.begin();
	int* const p_const = arr;
	cout << *iter_const << ", " << *p_const << endl; //iter_const�� p_constó�� ������.

	const vector<int>::const_iterator citer_const = v.begin();
	const int* const cp_const = arr;
	cout << *citer_const << ", " << *cp_const << endl; //citer_const�� cp_constó�� ������.
}

void example34(){
	vector<int> v;

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	vector<int>::iterator iter; //������ �ݺ���
	vector<int>::reverse_iterator riter; //������ �ݺ���

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

	// iter�� ����Ű�� ��ġ�� ���� 100�� ����.
	// iter2�� ������ ������ ����Ű�� �ݺ���.
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

	// iter�� ����Ű�� ��ġ�� ���� 100�� 3�� ����.   
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
	// iter�� ����Ű�� ��ġ�� [v.begin(), v.end()) ������ ���Ҹ� ����.   
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
	// iter�� ����Ű�� ��ġ�� ���Ҹ� �����մϴ�. iter2�� ���� ���� 40
	iter2 = v.erase(iter);

	for (iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	// [v.begin()+1, v.end()) ������ ���Ҹ� �����մϴ�.   
	iter2 = v.erase(v.begin() + 1, v.end()); // iter2�� ���� ���� v.end()

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

	vector<int> v2(v.begin(), v.end()); // ������ [v.begin(), v.end())�� v2�� �ʱ�ȭ.

	vector<int>::iterator iter;
	for (iter = v2.begin(); iter != v2.end(); ++iter)
		cout << *iter << " "; // v2 ���
	cout << endl;

	vector<int> v3;
	v3.assign(v.begin(), v.end());  // v3�� ������ [v.begin(), v.end())�� �Ҵ�.
	for (iter = v3.begin(); iter != v3.end(); ++iter)
		cout << *iter << " "; // v3 ���
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

	iter2 = lt.erase(iter); //iter(30)�� ���Ҹ� �����մϴ�.

	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "iter2 : " << *iter2 << endl;

	iter = iter2;
	iter2 = lt.insert(iter, 300); //iter2(40)�� ����Ű�� ��ġ�� 300�� �����մϴ�.
	for (iter = lt.begin(); iter != lt.end(); ++iter)
		cout << *iter << ' ';
	cout << endl;

	cout << "iter2 : " << *iter2 << endl;
}

void example42(){
	map<int, int> m;

	m.insert(pair<int, int>(5, 100)); // �ӽ� pair ��ü ���� �� ����
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 70));
	m.insert(pair<int, int>(7, 100));

	pair<int, int> pr(9, 50);
	m.insert(pr); // pr ��ü ���� �� ����

	map<int, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << (*iter).first << ',' << (*iter).second << ")" << " ";
	cout << endl;

	// �ݺ��ڴ� -> �����ڰ� ������ �����ε��Ǿ� �����Ƿ� 
	//������ó�� ����� -> �����ڷ� ������ �� �ֽ��ϴ�. 
	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;
}

void example43(){
	map<int, int> m;
	pair<map<int, int>::iterator, bool> pr; // insert() ��� pair ��ü

	m.insert(pair<int, int>(5, 100));
	m.insert(pair<int, int>(3, 100));
	m.insert(pair<int, int>(8, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(1, 70));
	m.insert(pair<int, int>(7, 100));

	pr = m.insert(pair<int, int>(9, 50)); // ����!
	if (true == pr.second)
		cout << "key: " << pr.first->first << ", value: " << pr.first->second << " ���� �Ϸ�!" << endl;
	else
		cout << "key 9�� �̹� m�� �ֽ��ϴ�." << endl;

	pr = m.insert(pair<int, int>(9, 50)); // ����!
	if (true == pr.second)
		cout << "key: " << pr.first->first << ", value: " << pr.first->second << "���� �Ϸ�!" << endl;
	else
		cout << "key: 9�� �̹� m�� �ֽ��ϴ�." << endl;
}

void example44(){
	map<int, int> m;

	m[5] = 100; //key 5, value 100�� ���Ҹ� m�� �����Ѵ�.
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

	m[5] = 200; //key 5�� value�� 200���� �����Ѵ�.

	for (iter = m.begin(); iter != m.end(); ++iter)
		cout << "(" << iter->first << ',' << iter->second << ")" << " ";
	cout << endl;
}

void example45(){
	map<int, string, greater<int> > m;

	m[5] = "five"; // ���� �߰�
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


	cout << m[9] << " "; //key�� ���ε� value�� ����մϴ�.
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
		cout << "key 5�� ���ε� value: " << iter->second << endl;

	map<int, int>::iterator lower_iter;
	map<int, int>::iterator upper_iter;
	lower_iter = m.lower_bound(5);
	upper_iter = m.upper_bound(5);

	cout << "���� [lower_iter, upper_iter)�� ������: ";
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;

	pair<map<int, int>::iterator, map<int, int>::iterator> iter_pair;
	iter_pair = m.equal_range(5);

	cout << "���� [iter_pair.first, iter_pair.second)�� ������: ";
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

	cout << "key 3�� ������ ������ " << mm.count(3) << endl;

	iter = mm.find(3);
	if (iter != mm.end())
		cout << "ù ��° key 3�� ���ε� value: " << iter->second << endl;
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

	cout << "���� [lower_iter, upper_iter)�� ������: ";
	multimap<int, int>::iterator iter;
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;

	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> iter_pair;
	iter_pair = mm.equal_range(3);

	cout << "���� [iter_pair.first, iter_pair.second)�� ������: ";
	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << "(" << iter->first << ',' << iter->second << ") ";
	cout << endl;
}

void example49(){
	set<int> s; // ���� ���Ҹ� �����ϴ� �⺻ ���� ������ less�� �� �����̳� ����

	s.insert(50); //�������� ����(key)�� �����Ѵ�.
	s.insert(30);
	s.insert(80);
	s.insert(40);
	s.insert(10);
	s.insert(70);
	s.insert(90);

	set<int>::iterator iter; // �⺻ ���� ������ less�� set�� ����� �ݺ���
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " "; // inorder 2�� Ʈ�� Ž�� ������ ��µȴ�.
	cout << endl;

	s.insert(50); //�ߺ��� ����(key)�� �����Ѵ�. ����!!
	s.insert(50);

	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " "; // ����� ����.
	cout << endl;
}

void example50(){
	set<int> s;

	pair<set<int>::iterator, bool> pr;

	pr = s.insert(50); // 50 ������ ù ��° ����
	s.insert(40);
	s.insert(80);

	if (true == pr.second)
		cout << *pr.first << " ���� ����!" << endl;
	else
		cout << *pr.first << "�� �̹� �ֽ��ϴ�. ���� ����!" << endl;

	set<int>::iterator iter;
	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	pr = s.insert(50); // 50 ������ �� ��° ����. ����!!

	if (true == pr.second)
		cout << *pr.first << " ���� ����!" << endl;
	else
		cout << *pr.first << "�� �̹� �ֽ��ϴ�. ���� ����!" << endl;

	for (iter = s.begin(); iter != s.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example51(){
	set<int, less<int> > s_less; // set<int> s�� �����ϴ�.
	set<int, greater<int> > s_greater; // ���� �������� greater<int> �����ڸ� ���.

	s_less.insert(50);
	s_less.insert(80);
	s_less.insert(40);

	s_greater.insert(50);
	s_greater.insert(80);
	s_greater.insert(40);

	set<int, less<int> >::key_compare l_cmp = s_less.key_comp();
	cout << l_cmp(10, 20) << endl; // 10 < 20 ����!!

	set<int, greater<int> >::key_compare g_cmp = s_greater.key_comp();
	cout << g_cmp(10, 20) << endl; // 10 > 20 ����!!

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

	cout << "���� 50�� ����: " << s.count(50) << endl;
	cout << "���� 100�� ����: " << s.count(100) << endl;
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

	iter = s.find(30); // 30�� �ݺ��ڸ� ��ȯ
	if (iter != s.end())
		cout << *iter << "�� s�� �ִ�!" << endl;
	else
		cout << "20�� s�� ����!" << endl;
}

void example54(){

	set<int, less<int> > s; // ���� ���� less

	// 30�� 50�� ��
	cout << (!s.key_comp()(30, 50) && !s.key_comp()(50, 30)) << endl; //�ٸ���
	// 30�� 30�� ��
	cout << (!s.key_comp()(30, 30) && !s.key_comp()(30, 30)) << endl; //����(equivalence)
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
		cout << "55�� s�� ����!" << endl;
	else
		cout << "55�� s�� ����!" << endl;
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

	pair<set<int>::iterator, set<int>::iterator> iter_pair; //�ݺ��� ���� pair ��ü

	iter_pair = s.equal_range(30);
	cout << *iter_pair.first << endl;
	cout << *iter_pair.second << endl;

	iter_pair = s.equal_range(55);
	if (iter_pair.first != iter_pair.second)
		cout << "55�� s�� ����!" << endl;
	else
		cout << "55�� s�� ����!" << endl;
}

void example57(){
	multiset<int> ms;
	multiset<int>::iterator iter;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 �ߺ�
	ms.insert(30); // 30 �ߺ�
	ms.insert(70);
	iter = ms.insert(10);

	cout << "iter�� ����: " << *iter << endl;

	for (iter = ms.begin(); iter != ms.end(); ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example58(){
	multiset<int> ms;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 �ߺ�
	ms.insert(30); // 30 �ߺ�
	ms.insert(70);
	ms.insert(10);

	multiset<int>::iterator iter;
	for (iter = ms.begin(); iter != ms.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	cout << "30 ������ ����: " << ms.count(30) << endl; // 30 ������ ����

	iter = ms.find(30); // 30 ù ��° ������ �ݺ���
	cout << "iter: " << *iter << endl;

	multiset<int>::iterator lower_iter;
	multiset<int>::iterator upper_iter;

	lower_iter = ms.lower_bound(30); // 30 �������� ���� �ݺ���
	upper_iter = ms.upper_bound(30); // 30 �������� �� ǥ�� �ݺ���
	cout << "lower_iter: " << *lower_iter << ",  " << "upper_iter: " << *upper_iter << endl;

	cout << "���� [lower_iter, upper_iter)�� ������: ";
	for (iter = lower_iter; iter != upper_iter; ++iter)
		cout << *iter << " ";
	cout << endl;
}

void example59(){
	multiset<int> ms;

	ms.insert(50);
	ms.insert(30);
	ms.insert(80);
	ms.insert(80); // 80 �ߺ�
	ms.insert(30); // 30 �ߺ�
	ms.insert(70);
	ms.insert(10);

	multiset<int>::iterator iter;
	for (iter = ms.begin(); iter != ms.end(); ++iter)
		cout << *iter << " ";
	cout << endl;

	//multiset�� �ݺ��� ��(pair) ��ü ����
	pair<multiset<int>::iterator, multiset<int>::iterator> iter_pair;
	iter_pair = ms.equal_range(30);

	for (iter = iter_pair.first; iter != iter_pair.second; ++iter)
		cout << *iter << " "; //[iter_pair.first, iter_pair.second) ������ ������
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