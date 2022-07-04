#include <iostream>

using namespace std;

void print(int depth, const char* str);
void whatIsRecursion(int n, int depth);

int problem17478() {
	int n;
	cin >> n;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	whatIsRecursion(n, 0);

	return 0;
}

void whatIsRecursion(int n, int depth) {
	print(depth, "\"����Լ��� ������?\"");

	if (n != 0) {
		print(depth, "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.");
		print(depth, "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.");
		print(depth, "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"");
		whatIsRecursion(n - 1, depth + 1);
	}
	else
		print(depth, "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"");

	print(depth, "��� �亯�Ͽ���.");
}

void print(int depth, const char* str) {
	for (int i = 0; i < depth; ++i)
		cout << "____";
	cout << str << "\n";
}