#ifndef GREEDY_HPP
#define GREEDY_HPP
#include <vector>

typedef struct {
  int start;
  int end;
} Task;

std::vector<Task> getTasks(FILE *file);

void sortTasks(std::vector<Task> &tasks);

#endif // !GREEDY_HPP
