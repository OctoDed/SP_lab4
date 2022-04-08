#include "mbed.h"
// Объявляем пин светодиода 1 как выход
DigitalOut oled1(LED1);
DigitalOut oled(D9);
InterruptIn ibutton1(BUTTON1);

Ticker toggle_led_ticker;
static auto sleep_time = 100ms;
void led_ticker()
{
    
oled1 = !oled1;


}
void pressed()
{
 toggle_led_ticker.detach(); // открепляет таймер
// Управление скоростью мерцания светодиода
sleep_time += 1000ms;
if (sleep_time > 3500ms)
sleep_time = 100ms;
 toggle_led_ticker.attach(&led_ticker, sleep_time); // прикрепляет
}




// Основной поток main
int main()
    {
        
toggle_led_ticker.attach(&led_ticker, sleep_time);
// Обратите внимание, что прерывания больше не могут управлять
// скоростью мигания светодиода
//ibutton1.fall(&released);
ibutton1.rise(&pressed);
while (true) {

    // oled1 = !oled1; // Включение/выключение светодиода
    ThisThread::sleep_for(sleep_time);
    oled=!oled;
    }
    }

