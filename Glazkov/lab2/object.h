#pragma once
#include <fstream>

using namespace std;

class Object {
private:
	int x;
	int y;
	int hp;
public:
	Object(int x, int y, int hp);
	Object(ifstream& file);
	Object();
	~Object();

	void getDamage(int); // �������� ����
	void getCoordsFromFile(ifstream& file); // ������� ���������� ������� �� �����
	bool checkObjCoords(int, int); // ��������� ������� ������� �� ������ �����������
	int getX(); // �������� ���������� x
	int getY(); // �������� ���������� y
	int getHp(); // �������� ���� ������
};
