#ifndef objH
#define objH
#include "Crown.h"
#include <iostream>
#include <fstream>
#include <memory>

class obj {
	private:
		int x, y, heal,id; //����������� � ���-�� �����
		std::shared_ptr< Crown > crown;
	public:	
		static int count;
		obj (const int& a, const int& b, const int& h) //�����������
		{
			x=a;
			y=b;
			heal=h;
			id=count++;
			std::cout<<"������: �="<<x<<" �="<<y<<" hp="<<heal<<" id="<<id<< std::endl;
		}
		obj (std::ifstream &f,std::shared_ptr< Crown > &cr) //�����������
		{
			if (!f.is_open()) exit(1); // ���� ���� �� ������
			f >> x;
			f >> y;
			f >> heal;
			crown=cr;
			id=count++;
			int temp=crown->getcolor();
			std::cout<<"������: �="<<x<<" �="<<y<<" hp="<<heal<<" id="<< id <<" id_crown="<<temp<< std::endl;
		}
		obj() 
		{
			x=-1;
			y=-1;
			heal=-1;
			id=count++;
			std::cout<<"������: �="<<x<<" �="<<y<<" hp="<<heal<<" id="<<id<< std::endl;
		}
		obj(const obj &a) //����������� �����������
		{
			x=a.x;
			y=a.y;
			heal=a.heal;
			crown=a.crown;
			id=count++;
			int temp=crown->getcolor();
			std::cout<<"������: �="<<x<<" �="<<y<<" hp="<<heal<<" id="<<id<<" id_crown="<<temp<< std::endl;
		}
		~obj() //����������
		{
			int temp=crown->getcolor();
			std::cout<<"~������: �="<<x<<" �="<<y<<" hp="<<heal<<" id="<<id<<" id_crown="<<temp<< std::endl;
			//count--;
		}	 
	int damage (const int& d) //�������, ������� ������� ����
		{
			//std::cout<<heal<<" ����" <<d<<"\n";
			heal=heal-d;
			return heal;
		}
	bool issure(const int& x1, const int& y1) //�������, ������� ��������� ������� ������� �� �����������
		{
			if ((x1==x) && (y1==y)) 
				return true;
			else
				return false; 
		}
	bool file(std::ifstream &f) //��� ���������� �� �����
		{
			if (!f.is_open()) return false; // ���� ���� �� ������
			f >> x;
			f >> y;
			f >> heal;
			//std::cout<<"������: �="<<x<<" �="<<y<<" hp="<<heal<< std::endl;
			return true; //��������� �� ����
		}
	void show() //�����
	{
		std::cout << "���������� x= " << x << std::endl;
		std::cout << "���������� y= " << y << std::endl;
		std::cout << "���������� �����/�������� heal= " << heal << std::endl;
		
	}
	friend std::ostream& operator << (std::ostream& ostr,obj& o)
	{
		int temp=(o.crown)->getcolor();
		ostr<<"������: �="<<o.x<<" �="<<o.y<<" hp="<<o.heal<<" id="<<o.id<<" id_crown="<<temp<< std::endl;
		return ostr;
	}
};
int obj::count=0;
#endif 
