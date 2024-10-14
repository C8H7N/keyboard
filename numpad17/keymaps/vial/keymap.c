#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT (
        KC_MUTE ,                             KC_NUM ,
        TO(0)   ,KC_P7   ,KC_P8     ,KC_P9   ,
        TO(1)   ,KC_P4   ,KC_P5     ,KC_P6   ,KC_PPLS,
        TO(2)   ,KC_P1   ,KC_P2     ,KC_P3   ,
        TO(3)   ,KC_P0   ,KC_PDOT   ,KC_PENT
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),ENCODER_CCW_CW(RGB_VAD, RGB_VAI)}
};
#endif
