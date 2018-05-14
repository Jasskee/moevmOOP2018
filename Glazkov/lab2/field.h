#pragma once
#include <fstream>
#include <vector>
#include "object.h"
#include "iter.h"



using namespace std;

class Field {
private:
	int xSize; // ������ ����
	int ySize; // ������ ����
	List<Object*> armyA; // ��������� ������ �����
	List<Object*> armyB; // ��������� ������ �����
	int countArmyA; // ���������� �������� ������ �����
	int countArmyB; // ���������� �������� ������ �����
public:
	//Field(int x, int y);
	Field(ifstream& file);
	~Field();

	void getSizeFromFile(ifstream& file); // �������� ������� ���� �� �����
	void getArmyFromFile(ifstream& file); // �������� ������� ����� �� �����
	Object* checkArmyCoords(List<Object*> &army, int count, int i, int j); // ��������� ������� �������� ����� �� �����������
	List<Object*>& getArmyA(); // �������� ��������� ������ �����
	List<Object*>& getArmyB(); // �������� ��������� ������ �����
	int getCountArmyA(); // �������� ���������� �������� ������ �����
	int getCountArmyB(); // �������� ���������� �������� ������ �����
	void printField(); // ���������� ����
	//void getDamage(vector<Object*> army, int count, int i, int j, int damage); // �������� �����
};
