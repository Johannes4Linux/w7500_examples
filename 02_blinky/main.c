#include <stdint.h>
#include "w7500x_gpio.h"

/**
 * @brief  Inserts a delay time.
 * @param  nTime: specifies the delay time length.
 * @retval None
 */
void Delay(__IO uint32_t nTime)
{
    while (nTime != 0) {
        nTime--;
    }
}

int main()
{
	GPIO_InitTypeDef led;

	SystemInit();

	led.GPIO_Pin = GPIO_Pin_15;
	led.GPIO_Direction = GPIO_Direction_OUT;
	led.GPIO_Pad = GPIO_OpenDrainDisable | GPIO_HighDrivingStrength | GPIO_PuPd_NOPULL;
	led.GPIO_AF = PAD_AF1;

	GPIO_Init(GPIOC, &led);

	volatile uint32_t i = 0;

	while (1) {
		GPIO_ToggleBits(GPIOC, GPIO_Pin_15);
		Delay(800000);
	}

	return 0;
}
