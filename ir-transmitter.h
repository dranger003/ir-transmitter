// ir-transmitter.h
//

// Connect A0 to A4 for reference PWM ISR
// Connect RX to IR LED anode (or CTL pin if using transistor)

#define CORE_CLK                72000000
#define TIMER_CLK			    24000000

#define PM_OFF                  0x0
#define PM_MARK                 0x4
#define PM_SPACE                0x0

#define REF_PIN                 A0
#define INT_PIN                 A4
#define CTL_PIN                 RX

#define MAX_CODE                72

// HW-C560S
//
namespace HWC560S
{
	const uint16_t FREQUENCY = 37773;
	const double DUTY_CYCLE = 0.37773;

	const uint16_t CODES[][2] =
	{
		{ 94, 72 },     // Init
		{ 16, 16 },     // 1
		{ 16, 44 },     // 2
	};

	const uint8_t KEYS[][MAX_CODE] =
	{
		{ 50,   // volume-up
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 2, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1 },
		{ 50,   // volume-down
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 2, 2, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1 },
		{ 50,   // input-bddvd
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		1, 2, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1 },
		{ 50,   // input-sat
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		1, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1 },
		{ 50,   // input-tv
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1 },
		{ 50,   // input-aux
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		2, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1 },
		{ 50,   // power
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1 },
		{ 50,   // input-select
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1 },
		{ 50,   // audio-assign
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		2, 1, 1, 2, 1, 2, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1 },
		{ 50,   // mute
		0, 2, 2, 1, 1, 1, 1, 2, 1, 2, 2, 1, 1, 2, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1,
		1, 1, 2, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 1, 1 },
	};

	enum KEY : uint8_t
	{
		VOL_UP,
		VOL_DOWN,
		INPUT_BDDVD,
		INPUT_SAT,
		INPUT_TV,
		INPUT_AUX,
		POWER,
		INPUT_SELECT,
		AUDIO_ASSIGN,
		MUTE,
	};
}

// VIP2262
//
namespace VIP2262
{
	const uint16_t FREQUENCY = 36250;
	const double DUTY_CYCLE = 0.33;

	const uint16_t CODES[][2] =
	{
		{ 15, 10 },   // Init
		{  6, 10 },   // 1
		{  6, 16 },   // 2
		{  6, 22 },   // 3
		{  6, 28 },   // 4
	};

	const uint8_t KEYS[][MAX_CODE] =
	{
		//  { 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, ?, ?, ?, ?, 1 },
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 1, 1, 1 }, // 0
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 1, 2, 1 }, // 1
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 1, 3, 1 }, // 2
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 1, 4, 1 }, // 3
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 2, 1, 1 }, // 4
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 2, 2, 1 }, // 5
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 2, 3, 1 }, // 6
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 2, 4, 1 }, // 7
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 3, 1, 1 }, // 8
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 3, 2, 1 }, // 9
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 3, 3, 1 }, // last
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 4, 1, 1 }, // power
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 1, 4, 4, 1 }, // info
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 2, 1, 1, 1 }, // volume-up
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 2, 1, 2, 1 }, // volume-down
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 3, 1, 1, 1 }, // channel-up
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 3, 1, 2, 1 }, // channel-down
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 3, 3, 1, 1 }, // fast-forward
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 3, 3, 2, 1 }, // rewind
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 3, 4, 1, 1 }, // play
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 4, 1, 1, 1 }, // pause
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 4, 1, 2, 1 }, // stop
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 4, 2, 4, 1 }, // record
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 4, 3, 1, 1 }, // settings
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 1, 4, 3, 2, 1 }, // favorites
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 1, 2, 1, 1 }, // recordings
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 1, 4, 1, 1 }, // forward
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 1, 4, 2, 1 }, // replay
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 2, 2, 1, 1 }, // menu
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 2, 2, 2, 1 }, // exit
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 2, 3, 1, 1 }, // up
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 2, 3, 2, 1 }, // down
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 2, 3, 3, 1 }, // left
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 2, 3, 4, 1 }, // right
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 2, 2, 4, 1, 1 }, // select
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 3, 1, 1, 4, 1 }, // back
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 3, 1, 2, 3, 1 }, // search
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 3, 2, 4, 3, 1 }, // delete
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 4, 1, 4, 1, 1 }, // guide
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 4, 3, 1, 2, 1 }, // enter
		{ 18, 0, 1, 3, 2, 2, 1, 1, 1, 1, 1, 3, 2, 3, 4, 4, 1, 1, 1 }, // video-on-demand
	};

	enum KEY : uint8_t
	{
		N0,
		N1,
		N2,
		N3,
		N4,
		N5,
		N6,
		N7,
		N8,
		N9,
		LAST,
		POWER,
		INFO,
		VOL_UP,
		VOL_DOWN,
		CHNL_UP,
		CHNL_DOWN,
		FF,
		REW,
		PLAY,
		PAUSE,
		STOP,
		RECORD,
		SETTINGS,
		FAVORITES,
		RECORDINGS,
		FWD,
		REPLAY,
		MENU,
		EXIT,
		UP,
		DOWN,
		LEFT,
		RIGHT,
		SELECT,
		BACK,
		SEARCH,
		DELETE,
		GUIDE,
		ENTER,
		VOD,
	};
}

