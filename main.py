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
    print('Has elegido la opción 1')

def accion2():
    print('Has elegido la opción 2')

def accion3():
    print('Has elegido la opción 3')

def accion4():
    print('Has elegido la opción 4')

def accion5():
    print('Has elegido la opción 5')

def accion6():
    print('Has elegido la opción 6')

def salir():
    print('Saliendo')

if __name__ == '__main__':
    menu_principal()
