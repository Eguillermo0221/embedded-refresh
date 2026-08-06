# Week 3
### Tasks vs Queues
1. What state is the monitor task in while waiting for the flag?
    Blocking
2. Does a thread flag preserve every heartbeat event?
    No, just the latest state
3. Why might a thread flag be better than a queue here?
    Lightweight and does not have the risk of missing info (i.e. from overflowing queue)
4. When would the queue still be the better choice?
    If it requires more information to be passed along.
5. What does HEARTBEAT_FLAG (1U << 0) represent?
    A one-bit flag

### Heartbeat monitoring
1. Why does the monitor use a timeout instead of osWaitForever?
    It determines if it receives a flag within a specified time.
2. Why is the timeout longer than the normal heartbeat interval?
    Having a timeout closer to the interval may cause false positives. In real world applications, it is important to have tolerance.
3. What happens when the heartbeat task waits for three seconds?
    At that point the monitor expected a flag. The monitor task has already deemed the heartbeat not healthy.
4. Does receiving one new heartbeat prove that the task was healthy the entire time?
    No. It only proves that the task is responding at that moment. The earlier missed heartbeats still indicate that the task was delayed or unresponsive during that period.
5. What could a real system do after several missed heartbeats?
    In a real system, the monitor could log the fault, alert another subsystem, enter a safe state, reset the affected subsystem, restart the task when safe, or allow a watchdog to reset the processor.
    