#ifndef buildingH
#define buildingH
#include "List.h"
#include "color.h"
#include "Crown.h"
#include <iostream>
#include <fstream>
#include <memory>

class building: public obj
{
	protected:
		int kol;
		int *dop;
	public:
		building()
		{
			kol=0;
			dop=NULL;
			std::cout<< "������: �������������� ������ = "<<kol<<std::endl;
		}
		/*building(const int& a, const int& b, const int& h):obj(a,b,h) //�����������
		{
			kol=0;
			std::cout<< "������: �������������� ������ == "<<kol<<std::endl;
		}*/
		building(std::ifstream &f,std::shared_ptr< Crown > &cr):obj(f,cr) //�����������
		{
			f >> kol;
			dop=new int[2*kol];
			for(int i=0;i<2*kol;i++)
			{
				f >> dop[i];
			}
			std::cout<<"������: �������������� ������ = "<<kol<<std::endl;
		}
		building(const building &b):obj(b.x,b.y,b.heal,b.crown)//����������� �����������
		{
			this->kol=b.kol;
			this->dop=new int[2*(b.kol)];
			for (int i=0;i<2*kol;i++)
			{
				this->dop[i]=b.dop[i];
			}
			std::cout<<"������: �������������� ������ = "<<kol<<std::endl;
		}
		~building() //����������
		{
			delete[] dop;
			std::cout<<"~������: �������������� ������ = "<<kol<<std::endl;
		}
		bool issure(const int& x1, const int& y1) //�������, ������� ��������� ������� ������� �� �����������
		{
			int tempx,tempy;
			
			for (int i=0;i<2*kol;i++)
			{
				tempx=dop[i];
				i++;
				tempy=dop[i];
				if ((x1==tempx) && (y1==tempy))
					return true;
			}	
			if ((x1==this->x) && (y1==this->y)) 
				return true;
			
			return false; 
		}
		
};


#endif 	
