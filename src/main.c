#include <stdio.h>
#include <string.h>

#include "delay.h"
#include "timer.h"
#include "radio.h"
#include "rtc-board.h"
#include "tremo_delay.h"
#include "tremo_gpio.h"
#include "tremo_pwr.h"
#include "tremo_rcc.h"
#include "tremo_uart.h"

extern int app_start(void);

void board_init() {
  rcc_enable_oscillator(RCC_OSC_XO32K, true);

  rcc_enable_peripheral_clk(RCC_PERIPHERAL_UART0, true);
  rcc_enable_peripheral_clk(RCC_PERIPHERAL_GPIOA, true);
  rcc_enable_peripheral_clk(RCC_PERIPHERAL_GPIOB, true);
  rcc_enable_peripheral_clk(RCC_PERIPHERAL_GPIOC, true);
  rcc_enable_peripheral_clk(RCC_PERIPHERAL_GPIOD, true);
  rcc_enable_peripheral_clk(RCC_PERIPHERAL_PWR, true);
  rcc_enable_peripheral_clk(RCC_PERIPHERAL_RTC, true);
  rcc_enable_peripheral_clk(RCC_PERIPHERAL_SAC, true);
  rcc_enable_peripheral_clk(RCC_PERIPHERAL_LORA, true);

  delay_ms(100);
  pwr_xo32k_lpm_cmd(true);

  // uart_log_init();

  RtcInit();
}

int main(void) {
  // Target board initialization
  board_init();
  app_start();
}