// GWC18KG-D3DNA6C/I
//
namespace GWC18KG
{
	const uint16_t FREQUENCY = 37648;
	const double DUTY_CYCLE = 0.3505;

	const uint16_t CODES[][2] =
	{
		{ 336, 168 },   // Init
		{  23,  22 },   // 1
		{  23,  63 },   // 2
		{  23, 745 },   // 3
	};

	const uint8_t KEYS[][MAX_CODE] =
	{
		{ 70, // ON		021121111122111111111122111112121121311111111111111111111111111112112
		0, 2, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2,
		1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1 },
		{ 70, // OFF	021111111122111111111121111112121121311111111111111111111111111112111
		0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1, 2,
		1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1 },
	};

	enum KEY : uint8_t
	{
		ON,
		OFF,
	};
}

namespace Transmitter
{
	//TCPServer server = TCPServer(12345);
	//TCPClient client;
	UDP udp;

	volatile uint8_t _r = 0;

	const uint16_t(*_pcs)[2] = 0;
	const uint8_t *_sqs = 0;

	volatile uint16_t _pc = 0;
	volatile uint16_t _si = 1;
	volatile uint16_t _pi = 0;

	const uint8_t(*keys)[MAX_CODE] = 0;

	class Program
	{
	public:
		static void Setup()
		{
			WiFi.connect();
			while (!WiFi.ready());
			/*
			Serial.begin(115200);
			while (!Serial.available())
			SPARK_WLAN_Loop();

			Serial.println("\r\nsetup()");

			Serial.println(WiFi.localIP());
			Serial.println(WiFi.subnetMask());
			Serial.println(WiFi.gatewayIP());
			Serial.println(WiFi.SSID());
			*/
			//    server.begin();

			udp.begin(12345);
		}

		static void Loop()
		{
			SPARK_WLAN_Loop();

			if (udp.parsePacket() > 0)
			{
				uint8_t ibuf[1024] = { 0 };
				udp.read(ibuf, sizeof(ibuf));

				uint8_t dfu = 0, reset = 0;

				if (!strcmp((const char *)ibuf, "DFU"))
					dfu = 1;
				else if (!strcmp((const char *)ibuf, "RESET"))
					reset = 1;
				else if (!strcmp((const char *)ibuf, "HWC560S"))
				{
					Set(HWC560S::FREQUENCY, HWC560S::DUTY_CYCLE, HWC560S::CODES);
					keys = HWC560S::KEYS;
				}
				else if (!strcmp((const char *)ibuf, "VIP2262"))
				{
					Set(VIP2262::FREQUENCY, VIP2262::DUTY_CYCLE, VIP2262::CODES);
					keys = VIP2262::KEYS;
				}
				else if (!strcmp((const char *)ibuf, "GWC18KG"))
				{
					Set(GWC18KG::FREQUENCY, GWC18KG::DUTY_CYCLE, GWC18KG::CODES);
					keys = GWC18KG::KEYS;
				}
				else if (keys != 0)
				{
					_sqs = keys[atoi((const char *)ibuf)];
					_r = !_r;
				}

				uint8_t obuf[1024] = { 0 };
				sprintf((char *)obuf, "[%s]", (const char *)ibuf);

				udp.beginPacket(udp.remoteIP(), udp.remotePort());
				udp.write(obuf, strlen((const char *)obuf));
				udp.endPacket();

				if (dfu || reset)
				{
					delay(500);

					if (dfu)
						System.bootloader();

					if (reset)
						System.reset();
				}
			}
		}

