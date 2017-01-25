# arduino_uav
Telecommunications system using arduino platform

This project is about my thesis.

The idea is to build a telecommunications system using specialized platforms like Arduino and Raspberry Pie.
This scenario develops a sensor network between four Arduinos. Two of the Arduinos are ground stations equipped with sensors, the first measures the humidity and the temperature of the air and the second the soil moisture.
Also the second station has the ability to control an electric motor depending on the measurements of the sensor.
The third Arduino platform can be attached on a UAV. It can collect the measurements from the ground stations, when it is in their range. In different case, the two stations switch to standby reception mode where stop sending the measurements until the UAV enters in their range.
When a measurement is received, the Arduino on the UAV adds a timestamp to it and stores the timed data to an SD memory card. Then forwards this timed data to the fourth and final Arduino.
That Arduino is called User device because it can receive and display the collected data.
