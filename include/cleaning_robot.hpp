#pragma once
#include "mobile_robots.hpp"
class CleaningRobot : public MobileRoobot{
public:
CleaningRobot(const std::string& id, const std::string& name,int battery,double speed,int brush_level);
void work() override;
std::string type() const override;
private:
int brush_level_;};
