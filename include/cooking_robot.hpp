#pragma once
#include "robot.hpp"
class CookingRobot: public Robot{
public:
CookingTobot{const std::string& id,const std::string& name, int battery, const std::string& cuisine);
void work() override;
std::string tyoe() const override;

private:
std::string cuisine_;}; 
