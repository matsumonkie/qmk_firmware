# Getting started

There are two main ways you could customize the ErgoDox EZ.

## Compilation

1. Download dfu-programmer and avr-gcc-libc (gcc-avr binutils-avr avr-libc)
2. Download and install the [Teensy Loader](https://www.pjrc.com/teensy/loader.html)
3. Compile your firmware by running `make clean` followed by `make KEYMAP=your_name`. Note that you must omit the `keymap_` prefix for your filename in this command -- for example, `make KEYMAP=german`. This will result in a hex file, which will always be called `ergodox_ez.hex`, regardless of your keymap name.
6. Flash this hex file using the [Teensy loader](https://www.pjrc.com/teensy/loader.html) as described in step 4 in the "Easy Way" above.
7. Submit your work as a pull request to this repository, so others can also use it. :)

## Flashing the firmware
1. start teensy as root `sudo ./teensy`
2. Plug the keyboard, press its Reset button (paperclip into the hole in the top-right corner)
2. click `open HEX file`
3. click `program` then `reboot`

## Finding the keycodes you need

Let's say you want a certain key in your layout to send a colon; to figure out what keycode to use to make it do that, you're going to need `quantum/keymap_common.h`.

That file contains a big list of all of the special, fancy keys (like, being able to shend % on its own and whatnot).

If you want to send a plain vanilla key, you can look up its code under `doc/keycode.txt`. That's where all the boring keys hang out.
