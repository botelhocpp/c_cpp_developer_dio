#include "view/include/user_interface.h"

#include <gtk/gtk.h>

#include "module/calc_manager/include/calc_manager.h"

// =============================================
// PRIVATE VARIABLES
// =============================================
widgets_t *widgets = NULL;

// =============================================
// PRIVATE FUNCTIONS DECLARATION
// =============================================
static GtkBuilder *prv_user_interface_builder_init(void);

static void prv_user_interface_config_style(void);

static void prv_user_interface_builder_free(GtkBuilder *builder);

// =============================================
// PUBLIC FUNCTIONS IMPLEMENTATION
// =============================================
bool user_interface_init(int *main_argc, char **main_argv[]) {
    gtk_init(main_argc, main_argv);
    GtkBuilder *builder = prv_user_interface_builder_init();
    if(!builder) {
        return false;
    }
    
    widgets = g_slice_new(widgets_t);
    widgets->window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    widgets->label_result = GTK_WIDGET(gtk_builder_get_object(builder, "label_result"));
    widgets->entry_expression = GTK_WIDGET(gtk_builder_get_object(builder, "entry_expression"));
    widgets->button_0 = GTK_WIDGET(gtk_builder_get_object(builder, "button_0"));
    widgets->button_1 = GTK_WIDGET(gtk_builder_get_object(builder, "button_1"));
    widgets->button_2 = GTK_WIDGET(gtk_builder_get_object(builder, "button_2"));
    widgets->button_3 = GTK_WIDGET(gtk_builder_get_object(builder, "button_3"));
    widgets->button_4 = GTK_WIDGET(gtk_builder_get_object(builder, "button_4"));
    widgets->button_5 = GTK_WIDGET(gtk_builder_get_object(builder, "button_5"));
    widgets->button_6 = GTK_WIDGET(gtk_builder_get_object(builder, "button_6"));
    widgets->button_7 = GTK_WIDGET(gtk_builder_get_object(builder, "button_7"));
    widgets->button_8 = GTK_WIDGET(gtk_builder_get_object(builder, "button_8"));
    widgets->button_9 = GTK_WIDGET(gtk_builder_get_object(builder, "button_9"));
    widgets->button_comma = GTK_WIDGET(gtk_builder_get_object(builder, "button_comma"));
    widgets->button_mod = GTK_WIDGET(gtk_builder_get_object(builder, "button_mod"));
    widgets->button_divide = GTK_WIDGET(gtk_builder_get_object(builder, "button_divide"));
    widgets->button_times = GTK_WIDGET(gtk_builder_get_object(builder, "button_times"));
    widgets->button_minus = GTK_WIDGET(gtk_builder_get_object(builder, "button_minus"));
    widgets->button_plus = GTK_WIDGET(gtk_builder_get_object(builder, "button_plus"));
    widgets->button_power = GTK_WIDGET(gtk_builder_get_object(builder, "button_power"));
    widgets->button_root = GTK_WIDGET(gtk_builder_get_object(builder, "button_root"));
    widgets->button_clear = GTK_WIDGET(gtk_builder_get_object(builder, "button_clear"));
    widgets->button_equals = GTK_WIDGET(gtk_builder_get_object(builder, "button_equals"));

    gtk_builder_connect_signals(builder, widgets);
    prv_user_interface_builder_free(builder);
    prv_user_interface_config_style();
    gtk_widget_show(widgets->window);
    return true;
}

void user_interface_start(void) {
    gtk_main();
}

void user_interface_set_expression_text(const char *text) {
    gtk_entry_set_text(GTK_ENTRY(widgets->entry_expression), (const gchar *) text);
}

const char *user_interface_get_expression_text(void) {
    return (const char *) gtk_entry_get_text(GTK_ENTRY(widgets->entry_expression));
}

void user_interface_set_result_text(const char *text) {
    gtk_label_set_text(GTK_LABEL(widgets->label_result), (const gchar *) text);
}

const char *user_interface_get_result_text(void) {
    return (const char *) gtk_label_get_text(GTK_LABEL(widgets->label_result));
}

void user_interface_append_to_expression_text(char symbol) {
    calc_manager_append_to_expression(symbol);
    const char *expression_text = calc_manager_get_expression();
    user_interface_set_expression_text(expression_text);
}

void user_interface_empty_fields(void) {
    calc_manager_empty_fields();
    user_interface_set_result_text("");
    user_interface_set_expression_text("");
}

void user_interface_free(void) {
    g_slice_free(widgets_t, widgets);
}

// =============================================
// PRIVATE FUNCTIONS IMPLEMENTATION
// =============================================

static GtkBuilder *prv_user_interface_builder_init(void) {
    GtkBuilder *builder = gtk_builder_new();
    if (!builder) {
        g_print("Error while constructing GTK API Builder.\n");
        return NULL;
    }
    GError *err = NULL;
    guint status = gtk_builder_add_from_file(builder, "model/main_window.glade", &err);
    if (!status) {
        g_print("Error adding build from file. Error: %s\n", err->message);
        g_error_free(err);
        return NULL;
    }
    return builder;
}

static void prv_user_interface_config_style(void) {
    GtkCssProvider *entry_css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(entry_css_provider, "static/entry_expression_style.css", NULL);
    
    GtkStyleContext *entry_style_context = gtk_widget_get_style_context(widgets->entry_expression);
    gtk_style_context_add_provider(entry_style_context, GTK_STYLE_PROVIDER(entry_css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    
    GtkCssProvider *button_css_provider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(button_css_provider, "static/button_equals_style.css", NULL);

    GtkStyleContext *button_style_context = gtk_widget_get_style_context(widgets->button_equals);
    gtk_style_context_add_provider(button_style_context, GTK_STYLE_PROVIDER(button_css_provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
}

static void prv_user_interface_builder_free(GtkBuilder *builder) {
    g_object_unref(builder);
}
