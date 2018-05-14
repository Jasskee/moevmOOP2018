#include "object.h"

Object::Object(ifstream& fl) { // ������� ������������� ����� ������� �� �����
	if (!fl.is_open()) {
		cout << "There are no file in directory!" << endl;
		exit(EXIT_FAILURE);
		system("pause");
	}
	fl >> x >> y >> hp;
	cout << "Object:" << endl;
	cout << "	x = " << x << endl;
	cout << "	y = " << y << endl;
	cout << "	hp = " << hp << endl;
	cout << "Object." << endl;
}

Object::Object() {
	x = y = hp = 0;
}

Object::~Object() { // ��������� ����������
	cout << "~Object:" << endl;
	cout << "	x = " << x << endl;
	cout << "	y = " << y << endl;
	cout << "	hp = " << hp << endl;
	cout << "~Object." << endl;

}

bool Object::Is_Located(int x1, int y1) { // �������, ������������, ��������� �� ������ � �������� �����������
	if (x == x1 && y == y1) return true;
	return false;
}

int Object::Damage(int damage){ // �������, ���������� �� ��������� ����� ��������
	hp -= damage;
	return hp;
}

bool Object::Is_Dead() { // �������, ������������, ���� �� ������
	if (hp <= 0) return true;
	return false;
}
