#include "view/include/user_interface.h"

#include "module/calc_manager/include/calc_manager.h"

void on_window_destroy(void) {
    gtk_main_quit();
}

void on_button_0_clicked(GtkButton *button_0, void *user_data) {
    user_interface_append_to_expression_text('0');
}

void on_button_1_clicked(GtkButton *button_1, void *user_data) {
    user_interface_append_to_expression_text('1');
}

void on_button_2_clicked(GtkButton *button_2, void *user_data) {
    user_interface_append_to_expression_text('2');
}

void on_button_3_clicked(GtkButton *button_3, void *user_data) {
    user_interface_append_to_expression_text('3');
}

void on_button_4_clicked(GtkButton *button_4, void *user_data) {
    user_interface_append_to_expression_text('4');
}

void on_button_5_clicked(GtkButton *button_5, void *user_data) {
    user_interface_append_to_expression_text('5');
}

void on_button_6_clicked(GtkButton *button_6, void *user_data) {
    user_interface_append_to_expression_text('6');
}

void on_button_7_clicked(GtkButton *button_7, void *user_data) {
    user_interface_append_to_expression_text('7');
}

void on_button_8_clicked(GtkButton *button_8, void *user_data) {
    user_interface_append_to_expression_text('8');
}

void on_button_9_clicked(GtkButton *button_9, void *user_data) {
    user_interface_append_to_expression_text('9');
}

void on_button_mod_clicked(GtkButton *button_mod, void *user_data) {
    calc_manager_execute_operation(kCALC_MANAGER_OPERATION_MOD);
}

void on_button_comma_clicked(GtkButton *button_comma, void *user_data) {
    
}

void on_button_divide_clicked(GtkButton *button_divide, void *user_data) {
    calc_manager_execute_operation(kCALC_MANAGER_OPERATION_DIV);
}

void on_button_times_clicked(GtkButton *button_times, void *user_data) {
    calc_manager_execute_operation(kCALC_MANAGER_OPERATION_MULT);
}

void on_button_minus_clicked(GtkButton *button_minus, void *user_data) {
    calc_manager_execute_operation(kCALC_MANAGER_OPERATION_SUB);
}

void on_button_plus_clicked(GtkButton *button_plus, void *user_data) {
    calc_manager_execute_operation(kCALC_MANAGER_OPERATION_ADD);
}

void on_button_power_clicked(GtkButton *button_power, void *user_data) {
    calc_manager_execute_operation(kCALC_MANAGER_OPERATION_POWER);
}

void on_button_root_clicked(GtkButton *button_root, void *user_data) {
    calc_manager_execute_operation(kCALC_MANAGER_OPERATION_ROOT);
}

void on_button_equals_clicked(GtkButton *button_equals, void *user_data) {
    calc_manager_execute_operation(kCALC_MANAGER_OPERATION_EQUALS);
}

void on_button_clear_clicked(GtkButton *button_equals, void *user_data) {
    user_interface_empty_fields();
}

/*
gboolean on_entry_expression_focus_out_event(GtkWidget *entry_expression, void *user_data) {
    gtk_widget_grab_focus(entry_expression);
    return TRUE;
}
*/
void on_entry_expression_changed(GtkEditable *entry_expression, void *user_data) {
    const char *entry_text = user_interface_get_expression_text();
    calc_manager_set_expression(entry_text);
}
