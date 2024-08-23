#include "../../pair/pair.h"
#include <stdio.h>
int main() {
  int_pair *point1 = make_pair(14, 27);
  int_pair *point2 = make_pair(30, 47);
  // print pair
  printf("print pair\n");
  print_int_pair(point1);
  print_int_pair(point2);
  // are point1 == point2
  printf("pairs compare\n");
  if (int_pair_cmp(point1, point2))
    printf("point1 and point2 are same value\n");
  else
    printf("point1 and point2 are not same value\n");
  printf("pairs swap\n");
  int_pair_swap(point1, point2);
  print_int_pair(point1);
  print_int_pair(point2);
  printf("pair clones\n");
  int_pair *point3 = int_pair_clone(point2);
  print_int_pair(point1);
  print_int_pair(point2);
  print_int_pair(point3);
  printf("pair free\n");
  int_pair_free(&point1);
  int_pair_free(&point2);
  int_pair_free(&point3);
  print_int_pair(point1);
  print_int_pair(point2);
  print_int_pair(point3);
  return 0;
}
