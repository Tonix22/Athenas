#n 1200
#array [1,5,6,9] m = len(array) O(nm)
#n= 1 moneda 1
#resul[0]=0
#resul[1]=1
#resul[2]=2
#resul[3]=3
#resul[4]=4
#resul[5]=1
#resul[6]=1
#resul[7]=2
#resul[8]=3
#resul[9]=1
#resul[10]=2
#resul[11]=2




# a e i o u
# 0 1 2 3 4
#n = 0

#a e i o u   = 5
#a            1                     
#  e          1
#    i        1
#      o      1
#        u    1
#n = 1

#aa ae ai ao au # 5
#   ee ei eo eu # 5 - 1 = 4 fila a
#      ii io iu # 5 - 1 -1 = 3 fila a + e
#         oo ou # 5 - 1 -1 -1 = 2 fila a+e+i
#            uu # 5 - 1 -1 -1 -1 = 1 fila a+e+i+o
# 15
#n = 2
#aaa aae aai aao aau aee aei aeo aeu aii aio aiu aoo aou auu # 15 
#                    eee eei eeo eeu eii eio eiu eoo eou euu # 15 - fila a
#                                    iii iio iiu ioo iou iuu # 15 - fila a - fila b
#                                                ooo oou ouu # 15 - fila a - fila b -fila c
#                                                        uuu = 15 - fila a - fila b -fila c - fila d
# 35

# n = 4
# fila 1 # 35
#fila 2  # 35 -15 = 20
#fila 3  # 35 -15 -10 = 10
#fila 4  # 35 -15 -10 - 6 = 4
#fila 5  # 35 -15 -10 - 6 -3 = 1
# 35 + 20 + 10 +4 +1 = 70

# n = 5
#Fila 1  # 70
#fila 2  # 70 - 35 = 35
#fila 3  # 70 - 35 - 20 = 15
#fila 4  # 70 - 35 - 20 - 10 = 5
#fila 5  # 70 - 35 - 20 - 10 - 4 = 1
# 126
#  

# n = 6
# fila 1 # 126
# fila 2 # 126 - 70 = 56
# fila 3 # 126 - 70 - 35 = 21
# fila 4 # 126 - 70 - 35 -15 = 6
# fila 5 # 126 - 70 - 35 - 5 = 1

# (N-1)-(N0-2)
# 15 - 5 
# 15 - (N-2)-(N-2)-1 = 15-5-5-1
# 15 - (N-1)-((N-2)-1)-(N-2-2) = 15-5-(5-1)-(5-2)

import math 
# Initialize the number of items to choose from
n = 2

# Print total number of possible combinations
print (math.comb(5+n-1, n-1)) 