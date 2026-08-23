#include <iostream>
#include "zephyr/kernel.h"
#include "zephyr/usb/usbd.h"
#include "zephyr/drivers/uart.h"

#define CDC_ACM_DEVICE_NODE DT_CHOSEN(zephyr_console)

int main()
{
    const struct device *uart_dev = DEVICE_DT_GET(CDC_ACM_DEVICE_NODE);
    
    /* 等待设备就绪 */
    while (!device_is_ready(uart_dev)) {
        k_sleep(K_MSEC(100));
    }

    /* 尝试输出 */
    for (int i = 0; i < 10; i++) {
        printk("Cute Light Initialized! %d\n", i);
        k_sleep(K_MSEC(100));
    }

    while (1) {
        k_sleep(K_MSEC(1000));
        printk("Cute Light Running...\n");
    }

    return 0;
}