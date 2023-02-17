#ifndef GREEDY_HPP
#define GREEDY_HPP
#include <vector>

typedef struct {
  int start;
  int end;
} Task;

std::vector<Task> getTasks(FILE *file);

#endif // !GREEDY_HPP
