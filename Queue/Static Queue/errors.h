#ifndef ERROR_H
#define ERROR_H

typedef enum error
{
    no_errors,
    invalid_pointer,
    memory_error,
    empty_queue,
    full_queue,
} error_t;

#endif //ERROR_H