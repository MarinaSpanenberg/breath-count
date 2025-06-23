import serial
import time
from datetime import datetime

serial_port_name = '/dev/ttyACM0' 
serial_port = serial.Serial(serial_port_name, 9600)
time.sleep(2)

# age = int(input())
# serial_port.write(bytes([age]))

def datetime_now():
    now = datetime.now()
    data_str = now.strftime("%d-%m-%Y-%H:%M:%S")
    return data_str


def register_log(rpm):
    now = datetime_now()
    log_line = f"{now} - RPM {rpm}\n"
    with open('log_breath_count.txt','a') as log_file:
        log_file.write(log_line)

try:
    while True:
        if serial_port.in_waiting > 0:
            data = serial_port.readline().decode('utf-8').strip()
            if '(RPM)' in data:
                rpm = data
                register_log(rpm)
            print("Recebido", data)
except KeyboardInterrupt:
    print("Close")
    serial_port.close()