#include"cooking_robot.hpp"
#include<iostream>
#include<algorithm>
#include<stdexcept>
CookingRobot::CookingRobot(const std::string& id,const std::string& name,int battery,const std::string& cuisine):Robot(id,name,battery),cuisine_(cuisine){}
void CookingRobot::work(){if (battery==0)throw std::runtime_error(name_+"has an empty battery");
status_="working;
battery_=std::max(0,battery_-10);
std::cout<<*this<<"is an expert at "<<cuisine_<<"cuisine_";}
std::strin CookingRobot::type() const{return "CookingRobot";}

