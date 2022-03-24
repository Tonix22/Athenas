from pathlib import Path #el path relativo
import ctypes # paquete para importar cosas de c
import numpy as np # para generar arreglos estilo C

# Load the shared library into c types.
libname = Path().absolute() / "file.so"
c_lib   = ctypes.CDLL(libname)

# Define return void pointer
# funcion en c -> void normal(int var)

c_lib.normal.restype  = ctypes.c_void_p
c_lib.normal.argtypes = [ctypes.c_int]

c_lib.normal(32)

# como conectar con numpy
# void no_normal(int * var,int size)

#int *
ptr = np.ctypeslib.ndpointer(dtype = np.int32, ndim = 1, flags = 'C')
c_lib.no_normal.restype  = ctypes.c_void_p
c_lib.no_normal.argtypes = [ptr, ctypes.c_int]

arr = np.array([170, 45, 75, 90, 802, 24, 2, 66],np.int32)
c_lib.no_normal(arr, len(arr))
print(arr)