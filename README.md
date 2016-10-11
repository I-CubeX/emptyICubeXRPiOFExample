##I-CubeX Raspberry Pi Shield Example for openFrameworks

![img](https://avatars1.githubusercontent.com/u/10518183?v=3&s=200)

This is a simple, minimal example showing how to use the Raspberry Pi Shield with I-CubeX sensors. It is part of our open source sensor interface platform, the [PiShield](https://infusionsystems.com/pishield/). The example app initializes the sensor interface and then performs 100 reads on the 8 analog input ports, followed by an i2c sensor (orient3d). it  prints the results to console, and then simply exits. It provides the basic building blocks to add sensing capability to your RPi oF application.

It has been tested with Raspbian Jessie on a RPi2 device, with openFrameworks 0.9.2 armv6 but should be functional on other distrubitions and hardware as long as your openFrameowkrs and hardware configuration is functional.



Requires wiringPi installed, as well as the i2c and spi devices to be configured properly. For full instructions please visit our website! [link here]
