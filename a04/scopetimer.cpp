#include "scopetimer.hpp"
#include <iostream>

int ScopeTimer::max_instances = 0;

ScopeTimer::ScopeTimer(const char *name)
    : name(name == nullptr ? "noname" : name),
      time_stamp(std::clock()),
      instance_num(max_instances) {
    for (int i = 0; i < 4 * instance_num; i++) std::cout << " ";
    std::cout << "Der Timer " << this->name << " wurde gestartet." << std::endl;
    max_instances++;
}

ScopeTimer::~ScopeTimer() {
    for (int i = 0; i < 4 * instance_num; i++) std::cout << " ";
    std::cout << "Der Timer " << name << " hat " << std::clock() - time_stamp << " ms gemessen." << std::endl;
}
