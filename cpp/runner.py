from sys import argv
from subprocess import call

source_code = argv[1]
binary = argv[1].split(".")[0]
call(["g++","-std=c++11","-g",source_code,"-o",binary])
call(["./"+binary])
