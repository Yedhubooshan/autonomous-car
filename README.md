# RC-and-Auto-Directing-Robo-Car

## Components Required:

- Arduino UNO(*) - Qty: 1
- HC-05 Bluetooth Module - Qty: 1 (password : 0000 or 1234)
- HC-SR04 Ultrasonic Sensor - Qty: 1
- Servo Motor - Qty: 1
- L298N Motor Driver - Qty: 1
- DC Motor (3V - 12V) - Qty: 2
- Power Supply 9V - 12V(*) - Qty: 1
- Switch (on/off)
- Chasis

## Circuit Diagram :

<img src="https://github.com/Yedhubooshan/autonomous-car/blob/master/Simulation%20diagram.JPG?raw=true" alt = "circuit diagram" />

## Software Required:
- Arduino IDE (https://www.arduino.cc/en/main/software)
- Bluetooth Car Controller App (https://play.google.com/store/apps/details?id=braulio.calle.bluetoothRCcontroller&hl=en_IN)

### Note:
1* Arduino UNO with cable to upload the code.

2* But after the finished project, DC connecting cable will be used to power the circuits. Also +5V pin in Arduino UNO can ve used to power the motor driver and the Servo motor. +3.3V from the Arduino board can be used to power the bluetooth module and ultrasonic sensor.

3* Sound button in the mobile app can be used to make the robot go into automatic mode, and forward button can be pressed(for more than 2 seconds) to generate the interrupt and turn the robot back to RC mode.

4* In order to change your bluetooth module name or password or any other parameter checking, search about "AT bluetooth module commands". 

Thanks to:
- The creator of the bluetooth app, Andi.co.
