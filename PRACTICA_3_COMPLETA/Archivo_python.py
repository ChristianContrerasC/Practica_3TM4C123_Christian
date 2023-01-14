"""AUTOR CHRISTIAN CONTRERAS"""
import serial as lib_serial

def invertir_nombre(nombre):
    """ FUNCION QUE INVIERTE """
    counter = 0
    nombre_nuevo = ''
    for index in range(len(nombre) - 1, -1, -1):
        nombre_nuevo += nombre[index]
        nombre_nuevo += str(counter)
        counter += 1
    return nombre_nuevo

"MODIFICAR AQUI PARA CADA PUERTO Y VELOCIDAD"
port = lib_serial.Serial('COM3', 9600)

while True:
    task = input("DESEA ESCRIBIR O LEER? (RESPUESTAS : ESCRIBIR / LEER ) ")
    if task == "ESCRIBIR":
        mensaje = input("ESCRIBA EL MENSAJE (, al final): ")
        port.write(bytes(mensaje, 'UTF-8'))
    elif task == "LEER":
        reading = port.readline()
        print(reading.decode()) #Default value UTF-8
    elif task == "ESCRIBIR_NOMBRE":
        nombre = input("NOMBRE? ")
        mensaje = invertir_nombre(nombre)
        port.write(bytes(mensaje, 'UTF-8'))

    if 0xff == ord('q'):
        break






