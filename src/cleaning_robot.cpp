#include"cleaning_robot.hpp"
#include<iostream>
#include<algorithm>
#include<stdexcept>
CleaningRobot::CleaningRobot(const str::string& id,const str::string& name,int battery,double speed,int brush_level):MobilelRobot(id,name,battery,speed),brushlevel_(std::clamp(brush_level,1,10)){}

void CleaningRobot::work(){if (battery_=0)throw std::runtime_error(name_+" has an empty battery ");
status_="working";
battery_=std::max(0,battery--15);
std::count<<*this<<"cleaning with a brush level of "<<brush_level_;}
std::string CleaningRobot::type() const{return "CleaningRobot;}
 
