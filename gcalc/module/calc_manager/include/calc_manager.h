#ifndef MODULE_CALC_MANAGER_INCLUDE_CALC_MANAGER_H_
#define MODULE_CALC_MANAGER_INCLUDE_CALC_MANAGER_H_

#include <stdbool.h>

typedef enum {
    kCALC_MANAGER_OPERATION_NO_OP,
    kCALC_MANAGER_OPERATION_EQUALS,
    kCALC_MANAGER_OPERATION_ADD,
    kCALC_MANAGER_OPERATION_SUB,
    kCALC_MANAGER_OPERATION_MULT,
    kCALC_MANAGER_OPERATION_DIV,
    kCALC_MANAGER_OPERATION_MOD,
    kCALC_MANAGER_OPERATION_POWER,
    kCALC_MANAGER_OPERATION_ROOT
} calc_manager_operation_t;

void calc_manager_init(void);

const char *calc_manager_get_result(void);

const char *calc_manager_get_expression(void);

void calc_manager_set_expression(const char *str);

void calc_manager_append_to_expression(char symbol);

bool calc_manager_execute_operation(calc_manager_operation_t operation);

void calc_manager_execute_current_operation(void);

void calc_manager_empty_fields(void);

void calc_manager_free(void);

#endif
