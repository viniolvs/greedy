#include "greedy.hpp"
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
    if (isdigit(c)) {
      number += c;
    } else if (number != "") {
      task.start = stoi(number);
      tasks.push_back(task);
      number = "";
    }
  }
  number = "";
  while (!feof(file)) {
    fread(&c, sizeof(char), 1, file);
    if (isdigit(c)) {
      number += c;
    } else if (number != "") {
      tasks[i].end = stoi(number);
      i++;
      number = "";
    }
  }
  return tasks;
}

void sortTasks(vector<Task> &tasks) {
  for (unsigned long i = 0; i < tasks.size(); i++) {
    for (unsigned long j = 0; j < tasks.size() - 1; j++) {
      if (tasks.at(j).start > tasks.at(j + 1).start) {
        Task temp = tasks.at(j);
        tasks.at(j) = tasks.at(j + 1);
        tasks.at(j + 1) = temp;
      }
    }
  }
}

void sortTasks_end(vector<Task> &tasks) {
  for (unsigned long i = 0; i < tasks.size(); i++) {
    for (unsigned long j = 0; j < tasks.size() - 1; j++) {
      if (tasks.at(j).end > tasks.at(j + 1).end) {
        Task temp = tasks.at(j);
        tasks.at(j) = tasks.at(j + 1);
        tasks.at(j + 1) = temp;
      }
    }
  }
}
