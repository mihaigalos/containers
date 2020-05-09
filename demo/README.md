### Simplified container implementations for AVR

##### Statically allocated unordered map

Usage of <300 bytes of flash (330-42 static data).
Since the example uses static data to circumvent not having extra *volatile*-qualified members, displayed size also contains opcode to zero-initialize the .bss section.

```
➜  demo git:(master) ✗ avr-gcc -std=c++17  -Os -mmcu=atmega328p  avr_main_static.cpp -o avr_main_static

➜  demo git:(master) ✗ avr-size avr_main_static
   text    data     bss     dec     hex filename
    330       0      42     372     174 avr_main_static

➜  demo git:(master) ✗ avr-nm --size-sort -C -r --radix=d avr_main_static
00000086 W containers::static_map<unsigned int, DemoStructure, 10u>::operator[](unsigned int)
00000050 T main
00000042 B sut_
00000022 T __do_global_ctors
00000016 T __do_clear_bss
00000012 T __tablejump2__
00000010 t _GLOBAL__sub_I_sut
```


##### Dynamically allocated unordered map

About 2kB of flash usage.

```
➜  demo git:(master) ✗ avr-gcc -std=c++17  -Os -mmcu=atmega328p  avr_main_dynamic.cpp -o avr_main_dynamic

➜  demo git:(master) ✗ avr-size avr_main_dynamic
   text    data     bss     dec     hex filename
   1724      14      14    1752     6d8 avr_main_dynamic

➜  demo git:(master) ✗ avr-nm --size-sort -C -r --radix=d avr_main_dynamic
00000396 T realloc
00000304 T malloc
00000274 T free
00000244 W containers::dynamic_map<unsigned int, DemoStructure, 10u>::operator[](unsigned int)
00000056 T __prologue_saves__
00000054 t _GLOBAL__sub_I__ZdlPvj
00000054 T __epilogue_restores__
00000050 T main
00000026 W containers::dynamic_map<unsigned int, DemoStructure, 10u>::~dynamic_map()
00000026 W containers::dynamic_map<unsigned int, DemoStructure, 10u>::~dynamic_map()
00000022 T __do_global_dtors
00000022 T __do_global_ctors
00000022 T __do_copy_data
00000018 T memcpy
00000016 T __do_clear_bss
00000012 T __tablejump2__
00000010 B sut_
00000008 V vtable for containers::dynamic_map<unsigned int, DemoStructure, 10u>
00000008 t _GLOBAL__sub_D__ZdlPvj
00000006 W containers::dynamic_map<unsigned int, DemoStructure, 10u>::~dynamic_map()
00000002 T operator delete(void*, unsigned int)
00000002 T operator delete(void*)
00000002 D __malloc_margin
00000002 D __malloc_heap_start
00000002 D __malloc_heap_end
00000002 B __flp
00000002 B __brkval
```
