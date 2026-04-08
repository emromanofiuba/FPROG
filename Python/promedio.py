numero = int(input("ingrese un numero para promediarlo: "))
while numero <=0 or type(numero) != "float":
    print("Debes ingresar numeros mayores a cero")
    numero = int(input("ingrese un numero nuevamente: "))


print("\n\n¡Ingresaste un numero mayor a cero. Ahora sí, estamos listos para calcular el promedio.")


suma = 0
cantidad_numeros = int(input("\ncuantos numeros quiere sumar para calcular el promedio: "))

for i in range (cantidad_numeros):
   numero = int(input(f"ingrese el {i+1}° un numero: "))
   suma+=numero

print(f"\nel promedio de los {i} numeros ingresados es: {suma/cantidad_numeros} ")


