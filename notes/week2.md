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

1. What state is a task in while it is inside osDelay()?
    Blocked
2. Can the monitor task run while the heartbeat task is delayed?
    Yes
3. Why does every task need to block, delay, suspend, or yield at some point?
    To allow other tasks to use resources
4. What could happen if a task contains an infinite loop with no blocking call?
    It will get stuck at running if it's the highest priority.
5. Are these tasks truly running simultaneously on the single-core STM32?
    Concurrently so virtually simultaneously

### Queues

1. What state is the monitor task in while waiting on osMessageQueueGet()?
    The monitor task will stay blocked.
2. Does the queue store the pointer or copy the uint32_t value?
    RTOS takes the value in the pointer and puts it in the queue.
3. What happens when osMessageQueuePut() uses a zero timeout and the queue is full?
    It normally returns a value but it will not accept the new message.
4. Why is the queue preferable to both tasks accessing one global counter?
    It avoids the risk of a race condition.
5. Why can the monitor task work without a periodic delay?
    Because it is set to block until there's activity in the queue. 

### Adding 
1. Why did the queue become full?
    The monitor task took long to handle the queue due to its delay
2. What does a zero timeout mean when sending?
    It will not wait for it to open.
3. Were old messages overwritten?
    No, it just stays in the queue.
4. What are two possible ways to handle a full queue?
    Increase queue capacity or slow the producer and/or speed up the consumer.
5. Should heartbeat data preserve every count, or would keeping only the latest value sometimes be better?
    The last value would be better.