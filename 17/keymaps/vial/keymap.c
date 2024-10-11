#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT (
        KC_NUM  ,KC_P7   ,KC_P8          ,KC_P9   ,KC_MUTE ,
        KC_PSLS ,KC_P4   ,KC_P5          ,KC_P6   ,KC_PPLS ,
        KC_PAST ,KC_P1   ,KC_P2          ,KC_P3   ,
        KC_PMNS ,KC_P0   ,LT(1,KC_PDOT)  ,KC_PENT
    ),
    [1] = LAYOUT (
        RGB_HUI ,RGB_TOG ,RGB_VAI ,XXXXXXX  ,XXXXXXX,
        RGB_HUD ,RGB_MOD ,KC_A    ,RGB_RMOD ,XXXXXXX,
        RGB_SAI ,RGB_SPI ,RGB_VAD ,RGB_SPD  ,
        RGB_SAD ,XXXXXXX ,XXXXXXX ,XXXXXXX
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
#endif

#if defined(RGB_MATRIX_ENABLE)
bool rgb_matrix_indicators_kb(void) {
    if (!rgb_matrix_indicators_user()) {
        return false;
    }
    if(host_keyboard_led_state().num_lock) {	//处于 NUM LOCK 状态
		rgb_matrix_set_color(0, 255, 0, 0);	//把序号0的灯变为红色（R:255, G:0, B:0）
	}
	if(get_highest_layer(layer_state) == 1) {	//如果在“1”层（Fn层）
		if(HAS_FLAGS(g_led_config.flags[15], 0x04)) {	//若该灯是轴座灯
			rgb_matrix_set_color(15, 153, 238, 255);			//颜色变为冰蓝色
		}
	}
    return true;
}
#endif
//



#if defined(OLED_ENABLE)
bool oled_task_user(void) {
    oled_write_P(PSTR("Hello World! "), false);
    return false;
}
#endif
