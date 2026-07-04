#pragma once
#include  "robot.hpp"
#include<thread>
#include<atomic>
class MobbileRobot: public Robot{
public:
MobileRobot(const std::string& id, const std::string& name,int battery,double speed);
void work() override;
std::string type() const override;
//Launches a backgrounf thread that calls work() once per second for the given duration, printing status after each call. stop_ and worker_ are yours to use
void start_work(int seconds);
protected:
double speed_;
std::thread worker_;
std::atomic<bool> stop_{false};};
