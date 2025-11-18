#include <iostream>
#include "zephyr/kernel.h"

int main()
{
    printk("Cute Light Initialized!\n");

    while(1)
    {
        k_sleep(K_MSEC(1000));
        printk("Cute Light Running...\n");
    }

    return 0;
}