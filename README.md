# Water Pollution Monitoring RC Boat  
**Real-Time Remote Water Quality Analysis & Control**

## Project Description  
This RC boat is designed to autonomously monitor water pollution parameters in real-time while being remotely controlled. It integrates sensors for temperature, turbidity, and pH level measurements, transmitting data via Bluetooth. The system features dual motor control for propulsion and a servo mechanism for directional steering, with visual/audible alerts for abnormal water conditions.

## Key Features  
- 🌡️ Temperature monitoring (DS18B20 sensor)  
- 🌀 Turbidity measurement (Analog turbidity sensor)  
- 🧪 pH level detection (pH electrode module)  
- 🚤 Dual DC motor control for forward/reverse motion  
- 🎮 Servo-based steering (left/center/right positions)  
- 📲 Bluetooth data transmission & command control  
- 🔔 Buzzer alert system for critical readings  
- 📊 Serial terminal data logging (local & remote)

## Pin Configuration  
| Arduino Pin | Component       | Note                     |  
|-------------|-----------------|--------------------------|  
| 2           | DS18B20 Data    | Temperature sensor       |  
| 5           | Red LED         | Motor status indicator   |  
| 6           | Green LED       | System status            |  
| 7           | Yellow LED      | Steering indicator       |  
| 8           | Servo PWM       | Steering control (sPin)  |  
| 9           | Motor A         | Forward motion control   |  
| 10          | Motor B         | Reverse motion control   |  
| 11          | Bluetooth RX    | HC-05/06 module          |  
| 12          | Bluetooth TX    | HC-05/06 module          |  
| A1          | Buzzer          | Audio alerts             |  
| A4          | pH Sensor       | Analog input             |  
| A5          | Turbidity Sensor| Analog input             |  

*Note: Schematic diagrams may require verification with actual hardware implementation*

## Included Code Files
- `Water_Quality_RC_Boat.ino` : Main control logic with sensor integration

## Operational Commands  
**Movement Control:**  
- `f` = Forward motion (pulsed)  
- `b` = Reverse motion
