Tested on Ubuntu 16.04 with a connected wired Xbox One controller:
```
cc evtest.c && ./a.out /dev/input/event13
```

Some devices may require root privileges.

Example log:
```
Event: time 1610646713.292403, -------------- SYN_REPORT ------------
Event: time 1610646713.300400, type 3 (EV_ABS), code 0 (ABS_X), value 188
Event: time 1610646713.300400, type 3 (EV_ABS), code 1 (ABS_Y), value 1445
Event: time 1610646713.300400, type 3 (EV_ABS), code 3 (ABS_RX), value 8018
Event: time 1610646713.300400, type 3 (EV_ABS), code 4 (ABS_RY), value -4305
Event: time 1610646713.300400, type 3 (EV_ABS), code 5 (ABS_RZ), value 0
Event: time 1610646713.300400, -------------- SYN_REPORT ------------
Event: time 1610646713.308405, type 3 (EV_ABS), code 0 (ABS_X), value 38
Event: time 1610646713.308405, type 3 (EV_ABS), code 1 (ABS_Y), value 1197
Event: time 1610646713.308405, type 3 (EV_ABS), code 3 (ABS_RX), value 6799
Event: time 1610646713.308405, type 3 (EV_ABS), code 4 (ABS_RY), value 4361
Event: time 1610646713.308405, -------------- SYN_REPORT ------------
Event: time 1610646713.316403, type 3 (EV_ABS), code 0 (ABS_X), value -117
Event: time 1610646713.316403, type 3 (EV_ABS), code 1 (ABS_Y), value 964
Event: time 1610646713.316403, type 3 (EV_ABS), code 3 (ABS_RX), value 6052
Event: time 1610646713.316403, type 3 (EV_ABS), code 4 (ABS_RY), value 4215
Event: time 1610646713.316403, -------------- SYN_REPORT ------------
Event: time 1610646713.324371, type 3 (EV_ABS), code 0 (ABS_X), value -235
Event: time 1610646713.324371, type 3 (EV_ABS), code 1 (ABS_Y), value 785
Event: time 1610646713.324371, type 3 (EV_ABS), code 3 (ABS_RX), value 5595
Event: time 1610646713.324371, type 3 (EV_ABS), code 4 (ABS_RY), value 3944
Event: time 1610646713.324371, -------------- SYN_REPORT ------------
Event: time 1610646713.332402, type 3 (EV_ABS), code 0 (ABS_X), value -318
Event: time 1610646713.332402, type 3 (EV_ABS), code 1 (ABS_Y), value 634
Event: time 1610646713.332402, type 3 (EV_ABS), code 3 (ABS_RX), value 5222
Event: time 1610646713.332402, type 3 (EV_ABS), code 4 (ABS_RY), value 3694
Event: time 1610646713.332402, -------------- SYN_REPORT ------------
Event: time 1610646713.340402, type 3 (EV_ABS), code 1 (ABS_Y), value 513
Event: time 1610646713.340402, type 3 (EV_ABS), code 3 (ABS_RX), value 4924
Event: time 1610646713.340402, type 3 (EV_ABS), code 4 (ABS_RY), value 3499
Event: time 1610646713.340402, -------------- SYN_REPORT ------------
Event: time 1610646713.348403, type 3 (EV_ABS), code 0 (ABS_X), value -383
Event: time 1610646713.348403, type 3 (EV_ABS), code 1 (ABS_Y), value 418
Event: time 1610646713.348403, type 3 (EV_ABS), code 3 (ABS_RX), value 4679
Event: time 1610646713.348403, type 3 (EV_ABS), code 4 (ABS_RY), value 3344
Event: time 1610646713.348403, -------------- SYN_REPORT ------------
Event: time 1610646713.356399, type 3 (EV_ABS), code 3 (ABS_RX), value 4477
Event: time 1610646713.356399, type 3 (EV_ABS), code 4 (ABS_RY), value 3214
Event: time 1610646713.356399, -------------- SYN_REPORT ------------
Event: time 1610646713.364398, type 3 (EV_ABS), code 1 (ABS_Y), value 279
Event: time 1610646713.364398, type 3 (EV_ABS), code 3 (ABS_RX), value 4317
Event: time 1610646713.364398, type 3 (EV_ABS), code 4 (ABS_RY), value 3105
Event: time 1610646713.364398, -------------- SYN_REPORT ------------
Event: time 1610646713.372404, type 3 (EV_ABS), code 3 (ABS_RX), value 4182
Event: time 1610646713.372404, type 3 (EV_ABS), code 4 (ABS_RY), value 3016
Event: time 1610646713.372404, type 3 (EV_ABS), code 5 (ABS_RZ), value 17
Event: time 1610646713.372404, -------------- SYN_REPORT ------------
Event: time 1610646713.384399, type 3 (EV_ABS), code 1 (ABS_Y), value 191
Event: time 1610646713.384399, type 3 (EV_ABS), code 4 (ABS_RY), value 3099
Event: time 1610646713.384399, -------------- SYN_REPORT ------------
Event: time 1610646713.392399, type 3 (EV_ABS), code 4 (ABS_RY), value 3296
Event: time 1610646713.392399, -------------- SYN_REPORT ------------
Event: time 1610646713.400404, type 3 (EV_ABS), code 4 (ABS_RY), value 3430
Event: time 1610646713.400404, type 3 (EV_ABS), code 5 (ABS_RZ), value 0
Event: time 1610646713.400404, -------------- SYN_REPORT ------------
Event: time 1610646713.408399, type 3 (EV_ABS), code 3 (ABS_RX), value 4370
Event: time 1610646713.408399, -------------- SYN_REPORT ------------
Event: time 1610646713.416401, type 3 (EV_ABS), code 1 (ABS_Y), value 97
Event: time 1610646713.416401, type 3 (EV_ABS), code 3 (ABS_RX), value 4664
Event: time 1610646713.416401, -------------- SYN_REPORT ------------
Event: time 1610646713.424399, type 3 (EV_ABS), code 3 (ABS_RX), value 5606
Event: time 1610646713.424399, -------------- SYN_REPORT ------------
Event: time 1610646713.432403, type 3 (EV_ABS), code 3 (ABS_RX), value 14258
Event: time 1610646713.432403, type 3 (EV_ABS), code 4 (ABS_RY), value 3243
Event: time 1610646713.432403, -------------- SYN_REPORT ------------
Event: time 1610646713.440400, type 3 (EV_ABS), code 3 (ABS_RX), value 15541
Event: time 1610646713.440400, type 3 (EV_ABS), code 4 (ABS_RY), value 2152
Event: time 1610646713.440400, type 3 (EV_ABS), code 5 (ABS_RZ), value 13
Event: time 1610646713.440400, -------------- SYN_REPORT ------------
Event: time 1610646713.448399, type 3 (EV_ABS), code 1 (ABS_Y), value 557
Event: time 1610646713.448399, type 3 (EV_ABS), code 3 (ABS_RX), value 29601
Event: time 1610646713.448399, type 3 (EV_ABS), code 4 (ABS_RY), value -6599
Event: time 1610646713.448399, type 3 (EV_ABS), code 5 (ABS_RZ), value 29
Event: time 1610646713.448399, -------------- SYN_REPORT ------------
Event: time 1610646713.456399, type 3 (EV_ABS), code 1 (ABS_Y), value 957
Event: time 1610646713.456399, type 3 (EV_ABS), code 3 (ABS_RX), value 32767
Event: time 1610646713.456399, type 3 (EV_ABS), code 4 (ABS_RY), value -7420
Event: time 1610646713.456399, type 3 (EV_ABS), code 5 (ABS_RZ), value 219
Event: time 1610646713.456399, -------------- SYN_REPORT ------------
Event: time 1610646713.464405, type 3 (EV_ABS), code 0 (ABS_X), value -462
Event: time 1610646713.464405, type 3 (EV_ABS), code 1 (ABS_Y), value 825
Event: time 1610646713.464405, type 3 (EV_ABS), code 4 (ABS_RY), value -8054
Event: time 1610646713.464405, type 3 (EV_ABS), code 5 (ABS_RZ), value 440
Event: time 1610646713.464405, -------------- SYN_REPORT ------------
Event: time 1610646713.472399, type 3 (EV_ABS), code 0 (ABS_X), value -823
Event: time 1610646713.472399, type 3 (EV_ABS), code 1 (ABS_Y), value 631
Event: time 1610646713.472399, type 3 (EV_ABS), code 4 (ABS_RY), value -8588
Event: time 1610646713.472399, type 3 (EV_ABS), code 5 (ABS_RZ), value 721
Event: time 1610646713.472399, -------------- SYN_REPORT ------------
Event: time 1610646713.480399, type 3 (EV_ABS), code 0 (ABS_X), value -1795
Event: time 1610646713.480399, type 3 (EV_ABS), code 1 (ABS_Y), value 293
Event: time 1610646713.480399, type 3 (EV_ABS), code 4 (ABS_RY), value -9112
Event: time 1610646713.480399, type 3 (EV_ABS), code 5 (ABS_RZ), value 969
Event: time 1610646713.480399, -------------- SYN_REPORT ------------
Event: time 1610646713.488390, type 1 (EV_KEY), code 304 (BTN_SOUTH), value 1
Event: time 1610646713.488390, type 3 (EV_ABS), code 0 (ABS_X), value -8706
Event: time 1610646713.488390, type 3 (EV_ABS), code 1 (ABS_Y), value -486
Event: time 1610646713.488390, type 3 (EV_ABS), code 4 (ABS_RY), value -9565
Event: time 1610646713.488390, type 3 (EV_ABS), code 5 (ABS_RZ), value 1023
```
