import subprocess
result = subprocess.getoutput("ls | grep cpp") #string 
result = result.split('\n') #array con todos los archivos individualmente
for file_cpp in result:
    file_cpp =file_cpp[0:-3]+"h" # RadixSort.cpp
    file = open(file_cpp,"w") # creando archivo
    
    guardian = file_cpp[0:-2].upper()+"_H" #quitamos punto y lo cambiamos por _
    file.write("#ifndef "+guardian+"\n")
    file.write("#define "+guardian+"\n")
    file.write("\t //insert code here \n")
    file.write("#endif\n")
    file.close()