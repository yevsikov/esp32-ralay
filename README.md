# ESP32 Relay - Learning Project

This is a small educational project for the [Embedded Development course](https://beetroot.academy/courses/online/kurs-embedded-development)

## Circuit Diagram

```
GPIO5
    |
    +-----> IN relay

GPIO18
    |
    +<----- NO

3.3V
    |
    +-----> COM

External 5V
    |
    +-----> VCC

GND
    |
    +-----> GND
```

## Result

### millis()  

```
ON: 4 ms
OFF: 8 ms
_
ON: 4 ms
OFF: 8 ms
_
ON: 4 ms
OFF: 8 ms
_
ON: 4 ms
OFF: 8 ms
_
ON: 4 ms
OFF: 8 ms
_
ON: 4 ms
OFF: 8 ms
_
ON: 4 ms
OFF: 8 ms
_
ON: 4 ms
OFF: 8 ms
_
ON: 4 ms
OFF: 8 ms
_
ON: 4 ms
OFF: 8 ms
_
Average: 6 ms
```


### micros()  

```
ON: 3562 mcs
OFF: 7499 mcs
_
ON: 3559 mcs
OFF: 7490 mcs
_
ON: 3559 mcs
OFF: 7494 mcs
_
ON: 3558 mcs
OFF: 7485 mcs
_
ON: 3558 mcs
OFF: 7481 mcs
_
ON: 3560 mcs
OFF: 7485 mcs
_
ON: 3558 mcs
OFF: 7480 mcs
_
ON: 3558 mcs
OFF: 7476 mcs
_
ON: 3560 mcs
OFF: 7476 mcs
_
ON: 3558 mcs
OFF: 7476 mcs
_
Average: 5521 mcs
```
