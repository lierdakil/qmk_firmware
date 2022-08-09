#!/bin/bash
make ktec/ergodone:lierdakil
hid_bootloader_cli -mmcu=atmega32u4 ktec_ergodone_lierdakil.hex
