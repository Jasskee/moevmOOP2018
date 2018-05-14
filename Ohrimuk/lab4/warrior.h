#ifndef warriorH
#define warriorH
#include "List.h"
#include "color.h"
#include "Crown.h"
#include "building.h"
#include <iostream>
#include <fstream>
#include <memory>

class warrior : public obj
{
	protected:
		int dmg;//���� �����
	public:
	    warrior():obj()
		{
			dmg=0;
			std::cout<< "����: ���� ����� = "<<dmg<<std::endl;
		}
		warrior(std::ifstream &f,std::shared_ptr< Crown > &cr):obj(f,cr) //�����������
		{
			f >> dmg;
			std::cout<<"����: ���� ����� = "<<dmg<<std::endl;
		}	
		warrior(const warrior &b):obj(b.x,b.y,b.heal,b.crown)//����������� �����������
		{
			dmg=b.dmg;
			std::cout<<"����: ���� ����� = "<<dmg<<std::endl;
		}
		/*warrior(const int& a, const int& b, const int& h,const int& d):obj(a,b,h) //�����������
		{
			dmg=d;
			std::cout<<"����: ���� ����� = "<<dmg<<std::endl;
		}*/
		~warrior() //����������
		{
			std::cout<<"~����: ���� ����� = "<<dmg<<std::endl;
		}
		void left()	
		{
			x=x-1;
		}
		void right()	
		{
			x=x+1;
		}
		void down()	//����
		{
			y=y+1;
		}
		void up()	//�����
		{
			y=y-1;
		}
		int attack(warrior &w)//������� ��� �����, ������� ��������� ����� �����,�������� �� �������
		{
			return w.damage(dmg);
		}
		int attack(building &w)//������� ��� �����, ������� ��������� ����� ������,������� �� �������
		{
			return w.damage(dmg);
		}
};


#endif 	
