#!/bin/bash

if [[ -d "$DEVKITARM/bin/" ]]; then
    OBJDUMP_BIN="$DEVKITARM/bin/arm-none-eabi-objdump"
else
    OBJDUMP_BIN="arm-none-eabi-objdump"
fi
OBJDUMP="$OBJDUMP_BIN -D -bbinary -marmv4t -Mforce-thumb"
OPTIONS="--start-address=$(($1)) --stop-address=$(($1 + $2))"
$OBJDUMP $OPTIONS baserom.gba > baserom.dump
$OBJDUMP $OPTIONS pokeemerald.gba > pokeemerald.dump
diff -u baserom.dump pokeemerald.dump