	private:
		static void _PWM(uint16_t pin, uint32_t frequency, double duty)
		{
			RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
			pinMode(pin, AF_OUTPUT_PUSHPULL);

			TIM_TypeDef *p = PIN_MAP[pin].timer_peripheral;

			if (p == TIM2)
				RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
			else if (p == TIM3)
				RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
			else if (p == TIM4)
				RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

			const uint16_t TIM_ARR = (uint16_t)(TIMER_CLK / frequency) - 1;

			TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure = { 0 };
			TIM_TimeBaseStructure.TIM_Period = TIM_ARR;
			TIM_TimeBaseStructure.TIM_Prescaler = (uint16_t)(CORE_CLK / TIMER_CLK) - 1;
			TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
			TIM_TimeBaseInit(p, &TIM_TimeBaseStructure);

			TIM_OCInitTypeDef TIM_OCInitStructure = { 0 };
			TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
			TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
			TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
			TIM_OCInitStructure.TIM_Pulse = (uint16_t)((TIM_ARR + 1) * duty);

			if (PIN_MAP[pin].timer_ch == TIM_Channel_1) {
				TIM_OC1Init(p, &TIM_OCInitStructure);
				TIM_OC1PreloadConfig(p, TIM_OCPreload_Enable);
			}
			else if (PIN_MAP[pin].timer_ch == TIM_Channel_2) {
				TIM_OC2Init(p, &TIM_OCInitStructure);
				TIM_OC2PreloadConfig(p, TIM_OCPreload_Enable);
			}
			else if (PIN_MAP[pin].timer_ch == TIM_Channel_3) {
				TIM_OC3Init(p, &TIM_OCInitStructure);
				TIM_OC3PreloadConfig(p, TIM_OCPreload_Enable);
			}
			else if (PIN_MAP[pin].timer_ch == TIM_Channel_4) {
				TIM_OC4Init(p, &TIM_OCInitStructure);
				TIM_OC4PreloadConfig(p, TIM_OCPreload_Enable);
			}

			TIM_ARRPreloadConfig(p, ENABLE);
			TIM_Cmd(p, ENABLE);
		}

		static void _ISR() {
			if (!_r)
				return;

			if (_pc == 0) {
				pinMode(CTL_PIN, (PinMode)PM_MARK);
			}
			else if (_pc == _pcs[_sqs[_si]][_pi % 2]) {
				_pc = 0;

				if (_si == _sqs[0]) {
					pinMode(CTL_PIN, (PinMode)PM_OFF);
					_si = 1;
					_pi = 0;
					_r = 0;
					return;
				}

				if (_pi % 2) {
					pinMode(CTL_PIN, (PinMode)PM_MARK);
					++_si;
				}
				else {
					pinMode(CTL_PIN, (PinMode)PM_SPACE);
				}

				++_pi;
			}

			++_pc;
		}

		static void Set(uint16_t frequency, double duty_cycle, const uint16_t(*codes)[2])
		{
			_PWM(REF_PIN, frequency, duty_cycle);

			_PWM(CTL_PIN, frequency, duty_cycle);
			pinMode(CTL_PIN, (PinMode)PM_OFF);

			pinMode(INT_PIN, INPUT);
			attachInterrupt(INT_PIN, _ISR, FALLING);

			_pcs = codes;
		}
	};
}
