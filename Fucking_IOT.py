import pyrebase
import time
import serial

#perintah cek nya "ls /dev/serial/by-id/"
s = serial.Serial('/dev/serial/by-id/usb-1a86_USB2.0-Serial-if00-port0',115200, timeout=0)
config = {
  
  			"apiKey": "",
  			"authDomain": "",
  			"databaseURL": "https://iot-ict.firebaseio.com/",
  			"storageBucket": ""
			}

firebase = pyrebase.initialize_app(config)
db = firebase.database()
print "Sedang berjalan..."
def saklar():
			digital_0 = db.child("digital/data_0").stream(stream_handler)
			digital_1 = db.child("digital/data_1").stream(stream_handler)
			digital_2 = db.child("digital/data_2").stream(stream_handler)
			digital_3 = db.child("digital/data_3").stream(stream_handler)
			digital_4 = db.child("digital/data_4").stream(stream_handler)

def stream_handler(message):
	#print(message["data"])
	s.write(bytes(message["data"]))

def sensor():
			a = 0;
			pecah = ""
			data = s.readline()
			s.flushInput()
			for n in range(0,len(data)):
				if data[n] != "-":
					pecah += data[n]
				if data[n] == "-":
					if a == 0 :
						db.child("sensor/sen_0").set(pecah)
					if a == 1:
						db.child("sensor/sen_1").set(pecah)
					if a == 2:
						db.child("sensor/sen_2").set(pecah)
					a += 1
					pecah = ""
			time.sleep(0.1)
			
saklar()

while True :
			sensor()
