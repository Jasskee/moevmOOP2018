#pragma once
using namespace std;

#include <fstream>
#include <memory>
#include <typeinfo>
#include "crown.h"
#include "iter.h"


class Object {
private:
	int x;
	int y;
	int hp;
	char type;
	const shared_ptr<Crown> crown;

	const int id;
	static int count;
	static int amount;
public:

	Object(int x, int y, int hp);
	Object(ifstream& file, const shared_ptr<Crown>);
	Object(istream& in, const shared_ptr<Crown>);
	Object();
	virtual ~Object();

	void getDamage(int); // �������� ����
	void getCoordsFromFile(ifstream& file); // ������� ���������� ������� �� �����
	void getCoordsFromConsole(istream& in);
	bool checkObjCoords(int, int); // ��������� ������� ������� �� ������ �����������
	void changeX(int);
	void changeY(int);
	int& getX(); // �������� ���������� x
	int& getY(); // �������� ���������� y
	int getHp(); // �������� ���� ������
	int getId(); // �������� ������������� �������
	char& getType();
	const shared_ptr<Crown>& getCrown(); // �������� ������������� �������

	friend ostream &operator<<(ostream &ostr, Object &obj);
};
