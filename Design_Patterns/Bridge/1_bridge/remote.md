# Remote Control Bridge

```lua
--[[ 
Bridge Pattern Visualization
--]]

 Abstraction           Implementation
+----------------+     +-----------------+
| RemoteControl  |     | Device          |
| -------------- |     | --------------- |
| - device*      | --> | + turnOn()      |
| + togglePower()|     | + turnOff()     |
+----------------+     +-----------------+
        ▲                       ▲
        |                       |
+----------------+     +-----------------+
| BasicRemote    |     | TV              |
| + togglePower()|     | + turnOn()      |
+----------------+     | + turnOff()     |
                       +-----------------+
                              ▲
                              |
                       +-----------------+
                       | Radio           |
                       | + turnOn()      |
                       | + turnOff()     |
                       +-----------------+
```
