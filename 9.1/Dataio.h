#pragma once
#include <string>

struct Time { int year, month, day, hour, min; };
struct Airport {
    int number;
    std::string type;
    std::string destination;
    Time timeo, timei;
};
enum Type {
    Chart, Reg, Priam, Tranz, Styic
};

void TmO(Airport*& temp, int count);
void TmI(Airport*& temp, int count);
void Enter(Airport*& temp, int count);
void printList(Airport* data, int count);
void addAirport(Airport*& data, int& count);
void printTable(Airport* data, int count);
std::string EnumString(int index);
void clear(Airport*& data, int& count);
