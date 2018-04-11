#pragma once
#include <fstream>
#include "object.h"
#include <vector>


using namespace std;

class Field {
private:
	int xSize; // ������ ����
	int ySize; // ������ ����
	vector<Object*> armyA; // ��������� ������ �����
	vector<Object*> armyB; // ��������� ������ �����
	int countArmyA; // ���������� �������� ������ �����
	int countArmyB; // ���������� �������� ������ �����
public:
	//Field(int x, int y);
	Field(ifstream& file);
	~Field();

	void getSizeFromFile(ifstream& file); // �������� ������� ���� �� �����
	void getArmyFromFile(ifstream& file); // �������� ������� ����� �� �����
	bool checkArmyCoords(vector<Object*> army, int count, int i, int j); // ��������� ������� �������� ����� �� �����������
	vector<Object*> getArmyA(); // �������� ��������� ������ �����
	vector<Object*> getArmyB(); // �������� ��������� ������ �����
	int getCountArmyA(); // �������� ���������� �������� ������ �����
	int getCountArmyB(); // �������� ���������� �������� ������ �����
	void printField(); // ���������� ����
	void getDamage(vector<Object*> army, int count, int i, int j, int damage); // �������� �����
};
