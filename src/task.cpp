#include "task.hpp"
bool Task::operator<(const Task& other) const {return priority<other.priority;}
std::ostream& operator<<(ostream& os, const Task& t){os<<"Task[ "<<t.name<<"] priority: "<<t.priority<<" assigned_to:"<<t.assigned_to;
return os;}
