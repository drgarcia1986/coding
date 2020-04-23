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

## Redis RESP protocol parser
A simple parser of [RESP protocol](https://redis.io/topics/protocol) than parse:

* `+`: simple string
* `:`: simple integer
* `-`: error
* `$`: bulk string

And build a plain string into a redis request with RESP protocol.

[source](./resp-parser/main.py)
