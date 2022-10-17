#include "utility.h"
#include "SeqList.h"
#include "SingleLinkList.h"
#include "DoubleLinkList.h"
#include "CirSingleLinkList.h"
#include "CirDoubleLInkList.h"
#include "BigInteger.h"
#define println() cout << "===================" << endl

void errorProcess(int error) {
	if (error == INDEX_OUT_OF_BOUND) cout << "下标越界" << endl;
	if (error == ENTRY_NOT_FOUND) cout << "未找到该数据" << endl;
	if (error == SUCCESS) return;
}

template<class Link>
void testLink() {
	int n;
	cout << "请输入数组的长度：";
	cin >> n;
	cout << "请输入这个数组：";
	int* num = new int[n];
	for (int i = 0; i < n; i ++) {
		cin >> num[i];
	}
	Link l(num, n);
	delete[] num;
	
	while (true) {
		println();
		cout << "请输入操作（数字）：\n"
			<< "1. 插入元素\n"
			<< "2. 删除元素\n"
			<< "3. 修改元素\n"
			<< "4. 查找元素\n"
			<< "5. 打印链表\n"
			<< "0. 结束" << endl;
		int op;
		cin >> op;
		if (!op) return;
		int idx;
		int entry;
		switch (op)
		{
		case 1:
			cout << "请输入要插入的下标（从0开始）：";
			cin >> idx;
			cout << "请输入要插入的数据：";;
			cin >> entry;
			errorProcess(l.insert(idx, entry));
			break;
		case 2:
			cout << "请输入要删除的下标（从0开始）：";
			cin >> idx;
			errorProcess(l.remove(idx));
			break;
		case 3:
			cout << "请输入要修改的下标（从0开始）:";
			cin >> idx;
			cout << "请输入修改后的数据：";
			cin >> entry;
			errorProcess(l.set(idx, entry));
			break;
		case 4:
			cout << "请输入要查询的数据：";
			cin >> entry;
			if (l.search(entry)) cout << "该数据在链表中" << endl;
			else cout << "未找到该数据" << endl;
			break;
		case 5:
			l.print();
			break;
		default:
			cout << "输入有误" << endl;
			break;
		}
	}
}

int instructor() {
	cout << "欢迎来到链表模拟器及大数计算器" << endl;
	int op;
	cout << "请选择功能：" << endl;
	cout << "0. 生成顺序表\n"
		<< "1. 生成单向链表\n"
		<< "2. 生成双向链表\n"
		<< "3. 生成循环单链表\n"
		<< "4. 生成循环双链表\n"
		<< "5. 计算大数" << endl;
	cin >> op;
	while (op < 0 || op > 5) {
		cout << "非法输入，请重新输入：";
		cin >> op;
	}
	return op;
}

int main() {
	
	//=========================================//
	int op = instructor();
	switch (op)
	{
	case 0:
		testLink<SeqList<int> >();
		break;
	case 1:
		testLink<SingleLinkList<int> >();
		break;
	case 2:
		testLink<DoubleLinkList<int> >();
		break;
	case 3:
		testLink<CirSingleLinkList<int> >();
		break;
	case 4:
		testLink<CirDoubleLinkList<int> >();
		break;
	case 5:
		string num1, num2;
		char ope;
		cout << "请输入第一个数：" << endl;
		cin >> num1;
		cout << "请输入第二个数：" << endl;
		cin >> num2;
		cout << "请输入运算符（仅支持+-*）：" << endl;
		cin >> ope;
		while (ope != '+' && ope != '-' && ope != '*') {
			cout << "符号错误，请重新输入：" << endl;
			cin >> ope;
		}
		try {
			BigInteger b1(num1);
			BigInteger b2(num2);
			cout<< b1 << ope << (b2.sign() < 0 ? "(" : "") << b2 << (b2.sign() < 0 ? ")" : "") << '=';
			if (ope == '+') {
				cout << b1 + b2 << endl;
			}
			else if (ope == '-') {
				cout << b1 - b2 << endl;
			}
			else if (ope == '*') {
				cout << b1 * b2 << endl;
			}
		}
		catch (int error) {
			if (error == SYNTAX_ERROR) cout << "输入有误" << endl;
			else cout << "溢出" << endl;
		}
		break;
	}

	system("pause");
	
	//=========================================//

	//BigInteger b1("12345672423525236546578977");
	//BigInteger b2("2347266751275417654365742783668726375");
	//BigInteger b3("-1232323746237464");
	//BigInteger b4("-24727627131253625463");
	//cout << "b1=" << b1 << endl;
	//cout << "b2=" << b2 << endl;
	//cout << "b3=" << b3 << endl;
	//cout << "b4=" << b4 << endl;
	//cout << b1 << "+" << b2 << "=" << b1 + b2 << endl;
	//cout << b1 << "-" << b2 << "=" << b1 - b2 << endl;
	//cout << b2 << "-" << b1 << "=" << b2 - b1 << endl;
	//cout << b1 << "*" << b2 << "=" << b1 * b2 << endl;
	//cout << b3 << "-" << b4 << "=" << b3 - b4 << endl;
	//cout << b3 << "*" << b4 << "=" << b3 * b4 << endl;
	//cout << b1 << "-" << b4 << "=" << b1 - b4 << endl;
	//cout << b4 << "-" << b1 << "=" << b4 - b1 << endl;
	//cout << "-" << b3 << "=" << -b3 << endl;

	return 0;
}