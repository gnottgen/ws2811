 /*
 * ledbuffer.h
 *
 * Created: 28.03.2014 10:48:58
 *  Author: stenkelfled
 */ 


#ifndef LEDBUFFER_H_
#define LEDBUFFER_H_

#include <compiler.h>

typedef struct{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
}__attribute__((packed)) rgbcolor_t;

typedef enum{
    normal = 0,
    shift,
    rainbow
}led_mode_t;

typedef struct _led_color_t_ led_color_t;

struct _led_color_t_{
    rgbcolor_t color;
    led_color_t *next_led;
}__attribute__((packed));

typedef struct{
    led_mode_t mode;
    led_color_t* start_led;
}__attribute__((packed)) led_group_t;

void color2data(uint8_t* *data, uint8_t color);
void fill_buffer(void);

void define_group(uint8_t group_id, uint8_t start_led,uint8_t end_led, uint8_t step);
void append_to_group(uint8_t group_id, uint8_t led_id);
void color_group(uint8_t group_id, rgbcolor_t color);
void color_led(uint8_t led_id, rgbcolor_t color);


#endif /* LEDBUFFER_H_ */