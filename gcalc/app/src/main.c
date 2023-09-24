#include <gtk/gtk.h>

#include <stdlib.h>
#include <string.h>

#include "view/include/user_interface.h"
#include "module/calc_manager/include/calc_manager.h"

int main(int argc, char *argv[]) {
    if(!user_interface_init(&argc, &argv)) {
        return EXIT_FAILURE;
    }  
    calc_manager_init();
    user_interface_start();
    calc_manager_free();
    user_interface_free();
    return EXIT_SUCCESS;
}
