#include "robot.hpp"
#include<algorithm>
#include<stdexcept>
//instead of rebuilding everything we only call the class
Robot::Robot(const std::string& id, const std::string&name, int battery):id_(id),name_(name),battery_(std::clamp(battery,0,100)),status_("idle"){}
void Robot:: charge(){battery_=100;
status_="charging";
}
std::string Robot::id() const{return id_;}
std::string Robot::name() const{return name_;}
int Robot::battery() const{return battery_;}
std::string Robot::status() const{return status_;}
bool Robot::operator==(const Robot& other)const{return id_==other.id_;}
std::string Robot::operator+(const Robot& other) const{return name_+" + "+other.name_;}
//the function is not a member function since its left side isn't of class roobot but ostream and given we chose the variables/ parameters to be private this function needs to be set to friend in order to access them
std::ostream& operator<<(std::ostream& os, const Robot& r){ os<<"["<<r.type()<<"]"<<r.name_<<"(id:"<<r.id_<<")"<<"battery: "<<r.battery_<<"%"<<"status:"<<r.status_;
return os;}


