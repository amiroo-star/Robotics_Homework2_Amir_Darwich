#include<iostream>
#include<memory>
#include<algorithm>
#include"robot.hpp"
#include"mobile_robot.hpp"
#include"cleaning_robot.hpp"
#include"cooking_robot.hpp"
#include"fleet.hpp"
#include"task.hpp"
int main(){
Fleet fleet;
fleet+=std::make_shared<CleaningRobot>("R1","Amir",80,1.5,7);
fleet+=std::make_shared<CleaningRobot>("R2","Roudy",30,1.2,5);
fleet+=std::make_shared<CookingRobot>("R3","Hiba",100,"Lebanese");
fleet+=std::make_shared<CookingRobot>("R4","Maya",0,"Italian");
fleet+=std::make_shared<MobileRobot>("R5","Elias",60,2.0);
std::cout<<fleet<<"/n";
auto r1=fleet.find("R1");
auto r3=fleet.find("R3");
std::cout<<"\noperator+: "<<(*r1+*r3)<<"\n";
std::cout<<"R1==R1:\n"<< (*r1==*r1?"true":"false")<<"\n";
std::cout<<"R1==R3:\n"<< (*r1==*r3?"true":"false")<<"\n\n";
fleet.assign_task("R1",{"Vacuum hall",4,"R1"});
fleet.assign_task("R3",{"Cook Dinner",5,"R3"});
fleet.assign_task("R5",{"Patrol sector",2,"R5"});
fleet.show_tasks();
fleet.work_all();
try{fleet.find("R4")->work();}
catch (const std::runtime_error& e){
std::cout<<"Error: "<<e.what()<<"\n";}
try{fleet.find("R99");}
catch (const std::runtime_error& e){
std::cout<<"Error: "<<e.what()<<"\n";}
std::vector<std::shared_ptr<Robot>> all;
for (const auto& id: std::vector<std::string>{"R1","R2","R3","R4","R5"})all.push_back(fleet.find(id));
auto low=std::find_if(all.begin(),all.end(),[](const std::shared_ptr<Robot>& r){return r->battery()<20;});
if(low!=all.end())std::cout<<"Low_battery: "<<**low<<"\n";
fleet.charge_all();
//background Thread
auto r2=std::dynamic_pointer_cast<MobileRobot>(fleet.find("R2"));
if(r2)r2->start_work(3);
std::cout<<"\n";
fleet-="R5";
std::cout<<fleet;
return 0;}
