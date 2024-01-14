idf_component_register(
        SRCS main.c
        driver/lvgl_driver/lvgl_init.c
        driver/lvgl_driver/lv_port_indev.c
        driver/littlefs_init.c
        gui/gui_qrcode.c

        INCLUDE_DIRS app/
        driver/
        gui/
)
