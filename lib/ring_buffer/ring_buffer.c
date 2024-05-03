#include "ring_buffer.h"

#include <assert.h>
#include <stdlib.h>

struct circular_buf_t
{
    uint8_t *buffer;
    size_t head;
    size_t tail;
    size_t max; // of the buffer
    bool full;
};

cbuff_handle_t cbuff_init(uint8_t *buffer, size_t size)
{
    assert(buffer && size);

    cbuff_handle_t handle = malloc(sizeof(circular_buf_t));
    assert(handle);

    handle->buffer = buffer;
    handle->max = size;
    cbuff_reset(handle);
    assert(cbuff_empty(handle));

    return handle;
}

void cbuff_free(cbuff_handle_t handle)
{
    free(handle);
}

void cbuff_reset(cbuff_handle_t handle)
{
    assert(handle);

    handle->head = 0;
    handle->tail = 0;
}

bool cbuff_full(cbuff_handle_t handle)
{
    assert(handle);

    return handle->full;
}

bool cbuff_empty(cbuff_handle_t handle)
{
    assert(handle);

    return (!handle->full && (handle->head == handle->tail));
}

size_t cbuff_capacity(cbuff_handle_t handle)
{
    assert(handle);

    return handle->max;
}

size_t cbuff_size(cbuff_handle_t handle)
{
    assert(handle);

    size_t size = handle->max;

    if (!handle->full)
    {
        if (handle->head >= handle->tail)
        {
            size = (handle->head - handle->tail);
        }
        else
        {
            size = (handle->max + handle->head - handle->tail);
        }
    }

    return size;
}

static void advance_pointer(cbuff_handle_t handle)
{
    assert(handle);

    if (handle->full)
    {
        if (++(handle->tail) == handle->max)
        {
            handle->tail = 0;
        }
    }

    if (++(handle->head) == handle->max)
    {
        handle->head = 0;
    }
    handle->full = (handle->head == handle->tail);
}

static void retreat_pointer(cbuff_handle_t handle)
{
    assert(handle);

    handle->full = false;
    if (++(handle->tail) == handle->max)
    {
        handle->tail = 0;
    }
}

void cbuff_put(cbuff_handle_t handle, uint8_t data)
{
    assert(handle && handle->buffer);

    handle->buffer[handle->head] = data;
    advance_pointer(handle);
}

int cbuff_put2(cbuff_handle_t handle, uint8_t data)
{
    assert(handle && handle->buffer);

    if (cbuff_full(handle))
    {
        return 0;
    }

    handle->buffer[handle->head] = data;
    advance_pointer(handle);

    return 1;
}

int cbuff_get(cbuff_handle_t handle, uint8_t *data)
{
    assert(handle && data && handle->buffer);

    if (cbuff_empty(handle))
    {
        return 0;
    }

    *data = handle->buffer[handle->tail];
    retreat_pointer(handle);

    return 1;
}
