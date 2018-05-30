#include <iostream>
#include <cstdlib>
#include <ctime>
#include "List.h"
#include "obj.h"
#include "Pole.h"
#include "building.h"
#include "warrior.h"


using std::cout;
using std::cin;
using std::endl;


int main()
{
setlocale(LC_ALL, "Russian");
std::ifstream fin("1.txt");	
int x,y,temp,damag,v,RED=1,GREEN=2;
Pole map;
warrior *w;
map.fromfile(fin); //������ �� �����
std::cout<<map; //������� �� ����� ����
x=y=-1;
std::cout<<"������� ���������� ����(����� ������)(q ��� ������)  \n";
std::cin>>x>>y;
while(y!=-1)
{
	w=map.prov_warr(x, y,RED);//���������� ���������, 0-��� �����, 1- ���� ����� ��������,
	// 2-�������, 
	if(w==NULL) std::cout<< "� ��������� ����� ���� ��� ������ ������� �����\n";
	else 
	{
		std::cout<< "� ��������� ����� ���� ��������� ���� ������� ����� x="<<x<<"y="<<y<<" \n";
		while(w)
		{
			std::cout<< "1: ���� ����� \n";
			std::cout<< "2: ���� ������ \n";
			std::cout<< "3: ���� ����� \n";
			std::cout<< "4: ���� ���� \n";
			if (map.prov(w->koor_x(),w->koor_y(),GREEN)!=0)
				std::cout<< "5: ���� \n";
			std::cout<< "0: ��������� \n";
			std::cin>>v;
			
			if (v==1)
			{
				if(map.prov_xy(w->koor_x()-1,w->koor_y()))
					w->left();
				else
				std::cout<<"���� ����� ���������� \n";
			}	
			if (v==2)
			{
				if(map.prov_xy(w->koor_x()+1,w->koor_y()))
					w->right();
				else
				std::cout<<"���� ������ ���������� \n";
			}	
			if (v==3)
			{
				if(map.prov_xy(w->koor_x(),w->koor_y()-1))
					w->up();
				else
				std::cout<<"���� ����� ���������� \n";
			}	
			if (v==4)
			{
				if(map.prov_xy(w->koor_x(),w->koor_y()+1))
					w->down();
				else
				std::cout<<"���� ���� ���������� \n";
			}	
			if (v==5)
			{
				if(map.prov(w->koor_x(),w->koor_y(),GREEN)!=0)
					map.damage(*w);
				else
				std::cout<<"���� ������ \n";
			}	
			if (v==0)
				w=NULL;
			std::cout<<map;
		}
	} 
	w=map.prov_warr(x, y,GREEN);//���������� ���������, 0-��� �����, 1- ���� ����� ��������,
	// 2-�������, 
	if(w==NULL) std::cout<< "� ��������� ����� ���� ��� ������ ������� �����\n";
	else 
	{
		std::cout<< "� ��������� ����� ���� ��������� ���� ������� ����� x="<<x<<"y="<<y<<" \n";
		while(w)
		{
			std::cout<< "1: ���� ����� \n";
			std::cout<< "2: ���� ������ \n";
			std::cout<< "3: ���� ����� \n";
			std::cout<< "4: ���� ���� \n";
			if (map.prov(w->koor_x(),w->koor_y(),RED)!=0)
				std::cout<< "5: ���� \n";
			std::cout<< "0: ��������� \n";
			std::cin>>v;
			
			if (v==1)
			{
				if(map.prov_xy(w->koor_x()-1,w->koor_y()))
					w->left();
				else
				std::cout<<"���� ����� ���������� \n";
			}	
			if (v==2)
			{
				if(map.prov_xy(w->koor_x()+1,w->koor_y()))
					w->right();
				else
				std::cout<<"���� ������ ���������� \n";
			}	
			if (v==3)
			{
				if(map.prov_xy(w->koor_x(),w->koor_y()-1))
					w->up();
				else
				std::cout<<"���� ����� ���������� \n";
			}	
			if (v==4)
			{
				if(map.prov_xy(w->koor_x(),w->koor_y()+1))
					w->down();
				else
				std::cout<<"���� ���� ���������� \n";
			}	
			if (v==5)
			{
				if(map.prov(w->koor_x(),w->koor_y(),RED)!=0)
					map.damage(*w);
				else
				std::cout<<"���� ������ \n";
			}	
			if (v==0)
				w=NULL;
			std::cout<<map;
		}
	}
	
	//if(temp==-1) std::cout<< "��������� ����� ��������� ��� ���� \n";
	
	/*if ((temp!=-1) && (temp!=0))
	{
		std::cout<<"������� ����: ";
		std::cin>>damag;
		std::cout<<"\n���������� ���� ��������: ";
		std::cout<<map.damage(x,y,damag);
		
		std::cout<<std::endl;
		//map.showPole();
		std::cout<<map;
	}*/
	 
	x=y=-1;
	std::cout<<"������� ���������� ����(����� ������)(q ��� ������) \n ";
	std::cin>>x>>y;
}



std::cin>>damag;
}
