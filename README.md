Soundcloud logo contest
=======================

Author: Jorge Pino <jpino@zeptocode.com>
Date: 2014-05-13

This C program (`soundcloud.c`) implements a very simple solution to the [Soundcloud logo problem](https://developers.soundcloud.com/blog/buzzwords-contest). It compares by brute force the Soundcloud logo sequence with every sequence of 84 numbers from the big file. The goodness of a sequence is measured by the [sum of absolute differences](http://en.wikipedia.org/wiki/Sum_of_absolute_differences).


## Instructions

1. Download the file [pi-billion.txt](http://stuff.mit.edu/afs/sipb/contrib/pi/pi-billion.txt) next to `soundcloud.c`
2. Compile: `gcc soundcloud.c`
3. Execute: `time ./a.out`

Good sequences will be printed on screen sorted by their starting position (offset):

    eval: 194 | offset: 197342978 | sequence: 313560984264300011495970664010077917573663456957498854662995598898697947677549686339
    eval: 193 | offset: 197342990 | sequence: 300011495970664010077917573663456957498854662995598898697947677549686339433357728071
    eval: 188 | offset: 297640119 | sequence: 082201638940102393659252475011295776958920282336494898427768768699465405437965994582
    eval: 193 | offset: 343577393 | sequence: 208503759370245135490877462200175839969750453766432680245845143285985661373828688970
    eval: 192 | offset: 509863836 | sequence: 130019949965424134524366868405264468588833190509687699654959636496916755646763968671
    eval: 193 | offset: 615021438 | sequence: 711013755962005413585569680665595617589960342457936899752952250549898008094549797848
    eval: 193 | offset: 702340521 | sequence: 510156458661130607192979267020226915882203362539599684666929466072856307246449876945
    eval: 194 | offset: 789652974 | sequence: 142204297650171312983445842322141909755200787408739757838589593329762648444919386594
    eval: 187 | offset: 972165010 | sequence: 212021479960265330123798820231693768599316147634474729776147987653958935291919768971
    eval: 180 | offset: 981165566 | sequence: 000053743536020032496985553181128909983810344939134894807349584729687746183109884672

    real        2m55.197s
    user        2m54.787s
    sys         0m0.228s

A lower evaluation is better.
