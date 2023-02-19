#ifndef GREEDY_HPP
#define GREEDY_HPP
#include <cstdio>
#include <list>
#include <vector>

typedef struct Task {
  int start;
  int end;
  int machine;
} Task;

typedef std::vector<Task> Machine;

std::vector<Task> getTasks(FILE *file);

void sortTasks(std::vector<Task> &tasks);

void mergeSortTasks(std::vector<Task> &tasks, unsigned long start,
                    unsigned long end);

unsigned greedy(std::vector<Task> &tasks);

std::vector<Machine> greedy2(std::vector<Task> &tasks);

void printMachines(std::vector<Machine> &machines);

void printTasks(std::vector<Task> &tasks, unsigned m);
#endif
