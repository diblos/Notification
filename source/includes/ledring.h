/*
 * ledring.h
 *
 * Created: 2015-07-02 6:18:35 PM
 *  Author: Justin
 */ 


#ifndef LEDRING_H_
#define LEDRING_H_

#define LEDRING_LED1	(1<<0)
#define LEDRING_LED2	(1<<1)
#define LEDRING_LED3	(1<<2)
#define LEDRING_LED4	(1<<3)
#define LEDRING_LED5	(1<<4)
#define LEDRING_LED6	(1<<5)
#define LEDRING_LED7	(1<<6)
#define LEDRING_LED8	(1<<7)
#define LEDRING_LEDALL	LEDRING_LED1|LEDRING_LED2|LEDRING_LED3|LEDRING_LED4|LEDRING_LED5|LEDRING_LED6|LEDRING_LED7|LEDRING_LED8


//turn on LEDRING by providing color in 16 bits
//IN: LedIds, OR LIST of LED ID to turn on
//IN: color in 16 bits. 0=Turn OFF led ring
extern void ledring_on(unsigned short ledIds, unsigned short color16);

//Turn OFF LEDRING respective to the ledid specified
void ledring_off(unsigned short ledIds);

//set LED light for LedId 1 to 8
//rgb color, 0=OFF, 1=Min, 0xFF=Max, 256 steps
void ledring_set(unsigned short ledIds, unsigned char red, unsigned char green, unsigned char blue);

//feed background ledring running in period of ms
//this function should put in main while loop
//in: periodms: period of next change color (suggest 70), put 0 to turn off
void ledring_background(int periodms);


//old links
extern void led_ring_on(unsigned char colour);
extern void led_ring_off(void);


#endif /* LEDRING_H_ */