//
// Created by adamk on 18.09.2024.
//
#include "ais1104/time.h"

inline Time* g_time = nullptr;

void Time::Init(const double deltaTime) {
    if(g_time) return;
    g_time = new Time(deltaTime);
}

Time Time::Instance() {
    return *g_time;
}
