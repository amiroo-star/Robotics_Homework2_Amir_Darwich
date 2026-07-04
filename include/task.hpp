#pragma once
#include<string>
#include<ostream>
struct Task{
std::string name;
int priority;
std::string assigned_to;
bool operator<(const Task& other) const;
friend std::ostream& operator<<(std::ostream& os,const Task&t);};

