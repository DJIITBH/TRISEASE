## TRISEASE
Trisease is simply a mouth opening smart device used for physiotherapy of patients suffering form Trismus disease, have difficulty in moving their lower jaw and thus need physiotherapy to overcome the stiffness.
The device halps them to excercise independently as well as monitor their progress by recording their data of distance moved by the lower jaw, the amount of force patient applied to achieve that much distance as well as 
the number of cycles of exercises perfromed by the patient.
Nonetheless, it communicates the data to a mobile application via WiFi, which can be accessible to the doctor from anywhere! ensuring easy monitoring of the patient.

## SENSORS
We have used Flex sensor to measure force applied by the patient and an analog based Infrared sensor to determine the linear distance jaws have moved.


![Force sensor](https://github.com/DJIITBH/TRISEASE/blob/main/force%20sensor.jpg)

![IR sensor](https://github.com/DJIITBH/TRISEASE/blob/main/Screenshot%20from%202024-01-09%2014-56-27.png)

## CODE 
We have used an ESP32 MCU to send the sensor's data to a mobile application using IOT. 
We used Thingspeak platform by Matlab for data storage and used API's to extract and represent the data in our mobile application for monitoring.
The code can be accessed from the INO file uploaded.

## Data Analysis
We used multivariate data analysis to calliberate the force and IR sensor's data into meaningful quantities and developed an efficient formulation to find accurate measurements.
The code has been uploaded.

## The device
#Early Stage:
First we developed a CAD model of the device and 3D printed the design and started integration of sensors in it.

![Device](https://github.com/DJIITBH/TRISEASE/blob/main/device1.jpeg)

Then after the calliberation, we made the circuit on a PCB and soldered the connections.

![Device](https://github.com/DJIITBH/TRISEASE/blob/main/device2.jpeg)


Here's the video of the device demonstrating the working:


[Video demonstration](https://youtu.be/JsGlxQTOuuI)





