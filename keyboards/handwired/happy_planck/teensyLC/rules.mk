SRC = matrix.c

# Compare with handwired/onekey
MCU  = MKL26Z64
USE_CHIBIOS_CONTRIB = yes

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
