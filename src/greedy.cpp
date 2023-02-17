#include "greedy.hpp"
#include <cstdio>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<Task> getTasks(FILE *file) {
  vector<Task> tasks;
  unsigned long i = 0;
  char c = '\0';
  string number;
  while (!feof(file) && c != '\n') {
    Task task;
    fread(&c, sizeof(char), 1, file);
    if (c != ' ') {
      number += c;
    } else {
      task.start = stoi(number);
      tasks.push_back(task);
      number = "";
    }
  }
  while (!feof(file)) {
    fread(&c, sizeof(char), 1, file);
    if (c != ' ') {
      number += c;
    } else {
      tasks.at(i).end = stoi(number);
      i++;
      number = "";
    }
  }
  return tasks;
}
