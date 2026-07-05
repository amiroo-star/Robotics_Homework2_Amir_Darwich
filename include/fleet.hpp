#pragma once
#include "robot.hpp"
#include"task.hpp"
#include<memory>
#include<string>
#include<ostream>
#include<unordered_map>
#include<queue>
class Fleet{
public:
void add(std::shared_ptr<Robot> robot);
void remove(const std::string& id);
std::shared_ptr<Robot> find(const std::string& id) const;
void assign_task(const std::string& robot_id, const Task& t);
void show_tasks() const;
void work_all() const;
void charge_all() const;
std::size_t size() const;
bool empty()const;
Fleet& operator+=(std::shared_ptr<Robot> robot);
Fleet& operator-=(const std::string& id);
friend std::ostream& operator<<(std::ostream& os, const Fleet& f);
private:
//choose te rightcontainer and justify each choice in a comment
//robots need fast lookup by id and tasks must always comeout highest priority first
//fastest lookup is in maps
std::unordered_map<std::string, std::shared_ptr<Robot>> robots_;//this way each robot is saved using its pointer and  id
//this way also lookup by id is O(1) also it allows fasr remove,find and asssign only using the key which in this case is the id
//in order to have always highest priority first we need  highest priority always on top which is all aout max-heap(priority queue) and searh similar to binary trees which takes O(log n ) in most tasks)
std::priority_queue<Task> tasks_;
};
