#include "func.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <unistd.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

void show(const control &ctrl)
{
  system("clear");
  int x;

  car *crex=(&ctrl)->cbeg;
  cout<<"================================================================================================================================================="<<endl;
  if (crex==NULL) 
  {		
	cout.width(86);
	cout<<"	 >>>Список машин пуст<<<"<<endl;
  }
      
  else
  {
    cout.width(80);
    cout<<" >>>Список машин<<<\n"<<endl;
    cout<<"Номер машины";
    cout.width(50);
    cout<<"Текущие координаты";
    cout.width(40);
    cout<<"Время(в сек.)";
    cout.width(40);
    cout<<"Тип машины"<<endl;
    while(crex!=NULL)
    {
      coord mul=crex->get_loc_cur();
      cout<<crex->get_num();
      cout.width(24);
      cout<<'('<<setprecision(2)<<mul.get_x()<<','<<setprecision(2)<<mul.get_y()<<')';
      time_t lol=crex->get_time()-def_time();
      cout.width(28);
      if (lol<=0) cout<<"0";
      else cout<<lol;
      cout.width(64);
      x=crex->get_type();
      switch(x){
      case 1:
             cout<<"Для взрослого человека"<<endl;
             break;
      case 2:
             cout<<"Для детей             "<<endl;
             break;
      case 3:
             cout<<"Для пожилых людей     "<<endl;
             break;
      default: cout<<"?????????"<<endl;
               }  
      crex=crex->next;
    }
  }
  cout<<"=================================================================================================================================================";
  cout<<endl;
  call *vrex=(&ctrl)->vbeg;
  if (vrex==NULL) 
  {
	cout.width(90);
	cout<<"	>>>Список вызовов пуст<<<"<<endl;
  }
  else
  {
    cout.width(80);
    cout<<" >>>Список вызовов<<<\n"<<endl;
    cout<<"Координаты";
    cout.width(60);
    cout<<"Пациент";
    cout.width(60);
    cout<<"Тип услуги"<<endl;
    while(vrex!=NULL)
    {
      cout<<'('<<setprecision(2)<<vrex->cloc.get_x()<<','<<setprecision(2)<<vrex->cloc.get_y()<<')';
      cout.width(64);
      x=vrex->get_ctype();
      switch(x){
      case 1:
             cout<<"Взрослый";
             break;
      case 2:
             cout<<"Ребёнок ";
             break;
      case 3:
             cout<<"Пожилой ";
             break;
      default: cout<<"?????????";
               }        
      cout.width(76);
      x=vrex->get_cserv();
      switch(x){
      case 1:
             cout<<"Оказать первую помощь"<<endl;
             break;
      case 2:
             cout<<"Довезти до больницы    "<<endl;
             break;
      default: cout<<"?????????"<<endl;
               }
      vrex=vrex->next;
    }
   }
  cout<<"=================================================================================================================================================";
  cout<<endl;
  coord *brex=(&ctrl)->bbeg;
  if (brex==NULL) 
  { 
	cout.width(90);
	cout<<"	>>>Список больниц пуст<<<"<<endl;
  }
  else
  {
    cout.width(83);
    cout<<"        >>>Список больниц<<<\n"<<endl;
    cout<<"Координаты"<<endl;
    while(brex!=NULL)
    {
      cout<<'('<<brex->get_x()<<','<<brex->get_y()<<')'<<endl;
      brex=brex->next;
    }
  }
  cout<<"================================================================================================================================================="<<endl;
  return;
}