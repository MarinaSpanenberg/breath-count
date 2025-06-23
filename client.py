import socket
import serial
import time

serial_port_name = "/dev/ttyACM0"
serial_port = serial.Serial(serial_port_name, 9600)
# time.sleep(2)


def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(("localhost", 8080))

    while True:
        receive_message = serial_port.readline().decode("utf-8").strip()
        message = f"{receive_message}"
        print(message)
        client_socket.send(message.encode("utf-8"))
        # time.sleep(2)

    client_socket.close()


if __name__ == "__main__":
    start_client()