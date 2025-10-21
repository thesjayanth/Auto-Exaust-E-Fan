# Auto Exhaust E-Fan

An **Arduino-based automatic exhaust fan** designed to reduce noise and power consumption.  
The fan speed automatically adjusts based on room temperature using the LM35 sensor.

---

## 🔍 Problem Statement
Traditional exhaust fans in hotels and homes run continuously, causing:
- Loud noise disturbances
- High electricity usage
- Reduced fan lifespan

---

## 🎯 Objective
To design an **automated exhaust fan system** using Arduino that:
- Monitors temperature in real-time
- Controls fan speed automatically
- Reduces noise and energy waste

---

## ⚙️ Components Used
| Component | Purpose |
|------------|----------|
| Arduino Uno | Controls the entire system |
| LM35 Temperature Sensor | Detects room temperature |
| 12V DC Fan | Cooling device controlled via Arduino |
| 16x2 LCD | Displays temperature and fan speed |
| Transistor (2N2222) | Used for fan power control |
| Potentiometer (10K) | Adjusts display contrast and signal control |
| Resistors, Diodes, Capacitors | Circuit stability |
| Jumper Wires, Breadboard | Connections and prototyping |

---

## 🧩 Circuit Diagram
You can find the circuit diagram in the `Circuit_Diagram` folder.

---

## 💻 Arduino Code
Code is located in the `Code/auto_exhaust_fan.ino` file.

---

## 🧠 Working Principle
1. LM35 senses the current room temperature.  
2. Arduino compares it with the threshold (e.g., 30°C).  
3. If the temperature rises above the threshold, the fan automatically starts.  
4. The LCD displays the temperature and fan speed in percentage.  
5. Fan stops automatically when temperature drops below the threshold.

---

## 📈 Benefits
✅ Reduced electricity usage  
✅ Lower noise levels  
✅ Automation for comfort  
✅ Environment-friendly approach

---

## 🧾 Budget
| Component | Cost (INR) |
|------------|------------|
| Arduino Board | 800 |
| Breadboard | 120 |
| 9V Battery | 25 |
| Transistor (2N2222) | 15 |
| Resistor (1K) | 15 |
| Connecting wires | 60 |
| 12V DC Fan | 160 |
| Potentiometer (10K) | 400 |
| LCD Display | 250 |
| LM35 Sensor | 80 |
| **Total** | **₹2,040** |

---

## 📜 License
This project is open-source under the [MIT License](LICENSE).

---

## 👤 Author
**[Jayanth]**  
Electronics and Communication Engineering  
Institute of Aeronautical Engineering, Hyderabad
