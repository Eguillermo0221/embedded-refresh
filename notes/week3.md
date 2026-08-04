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
    