#!/usr/bin/env python3

import soy
from time import sleep

client = soy.Client()
print(client.controllers)
print(client.pointer)

if __name__ == '__main__' :
	while True:
		print("Position:", client.pointer.position)


