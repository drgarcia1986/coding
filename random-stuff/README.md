# Random Stuff
Some random code

## Async Background Task Scheduler
A very simple background task scheduler written on top of python's asyncio.

```python
scheduler = Scheduler()
scheduler.add(some_coroutine)
# ...

asyncio.get_event_loop().run_until_complete(scheduler.join())
```

[source](./scheduler/main.py)
