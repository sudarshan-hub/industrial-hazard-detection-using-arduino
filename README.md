# Industrial-Hazard-detection-using-Arduino

## Background of the Project
  The gas leakage in industries is highly risky and it is hazardous for employees working there. Safety is an essential component of any healthy workspace. Research so far in the area of safety has been revealed that majority of incidents in hazardous industry takes place because of human error, the control which would enhance safety levels in working sites to a considerable extent. This project is intended to provide a secured surrounding for the people who risk their life in industries. The aim of this project is to alert the workers in the field if the concentration of gases increases beyond the set value by gathering the data with the help of advanced technologies.

## Proposed system
  The transmitting unit uses three different sensors namely MQ-4(gas sensor to detect smoke, methane), flame sensor (detect fire) and vibration sensor (detect the roof collapse). The sensors are connected to the analog pins of Arduino UNO and the collected sensor data is displayed on the 16×2 LCD display. Then communication establishment occurs between sensors and GSM module. The data is then transmitted through GSM as message. In the receiving side, the receiver (rescue team) will receive an alert and do the necessary.

