#pragma once
#include "Dataio.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio > 

using namespace std;

string prefix(string filename, bool binary);

ofstream new_DB(string& filename, bool binary);
bool remove_DB(string filename, bool binary);
void save_DB(string filename, Airport* data, int count, bool binary, bool append);
void load_DB(string filename, Airport*& data, int& count, bool binary);
void add_to_history(string*& history, int& count, string filename);
void remove_from_history(string*& history, int& count, string filename);
void print_history(string* history, int count);