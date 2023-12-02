idf_component_register(
        SRCS main.c
        lvgl_driver/lvgl_init.c
        lvgl_driver/lv_port_indev.c

        INCLUDE_DIRS lvgl_driver/
)
