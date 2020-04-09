/* Copyright Bricen Bennett 2020 CSCE240 */

#include <inc/functional_array.h>

size_t** Allocate(const size_t* sizes, size_t lenght) {
  size_t** ret = new size_t*[lenght];
  for (size_t i = 0; i < lenght; ++i) {
    size_t holder = sizes[i];
    ret[i] = new size_t[holder];
    for (size_t j = 0; j < holder; ++j)
      ret[i][j] = holder;
  }
  return ret;
}

size_t Deallocate(const size_t** arrays,
                  const size_t* sizes,
                  size_t length) {
  size_t run_sum = 0;
  for (size_t i = 0; i < length; ++i) {
    run_sum += sizes[i] * sizes[i];
  }
  for (size_t i = 0; i < length; ++i)
    delete [] arrays[i];
  delete [] arrays;
  return run_sum;
}
