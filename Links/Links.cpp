#include "utility.h"
#include "SeqList.h"
#include "SingleLinkList.h"
#include "DoubleLinkList.h"
#include "CirSingleLinkList.h"
#include "CirDoubleLInkList.h"
#include "BigInteger.h"
#define println() cout << "===================" << endl

void errorProcess(int error) {
	if (error == INDEX_OUT_OF_BOUND) cout << "�±�Խ��" << endl;
	if (error == ENTRY_NOT_FOUND) cout << "δ�ҵ�������" << endl;
	if (error == SUCCESS) return;
}

template<class Link>
void testLink() {
	int n;
	cout << "����������ĳ��ȣ�";
	cin >> n;
	cout << "������������飺";
	int* num = new int[n];
	for (int i = 0; i < n; i ++) {
		cin >> num[i];
	}
	Link l(num, n);
	delete[] num;
	
	while (true) {
		println();
		cout << "��������������֣���\n"
			<< "1. ����Ԫ��\n"
			<< "2. ɾ��Ԫ��\n"
			<< "3. �޸�Ԫ��\n"
			<< "4. ����Ԫ��\n"
			<< "5. ��ӡ����\n"
			<< "0. ����" << endl;
		int op;
		cin >> op;
		if (!op) return;
		int idx;
		int entry;
		switch (op)
		{
		case 1:
			cout << "������Ҫ������±꣨��0��ʼ����";
			cin >> idx;
			cout << "������Ҫ��������ݣ�";;
			cin >> entry;
			errorProcess(l.insert(idx, entry));
			break;
		case 2:
			cout << "������Ҫɾ�����±꣨��0��ʼ����";
			cin >> idx;
			errorProcess(l.remove(idx));
			break;
		case 3:
			cout << "������Ҫ�޸ĵ��±꣨��0��ʼ��:";
			cin >> idx;
			cout << "�������޸ĺ�����ݣ�";
			cin >> entry;
			errorProcess(l.set(idx, entry));
			break;
		case 4:
			cout << "������Ҫ��ѯ�����ݣ�";
			cin >> entry;
			if (l.search(entry)) cout << "��������������" << endl;
			else cout << "δ�ҵ�������" << endl;
			break;
		case 5:
			l.print();
			break;
		default:
			cout << "��������" << endl;
			break;
		}
	}
}

int instructor() {
	cout << "��ӭ��������ģ����������������" << endl;
	int op;
	cout << "��ѡ���ܣ�" << endl;
	cout << "0. ����˳���\n"
		<< "1. ���ɵ�������\n"
		<< "2. ����˫������\n"
		<< "3. ����ѭ��������\n"
		<< "4. ����ѭ��˫����\n"
		<< "5. �������" << endl;
	cin >> op;
	while (op < 0 || op > 5) {
		cout << "�Ƿ����룬���������룺";
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
		cout << "�������һ������" << endl;
		cin >> num1;
		cout << "������ڶ�������" << endl;
		cin >> num2;
		cout << "���������������֧��+-*����" << endl;
		cin >> ope;
		while (ope != '+' && ope != '-' && ope != '*') {
			cout << "���Ŵ������������룺" << endl;
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
			if (error == SYNTAX_ERROR) cout << "��������" << endl;
			else cout << "���" << endl;
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