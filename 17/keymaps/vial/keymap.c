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



#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

bool oled_task_user(void) {
    render_logo();
    return true;
}
#endif
