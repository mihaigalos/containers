### Simplified container implementations for AVR

##### Statically allocated map

Usage of about 350 bytes of flash, example includes RAM usage 10*structure of 2 bytes.

```
➜  demo git:(master) ✗ avr-gcc -std=c++14  -Os -mmcu=atmega328p  avr_main_static.cpp -o avr_main_static

➜  demo git:(master) ✗ avr-size avr_main_static
   text    data     bss     dec     hex filename
    352       2      42     396     18c avr_main_static

➜  demo git:(master) ✗ avr-nm --size-sort -C -r --radix=d avr_main_static
00000086 W containers::static_map<DemoStructure, unsigned int, 10u>::operator[](unsigned int)
00000050 T main
00000042 B sut_
00000022 T __do_global_ctors
00000022 T __do_copy_data
00000016 T __do_clear_bss
00000012 T __tablejump2__
00000010 t _GLOBAL__sub_I_expected_size
00000002 D expected_size
```


##### Dynamically allocated map

About 1kB of flash usage.

```
➜  demo git:(master) ✗ avr-gcc -std=c++14  -Os -mmcu=atmega328p  avr_main_dynamic.cpp -o avr_main_dynamic

➜  demo git:(master) ✗ avr-size avr_main_dynamic                                                         
   text    data     bss     dec     hex filename
   1064      16      12    1092     444 avr_main_dynamic

➜  demo git:(master) ✗ avr-nm --size-sort -C -r --radix=d avr_main_dynamic                               
00000304 T malloc
00000274 T free
00000100 W containers::dynamic_map<DemoStructure, unsigned int>::operator[](unsigned int)
00000062 t _GLOBAL__sub_I__ZdlPvj
00000050 T main
00000026 W containers::dynamic_map<DemoStructure, unsigned int>::~dynamic_map()
00000026 W containers::dynamic_map<DemoStructure, unsigned int>::~dynamic_map()
00000022 T __do_global_dtors
00000022 T __do_global_ctors
00000022 T __do_copy_data
00000016 T __do_clear_bss
00000012 T __tablejump2__
00000008 V vtable for containers::dynamic_map<DemoStructure, unsigned int>
00000008 B sut_
00000008 t _GLOBAL__sub_D__ZdlPvj
00000006 W containers::dynamic_map<DemoStructure, unsigned int>::~dynamic_map()
00000002 T operator delete(void*, unsigned int)
00000002 T operator delete(void*)
00000002 D __malloc_margin
00000002 D __malloc_heap_start
00000002 D __malloc_heap_end
00000002 B __flp
00000002 D expected_size
00000002 B __brkval
```
