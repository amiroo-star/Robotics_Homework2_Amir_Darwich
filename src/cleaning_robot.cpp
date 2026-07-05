#include"cleaning_robot.hpp"
#include<iostream>
#include<algorithm>
#include<stdexcept>
CleaningRobot::CleaningRobot(const std::string& id,const std::string& name,int battery,double speed,int brush_level):MobileRobot(id,name,battery,speed),brush_level_(std::clamp(brush_level,1,10)){}

void CleaningRobot::work(){if (battery_==0)throw std::runtime_error(name_+" has an empty battery ");
status_="working";
battery_=std::max(0,battery_-15);
std::cout<<*this<<"cleaning with a brush level of "<<brush_level_;}
std::string CleaningRobot::type() const{return "CleaningRobot";}
 
