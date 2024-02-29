idf_component_register(
        SRCS main.c
        app/wifi_dpp.c
        app/wifi_connect.c
        driver/lvgl_driver/lvgl_init.c
        driver/lvgl_driver/lv_port_indev.c
        driver/littlefs_init.c
        gui/gui_qrcode.c
        gui/custom/custom.c
        gui/carousel/lv_carousel.c
        gui/dclock/lv_dclock.c
        gui/generated/events_init.c
        gui/generated/gui_guider.c
        gui/generated/setup_scr_about_page.c
        gui/generated/setup_scr_main_page.c
        gui/generated/setup_scr_setting_page.c
        gui/generated/setup_scr_uart_chart_page.c
        gui/generated/guider_fonts/lv_font_montserratMedium_10.c
        gui/generated/guider_fonts/lv_font_montserratMedium_12.c
        gui/generated/guider_fonts/lv_font_montserratMedium_16.c
        gui/generated/guider_fonts/lv_font_montserratMedium_32.c
        gui/generated/guider_fonts/lv_font_simsun_18.c
        gui/generated/images/_setting_alpha_60x60.c
        gui/generated/images/_setting_press_alpha_60x60.c
        gui/generated/images/_uart_alpha_60x60.c
        gui/generated/images/_uart_press_alpha_60x60.c

        INCLUDE_DIRS app/
        driver/
        gui/
        gui/carousel
        gui/dclock
        gui/custom
        gui/generated
        gui/generated/guider_customer_fonts
        gui/generated/guider_fonts
        gui/generated/images
)
