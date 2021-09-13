# name of your application
APPLICATION = AnalogRead

# If no BOARD is found in the environment, use this default:
#BOARD ?= nucleo-f401re
BOARD ?= b-l072z-lrwan1

# This has to be the absolute path to the RIOT base directory:
#RIOTBASE ?= $(CURDIR)/../../RIOT
RIOTBASE ?= /home/salvo/RIOT-202107

# Comment this out to disable code in RIOT that does safety checking
# which is not needed in a production environment but helps in the
# development process:
DEVELHELP ?= 1

# Change this to 0 show compiler invocation lines by default:
QUIET ?= 1

# Modules to include:
USEMODULE += xtimer
USEMODULE += periph_gpio
USEMODULE += analog_util
USEMODULE += printf_float
FEATURES_REQUIRED += periph_adc

#LoRa
# Default region is Europe and default band is 868MHz
USEMODULE += fmt
LORA_REGION ?= EU868
USEMODULE += semtech_loramac_rx

# Include the Semtech-loramac package
USEPKG += semtech-loramac

# Default radio driver is Semtech SX1276 (used by the B-L072Z-LRWAN1 board)
LORA_DRIVER ?= sx1276
USEMODULE += $(LORA_DRIVER) 	# Variable for Source code (main.c)

include $(RIOTBASE)/Makefile.include