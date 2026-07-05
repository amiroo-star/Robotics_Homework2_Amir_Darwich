#pragma once
#include<string>
#include<ostream>
class Task;
class Robot{
public:
	Robot(const std::string& id,const std::string& name,int battery);
	virtual~Robot()=default;
	virtual void work()=0;
	virtual void charge();
	virtual std::string type() const=0;
	std::string id() const;
std::string name() const;
int battery() const;
std::string status() const;
bool operator== (const Robot& other) const;
std::string operator+(const Robot& other) const;
friend std::ostream& operator<< (std::ostream& os,const Robot&r);
protected:
std::string id_;
std::string name_;
int battery_;
std::string status_;};
