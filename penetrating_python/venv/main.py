"""
Written by Johnny 2021
"""

import threading

ip = "1.1.1"
host = "ya.ru"
id = "1412"


class Factory:

    def __init__(self, value1="message", value2=id, value3=host, value4=ip):
        self.value1 = value1
        self.value2 = value2
        self.value3 = value3
        self.value4 = value4
        self.string = f"Id: {value2}, host: {value3}, ip: {value4}, msg: {value1}"

    def send_to_temp(self):
        print(f"Making actions with {self.string}")

    def msg(self):
        print(f"Sending msg")

    def catch(self):
        self.msg()
        self.send_to_temp()


def main():
    print("If default:\n")
    one = Factory("hello world")
    one.catch()
    two = Factory("command", "id", "host", "ip")
    two.catch()


if __name__ == '__main__':
    main()
