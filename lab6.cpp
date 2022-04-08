#include "mbed.h"
#include "BME280.h"


  
  
  BME280 sensor(I2C_SDA, I2C_SCL);


// RawSerial  dev(D14, D15);
DigitalOut oled1(LED1);
// DigitalOut oled(D9);
InterruptIn ibutton1(BUTTON1);

Ticker toggle_led_ticker;
static auto sleep_time = 1000ms;
void led_ticker()
{
    
oled1 = !oled1;


}
void pressed()
{
 toggle_led_ticker.detach(); // открепляет таймер
// Управление скоростью мерцания светодиода
sleep_time = 100ms;
// if (sleep_time > 3500ms)
// sleep_time = 100ms;
 toggle_led_ticker.attach(&led_ticker, sleep_time); // прикрепляет
}




// Основной поток main
char buf[2];
int main()
    {
        
toggle_led_ticker.attach(&led_ticker, sleep_time);
// Обратите внимание, что прерывания больше не могут управлять
// скоростью мигания светодиода
//ibutton1.fall(&released);
// ibutton1.rise(&pressed);
while (true) {
    
    // string tmp_out = i2c.read(addr8bit, buf, 2);
    // printf(tmp_out);
    printf("%d degC, %d hPa, %d %%\n", (int)sensor.getTemperature(), (int)sensor.getPressure(), (int)sensor.getHumidity());
    if ((int)sensor.getTemperature()>=30){
        // sleep_time = 100ms;
        pressed();
        printf(" temp \n");
    }
    else {
        toggle_led_ticker.detach(); // открепляет таймер
sleep_time = 1000ms;
 toggle_led_ticker.attach(&led_ticker, sleep_time); // прикрепляет

        }
    
    // i2c.read(addr8bit, buf, 2);
    //printf(" temp \n");
    // printf(%d, i2c.read(addr8bit, buf, 2));
    //oled1 = !oled1; // Включение/выключение светодиода
    ThisThread::sleep_for(1000ms);
    
    }
    }


