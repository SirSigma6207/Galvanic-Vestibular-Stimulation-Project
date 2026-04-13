import socket
import keyboard
import time

ESP_IP = "10.239.48.81"
UDP_PORT = 4210

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

x = 0

print("Hold A/D. Release → returns to 0. ESC to quit")

while True:

    if keyboard.is_pressed('a'):
        x -= 1

    elif keyboard.is_pressed('d'):
        x += 1

    else:
        # 🔥 RETURN TO ZERO LOGIC
        if x <= 4 and x >= -4:
            x = 0
        if x > 0:
            x -= 5
        elif x < 0:
            x += 5

    # Clamp
    if x > 127:
        x = 127
    if x < -127:
        x = -127

    # Send UDP
    message = f"X:{x}".encode()
    sock.sendto(message, (ESP_IP, UDP_PORT))

    print(f"X: {x}")

    if keyboard.is_pressed('esc'):
        break

    time.sleep(0.01)
