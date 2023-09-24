#ifndef APP_INCLUDE_INTERFACE_COMPONENTS_H_
#define APP_INCLUDE_INTERFACE_COMPONENTS_H_

#include <gtk/gtk.h>

#include <stdbool.h>

typedef struct {
    GtkWidget *window;
    GtkWidget *label_result;
    GtkWidget *entry_expression;
    GtkWidget *button_0;
    GtkWidget *button_1;
    GtkWidget *button_2;
    GtkWidget *button_3;
    GtkWidget *button_4;
    GtkWidget *button_5;
    GtkWidget *button_6;
    GtkWidget *button_7;
    GtkWidget *button_8;
    GtkWidget *button_9;
    GtkWidget *button_comma;
    GtkWidget *button_mod;
    GtkWidget *button_divide;
    GtkWidget *button_times;
    GtkWidget *button_minus;
    GtkWidget *button_plus;
    GtkWidget *button_power;
    GtkWidget *button_root;
    GtkWidget *button_clear;
    GtkWidget *button_equals;
} widgets_t;

bool user_interface_init(int *main_argc, char **main_argv[]);

void user_interface_start(void);

void user_interface_set_expression_text(const char *text);

const char *user_interface_get_expression_text(void);

void user_interface_set_result_text(const char *text);

const char *user_interface_get_result_text(void);

void user_interface_append_to_expression_text(char symbol);

void user_interface_empty_fields(void);

void user_interface_free(void);

#endif
