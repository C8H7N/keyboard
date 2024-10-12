#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT (
        KC_MUTE ,                                  KC_MUTE ,
        KC_NUM  ,KC_P7   ,KC_P8          ,KC_P9   ,
        KC_PSLS ,KC_P4   ,KC_P5          ,KC_P6   ,KC_PPLS ,
        KC_PAST ,KC_P1   ,KC_P2          ,KC_P3   ,
        KC_PMNS ,KC_P0   ,LT(1,KC_PDOT)  ,KC_PENT
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
#endif

// #if defined(RGB_MATRIX_ENABLE)
// bool rgb_matrix_indicators_kb(void) {
//     if (!rgb_matrix_indicators_user()) {
//         return false;
//     }
//     if(host_keyboard_led_state().num_lock) {	//处于 NUM LOCK 状态
// 		rgb_matrix_set_color(0, 255, 0, 0);	//把序号0的灯变为红色（R:255, G:0, B:0）
// 	}
// 	if(get_highest_layer(layer_state) == 1) {	//如果在“1”层（Fn层）
// 		if(HAS_FLAGS(g_led_config.flags[15], 0x04)) {	//若该灯是轴座灯
// 			rgb_matrix_set_color(15, 153, 238, 255);			//颜色变为冰蓝色
// 		}
// 	}
//     return true;
// }
// #endif
// //


#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("2\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("3\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
