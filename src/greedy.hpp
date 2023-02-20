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

unsigned greedy_validate(std::vector<Task> &tasks);

unsigned greedy2(std::vector<Task> &tasks);

unsigned greedy2_validate(std::vector<Task> &tasks);

void printTasks(std::vector<Task> &tasks, unsigned m);
#endif
