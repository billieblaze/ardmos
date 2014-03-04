#include "Event.h"
#define I2C_DEVICE_DEBUG
#include <I2C.h>

EventManager evtManager;
int ledPin = 4;
boolean ledOn = false;
     
// Set up the LED task
struct LEDListener : public EventTask
{
    using EventTask::execute;
     
    void execute(Event evt)
    {
        if (ledOn == true)
        {
            digitalWrite(ledPin, LOW);
        }
        else
        {
            digitalWrite(ledPin, HIGH);
        }
    }
     
} LEDListener;
     
     
// Run the sketch
void setup()
{
    Serial.begin(115200);
    i2csetup();
   
    pinMode(ledPin, OUTPUT);
    evtManager.subscribe(Subscriber("led.on", &LEDListener));
     
    Event toggleLed = Event("led.on");
    evtManager.triggerInterval(TimedTask(2000, toggleLed));
}
     
void loop()
{
    evtManager.tick();
}





