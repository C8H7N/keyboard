#include "quantum.h"

bool oled_task_user(void) {
    uint8_t charmax = oled_max_chars();
    char    line0[charmax + 1];
    char    line1[charmax + 1];
    char    line2[charmax + 1];
    char    line3[charmax + 1];

    // Host Keyboard LED Status
    led_t   led_state = host_keyboard_led_state();
    uint8_t rgbval    = rgblight_get_val();
    uint8_t rgbspd    = rgblight_get_speed();
    uint8_t rgbhue    = rgblight_get_hue();
    uint8_t rgbsat    = rgblight_get_sat();

    char layer[10];
    // Host Keyboard Layer Status
    switch (get_highest_layer(layer_state)) {
        case 0:
            strcpy(layer, "Number");
            break;
        case 1:
            strcpy(layer, "Function");
            break;
        case 2:
            strcpy(layer, "Custom");
            break;
        case 3:
            strcpy(layer, "Macros");
            break;
        default:
            strcpy(layer, "Undefined");
    }
    snprintf(line0, sizeof(line0), "Layer:%9s%5s", layer, led_state.num_lock ? "NUM" : "");
    oled_write_ln_P(PSTR(line0), false);

    snprintf(line1, sizeof(line1), "Bri:%3u Spd:%3u%5s", rgbval, rgbspd, led_state.caps_lock ? "CAP" : "");
    oled_write_ln_P(PSTR(line1), false);

    snprintf(line2, sizeof(line2), "Hue:%3u Sat:%3u%5s", rgbhue, rgbsat, led_state.scroll_lock ? "SCR " : "");
    oled_write_ln_P(PSTR(line2), false);

    snprintf(line3, sizeof(line3), "Creator Dock");
    oled_write_ln_P(PSTR(line3), false);

    return false;
}
