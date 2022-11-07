import os

env = Environment()
env['CC'] = '/opt/homebrew/bin/avr-gcc'
env['CXX'] = '/opt/homebrew/bin/avr-g++'
env['AS'] = '/opt/homebrew/bin/avr-gcc'
env['OBJCOPY'] = '/opt/homebrew/bin/avr-objcopy'
env['UPLOAD'] = '/opt/homebrew/bin/avrdude'
env['SIZE'] = '/opt/homebrew/bin/avr-size'
env.Append(CCFLAGS = '-Os')

MCU='atmega328p'
MCUU='ATMEGA328P'
F_CPU='16000000UL'
TARGET='main'

# env.Append(CCFLAGS = '--std=gnu++11')
# env.Append(CCFLAGS = '--std=gnu++11')
env.Append(CCFLAGS = '-mmcu=' + MCU)
env.Append(CCFLAGS = '-DF_CPU=' + F_CPU)
env.Append(LINKFLAGS = '-mmcu=' + MCU)
env.Append(LINKFLAGS = '-Wl,-u,vfprintf -lprintf_min')
env.Append(LINKFLAGS = '-lm')

files = []
for root, dirs,fs in os.walk(".", topdown=False):
    for name in fs:
        if name.endswith((".c", ".cpp")) and "wiring_pulse" not in name:
            files.append(os.path.join(root,name))

o_files = env.Object(files)

env.Program(f"{TARGET}.bin",o_files)

env.Command(f"{TARGET}.hex", f"{TARGET}.bin", env['OBJCOPY'] + f' -O ihex -R .eeprom {TARGET}.bin {TARGET}.hex')

upload = env.Command([],f"{TARGET}.hex", f"{env['UPLOAD']} -F -V -c arduino -p {MCUU} -P /dev/tty.usbmodem833301 -b 115200 -U flash:w:{TARGET}.hex")

env.AlwaysBuild(upload)

