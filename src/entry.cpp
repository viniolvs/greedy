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

static void mergeTasks(vector<Task> &tasks, unsigned long start,
                       unsigned long middle, unsigned long end) {
  unsigned long i = start;
  unsigned long j = middle + 1;
  unsigned long k = 0;
  vector<Task> temp(end - start + 1);
  while (i <= middle && j <= end) {
    if (tasks[i].start < tasks[j].start) {
      temp[k] = tasks[i];
      i++;
    } else {
      temp[k] = tasks[j];
      j++;
    }
    k++;
  }
  while (i <= middle) {
    temp[k] = tasks[i];
    i++;
    k++;
  }
  while (j <= end) {
    temp[k] = tasks[j];
    j++;
    k++;
  }
  for (unsigned long l = start; l <= end; l++) {
    tasks[l] = temp[l - start];
  }
}

void mergeSortTasks(vector<Task> &tasks, unsigned long start,
                    unsigned long end) {
  if (start < end) {
    unsigned long middle = (start + end) / 2;
    mergeSortTasks(tasks, start, middle);
    mergeSortTasks(tasks, middle + 1, end);
    mergeTasks(tasks, start, middle, end);
  }
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
