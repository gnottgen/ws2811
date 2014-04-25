/*
 * Leds.h
 *
 * Created: 22.03.2014 12:46:18
 *  Author: stenkelfled
 */ 


#ifndef LEDS_H_
#define LEDS_H_

#define SEND_BITS_PER_DATA_BIT	(4)
#define BYTES_PER_COLOR			(SEND_BITS_PER_DATA_BIT)//*8/8) //*8Bits/Color-Byte, /8send-Bits/data-Byte
#define BYTES_PER_LED			(BYTES_PER_COLOR*3)
#define LED_COUNT				(100)
#define GROUP_COUNT				(8)

#define LED_CODE_1				(0b0011) //lsb is transmitted first
#define LED_CODE_0				(0b0001) //lsb is transmitted first

//#define LED_GN_ON			()

typedef struct{
	uint8_t red[BYTES_PER_COLOR];
	uint8_t green[BYTES_PER_COLOR];
	uint8_t blue[BYTES_PER_COLOR];
}led_data_t;


void usart_init(void);
void dma_init(void);

#endif /* LEDS_H_ */