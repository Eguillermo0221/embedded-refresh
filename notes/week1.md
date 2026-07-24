# Week 1
## Responses:
1. Why is `uint32_t` useful in embedded systems?

    `uint32_t` guarantees an unsigned 32-bit integer.
2. What does `volatile` tell the compiler?

    When `volatile` is used, it tells the compiler that it may unexpectingly change.
3. Why does `volatile` not make code thread-safe?

    Just because `volatile` is used does not mean it is safe to be used in threads. There still needs to have concurrency measures put in place like mutex or semaphores. It does not make operations atomic or prevent race conditions.
4. What does 1UL << position produce?

    It produces an unsigned long 1 at the specified bit location.
    E.g. `1UL << 3` makes bin `1000` or 8 in dec.

**Note:** `volatile` is commonly needed for memory-mapped hardware reg and variables shared with an interrupt. ##

An atomic operation completes as one indivisible action. Other threads or interrupts cannot observe it halfway through.`volatile` does not make an operation atomic.

1. Why might counter++ not be atomic?

    `counter++` can still be divided into smaller operations which can still be interrupted.
2. What is a race condition?

    Race condition is when the variable is being access by various threads or processes, trying to be read and modified, causing unexpected outcomes.
3. When would you use a mutex instead of an atomic operation?

    One would use a mutex if there is a change of a race condition on that variable.
