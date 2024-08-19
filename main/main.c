/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN = 16; 

const int LED_PIN = 5;

const int PAR_1 = 21;
const int PAR_2 = 20;
const int PAR_3 = 19;
const int PAR_4 = 18;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN); // Ativando pull-up

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(PAR_1);
    gpio_init(PAR_2);
    gpio_init(PAR_3);
    gpio_init(PAR_4);

    gpio_set_dir(PAR_1, GPIO_OUT);
    gpio_set_dir(PAR_2, GPIO_OUT);
    gpio_set_dir(PAR_3, GPIO_OUT);
    gpio_set_dir(PAR_4, GPIO_OUT);






    bool button_pressed = false;

    while (true) {
        if (!gpio_get(BTN_PIN) && !button_pressed){
            button_pressed = true;
            printf("Botão aperdado! \n");


            for(int i = 0; i < (2048/8); i++){
                gpio_put(LED_PIN, 1);
                sleep_ms(20);
                gpio_put(PAR_1,1);
                sleep_ms(20);
                gpio_put(PAR_1,0);
                gpio_put(PAR_2,1);
                sleep_ms(20);
                gpio_put(PAR_2,0);
                gpio_put(PAR_3,1);
                sleep_ms(20);
                gpio_put(PAR_3,0);
                gpio_put(PAR_4,1);
                sleep_ms(20);
                gpio_put(PAR_4,0);
                sleep_ms(20);
                gpio_put(LED_PIN, 0);
                sleep_ms(120);
            }


            

        } else if (gpio_get(BTN_PIN)) {
            button_pressed = false; 
        }
        

    }
}
