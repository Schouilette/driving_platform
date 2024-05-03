#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct circular_buf_t circular_buf_t;

typedef circular_buf_t* cbuff_handle_t;

// pass buffer to be used for circular buffer and size of buffer
// returns handle to circular buffer
cbuff_handle_t cbuff_init(uint8_t* buffer, size_t size);

// free memory allocated for circular buffer
void cbuff_free(cbuff_handle_t handle);

// erase all data in circular buffer
void cbuff_reset(cbuff_handle_t handle);

// write data to circular buffer, witout checking if buffer is full
void cbuff_put(cbuff_handle_t handle, uint8_t data);

// write data to circular buffer, checking if buffer is full
// returns 0 if buffer is full, 1- if data is written
int cbuff_put2(cbuff_handle_t handle, uint8_t data);

// get data from circular buffer,
// returns 0 if buffer is empty, 1- if data is read
int cbuff_get(cbuff_handle_t handle, uint8_t* data);

// get buffer max size
size_t cbuff_capacity(cbuff_handle_t handle);

// get buffer current size
size_t cbuff_size(cbuff_handle_t handle);

// returns true if buffer is full
bool cbuff_full(cbuff_handle_t handle);

// returns true if buffer is empty
bool cbuff_empty(cbuff_handle_t handle);

#endif  // RING_BUFFER_H