#pragma once
using namespace std;
#include <fstream>
#include <vector>
#include <memory>
#include "object.h"

class Field {
private:
	int xSize; // ������ ����
	int ySize; // ������ ����
	List<Object*> armyA; // ��������� ������ �����
	List<Object*> armyB; // ��������� ������ �����
	int countArmyA; // ���������� �������� ������ �����
	int countArmyB; // ���������� �������� ������ �����
	weak_ptr<Crown> crownA;
	weak_ptr<Crown> crownB;
public:
	Field(istream& in);
	Field(int x, int y);
	Field(ifstream& file);
	~Field();

	void getSizeFromFile(ifstream& file); // �������� ������� ���� �� �����
	void getArmyFromFile(ifstream& file); // �������� ������� ����� �� �����
	void getSizeFromConsole(istream& in); 
	void getArmyFromConsole(istream& in); 
	Object* checkArmyCoords(List<Object*> &army, int count, int i, int j); // ��������� ������� �������� ����� �� �����������
	List<Object*>& getArmyA(); // �������� ��������� ������ �����
	List<Object*>& getArmyB(); // �������� ��������� ������ �����
	int& getCountArmyA(); // �������� ���������� �������� ������ �����
	int& getCountArmyB(); // �������� ���������� �������� ������ �����
	void printField(ostream& out); // ���������� ����
	weak_ptr<Crown> getCrownA();
	weak_ptr<Crown> getCrownB();
	//void getDamage(vector<Object*> army, int count, int i, int j, int damage); // �������� �����
};