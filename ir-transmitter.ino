// ir-transmitter.ino
//

SYSTEM_MODE(MANUAL);

#include "ir-transmitter.h"

using namespace Transmitter;

void setup() {
	Program::Setup();
}

void loop() {
	Program::Loop();
/*
    if (client.connected())
    {
        uint8_t ibuf[1024] = { 0 };
        uint32_t c = 0, t = 0;

        while (client.available() > 0)
        {
            SPARK_WLAN_Loop();

            c = client.read(ibuf, sizeof(ibuf) - t);
            t += c;
        }

        if (t > 0)
        {
			const uint8_t dfu[] = "DFU";
			const uint8_t reset[] = "RESET";
            const uint8_t cmd1[] = "HW-C560S";
            const uint8_t cmd2[] = "VIP2262";

            if (!strncmp((const char *)ibuf, (const char *)dfu, sizeof(dfu) - 1))
            {
				System.bootloader();
			}
            else if (!strncmp((const char *)ibuf, (const char *)reset, sizeof(reset) - 1))
            {
				System.reset();
			}
            else if (!strncmp((const char *)ibuf, (const char *)cmd1, sizeof(cmd1) - 1))
            {
                set(HWC560S::FREQUENCY, HWC560S::DUTY_CYCLE, HWC560S::CODES);
                keys = HWC560S::KEYS;
            }
            else if (!strncmp((const char *)ibuf, (const char *)cmd2, sizeof(cmd2) - 1))
            {
                set(VIP2262::FREQUENCY, VIP2262::DUTY_CYCLE, VIP2262::CODES);
                keys = VIP2262::KEYS;
            }
            else if (keys != 0)
            {
                _sqs = keys[atoi((const char *)ibuf)];
                _r = !_r;
            }

            client.write(ibuf, t);
        }

        client.stop();
    }
    else
    {
        client = server.available();
    }
*/
/*
    if (Serial.available())
    {
        uint8_t k = Serial.read();
        switch (k)
        {
            case '1':
                set(VIP2262::FREQUENCY, VIP2262::DUTY_CYCLE, VIP2262::CODES);
                Serial.println("VIP2262");
                break;
            case '2':
                set(HWC560S::FREQUENCY, HWC560S::DUTY_CYCLE, HWC560S::CODES);
                Serial.println("HW-C560S");
                break;
            case 'q':
                _sqs = HWC560S::KEYS[HWC560S::VOL_UP];
                _r = !_r;
                break;
            case 'w':
                _sqs = HWC560S::KEYS[HWC560S::VOL_DOWN];
                _r = !_r;
                break;
            case 'e':
                _sqs = VIP2262::KEYS[VIP2262::EXIT];
                _r = !_r;
                break;
            case 'u':
                _sqs = VIP2262::KEYS[VIP2262::UP];
                _r = !_r;
                break;
            case 'd':
                _sqs = VIP2262::KEYS[VIP2262::DOWN];
                _r = !_r;
                break;
            case 'l':
                _sqs = VIP2262::KEYS[VIP2262::LEFT];
                _r = !_r;
                break;
            case 'r':
                _sqs = VIP2262::KEYS[VIP2262::RIGHT];
                _r = !_r;
                break;
            case 's':
                _sqs = VIP2262::KEYS[VIP2262::SELECT];
                _r = !_r;
                break;
            case 'g':
                _sqs = VIP2262::KEYS[VIP2262::GUIDE];
                _r = !_r;
                break;
            default:
                break;
        }
    }
*/
}
