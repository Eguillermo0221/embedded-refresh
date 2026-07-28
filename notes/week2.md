# Week 2
## RTOS
1. Why should a FreeRTOS task usually contain an infinite loop?
    To keep the task running
2. What happens to the CPU when a task calls osDelay()?
    It sets the task to blocked state.
3. Why is osDelay() preferable to HAL_Delay() inside a task?
    osDelay allows the RTOS to perform other tasks while this task is blocked.
4. Does having two tasks mean the STM32 is truly executing both instructions simultaneously?
    No, rather concurrently
5. What do you predict would happen if the LED task never delayed or blocked?
    It will always stay at read, using up resources especially if it is in higher priority.