#include "module/calc_manager/include/calc_manager.h"

#include <math.h>
#include <string.h>
#include <string.h>

#include "view/include/user_interface.h"

#define CALC_MANAGER_EXPRESSION_DEFAULT_SIZE    1024
#define CALC_MANAGER_RESULT_DEFAULT_SIZE        64

typedef struct {
    char *str;
    size_t size;
} string_t;

string_t *prv_expression_string = NULL;
string_t *prv_result_string = NULL;
calc_manager_operation_t prv_current_operation = kCALC_MANAGER_OPERATION_NO_OP;

// =============================================
// PRIVATE FUNCTIONS DECLARATION
// =============================================
static void prv_calc_manager_submit_result(void);

bool prv_calc_manager_is_result_empty(void);

bool prv_calc_manager_is_expression_empty(void);

// =============================================
// PUBLIC FUNCTIONS IMPLEMENTATION
// =============================================
void calc_manager_init(void) {
    prv_expression_string = (string_t *) malloc(sizeof(string_t));
    prv_expression_string->str = (char *) malloc(sizeof(char)*CALC_MANAGER_EXPRESSION_DEFAULT_SIZE + 1);
    prv_expression_string->size = CALC_MANAGER_EXPRESSION_DEFAULT_SIZE;
    prv_expression_string->str[0] = '\0';

    prv_result_string = (string_t *) malloc(sizeof(string_t));
    prv_result_string->str = (char *) malloc(sizeof(char)*CALC_MANAGER_RESULT_DEFAULT_SIZE + 1);
    prv_result_string->size = CALC_MANAGER_RESULT_DEFAULT_SIZE;
    prv_result_string->str[0] = '\0';
}

const char *calc_manager_get_result(void) {
    return prv_result_string->str;
}

const char *calc_manager_get_expression(void) {
    return prv_expression_string->str;
}

void calc_manager_set_expression(const char *str) {
    if(!str) {
        return;
    }
    strcpy(prv_expression_string->str, str);
}

void calc_manager_append_to_expression(char symbol) {
    char symbol_str[] = {symbol, '\0'};
    if (prv_calc_manager_is_expression_empty()) {
        strcpy(prv_expression_string->str, symbol_str);
    }
    else {
        strcat(prv_expression_string->str, symbol_str);
    }
}

bool calc_manager_execute_operation(calc_manager_operation_t operation) {
    if(operation == kCALC_MANAGER_OPERATION_ROOT) {
        prv_current_operation = operation;
        calc_manager_execute_current_operation();
    }
    else if(prv_calc_manager_is_result_empty()) {
        prv_current_operation = operation;
        prv_calc_manager_submit_result();
        return false;
    }
    else if(prv_current_operation == kCALC_MANAGER_OPERATION_NO_OP) {
        calc_manager_execute_current_operation();
        prv_current_operation = operation;
    }
    else if(operation == kCALC_MANAGER_OPERATION_EQUALS) {
        calc_manager_execute_current_operation();
        prv_current_operation = kCALC_MANAGER_OPERATION_NO_OP;
    }
    else {
        prv_current_operation = operation;
        calc_manager_execute_current_operation();
    }
    return true;
}

void calc_manager_execute_current_operation(void) {
    double op1 = 0;
    double op2 = 0;

    switch (prv_current_operation) {
    default:
        break;
    case kCALC_MANAGER_OPERATION_ADD:
        op1 = atof(prv_expression_string->str);
        op2 = atof(prv_result_string->str);
        op2 += op1;
        gcvt(op2, 6, prv_expression_string->str);
        break;
    case kCALC_MANAGER_OPERATION_SUB:
        op1 = atof(prv_expression_string->str);
        op2 = atof(prv_result_string->str);
        op2 -= op1;
        gcvt(op2, 6, prv_expression_string->str);
        break;
    case kCALC_MANAGER_OPERATION_MULT:
        op1 = atof(prv_expression_string->str);
        op2 = atof(prv_result_string->str);
        op2 *= op1;
        gcvt(op2, 6, prv_expression_string->str);
        break;
    case kCALC_MANAGER_OPERATION_DIV:
        op1 = atof(prv_expression_string->str);
        op2 = atof(prv_result_string->str);   
        if(op1 == 0) {
            strcpy(prv_expression_string->str, "Can't divide by zero!");
            break;
        }    
        op2 /= op1;
        gcvt(op2, 6, prv_expression_string->str);
        break;
    case kCALC_MANAGER_OPERATION_MOD:
        op1 = atof(prv_expression_string->str);
        op2 = atof(prv_result_string->str);
        op2 = ((int) op2) % ((int) op1);
        gcvt(op2, 6, prv_expression_string->str);
        break;
    case kCALC_MANAGER_OPERATION_POWER:
        op1 = atof(prv_expression_string->str);
        op2 = atof(prv_result_string->str);
        op2 = pow(op2, op1);
        gcvt(op2, 6, prv_expression_string->str);
        break;
    case kCALC_MANAGER_OPERATION_ROOT:
        op1 = atof(prv_expression_string->str);
        op2 = sqrt(op1);
        gcvt(op2, 6, prv_expression_string->str);
        break;
    }
    prv_calc_manager_submit_result();
}

void calc_manager_empty_fields(void) {
    prv_result_string->str[0] = '\0';
    prv_expression_string->str[0] = '\0';
    prv_current_operation = kCALC_MANAGER_OPERATION_NO_OP;
}

void calc_manager_free(void) {
    free(prv_expression_string->str);
    free(prv_expression_string);
    free(prv_result_string->str);
    free(prv_result_string);
}

// =============================================
// PRIVATE FUNCTIONS IMPLEMENTATION
// =============================================
static void prv_calc_manager_submit_result(void) {
    if(strlen(prv_expression_string->str) == 0) {
        return;
    }
    strcpy(prv_result_string->str, prv_expression_string->str);
    prv_expression_string->str[0] = '\0';
    user_interface_set_expression_text(prv_expression_string->str);
    user_interface_set_result_text(prv_result_string->str);
}

bool prv_calc_manager_is_result_empty(void) {
    return strlen(prv_result_string->str) == 0;
}

bool prv_calc_manager_is_expression_empty(void) {
    return strlen(prv_expression_string->str) == 0;
}
