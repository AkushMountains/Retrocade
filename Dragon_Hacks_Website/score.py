import serial
from firebase import firebase
from serial.tools import list_ports
serial  = Serial(list_ports.comports()[2][0],9600,timeout=5)

def __init__(self):
    self.Fire = None


def enableFirebase(self):
    self.Fire = firebase.FirebaseApplication('https://scores-dragonhacks.firebaseio.com/', None)
    self.Fire.enableFirebase()

def getScore(self):
    score = serial.readline()
    self.Fire.post('/scores', score, {'print':'pretty'} )
