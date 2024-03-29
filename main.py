from funciones_py import pyalops
import ctypes

fppc = ctypes.CDLL('funciones_c/p_punto.c.so')
fppcavx = ctypes.CDLL('funciones_c/p_punto_avx.c.so')
fvesc = ctypes.CDLL('funciones_c/vector_x_escalar.c.so')
fvescavx = ctypes.CDLL('funciones_c/vector_x_escalar_avx.c.so')

def mostrar_menu(opciones):
    print('Seleccione una opción:')
    for clave in sorted(opciones):
        print(f' {clave}) {opciones[clave][0]}')

def leer_opcion(opciones):
    while (a := input('Opción: ')) not in opciones:
        print('Opción incorrecta, vuelva a intentarlo.')
    return a

def ejecutar_opcion(opcion, opciones):
    opciones[opcion][1]()

def generar_menu(opciones, opcion_salida):
    opcion = None
    while opcion != opcion_salida:
        mostrar_menu(opciones)
        opcion = leer_opcion(opciones)
        ejecutar_opcion(opcion, opciones)
        print()

def menu_principal():
    opciones = {
        '1': ('Opción 1 - Vector x Escalar - C', accion1),
        '2': ('Opción 2 - Vector x Escalar (AVX) - C', accion2),
        '3': ('Opción 3 - Vector x Escalar - Py', accion3),
        '4': ('Opción 4 - Vector x Vector - C', accion4),
        '5': ('Opción 5 - Vector x Vector (AVX)- C', accion5),
        '6': ('Opción 6 - Vector x Vector - Py', accion6),
        '7': ('Salir', salir)
    }
    generar_menu(opciones, '7')

def accion1():
    resultVxE = fvesc.vectorXescalar()
    print('Has elegido la opción 1')
    print('Vector x Escalar - C: %s' % resultVxE)

def accion2():
    resultVxEAVX = fvescavx.vectorXescalarAVX()
    print('Has elegido la opción 2')
    print('Vector x Escalar (AVX) - C: %s' % resultVxEAVX)

def accion3():
    vxepy = pyalops.vector_x_escalar()
    print('Has elegido la opción 3')
    print('vector x escalar - py : %s' % vxepy)

def accion4():
    resultFPPC = fppc.calculateDotPoint() 
    print('Has elegido la opción 4')
    print('vector x vector - C : %s' % resultFPPC)

def accion5():
    resultFPPCAVX = fppcavx.calculateDotPointAvx() 
    print('Has elegido la opción 5')
    print('Vector x Vector (AVX)- C: %s' % resultFPPCAVX)

def accion6():
    vxvpy = pyalops.p_punto_py()
    print('Has elegido la opción 6')
    print("vector x vector - py : %s" % vxvpy)

def salir():
    print('Saliendo')

if __name__ == '__main__':
    menu_principal()
    
