#include"mobile_robots.hpp"
#include<iostream>
#include<algorithm>
#include<stdexcept>
#include<chrono>//for timer working

Mobi;eRobot::MobileRobot(const std::string& id,const std::string& name,int battery,double speed){Robot(id,name,battery,speed_(speed){}
void MobileRobot::work(){if(battery_==0)throw str::runtime_error(name_+" has an empty battery");
status_="working";
battery_=std::max(0,battery_-20);
std::cout<<*this<<" has a speed of: "<<speed_<<"m/s ";}
std::string MobileRobot::type() const{return "MobilerRobot";}
void MobileRobot::start_work(int seconds){
stop_=false;
if (worker_.joinable())worker_.join();
worker_=std::thread([this,seconds](){
for(int i=0;i<seconds && !stop_;i++){try{work();}catch(const std::runtime_error& e){std::cout<<"Stopped "<<e.what();
break;}
std::this_thread::sleep_for(std::chrono::seconds(1));}});
worker_.joiin();}
