# Prism

Named after the split-prism mechanism of manually focusing old film cameras. A
timer for getting work done in chunks.

Tested on Mac and Fedora.

## Build

Install `ncurses` on whatever platform.

`gcc main.c lib/*.c -o /path/to/target/prism -lncurses`

## Todo

- [ ] Remove hardcoded sounds and use user-provided ones
- [ ] Configure work/break focus splits other than default 25/5
