/*
 * Auto Exhaust E-Fan
 * -------------------
 * Controls a DC fan speed based on temperature using LM35 sensor.
 * 
 * Language: C
 * Compatible with: AVR / ARM / 8051 / PIC (with minimal modifications)
 * 
 * Author: Just Jayanth
 * Year: 2025
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// ----------- Configuration (Modify as per your hardware) -----------
#define TEMP_MIN 25.0     // Fan off below this temperature (°C)
#define TEMP_MAX 40.0     // Fan full speed above this temperature (°C)

// Simulated function stubs (replace with microcontroller-specific functions)
float readTemperature(void);
void setFanSpeed(uint8_t pwmValue);
void lcdPrint(char *line1, char *line2);
void delay_ms(unsigned int ms);

// -------------------- Main Function --------------------
int main(void)
{
    float temperature = 0.0;
    uint8_t fanPWM = 0;
    uint8_t fanSpeedPercent = 0;
    char line1[20], line2[20];

    // Initialize LCD, ADC, PWM here (platform specific)
    // e.g., lcd_init(); adc_init(); pwm_init();

    while (1)
    {
        // Read temperature from LM35 (10mV/°C)
        temperature = readTemperature();

        // Calculate PWM output based on temperature
        if (temperature < TEMP_MIN)
        {
            fanPWM = 0;
        }
        else if (temperature > TEMP_MAX)
        {
            fanPWM = 255;
        }
        else
        {
            fanPWM = (uint8_t)(((temperature - TEMP_MIN) / (TEMP_MAX - TEMP_MIN)) * 255);
        }

        // Control fan speed (PWM)
        setFanSpeed(fanPWM);

        // Calculate speed percentage for display
        fanSpeedPercent = (fanPWM * 100) / 255;

        // Display info on LCD (simulated with printf here)
        sprintf(line1, "Temp: %.1f C", temperature);
        sprintf(line2, "Fan: %d%%", fanSpeedPercent);
        lcdPrint(line1, line2);

        delay_ms(1000); // 1 second delay
    }

    return 0;
}

// -------------------- Helper Functions --------------------

// Simulate reading temperature (Replace with ADC read logic)
float readTemperature(void)
{
    // Example: simulate temperature change
    static float t = 24.0;
    t += 0.5;
    if (t > 42.0)
        t = 24.0;
    return t;
}

// Simulate PWM output (Replace with microcontroller PWM register code)
void setFanSpeed(uint8_t pwmValue)
{
    // Example: print PWM value (0–255)
    printf("PWM Output: %d\n", pwmValue);
}

// Simulate LCD display (Replace with actual LCD library functions)
void lcdPrint(char *line1, char *line2)
{
    printf("%s | %s\n", line1, line2);
}

// Simulated delay
void delay_ms(unsigned int ms)
{
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}
