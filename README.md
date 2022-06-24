# precognitive_LED
Arduino-based implementation of a device to test a perceptual illusion

## The Theory
Our perception of "now" is actually on a bit of a delay, since our brains need time to process sensory information and construct our internal models of reality. This takes about 80ms.

In theory, any events that happen within 80ms of each other will be perceived as simultaneous.

If you become acclimated to perceiving two events 80ms apart as simultaneous and then that delay is removed, you will perceive the second event as occuring before the first one.

## The Device
### Assembly
1. Connect the positive lead of an LED to pin D5 on the Arudino and the other end to ground through a current-limiting resistor (220 Ohm is fine).
2. Connect one momentary pushbutton between pin D3 and ground
3. Connect a second momenty pushbutton between pin D2 and ground

### Use
When powered, pushing the button connected to D2 will initiate an 80ms delay after which the LED on pin D5 will turn on briefly.

Pushing the button connected to D3 will arm "precognitive mode." In this mode, the next time the button on D2 is pressed, it will immediately turn on the LED. Precognitive mode will be disarmed automatically after this.

If you turn on the LED in normal mode several times and then arm precognitive mode, it should appear as though the light turns on just before you push the button.

This effect is subtle, and friends I've shown it to did not report observing it.

YMMV
